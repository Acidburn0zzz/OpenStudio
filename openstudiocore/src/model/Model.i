#ifndef MODEL_I
#define MODEL_I

#ifdef SWIGPYTHON
  %module openstudiomodel

  %pythoncode %{
    from openstudiomodelcore import *
    from openstudiomodelsimulation import *
    from openstudiomodelresources import *
    from openstudiomodelgeometry import *
    from openstudiomodelhvac import *
    from openstudiomodelrefrigeration import *
    from openstudiomodelgenerators import *
	from openstudiomodelairflow import *
  %}

#endif


%include <model/Model_Common_Include.i>

%import <model/ModelCore.i>
%import <model/ModelSimulation.i>
%import <model/ModelResources.i>
%import <model/ModelGeometry.i>
%import <model/ModelHVAC.i>
%import <model/ModelAirflow.i>
%import <model/ModelRefrigeration.i>
%import <model/ModelGenerators.i>
%import <model/ModelAirflow.i>

#endif //MODEL_I 
