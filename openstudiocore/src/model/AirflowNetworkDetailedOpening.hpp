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

#ifndef MODEL_AIRFLOWNETWORKDETAILEDOPENING_HPP
#define MODEL_AIRFLOWNETWORKDETAILEDOPENING_HPP

#include <model/ModelAPI.hpp>

#include "AirflowNetworkComponent.hpp"

namespace openstudio {

namespace model {

class MODEL_API DetailedOpeningFactorData
{
public:
  /** @name Constructor */
  //@{
  DetailedOpeningFactorData(double openingFactor, double dischargeCoefficient, double widthFactor, double heightFactor,
    double startHeightFactor);

  //@}
  /** @name Getters */
  //@{
  /** For a rectangular non-pivoted window or door (LVO Type 1), the opening factor corresponds to the fraction of the 
   * window or door that is opened. For rectangular horizontally-pivoted windows (LVO Type 2), the opening factor is
   * the angular fraction that window is open. For example, an opening angle of 45 degrees corresponds to an opening
   * factor of 0.50 since the maximum opening angle is 90 degrees.
   */
  double openingFactor() const;
  /** The discharge coefficient indicates the fractional effectiveness for air flow through a window or door at
   * that Opening Factor.
   */
  double dischargeCoefficient() const;
  /** The width factor is the opening width divided by the window or door width. */
  double widthFactor() const;
  /** The height factor is the opening height divided by the window or door height. */
  double heightFactor() const;
  /** The start height factor is the start height divided by the window or door height.
   * Start height is the distance between the bottom of the window or door and the
   * bottom of the window or door opening. The sum of the height factor and the start height
   * factor must be less than 1.0 in order to have the opening within the window or door dimensions.
   */
  double startHeightFactor() const;

  //@}
  /** @name Setters */
  //@{
  /** Sets the opening factor. */
  bool setOpeningFactor(double openingFactor);
  /** Sets the discharge coefficient. */
  bool setDischargeCoefficient(double dischargeCoefficient);
  /** Sets the width factor. */
  bool setWidthFactor(double widthFactor);
  /** Sets the height factor. */
  bool setHeightFactor(double heightFactor);
  /** Sets the start height factor. */
  bool setStartHeightFactor(double startHeightFactor);
  //@}
private:
  double m_openingFactor;
  double m_dischargeCoefficient;
  double m_widthFactor;
  double m_heightFactor;
  double m_startHeightFactor;

};

namespace detail {

class AirflowNetworkDetailedOpening_Impl;

} // detail

/** AirflowNetworkDetailedOpening is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkDetailedOpening'. */
class MODEL_API AirflowNetworkDetailedOpening : public AirflowNetworkComponent
{
public:
  /** @name Constructors and Destructors */
  //@{

  AirflowNetworkDetailedOpening(const Model& model,
    double massFlowCoefficientWhenOpeningisClosed,
    double massFlowExponentWhenOpeningisClosed,
    std::string typeofRectangularLargeVerticalOpening,
    double extraCrackLengthorHeightofPivotingAxis,
    std::vector<DetailedOpeningFactorData>& openingFactors);

  virtual ~AirflowNetworkDetailedOpening() {}

  //@}

  static IddObjectType iddObjectType();

  static std::vector<std::string> typeofRectangularLargeVerticalOpeningValues();

  /** @name Getters */
  //@{

  double airMassFlowCoefficientWhenOpeningisClosed() const;

  double airMassFlowExponentWhenOpeningisClosed() const;

  bool isAirMassFlowExponentWhenOpeningisClosedDefaulted() const;

  std::string typeofRectangularLargeVerticalOpening() const;

  bool isTypeofRectangularLargeVerticalOpeningDefaulted() const;

  double extraCrackLengthorHeightofPivotingAxis() const;

  bool isExtraCrackLengthorHeightofPivotingAxisDefaulted() const;

  std::vector<DetailedOpeningFactorData> openingFactors() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed);

  bool setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed);

  void resetAirMassFlowExponentWhenOpeningisClosed();

  bool setTypeofRectangularLargeVerticalOpening(std::string typeofRectangularLargeVerticalOpening);

  void resetTypeofRectangularLargeVerticalOpening();

  bool setExtraCrackLengthorHeightofPivotingAxis(double extraCrackLengthorHeightofPivotingAxis);

  void resetExtraCrackLengthorHeightofPivotingAxis();

  bool setOpeningFactors(std::vector<DetailedOpeningFactorData>& factors);

  //@}
protected:
  /// @cond
  typedef detail::AirflowNetworkDetailedOpening_Impl ImplType;

  explicit AirflowNetworkDetailedOpening(std::shared_ptr<detail::AirflowNetworkDetailedOpening_Impl> impl);

  friend class detail::AirflowNetworkDetailedOpening_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkDetailedOpening");
};

/** \relates AirflowNetworkDetailedOpening*/
typedef boost::optional<AirflowNetworkDetailedOpening> OptionalAirflowNetworkDetailedOpening;

/** \relates AirflowNetworkDetailedOpening*/
typedef std::vector<AirflowNetworkDetailedOpening> AirflowNetworkDetailedOpeningVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKDETAILEDOPENING_HPP

