
#ifndef stave_scratch_DetectorMessenger_h
#define stave_scratch_DetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class stave_scratch_DetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class stave_scratch_DetectorMessenger: public G4UImessenger
{
  public:
    stave_scratch_DetectorMessenger(stave_scratch_DetectorConstruction*);
   ~stave_scratch_DetectorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    stave_scratch_DetectorConstruction* myDetector;
    
    G4UIdirectory*             stave_scratch_Dir;
    G4UIdirectory*             detDir;
    G4UIcmdWithAString*        TargMatCmd;
//    G4UIcmdWithAString*        ChamMatCmd;    
//    G4UIcmdWithADoubleAndUnit* FieldCmd;
    G4UIcmdWithADoubleAndUnit* StepMaxCmd;    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

