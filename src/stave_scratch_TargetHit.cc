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
  chamberNb = right.chamberNb; // TODO Chamber
  edep      = right.edep;
  pos       = right.pos;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const stave_scratch_TargetHit& stave_scratch_TargetHit::operator=(const stave_scratch_TargetHit& right)
{
  trackID   = right.trackID;
  chamberNb = right.chamberNb; //TODO Chamber
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
  G4cout << "  trackID: " << trackID << "  chamberNb: " << chamberNb //TODO Chamber
         << "  energy deposit: " << G4BestUnit(edep,"Energy")
	 << "  position: " << G4BestUnit(pos,"Length") << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

