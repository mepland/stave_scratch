#include "stave_scratch_TargetHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

G4Allocator<stave_scratch_TargetHit> stave_scratch_TargetHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

stave_scratch_TargetHit::stave_scratch_TargetHit() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

stave_scratch_TargetHit::~stave_scratch_TargetHit() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

stave_scratch_TargetHit::stave_scratch_TargetHit(const stave_scratch_TargetHit& right)
  : G4VHit()
{
  trackID   = right.trackID;
//  chamberNb = right.chamberNb;
  edep      = right.edep;
  pos       = right.pos;
// TODO New variables to unbind the G4Threevector pos so it can be written to root file, also to convert from G4 to regular variables
  trackID_reg = trackID;
  edep_reg = edep;
  pos_x_reg = pos.x();
  pos_y_reg = pos.y();
  pos_z_reg = pos.z();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const stave_scratch_TargetHit& stave_scratch_TargetHit::operator=(const stave_scratch_TargetHit& right)
{
  trackID   = right.trackID;
//  chamberNb = right.chamberNb;
  edep      = right.edep;
  pos       = right.pos;
  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4int stave_scratch_TargetHit::operator==(const stave_scratch_TargetHit& right) const
{
  return (this==&right) ? 1 : 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void stave_scratch_TargetHit::Draw()
{
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if(pVVisManager)
  {
    G4Circle circle(pos);
    circle.SetScreenSize(2.);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,0.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void stave_scratch_TargetHit::Print()
{
  G4cout << "  trackID: " << trackID 
      // << "  chamberNb: " << chamberNb //Chamber
         << "  energy deposit: " << G4BestUnit(edep,"Energy")
	 << "  position: " << G4BestUnit(pos,"Length") << G4endl;
}

// TODO New function to open root file, probably will not work as it may close the file when the program leaves this scope
void stave_scratch_TargetHit::Rootopen()
{
/*
TFile f("run_output.root", "recreate");
TTree t1("t1", "Geant4 Event Output");

t1.Branch("trackID", &trackID_reg, "trackID/I");
t1.Branch("edep", &edep_reg, "edep/D");// TODO How to handle units!!
t1.Branch("pos_x", &pos_x_reg, "pos_x_reg/D"); 
t1.Branch("pos_y", &pos_y_reg, "pos_y_reg/D"); 
t1.Branch("pos_z", &pos_z_reg, "pos_z_reg/D"); 
*/
}

// New function to close root file
void stave_scratch_TargetHit::Rootclose()
{
//t1.Write();
}

// New function to output the data in Print() to a root file
void stave_scratch_TargetHit::Rootout()
{
//t1.Fill();
}
