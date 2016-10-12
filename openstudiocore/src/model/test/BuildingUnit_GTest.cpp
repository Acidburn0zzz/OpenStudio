/**********************************************************************
 *  Copyright (c) 2008-2016, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include <algorithm>
#include <gtest/gtest.h>

#include <string>
#include <boost/optional.hpp>

#include "ModelFixture.hpp"

#include "../BuildingUnit.hpp"
#include "../BuildingUnit_Impl.hpp"
#include "../RenderingColor.hpp"
#include "../RenderingColor_Impl.hpp"
#include "../Space.hpp"
#include "../Space_Impl.hpp"

#include "../../utilities/units/Quantity.hpp"
#include "../../utilities/units/Unit.hpp"

using namespace openstudio;
using namespace openstudio::model;

TEST_F(ModelFixture, BuildingUnit_RenderingColor)
{

  Model model;
  BuildingUnit buildingUnit(model);
  RenderingColor color1(model);

  color1.setRenderingRedValue(255);
  color1.setRenderingGreenValue(0);
  color1.setRenderingBlueValue(0);
  color1.setRenderingAlphaValue(255);

  EXPECT_FALSE(buildingUnit.renderingColor());

  ASSERT_TRUE(buildingUnit.setRenderingColor(color1));

  boost::optional<RenderingColor> color2 = buildingUnit.renderingColor();
  ASSERT_TRUE(color2);

  EXPECT_EQ(color2->renderingRedValue(), 255);
  EXPECT_EQ(color2->renderingGreenValue(), 0);
  EXPECT_EQ(color2->renderingBlueValue(), 0);
  EXPECT_EQ(color2->renderingAlphaValue(), 255);

  buildingUnit.resetRenderingColor();
  ASSERT_FALSE(buildingUnit.renderingColor());

}

TEST_F(ModelFixture, BuildingUnit_BuildingUnitType)
{
  Model model;
  BuildingUnit bldgUnit(model);

  std::vector<std::string> bldgUnitTypeValues(bldgUnit.buildingUnitTypeValues());

  // Make sure both Residential and NonResidential are in the list and that there's only two items.
  EXPECT_NE(std::find(bldgUnitTypeValues.begin(), bldgUnitTypeValues.end(), "Residential"), bldgUnitTypeValues.end());
  EXPECT_NE(std::find(bldgUnitTypeValues.begin(), bldgUnitTypeValues.end(), "NonResidential"), bldgUnitTypeValues.end());
  EXPECT_EQ(bldgUnitTypeValues.size(), 2);

  // Check default
  boost::optional<std::string> bldgUnitType = bldgUnit.buildingUnitType();
  EXPECT_TRUE(bldgUnitType);
  if (bldgUnitType) {
      EXPECT_EQ(*bldgUnitType, "Residential");
  }

  // Assign New and check that the assignment worked.
  EXPECT_TRUE(bldgUnit.setBuildingUnitType("NonResidential"));
  bldgUnitType = bldgUnit.buildingUnitType();
  EXPECT_TRUE(bldgUnitType);
  if (bldgUnitType) {
      EXPECT_EQ(*bldgUnitType, "NonResidential");
  }

  // Reset and check that its back at the default.
  bldgUnit.resetBuildingUnitType();
  bldgUnitType = bldgUnit.buildingUnitType();
  EXPECT_TRUE(bldgUnitType);
  if (bldgUnitType) {
      EXPECT_EQ(*bldgUnitType, "Residential");
  }

  // Set it to something invalid
  EXPECT_TRUE(bldgUnit.setBuildingUnitType("NonResidential"));
  EXPECT_FALSE(bldgUnit.setBuildingUnitType("Bogus"));
  bldgUnitType = bldgUnit.buildingUnitType();
  EXPECT_TRUE(bldgUnitType);
  if (bldgUnitType) {
      EXPECT_EQ(*bldgUnitType, "NonResidential");
  }

}

TEST_F(ModelFixture, BuildingUnit_Spaces)
{
  Model model;
  BuildingUnit bldgUnit(model);
  bldgUnit.setName("Building Unit 1");

  Space space1 = Space(model);
  space1.setName("Space 1");
  EXPECT_TRUE(space1.setBuildingUnit(bldgUnit));
  boost::optional<BuildingUnit> retrievedBldgUnit(space1.buildingUnit());
  ASSERT_TRUE(retrievedBldgUnit);
  EXPECT_EQ(*retrievedBldgUnit, bldgUnit);

  Space space2 = Space(model);
  space2.setName("Space 2");
  EXPECT_TRUE(space2.setBuildingUnit(bldgUnit));

  std::vector<Space> spaces(bldgUnit.spaces());
  EXPECT_EQ(spaces.size(), 2);
  EXPECT_NE(std::find(spaces.begin(), spaces.end(), space1), spaces.end());
  EXPECT_NE(std::find(spaces.begin(), spaces.end(), space2), spaces.end());

  space1.resetBuildingUnit();
  retrievedBldgUnit = space1.buildingUnit();
  ASSERT_FALSE(retrievedBldgUnit);
  spaces = bldgUnit.spaces();
  EXPECT_EQ(spaces.size(), 1);
  EXPECT_EQ(spaces.at(0), space2);

}

TEST_F(ModelFixture, BuildingUnit_Features)
{
  Model model;
  BuildingUnit bldgUnit(model);

  // Test initially setting a string value
  EXPECT_TRUE(bldgUnit.setFeature("NumberOfBedrooms", "five"));
  boost::optional<std::string> dataType = bldgUnit.getFeatureDataType("NumberOfBedrooms");
  ASSERT_TRUE(dataType);
  EXPECT_EQ(*dataType, "String");
  boost::optional<std::string> strValue = bldgUnit.getFeatureAsString("NumberOfBedrooms");
  ASSERT_TRUE(strValue);
  EXPECT_EQ(*strValue, "five");

  // Test changing a string value
  EXPECT_TRUE(bldgUnit.setFeature("NumberOfBedrooms", "six"));
  dataType = bldgUnit.getFeatureDataType("NumberOfBedrooms");
  ASSERT_TRUE(dataType);
  EXPECT_EQ(*dataType, "String");
  strValue = bldgUnit.getFeatureAsString("NumberOfBedrooms");
  ASSERT_TRUE(strValue);
  EXPECT_EQ(*strValue, "six");

  // Test setting a boolean value
  EXPECT_TRUE(bldgUnit.setFeature("isNicePlace", false));
  dataType = bldgUnit.getFeatureDataType("isNicePlace");
  ASSERT_TRUE(dataType);
  EXPECT_EQ(*dataType, "Boolean");
  boost::optional<bool> boolValue = bldgUnit.getFeatureAsBoolean("isNicePlace");
  ASSERT_TRUE(boolValue);
  ASSERT_FALSE(*boolValue);

  // Test changing a boolean value
  EXPECT_TRUE(bldgUnit.setFeature("isNicePlace", true));
  dataType = bldgUnit.getFeatureDataType("isNicePlace");
  ASSERT_TRUE(dataType);
  EXPECT_EQ(*dataType, "Boolean");
  boolValue = bldgUnit.getFeatureAsBoolean("isNicePlace");
  ASSERT_TRUE(boolValue);
  ASSERT_TRUE(*boolValue);

  // Test Feature Name getter
  const std::vector<std::string> featureNames(bldgUnit.featureNames());
  EXPECT_EQ(featureNames.size(), 2);
  EXPECT_EQ(featureNames[0], "NumberOfBedrooms");
  EXPECT_EQ(featureNames[1], "isNicePlace");

  // Test setting a double value
  EXPECT_TRUE(bldgUnit.setFeature("NumberOfBathrooms", 1.5));
  dataType = bldgUnit.getFeatureDataType("NumberOfBathrooms");
  ASSERT_TRUE(dataType);
  EXPECT_EQ(*dataType, "Double");
  boost::optional<double> dblValue = bldgUnit.getFeatureAsDouble("NumberOfBathrooms");
  ASSERT_TRUE(dblValue);
  boost::optional<int> intValue = bldgUnit.getFeatureAsInteger("NumberOfBathrooms");
  ASSERT_FALSE(intValue);
  ASSERT_FLOAT_EQ(*dblValue, 1.5);

  // Test setting a feature to a value of a different type
  EXPECT_TRUE(bldgUnit.setFeature("NumberOfBedrooms", 3));
  dataType = bldgUnit.getFeatureDataType("NumberOfBedrooms");
  ASSERT_TRUE(dataType);
  EXPECT_EQ(*dataType, "Integer");
  dblValue = bldgUnit.getFeatureAsDouble("NumberOfBedrooms");
  ASSERT_FALSE(dblValue);
  intValue = bldgUnit.getFeatureAsInteger("NumberOfBedrooms");
  ASSERT_TRUE(intValue);
  ASSERT_EQ(*intValue, 3);

  // Test resetting a feature
  EXPECT_TRUE(bldgUnit.resetFeature("isNicePlace"));
  dataType = bldgUnit.getFeatureDataType("isNicePlace");
  ASSERT_FALSE(dataType);
  EXPECT_FALSE(bldgUnit.resetFeature("bogusName"));

  // Test suggested feature names
  EXPECT_TRUE(bldgUnit.setFeature("MyUniqueFeature", 5));
  BuildingUnit bldgUnit2(model);
  std::vector<std::string> suggestedFeatures(bldgUnit2.suggestedFeatures());
  ASSERT_EQ(suggestedFeatures.size(), 3);
  ASSERT_NE(std::find(suggestedFeatures.begin(), suggestedFeatures.end(), "NumberOfBedrooms"), suggestedFeatures.end());
  ASSERT_NE(std::find(suggestedFeatures.begin(), suggestedFeatures.end(), "NumberOfBathrooms"), suggestedFeatures.end());
  ASSERT_NE(std::find(suggestedFeatures.begin(), suggestedFeatures.end(), "MyUniqueFeature"), suggestedFeatures.end());

}