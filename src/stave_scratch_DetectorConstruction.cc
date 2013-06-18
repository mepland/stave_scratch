#include "stave_scratch_DetectorConstruction.hh"
#include "stave_scratch_DetectorMessenger.hh"
//#include "ExN02ChamberParameterisation.hh"
//#include "ExN02MagneticField.hh"
#include "stave_scratch_TargetSD.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4SDManager.hh"
#include "G4GeometryTolerance.hh"
#include "G4GeometryManager.hh"

#include "G4UserLimits.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
stave_scratch_DetectorConstruction::stave_scratch_DetectorConstruction()
:solidWorld(0), logicWorld(0), physiWorld(0),
 solidTarget(0), logicTarget(0), physiTarget(0), 
// solidTracker(0),logicTracker(0),physiTracker(0), 
// solidChamber(0),logicChamber(0),physiChamber(0), 
 TargetMater(0),
// ChamberMater(0), chamberParam(0),
 stepLimit(0),
//  fpMagField(0),
 fWorldLength(0.), fTargetLength(0.)
// , fTrackerLength(0.),NbOfChambers(0),ChamberWidth(0.), ChamberSpacing(0.)

{
//  fpMagField = new ExN02MagneticField();
  detectorMessenger = new stave_scratch_DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
stave_scratch_DetectorConstruction::~stave_scratch_DetectorConstruction()
{
//  delete fpMagField;
  delete stepLimit;
//  delete chamberParam;
  delete detectorMessenger;             
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
G4VPhysicalVolume* stave_scratch_DetectorConstruction::Construct()
{

//--------- Material definition ---------

  G4String name, symbol;    
  G4double a, z, density;
  G4int nel, ncomponents, natoms;

  // ------------------------------------------------
  // Define Elements 
  // ------------------------------------------------
        
  // Hydrogen
  G4Element* elementH = new G4Element("Hydrogen", "H", z=1., a=1.01*g/mole);
               
  // Carbon
  G4Element* elementC = new G4Element("Carbon", "C", z=6., a=12.011*g/mole);
                    
  // Nitrogen
  G4Element* elementN = new G4Element(name="Nitrogen", "N", z=7., a=14.00674*g/mole);	 
                          
  // Oxygen
  G4Element* elementO = new G4Element(name="Oxygen", "O", z=8., a=15.9994*g/mole);	
  
  // Silicon
  G4Element* elementSi = new G4Element("Silicon", "Si", z=14., a=28.09*g/mole);
                                    
  // Copper
  G4Element* elementCu = new G4Element("Copper", "Cu", z=29., a=63.5460*g/mole);
/*                                          
  // Lead
  G4Element* elementPb = new G4Element("Lead", "Pb", z=82., a=207.2*g/mole);
*/ 
                                              	
  //-------------------------------------------------
  // Define Materials
  // ------------------------------------------------
    //Air
  G4Material* Air = new G4Material("Air", density= 1.29*mg/cm3, nel=2);
  Air->AddElement(elementN, 70*perCent);
  Air->AddElement(elementO, 30*perCent);
                                       	              	
  // Silicon 
  G4Material* Silicon = new G4Material(name="Silicon", density = 2.330*g/cm3, ncomponents=1);
  Silicon->AddElement(elementSi, natoms=1);
                                               	              	        
  // Copper
  G4Material* Copper = new G4Material(name="Copper", density = 8.920*g/cm3, ncomponents=1);
  Copper->AddElement(elementCu, natoms=1);
  
  // Kapton
  G4Material* Kapton=new G4Material(name="Kapton", density=1.4243*g/cm3, ncomponents=4);
  Kapton->AddElement(elementO,natoms=5);
  Kapton->AddElement(elementC,natoms=22);
  Kapton->AddElement(elementN,natoms=2);
  Kapton->AddElement(elementH,natoms=10);
                                               	              	                             
  /*
  // Lead
  G4Material* Lead = new G4Material(name="Lead_brick", density=11.35*g/cm3, ncomponents=1);
  Lead->AddElement(elementPb,1);
  
  // Vacuum
  G4Material* Vacuum = new G4Material("Vacuum", z=1.0, a=1.01*g/mole, density=universe_mean_density, kStateGas, temperature=2.73*kelvin, pressure=1.0e-19*pascal);
  
  // Poly
  G4Material* Poly=new G4Material(name="Poly", density=0.935*g/cm3, ncomponents=2);
  Poly->AddElement(elementH,natoms=2);
  Poly->AddElement(elementC,natoms=1);
                                               	              	                                                    
  // Aluminum
  G4Material* Aluminum = new G4Material(name="Aluminum", density=2.7*g/cm3, ncomponents=1);
  Aluminum->AddElement(elementAl,1);  
                            	              	                                                               
  // Graphite
  G4Material* Graphite=new G4Material(name="Graphite", density=1.76*g/cm3, ncomponents=1);
  Graphite->AddElement(elementC,1);
  
  */

  // Print all the materials defined.
  //
  G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;

//--------- Sizes of the principal geometrical components (solids)  ---------
  
//  NbOfChambers = 5;
//  ChamberWidth = 10*cm; 
//  ChamberSpacing = 80*cm;
//  fTrackerLength = (NbOfChambers+1)*ChamberSpacing; // Full length of Tracker

  fWorldLength = 20*cm;			// Full length of world

  TargetMater  = Silicon;
//  ChamberMater = Air;

//  fTargetLength  = 10.0*cm;                    // Full length of Target
//  G4double targetSize  = 0.5*fTargetLength;    // Half length of the Target  
//  G4double trackerSize = 0.5*fTrackerLength;   // Half length of the Tracker
      
//--------- Definitions of Solids, Logical Volumes, Physical Volumes ---------
  
  //------------------------------ 
  // World
  //------------------------------ 

  G4double HalfWorldLength = 0.5*fWorldLength;
 
  G4GeometryManager::GetInstance()->SetWorldMaximumExtent(fWorldLength);
  G4cout << "Computed tolerance = "
         << G4GeometryTolerance::GetInstance()->GetSurfaceTolerance()/mm
         << " mm" << G4endl;

  solidWorld= new G4Box("world",HalfWorldLength,HalfWorldLength,HalfWorldLength);
  logicWorld= new G4LogicalVolume( solidWorld, Air, "World", 0, 0, 0);
 
  //  Must place the World Physical volume unrotated at (0,0,0).
  // 
  physiWorld = new G4PVPlacement(0,               // no rotation
                                 G4ThreeVector(), // at (0,0,0)
                                 logicWorld,      // its logical volume
				 "World",         // its name
                                 0,               // its mother  volume
                                 false,           // no boolean operations
                                 0);              // copy number
				 
  //------------------------------ 
  // Target
  //------------------------------
  
  G4ThreeVector positionTarget = G4ThreeVector(0, 0, 0);
// One module 10x10 cm square,   
  solidTarget = new G4Box("target",0.5*9.75*cm,0.5*9.75*cm,0.5*0.320*mm); // z is 0.5*0.320*cm pending better info. Use halflengths, formally targetSize
  logicTarget = new G4LogicalVolume(solidTarget,TargetMater,"Target",0,0,0);

  physiTarget = new G4PVPlacement(0,               // no rotation
				  positionTarget,  // at (x,y,z)
				  logicTarget,     // its logical volume				  
				  "Target",        // its name
				  logicWorld,      // its mother  volume
				  false,           // no boolean operations
				  0);              // copy number 

  G4cout << "Target is made of " << TargetMater->GetName() << G4endl;
/*
  //------------------------------ 
  // Tracker
  //------------------------------
  
  G4ThreeVector positionTracker = G4ThreeVector(0,0,0);
  
  solidTracker = new G4Box("tracker",trackerSize,trackerSize,trackerSize);
  logicTracker = new G4LogicalVolume(solidTracker , Air, "Tracker",0,0,0);  
  physiTracker = new G4PVPlacement(0,              // no rotation
				  positionTracker, // at (x,y,z)
				  logicTracker,    // its logical volume				  
				  "Tracker",       // its name
				  logicWorld,      // its mother  volume
				  false,           // no boolean operations
				  0);              // copy number 

  //------------------------------ 
  // Tracker segments
  //------------------------------
  // 
  // An example of Parameterised volumes
  // dummy values for G4Box -- modified by parameterised volume
*/

//  solidChamber = new G4Box("chamber", 100*cm, 100*cm, 10*cm); 
//  logicChamber = new G4LogicalVolume(solidChamber,ChamberMater,"Chamber",0,0,0);

/*  
  G4double firstPosition = -trackerSize + 0.5*ChamberWidth;
  G4double firstLength = fTrackerLength/10;
  G4double lastLength  = fTrackerLength;
   
  chamberParam = new ExN02ChamberParameterisation(  
			   NbOfChambers,          // NoChambers 
			   firstPosition,         // Z of center of first 
			   ChamberSpacing,        // Z spacing of centers
			   ChamberWidth,          // Width Chamber 
			   firstLength,           // lengthInitial 
			   lastLength);           // lengthFinal
			   
  // dummy value : kZAxis -- modified by parameterised volume
  //
  physiChamber = new G4PVParameterised(
                            "Chamber",       // their name
                            logicChamber,    // their logical volume
                            logicTracker,    // Mother logical volume
			    kZAxis,          // Are placed along this axis 
                            NbOfChambers,    // Number of chambers
                            chamberParam);   // The parametrisation

  G4cout << "There are " << NbOfChambers << " chambers in the tracker region. "
         << "The chambers are " << ChamberWidth/mm << " mm of " 
         << ChamberMater->GetName() << "\n The distance between chamber is "
	 << ChamberSpacing/cm << " cm" << G4endl;
*/
	 
  //------------------------------------------------ 
  // Sensitive detectors
  //------------------------------------------------ 

  G4SDManager* SDman = G4SDManager::GetSDMpointer();

  G4String targetSDname = "stave_scratch_TargetSD";
  stave_scratch_TargetSD* aTargetSD = new stave_scratch_TargetSD( targetSDname );
  SDman->AddNewDetector( aTargetSD );
  logicTarget->SetSensitiveDetector( aTargetSD );

//--------- Visualization attributes -------------------------------

  G4VisAttributes* WorldVisAtt= new G4VisAttributes(G4Colour(1.0,1.0,1.0));//White 
  G4VisAttributes* TargetVisAtt= new G4VisAttributes(G4Colour(0.0,1.0,0.0));//Green
//  G4VisAttributes* ChamberVisAtt =new G4VisAttributes(G4Colour(0.0,1.0,0.0));//Green

  logicWorld  ->SetVisAttributes(WorldVisAtt);  
  logicTarget ->SetVisAttributes(TargetVisAtt);
//  logicChamber->SetVisAttributes(ChamberVisAtt);
//logicTracker->SetVisAttributes(BoxVisAtt);
  
//--------- example of User Limits -------------------------------

  // below is an example of how to set tracking constraints in a given
  // logical volume(see also in N02PhysicsList how to setup the processes
  // G4StepLimiter or G4UserSpecialCuts).
    
  // Sets a max Step length in the tracker region, with G4StepLimiter
  //

  G4double maxStep = 0.025*mm; // For now...
  stepLimit = new G4UserLimits(maxStep);

//  logicTracker->SetUserLimits(stepLimit);
  
  // Set additional contraints on the track, with G4UserSpecialCuts
  //
  // G4double maxLength = 2*fTrackerLength, maxTime = 0.1*ns, minEkin = 10*MeV;
  // logicTracker->SetUserLimits(new G4UserLimits(maxStep,maxLength,maxTime,
  //                                               minEkin));
  
  return physiWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void stave_scratch_DetectorConstruction::setTargetMaterial(G4String materialName)
{
  // search the material by its name 
  G4Material* pttoMaterial = G4Material::GetMaterial(materialName);  
  if (pttoMaterial)
     {TargetMater = pttoMaterial;
      logicTarget->SetMaterial(pttoMaterial); 
      G4cout << "\n----> The target is " << fTargetLength/cm << " cm of "
             << materialName << G4endl;
     }             
}
 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/*
void stave_scratch_DetectorConstruction::setChamberMaterial(G4String materialName)
{
  // search the material by its name 
  G4Material* pttoMaterial = G4Material::GetMaterial(materialName);  
  if (pttoMaterial)
     {ChamberMater = pttoMaterial;
      logicChamber->SetMaterial(pttoMaterial); 
      G4cout << "\n----> The chambers are " << ChamberWidth/cm << " cm of "
             << materialName << G4endl;
     }             
}
 
*/

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/* 
void stave_scratch_DetectorConstruction::SetMagField(G4double fieldValue)
{
  fpMagField->SetMagFieldValue(fieldValue);  
}
*/
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void stave_scratch_DetectorConstruction::SetMaxStep(G4double maxStep)
{
  if ((stepLimit)&&(maxStep>0.)) stepLimit->SetMaxAllowedStep(maxStep);
}

// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
