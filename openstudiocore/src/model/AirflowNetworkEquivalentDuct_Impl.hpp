/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2017, Alliance for Sustainable Energy, LLC. All rights reserved.
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

#ifndef MODEL_AIRFLOWNETWORKEQUIVALENTDUCT_IMPL_HPP
#define MODEL_AIRFLOWNETWORKEQUIVALENTDUCT_IMPL_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

// AFNCoilNames
class CoilCoolingDXSingleSpeed;
class CoilCoolingDXTwoStageWithHumidityControlMode;
class CoilCoolingDXMultiSpeed;
class CoilCoolingWater;
class CoilHeatingDXSingleSpeed;
class CoilHeatingElectric;
class CoilHeatingGas;
class CoilHeatingDesuperheater;
class CoilHeatingWater;
class CoilHeatingDXMultiSpeed;

namespace detail {

  /** AirflowNetworkEquivalentDuct_Impl is a ModelObject_Impl that is the implementation class for AirflowNetworkEquivalentDuct.*/
  class MODEL_API AirflowNetworkEquivalentDuct_Impl : public ModelObject_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    AirflowNetworkEquivalentDuct_Impl(const IdfObject& idfObject,
                                      Model_Impl* model,
                                      bool keepHandle);

    AirflowNetworkEquivalentDuct_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                      Model_Impl* model,
                                      bool keepHandle);

    AirflowNetworkEquivalentDuct_Impl(const AirflowNetworkEquivalentDuct_Impl& other,
                                      Model_Impl* model,
                                      bool keepHandle);

    virtual ~AirflowNetworkEquivalentDuct_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    // TODO: Check return type. From object lists, some candidates are: AFNTerminalUnit.
    template <typename T> typename std::enable_if<
                                        std::is_same<CoilCoolingDXSingleSpeed, T>::value ||
                                        std::is_same<CoilCoolingDXTwoStageWithHumidityControlMode, T>::value ||
                                        std::is_same<CoilCoolingDXMultiSpeed, T>::value ||
                                        std::is_same<CoilCoolingWater, T>::value ||
                                        std::is_same<CoilHeatingDXSingleSpeed, T>::value ||
                                        std::is_same<CoilHeatingElectric, T>::value ||
                                        std::is_same<CoilHeatingGas, T>::value ||
                                        std::is_same<CoilHeatingDesuperheater, T>::value ||
                                        std::is_same<CoilHeatingWater, T>::value ||
                                        std::is_same<CoilHeatingDXMultiSpeed, T>::value, T>::type
    getComponent() const
    {
      return getObject<ModelObject>().getModelObjectTarget<T>(OS_AirflowNetworkEquivalentDuctFields::ComponentName);
    }

    double airPathLength() const;

    double airPathHydraulicDiameter() const;

    //@}
    /** @name Setters */
    //@{

    template <typename T> bool setComponent(typename std::enable_if<
                                            std::is_same<CoilCoolingDXSingleSpeed, T>::value ||
                                            std::is_same<CoilCoolingDXTwoStageWithHumidityControlMode, T>::value ||
                                            std::is_same<CoilCoolingDXMultiSpeed, T>::value ||
                                            std::is_same<CoilCoolingWater, T>::value ||
                                            std::is_same<CoilHeatingDXSingleSpeed, T>::value ||
                                            std::is_same<CoilHeatingElectric, T>::value ||
                                            std::is_same<CoilHeatingGas, T>::value ||
                                            std::is_same<CoilHeatingDesuperheater, T>::value ||
                                            std::is_same<CoilHeatingWater, T>::value ||
                                            std::is_same<CoilHeatingDXMultiSpeed, T>::value, T>::type
                                            &component)
    {
      // Set parent or something here?
      return setPointer(OS_AirflowNetworkEquivalentDuctFields::ComponentName, component.handle());
    }

    bool setAirPathLength(double airPathLength);

    bool setAirPathHydraulicDiameter(double airPathHydraulicDiameter);

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.AirflowNetworkEquivalentDuct");

    // TODO: Check the return types of these methods.
    // Optional getters for use by methods like children() so can remove() if the constructor fails.
    // There are other ways for the public versions of these getters to fail--perhaps all required
    // objects should be returned as boost::optionals
    //boost::optional<AFNTerminalUnit> optionalTerminalUnit() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKEQUIVALENTDUCT_IMPL_HPP

