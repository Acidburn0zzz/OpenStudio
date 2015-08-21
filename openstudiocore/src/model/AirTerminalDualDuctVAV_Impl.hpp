/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
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

#ifndef MODEL_AIRTERMINALDUALDUCTVAV_IMPL_HPP
#define MODEL_AIRTERMINALDUALDUCTVAV_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/Mixer_Impl.hpp>

namespace openstudio {
namespace model {

class Schedule;
class DesignSpecificationOutdoorAir;
class Node;

namespace detail {

  /** AirTerminalDualDuctVAV_Impl is a Mixer_Impl that is the implementation class for AirTerminalDualDuctVAV.*/
  class MODEL_API AirTerminalDualDuctVAV_Impl : public Mixer_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    AirTerminalDualDuctVAV_Impl(const IdfObject& idfObject,
                                Model_Impl* model,
                                bool keepHandle);

    AirTerminalDualDuctVAV_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                Model_Impl* model,
                                bool keepHandle);

    AirTerminalDualDuctVAV_Impl(const AirTerminalDualDuctVAV_Impl& other,
                                Model_Impl* model,
                                bool keepHandle);

    virtual ~AirTerminalDualDuctVAV_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const;

    //@}
    /** @name Getters */
    //@{

    boost::optional<Schedule> availabilitySchedule() const;

    boost::optional<double> maximumDamperAirFlowRate() const;

    bool isMaximumDamperAirFlowRateAutosized() const;

    double zoneMinimumAirFlowFraction() const;

    boost::optional<DesignSpecificationOutdoorAir> designSpecificationOutdoorAirObject() const;

    //@}
    /** @name Setters */
    //@{

    bool setAvailabilitySchedule(Schedule& schedule);

    void resetAvailabilitySchedule();

    bool setMaximumDamperAirFlowRate(boost::optional<double> maximumDamperAirFlowRate);

    void autosizeMaximumDamperAirFlowRate();

    bool setZoneMinimumAirFlowFraction(double zoneMinimumAirFlowFraction);

    bool setDesignSpecificationOutdoorAirObject(const boost::optional<DesignSpecificationOutdoorAir>& designSpecificationOutdoorAir);

    void resetDesignSpecificationOutdoorAirObject();

    //@}
    /** @name Other */
    //@{

    virtual unsigned outletPort() const override;

    virtual unsigned inletPort(unsigned branchIndex) const override;

    virtual unsigned nextInletPort() const override;

    unsigned newInletPortAfterBranch(unsigned branchIndex) override;

    void removePortForBranch(unsigned branchIndex) override;

    boost::optional<Node> hotAirInletNode() const;

    boost::optional<Node> coldAirInletNode() const;

    bool addToNode(Node & node);

    std::vector<IdfObject> remove();

    virtual ModelObject clone(Model model) const override;

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.AirTerminalDualDuctVAV");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_AIRTERMINALDUALDUCTVAV_IMPL_HPP
