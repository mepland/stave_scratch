
#include "stave_scratch_DetectorMessenger.hh"
#include "stave_scratch_DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "globals.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

stave_scratch_DetectorMessenger::stave_scratch_DetectorMessenger(stave_scratch_DetectorConstruction* myDet)
:myDetector(myDet)
{ 
  stave_scratch_Dir = new G4UIdirectory("/stave_scratch/");
  stave_scratch_Dir->SetGuidance("UI commands specific to this example.");

  detDir = new G4UIdirectory("/stave_scratch/det/");
  detDir->SetGuidance("detector control.");
  
  TargMatCmd = new G4UIcmdWithAString("/stave_scratch/det/setTargetMate",this);
  TargMatCmd->SetGuidance("Select Material of the Target.");
  TargMatCmd->SetParameterName("choice",false);
  TargMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

/*  
  ChamMatCmd = new G4UIcmdWithAString("/stave_scratch/det/setChamberMate",this);
  ChamMatCmd->SetGuidance("Select Material of the Target.");
  ChamMatCmd->SetParameterName("choice",false);
  ChamMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);  
  
  FieldCmd = new G4UIcmdWithADoubleAndUnit("/N02/det/setField",this);  
  FieldCmd->SetGuidance("Define magnetic field.");
  FieldCmd->SetGuidance("Magnetic field will be in X direction.");
  FieldCmd->SetParameterName("Bx",false);
  FieldCmd->SetUnitCategory("Magnetic flux density");
  FieldCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
*/
        
  StepMaxCmd = new G4UIcmdWithADoubleAndUnit("/stave_scratch/det/stepMax",this);  
  StepMaxCmd->SetGuidance("Define a step max");
  StepMaxCmd->SetParameterName("stepMax",false);
  StepMaxCmd->SetUnitCategory("Length");
  StepMaxCmd->AvailableForStates(G4State_Idle);    

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

stave_scratch_DetectorMessenger::~stave_scratch_DetectorMessenger()
{
  delete TargMatCmd;
//  delete ChamMatCmd;
//  delete FieldCmd;
  delete StepMaxCmd; 
  delete detDir;
  delete stave_scratch_Dir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void stave_scratch_DetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == TargMatCmd )
   { myDetector->setTargetMaterial(newValue);}
   
//  if( command == ChamMatCmd )
//   { myDetector->setChamberMaterial(newValue);}  
  
//  if( command == FieldCmd )
//   { myDetector->SetMagField(FieldCmd->GetNewDoubleValue(newValue));}
     
  if( command == StepMaxCmd )
   { myDetector->SetMaxStep(StepMaxCmd->GetNewDoubleValue(newValue));}   

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
