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

#ifndef MODEL_GENERATORFUELCELLSTACKCOOLER_HPP
#define MODEL_GENERATORFUELCELLSTACKCOOLER_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject.hpp"

namespace openstudio {

namespace model {

class Connection;

namespace detail {

  class GeneratorFuelCellStackCooler_Impl;

} // detail

/** GeneratorFuelCellStackCooler is a ModelObject that wraps the OpenStudio IDD object 'OS:Generator:FuelCell:StackCooler'. */
class MODEL_API GeneratorFuelCellStackCooler : public ModelObject {
 public:
  /** @name Constructors and Destructors */
  //@{

  explicit GeneratorFuelCellStackCooler(const Model& model);

  explicit GeneratorFuelCellStackCooler(const Model& model,
                                        const Connection& waterInletNode,
                                        const Connection& waterOutletNode);

  virtual ~GeneratorFuelCellStackCooler() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  boost::optional<Connection> heatRecoveryWaterInletNode() const;

  boost::optional<Connection> heatRecoveryWaterOutletNode() const;

  double nominalStackTemperature() const;

  double actualStackTemperature() const;

  double coefficientr0() const;

  double coefficientr1() const;

  double coefficientr2() const;

  double coefficientr3() const;

  double stackCoolantFlowRate() const;

  double stackCoolerUFactorTimesAreaValue() const;

  double fscogenAdjustmentFactor() const;

  double stackCogenerationExchangerArea() const;

  double stackCogenerationExchangerNominalFlowRate() const;

  double stackCogenerationExchangerNominalHeatTransferCoefficient() const;

  double stackCogenerationExchangerNominalHeatTransferCoefficientExponent() const;

  double stackCoolerPumpPower() const;

  double stackCoolerPumpHeatLossFraction() const;

  double stackAirCoolerFanCoefficientf0() const;

  double stackAirCoolerFanCoefficientf1() const;

  double stackAirCoolerFanCoefficientf2() const;

  //@}
  /** @name Setters */
  //@{

  bool setHeatRecoveryWaterInletNode(const Connection& connection);

  void resetHeatRecoveryWaterInletNode();

  bool setHeatRecoveryWaterOutletNode(const Connection& connection);

  void resetHeatRecoveryWaterOutletNode();

  void setNominalStackTemperature(double nominalStackTemperature);

  void resetNominalStackTemperature();

  void setActualStackTemperature(double actualStackTemperature);

  void resetActualStackTemperature();

  void setCoefficientr0(double coefficientr0);

  void resetCoefficientr0();

  void setCoefficientr1(double coefficientr1);

  void resetCoefficientr1();

  void setCoefficientr2(double coefficientr2);

  void resetCoefficientr2();

  void setCoefficientr3(double coefficientr3);

  void resetCoefficientr3();

  void setStackCoolantFlowRate(double stackCoolantFlowRate);

  void resetStackCoolantFlowRate();

  void setStackCoolerUFactorTimesAreaValue(double stackCoolerUFactorTimesAreaValue);

  void resetStackCoolerUFactorTimesAreaValue();

  void setFscogenAdjustmentFactor(double fscogenAdjustmentFactor);

  void resetFscogenAdjustmentFactor();

  void setStackCogenerationExchangerArea(double stackCogenerationExchangerArea);

  void resetStackCogenerationExchangerArea();

  void setStackCogenerationExchangerNominalFlowRate(double stackCogenerationExchangerNominalFlowRate);

  void resetStackCogenerationExchangerNominalFlowRate();

  void setStackCogenerationExchangerNominalHeatTransferCoefficient(double stackCogenerationExchangerNominalHeatTransferCoefficient);

  void resetStackCogenerationExchangerNominalHeatTransferCoefficient();

  void setStackCogenerationExchangerNominalHeatTransferCoefficientExponent(double stackCogenerationExchangerNominalHeatTransferCoefficientExponent);

  void resetStackCogenerationExchangerNominalHeatTransferCoefficientExponent();

  void setStackCoolerPumpPower(double stackCoolerPumpPower);

  void resetStackCoolerPumpPower();

  bool setStackCoolerPumpHeatLossFraction(double stackCoolerPumpHeatLossFraction);

  void resetStackCoolerPumpHeatLossFraction();

  void setStackAirCoolerFanCoefficientf0(double stackAirCoolerFanCoefficientf0);

  void resetStackAirCoolerFanCoefficientf0();

  void setStackAirCoolerFanCoefficientf1(double stackAirCoolerFanCoefficientf1);

  void resetStackAirCoolerFanCoefficientf1();

  void setStackAirCoolerFanCoefficientf2(double stackAirCoolerFanCoefficientf2);

  void resetStackAirCoolerFanCoefficientf2();

  //@}
  /** @name Other */
  //@{

  //@}
 protected:
  /// @cond
  typedef detail::GeneratorFuelCellStackCooler_Impl ImplType;

  explicit GeneratorFuelCellStackCooler(std::shared_ptr<detail::GeneratorFuelCellStackCooler_Impl> impl);

  friend class detail::GeneratorFuelCellStackCooler_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
 private:
  REGISTER_LOGGER("openstudio.model.GeneratorFuelCellStackCooler");
};

/** \relates GeneratorFuelCellStackCooler*/
typedef boost::optional<GeneratorFuelCellStackCooler> OptionalGeneratorFuelCellStackCooler;

/** \relates GeneratorFuelCellStackCooler*/
typedef std::vector<GeneratorFuelCellStackCooler> GeneratorFuelCellStackCoolerVector;

} // model
} // openstudio

#endif // MODEL_GENERATORFUELCELLSTACKCOOLER_HPP

