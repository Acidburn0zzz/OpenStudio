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

#ifndef MODEL_AIRFLOWNETWORKDISTRIBUTIONLINKAGE_HPP
#define MODEL_AIRFLOWNETWORKDISTRIBUTIONLINKAGE_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject.hpp"

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class AirflowNetworkNode;
class AirflowNetworkComponent;
class ThermalZone;

namespace detail {

  class AirflowNetworkDistributionLinkage_Impl;

} // detail

/** AirflowNetworkDistributionLinkage is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkDistributionLinkage'. */
class MODEL_API AirflowNetworkDistributionLinkage : public ModelObject {
 public:
  /** @name Constructors and Destructors */
  //@{

  explicit AirflowNetworkDistributionLinkage(const Model& model);

  virtual ~AirflowNetworkDistributionLinkage() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  // TODO: Check return type. From object lists, some candidates are: AirflowNetworkNodeAndZone.
  AirflowNetworkNode node1() const;

  // TODO: Check return type. From object lists, some candidates are: AirflowNetworkNodeAndZone.
  AirflowNetworkNode node2() const;

  // TODO: Check return type. From object lists, some candidates are: AirflowNetworkComponent.
  AirflowNetworkComponent component() const;

  // TODO: Check return type. From object lists, some candidates are: Zone.
  boost::optional<ThermalZone> thermalZone() const;

  //@}
  /** @name Setters */
  //@{

  // TODO: Check argument type. From object lists, some candidates are: AirflowNetworkNodeAndZone.
  bool setNode1(const AirflowNetworkNode& airflowNetworkNodeAndZone);

  // TODO: Check argument type. From object lists, some candidates are: AirflowNetworkNodeAndZone.
  bool setNode2(const AirflowNetworkNode& airflowNetworkNodeAndZone);

  // TODO: Check argument type. From object lists, some candidates are: AirflowNetworkComponent.
  bool setComponent(const AirflowNetworkComponent& airflowNetworkComponent);

  // TODO: Check argument type. From object lists, some candidates are: Zone.
  bool setThermalZone(const ThermalZone& zone);

  void resetThermalZone();

  //@}
  /** @name Other */
  //@{

  //@}
 protected:
  /// @cond
  typedef detail::AirflowNetworkDistributionLinkage_Impl ImplType;

  explicit AirflowNetworkDistributionLinkage(std::shared_ptr<detail::AirflowNetworkDistributionLinkage_Impl> impl);

  friend class detail::AirflowNetworkDistributionLinkage_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
 private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkDistributionLinkage");
};

/** \relates AirflowNetworkDistributionLinkage*/
typedef boost::optional<AirflowNetworkDistributionLinkage> OptionalAirflowNetworkDistributionLinkage;

/** \relates AirflowNetworkDistributionLinkage*/
typedef std::vector<AirflowNetworkDistributionLinkage> AirflowNetworkDistributionLinkageVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKDISTRIBUTIONLINKAGE_HPP

