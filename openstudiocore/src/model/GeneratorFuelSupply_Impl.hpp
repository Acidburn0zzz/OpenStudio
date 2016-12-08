/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2016, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#ifndef MODEL_GENERATORFUELSUPPLY_IMPL_HPP
#define MODEL_GENERATORFUELSUPPLY_IMPL_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class Connection;
class Schedule;
class CurveCubic;

namespace detail {

  /** GeneratorFuelSupply_Impl is a ModelObject_Impl that is the implementation class for GeneratorFuelSupply.*/
  class MODEL_API GeneratorFuelSupply_Impl : public ModelObject_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    GeneratorFuelSupply_Impl(const IdfObject& idfObject,
                             Model_Impl* model,
                             bool keepHandle);

    GeneratorFuelSupply_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                             Model_Impl* model,
                             bool keepHandle);

    GeneratorFuelSupply_Impl(const GeneratorFuelSupply_Impl& other,
                             Model_Impl* model,
                             bool keepHandle);

    virtual ~GeneratorFuelSupply_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const;

    //extensible fields

    bool addConstituent(std::string name, std::string molarFraction);

    void removeConstituent(unsigned groupIndex);

    void removeAllConstituents();

    std::vector< std::pair<std::string, std::string> > constituents();

    //@}
    /** @name Getters */
    //@{

    std::string fuelTemperatureModelingMode() const;

    boost::optional<Connection> fuelTemperatureReferenceNode() const;

    boost::optional<Schedule> fuelTemperatureSchedule() const;

    CurveCubic compressorPowerMultiplierFunctionofFuelRateCurve() const;

    double compressorHeatLossFactor() const;

    std::string fuelType() const;

    double liquidGenericFuelLowerHeatingValue() const;

    double liquidGenericFuelHigherHeatingValue() const;

    double liquidGenericFuelMolecularWeight() const;

    double liquidGenericFuelCO2EmissionFactor() const;

    double numberofConstituentsinGaseousConstituentFuelSupply() const;

    //@}
    /** @name Setters */
    //@{

    bool setFuelTemperatureModelingMode(const std::string& fuelTemperatureModelingMode);

    void resetFuelTemperatureModelingMode();

    bool setFuelTemperatureReferenceNode(const Connection& connection);

    void resetFuelTemperatureReferenceNode();

  // Note Schedules are passed by reference, not const reference.
    bool setFuelTemperatureSchedule(Schedule& schedule);

    void resetFuelTemperatureSchedule();

    bool setCompressorPowerMultiplierFunctionofFuelRateCurve(const CurveCubic& cubicCurves);

    void resetCompressorPowerMultiplierFunctionofFuelRateCurve();

    bool setCompressorHeatLossFactor(double compressorHeatLossFactor);

    void resetCompressorHeatLossFactor();

    bool setFuelType(const std::string& fuelType);

    void resetFuelType();

    void setLiquidGenericFuelLowerHeatingValue(double liquidGenericFuelLowerHeatingValue);

    void resetLiquidGenericFuelLowerHeatingValue();

    void setLiquidGenericFuelHigherHeatingValue(double liquidGenericFuelHigherHeatingValue);

    void resetLiquidGenericFuelHigherHeatingValue();

    void setLiquidGenericFuelMolecularWeight(double liquidGenericFuelMolecularWeight);

    void resetLiquidGenericFuelMolecularWeight();

    void setLiquidGenericFuelCO2EmissionFactor(double liquidGenericFuelCO2EmissionFactor);

    void resetLiquidGenericFuelCO2EmissionFactor();

    bool setNumberofConstituentsinGaseousConstituentFuelSupply(double numberofConstituentsinGaseousConstituentFuelSupply);

    void resetNumberofConstituentsinGaseousConstituentFuelSupply();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.GeneratorFuelSupply");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_GENERATORFUELSUPPLY_IMPL_HPP

