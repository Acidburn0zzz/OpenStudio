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

#ifndef MODEL_GENERATORFUELCELLAUXILIARYHEATER_IMPL_HPP
#define MODEL_GENERATORFUELCELLAUXILIARYHEATER_IMPL_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class ThermalZone;

namespace detail {

  /** GeneratorFuelCellAuxiliaryHeater_Impl is a ModelObject_Impl that is the implementation class for GeneratorFuelCellAuxiliaryHeater.*/
  class MODEL_API GeneratorFuelCellAuxiliaryHeater_Impl : public ModelObject_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    GeneratorFuelCellAuxiliaryHeater_Impl(const IdfObject& idfObject,
                                          Model_Impl* model,
                                          bool keepHandle);

    GeneratorFuelCellAuxiliaryHeater_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                          Model_Impl* model,
                                          bool keepHandle);

    GeneratorFuelCellAuxiliaryHeater_Impl(const GeneratorFuelCellAuxiliaryHeater_Impl& other,
                                          Model_Impl* model,
                                          bool keepHandle);

    virtual ~GeneratorFuelCellAuxiliaryHeater_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    boost::optional<double> excessAirRatio() const;

    boost::optional<double> ancillaryPowerConstantTerm() const;

    boost::optional<double> ancillaryPowerLinearTerm() const;

    boost::optional<double> skinLossUFactorTimesAreaValue() const;

    boost::optional<std::string> skinLossDestination() const;

    // TODO: Check return type. From object lists, some candidates are: Zone.
    boost::optional<ThermalZone> zonetoReceiveSkinLosses() const;

    boost::optional<std::string> heatingCapacityUnits() const;

    boost::optional<double> maximumHeatingCapacityinWatts() const;

    boost::optional<double> minimumHeatingCapacityinWatts() const;

    boost::optional<double> maximumHeatingCapacityinKmolperSecond() const;

    boost::optional<double> minimumHeatingCapacityinKmolperSecond() const;

    //@}
    /** @name Setters */
    //@{

    void setExcessAirRatio(double excessAirRatio);

    void resetExcessAirRatio();

    void setAncillaryPowerConstantTerm(double ancillaryPowerConstantTerm);

    void resetAncillaryPowerConstantTerm();

    void setAncillaryPowerLinearTerm(double ancillaryPowerLinearTerm);

    void resetAncillaryPowerLinearTerm();

    void setSkinLossUFactorTimesAreaValue(double skinLossUFactorTimesAreaValue);

    void resetSkinLossUFactorTimesAreaValue();

    bool setSkinLossDestination(const std::string& skinLossDestination);

    void resetSkinLossDestination();

    // TODO: Check argument type. From object lists, some candidates are: Zone.
    bool setZonetoReceiveSkinLosses(const ThermalZone& zone);

    void resetZonetoReceiveSkinLosses();

    bool setHeatingCapacityUnits(const std::string& heatingCapacityUnits);

    void resetHeatingCapacityUnits();

    void setMaximumHeatingCapacityinWatts(double maximumHeatingCapacityinWatts);

    void resetMaximumHeatingCapacityinWatts();

    void setMinimumHeatingCapacityinWatts(double minimumHeatingCapacityinWatts);

    void resetMinimumHeatingCapacityinWatts();

    void setMaximumHeatingCapacityinKmolperSecond(double maximumHeatingCapacityinKmolperSecond);

    void resetMaximumHeatingCapacityinKmolperSecond();

    void setMinimumHeatingCapacityinKmolperSecond(double minimumHeatingCapacityinKmolperSecond);

    void resetMinimumHeatingCapacityinKmolperSecond();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.GeneratorFuelCellAuxiliaryHeater");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_GENERATORFUELCELLAUXILIARYHEATER_IMPL_HPP

