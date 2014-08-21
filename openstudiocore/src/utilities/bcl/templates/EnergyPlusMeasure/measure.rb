#see the URL below for information on how to write OpenStudio measures
# http://openstudio.nrel.gov/openstudio-measure-writing-guide

#start the measure
class EnergyPlusMeasure < OpenStudio::Ruleset::WorkspaceUserScript
  
  # machine readable name
  def name
    return "EnergyPlusMeasure"
  end
  # human readable name
  def display_name
    return "EnergyPlusMeasure"
  end
  
  # human readable description
  def description
    return "A human readable description goes here"
  end
  
  # human readable description
  def modeler_description
    return "A human readable description of the technical implementation details goes here"
  end
  
  #define the arguments that the user will input
  def arguments(workspace)
    args = OpenStudio::Ruleset::OSArgumentVector.new
    
    #make an argument for your name
    user_name = OpenStudio::Ruleset::OSArgument::makeStringArgument("user_name", true)
    user_name.setDisplayName("What is your name?")
    user_name.setDescription("This name will be appended to the zone name if a new zone is created.")
    args << user_name

    #make an argument to add new zone true/false
    add_zone = OpenStudio::Ruleset::OSArgument::makeBoolArgument("add_zone", true)
    add_zone.setDisplayName("Add a zone to your model?")
    add_zone.setDescription("If true a new zone will be added to the model.")
    add_zone.setDefaultValue(true)
    args << add_zone
    
    return args
  end #end the arguments method

  #define what happens when the measure is run
  def run(workspace, runner, user_arguments)
    super(workspace, runner, user_arguments)
    
    #use the built-in error checking 
    if not runner.validateUserArguments(arguments(workspace), user_arguments)
      return false
    end

    #assign the user inputs to variables
    user_name = runner.getStringArgumentValue("user_name", user_arguments)
    add_zone = runner.getBoolArgumentValue("add_zone", user_arguments)

    #check the user_name for reasonableness
    puts user_name
    if user_name == ""
      runner.registerError("No Name was Entered.")
      return false
    end
    
    #ruby test to see if first charter of string is uppercase letter
    if not user_name[0..0] =~ /[A-Z]/ 
      runner.registerWarning("Your entered name was not capitalized.")    
    end
    
    #returning the name in an a sentence
    runner.registerInfo("Hello #{user_name}, thanks for entering your name.")

    #get all thermal zones in model
    zones = workspace.getObjectsByType("Zone".to_IddObjectType)

    #reporting initial condition of model
    runner.registerInitialCondition("The building started with #{zones.size} zones.")

    #adding a new zone to the model and then using setString to change the name
    # http://apps1.eere.energy.gov/buildings/energyplus/pdfs/inputoutputreference.pdf#nameddest=Zone
    if add_zone == true
      new_zone_string = "    
      Zone,
        zone 1,               !- Name
        0,                       !- Direction of Relative North {deg}
        0,                       !- X Origin {m}
        0,                       !- Y Origin {m}
        0,                       !- Z Origin {m}
        1,                       !- Type
        1,                       !- Multiplier
        autocalculate,           !- Ceiling Height {m}
        autocalculate;           !- Volume {m3}
        "
      idfObject = OpenStudio::IdfObject::load(new_zone_string)
      object = idfObject.get
      wsObject = workspace.addObject(object)
      new_zone = wsObject.get
    
      #you could just add variable in the string above. Name is changed after zone added just to demonstrate setString
      new_zone.setString(0,"Hello_World test zone")

      runner.registerInfo("A zone named '#{new_zone.getString(0)}' was added.")

    else
      runner.registerAsNotApplicable("You have chosen not to add a zone. Your model will not be altered.")
      return true
    end

    #reporting final condition of model
    finishing_zones = workspace.getObjectsByType("Zone".to_IddObjectType)
    runner.registerFinalCondition("The building finished with #{finishing_zones.size} zones.")
    
    return true
 
  end #end the run method

end #end the measure

#this allows the measure to be use by the application
EnergyPlusMeasure.new.registerWithApplication