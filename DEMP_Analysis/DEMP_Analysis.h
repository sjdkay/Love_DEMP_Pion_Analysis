// Stephen JD Kay - University of York
// Stephen.Kay@york.ac.uk
// 28/03/25
// Header file for new DEMP Analysis script

// Input file naming, hardcoded assuming certain convention, change as needed
TString InFilePath = "/home/sjdkay/Work/ePIC_EIC/DEMP/Love_DEMP_Pion_Analysis/InputFiles";

string ConstructFileName(TString InBeamE, TString Inpart, TString In_Q2, TString InBeamConfig, TString InDate){
  string FileName = Form("%s/EICreconOut_%s_ip6_%s_q2_%s_%s_Combined_%s_Pruned.root", InFilePath.Data(), InBeamE.Data(), Inpart.Data(), In_Q2.Data(), InBeamConfig.Data(), InDate.Data());  
  return FileName;
}

Bool_t Good_eSc_Track, Good_Pi_Track, Good_nRec, nZDCHit, nB0Hit, DEMP_PassCuts;
Double_t ThetaStar_Max, n_Emin, ZDCDeltaTheta_Min, ZDCDeltaTheta_Max, ZDCDeltaPhi_Min, ZDCDeltaPhi_Max, B0DeltaTheta_Min, B0DeltaTheta_Max, B0DeltaPhi_Min, B0DeltaPhi_Max, MissingMass_Tol, W_Tol, B0_ECut, B0_XYTol;

//Defining the four vectors
PxPyPzEVector Vec_eSc_MC;
PxPyPzEVector Vec_eSc_MC_NoAB;
PxPyPzEVector Vec_Pi_MC;
PxPyPzEVector Vec_Pi_MC_NoAB;
PxPyPzEVector Vec_n_MC;
PxPyPzEVector Vec_n_MC_NoAB;
RotationY rot; // initialized rotation vector
rot.SetAngle(0.025);
PxPyPzEVector Vec_nRot_MC;
PxPyPzEVector Vec_nRot_MC_NoAB;

PxPyPzEVector Vec_e_beam; // initialized the 4 vector for electron beam */
PxPyPzEVector Vec_p_beam; // initialized the 4 vector for proton beam */
PxPyPzEVector Vec_e_beam_NoAB; // initialized the 4 vector for proton beam for nbf */
PxPyPzEVector Vec_p_beam_NoAB; // initialized the 4 vector for proton beam for nbf */

PxPyPzEVector Vec_eSc_Rec;
PxPyPzEVector Vec_Pi_Rec;
PxPyPzEVector Vec_n_Rec;
PxPyPzEVector Vec_nRot_Rec;
PxPyPzEVector Vec_n_RecCorr;
PxPyPzEVector Vec_PMiss_Rec;
PxPyPzEVector Vec_PMissRot_Rec;

XYZVector Vec_n_Vertex;

PxPyPzEVector Vec_Q_MC;
PxPyPzEVector Vec_Q_MC_NoAB;
PxPyPzEVector Vec_t_MC;
PxPyPzEVector Vec_t_MC_NoAB;
PxPyPzEVector Vec_Q_Rec;
PxPyPzEVector Vec_t_BABE;
PxPyPzEVector Vec_t_eX;
PxPyPzEVector Vec_t_eXPT;
PxPyPzEVector Vec_t_eXBABE;

int hcal_clus_size;
double neut_rec_p_hcal;
  
double neutMass = 0.93965420;
double eMass = 0.000510998950; //electron beam
double pMass = 0.93827208816; // proton beam
double PartE, NoABPartE; // Energy of the MC particles 
int eSc_Index, pi_Index, n_Index;

Double_t Q2_MC, t_MC, W_MC, y_MC, eps_MC;
Double_t Q2_MC_NoAB, t_MC_NoAB, W_MC_NoAB, y_MC_NoAB, eps_MC_NoAB;
Double_t Q2_Rec, W_Rec, y_Rec, eps_Rec, t_BABE, t_eX, t_eXPT, t_eXBABE; // Add other methods if needed
Double_t nTheta_Diff, nPhi_Diff, MMiss;
Double_t Q2Vals[8]={5, 7.5, 10, 15, 20, 25, 30, 35};

// Check files exist, can be opened and contain a relevant tree
Bool_t CheckFiles(TString Files[3]){
  Bool_t FileCheck = kTRUE;
  for (unsigned int i = 0;  i < 3; i++){
    if (gSystem->AccessPathName(Files[i]) == kTRUE){
      FileCheck = kFALSE;
      cout << "Input file - " << Files[i] << " not found." << endl;
      cout << "Check pathing and edit input arguments/DEMP_Analysis.h as needed!" << endl;
    }
    else{ // File exists, try to open it!
      TFile *tmpfile = TFile::Open(Files[i]);
      if (tmpfile && !tmpfile->IsZombie()) {
	TTree *tmptree = (TTree*)tmpfile->Get("events");
	// Ensure the file also contains a valid tree
	if (!tmptree) {
	  cout << "Tree 'events' not found in file: " << Files[i] << endl;
	  FileCheck = kFALSE;
	}
	tmpfile->Close();  // Close the file
	delete tmpfile;    // Delete the file pointer
      }
      else {
	cout << "Failed to open file: " << Files[i] <<endl;
	FileCheck = kFALSE;
	if (tmpfile) {
	  tmpfile->Close();  // Close the file if it was partially opened
	  delete tmpfile;    // Delete the file pointer
	}
      }
    }
  }
  return FileCheck;
}

void CalculateKinematicsMC(PxPyPzEVector eSc_MC, PxPyPzEVector pi_MC, PxPyPzEVector n_MC, PxPyPzEVector EBeam, PxPyPzEVector HBeam){
  Vec_Q_MC = (EBeam - eSc_MC); // Virtual photon beam vector
  Q2_MC = -1*(Vec_Q_MC.mag2());
  Vec_t_MC = (Vec_Q_MC - pi_MC);
  t_MC = -1*(Vec_t_MC.mag2());
  W_MC = (Vec_Q_MC + HBeam).mag();
  y_MC =(HBeam.Dot(Vec_Q_MC))/(HBeam.Dot(EBeam)); 
  eps_MC = (2*(1-y_MC))/(1+(pow(1-y_MC,2)));
}

void CalculateKinematicsMCNoAB(PxPyPzEVector eSc_MC, PxPyPzEVector pi_MC, PxPyPzEVector n_MC, PxPyPzEVector EBeam, PxPyPzEVector HBeam){
  Vec_Q_MC_NoAB = (EBeam - eSc_MC);
  Q2_MC_NoAB = -1*(Vec_Q_MC_NoAB.mag2());
  Vec_t_MC_NoAB = (Vec_Q_MC_NoAB - pi_MC);
  t_MC_NoAB = -1*(Vec_t_MC_NoAB.mag2());
  W_MC_NoAB = (Vec_Q_MC_NoAB + HBeam).mag();
  y_MC_NoAB =(HBeam.Dot(Vec_Q_MC_NoAB))/(HBeam.Dot(EBeam)); 
  eps_MC_NoAB = (2*(1-y_MC_NoAB))/(1+(pow(1-y_MC_NoAB,2)));
}

void CalculateBasicKinematics_DEMPRec(PxPyPzEVector eSc_Rec, PxPyPzEVector pi_Rec, PxPyPzEVector EBeam, PxPyPzEVector HBeam){
  Vec_Q_Rec = (EBeam - eSc_Rec);
  Q2_Rec = -1*(Vec_Q_Rec.mag2());
  W_Rec = (Vec_Q_Rec + HBeam).mag();
  y_Rec =(HBeam.Dot(Vec_Q_Rec))/(HBeam.Dot(EBeam));
  eps_Rec = (2*(1-y_Rec))/(1+(pow(1-y_Rec,2)));
}

void CorrectNeutronTrack(PxPyPzEVector eSc_Rec, PxPyPzEVector pi_Rec, PxPyPzEVector n_Rec, PxPyPzEVector EBeam, PxPyPzEVector HBeam){
  Vec_PMiss_Rec = (EBeam + HBeam) - (eSc_Rec + pi_Rec);
  Vec_PMissRot_Rec = rot*Vec_PMiss_Rec;
  Vec_n_RecCorr.SetPxPyPzE(Vec_PMiss_Rec.P()*sin(n_Rec.Theta())*cos(n_Rec.Phi()), Vec_PMiss_Rec.P()*sin(n_Rec.Theta())*sin(n_Rec.Phi()), Vec_PMiss_Rec.P()*cos(n_Rec.Theta()), sqrt(pow(Vec_PMiss_Rec.P(),2)+(pow(neutMass,2))));
}

void Calculate_t_DEMPRec(PxPyPzEVector eSc_Rec, PxPyPzEVector pi_Rec, PxPyPzEVector n_Rec, PxPyPzEVector n_RecCorr, PxPyPzEVector EBeam, PxPyPzEVector HBeam){
  Vec_t_BABE = (HBeam - n_Rec);
  Vec_t_eX = ((EBeam - eSc_Rec) - pi_Rec);
  Vec_t_eXPT = rot*(eSc_Rec + pi_Rec); // Rotate vetors prior to getting perpendicular component
  Vec_t_eXBABE = (HBeam - n_RecCorr);
  t_BABE = -1*(Vec_t_BABE.mag2());
  t_eX = -1*(Vec_t_eX.mag2());
  t_eXPT = Vec_t_eXPT.Perp2();
  t_eXBABE = -1*(Vec_t_eXBABE.mag2());
}

// Define set of cut values, check input and return appropriate cut values
void SetCutVals(Double_t Hadron_Beam_E){
  Double_t ExpectedVals[5]={41,100,130,250,275};
  
  // Check hadron beam input value, set to closest if not exactly equal. Forces sensible values
  if(Hadron_Beam_E != 41 | Hadron_Beam_E != 100 | Hadron_Beam_E != 130 | Hadron_Beam_E != 250 | Hadron_Beam_E != 275 ){
    Double_t tmpE = ExpectedVals[0];
    Double_t diff = abs(Hadron_Beam_E - tmpE);
    for(Int_t i = 0; i < 5; i++){
      Double_t tmp_diff = abs(Hadron_Beam_E-ExpectedVals[i]);
      if(tmp_diff < diff){
	tmpE = ExpectedVals[i];
	diff = tmp_diff;
      }
    }
    Hadron_Beam_E = tmpE;
  }

  ThetaStar_Max = 4.0;
  B0_ECut = 0.25;
  B0_XYTol = 50;
  
  if(Hadron_Beam_E == 41){
    n_Emin = 10;
    ZDCDeltaTheta_Min = -0.1;
    ZDCDeltaTheta_Max = 0.2;
    ZDCDeltaPhi_Min = -55;
    ZDCDeltaPhi_Max = 55;
    B0DeltaTheta_Min = -0.2;
    B0DeltaTheta_Max = 0.2;
    B0DeltaPhi_Min = -50;
    B0DeltaPhi_Max = 50;
    MissingMass_Tol= 0;
    W_Tol = 0;
  }
  else if(Hadron_Beam_E == 100){
    n_Emin =40;
    ZDCDeltaTheta_Min = -0.09;
    ZDCDeltaTheta_Max = 0.14;
    ZDCDeltaPhi_Min = -45;
    ZDCDeltaPhi_Max = 45;
    B0DeltaTheta_Min = -0.8;
    B0DeltaTheta_Max = 0.7;
    B0DeltaPhi_Min = -30;
    B0DeltaPhi_Max = 30;
    MissingMass_Tol=0 ;
    W_Tol = 0;
  }
  else if(Hadron_Beam_E == 130){
    n_Emin =40;
    ZDCDeltaTheta_Min = -0.09;
    ZDCDeltaTheta_Max = 0.14;
    ZDCDeltaPhi_Min = -45;
    ZDCDeltaPhi_Max = 45;
    B0DeltaTheta_Min = -0.8;
    B0DeltaTheta_Max = 0.7;
    B0DeltaPhi_Min = -30;
    B0DeltaPhi_Max = 30;
    MissingMass_Tol=0 ;
    W_Tol = 0;
  }
  else if(Hadron_Beam_E == 250){
    n_Emin = 120;
    ZDCDeltaTheta_Min = -0.07;
    ZDCDeltaTheta_Max = 0.17;
    ZDCDeltaPhi_Min = -80;
    ZDCDeltaPhi_Max = 80;
    B0DeltaTheta_Min = -0.07;
    B0DeltaTheta_Max = 0.17;
    B0DeltaPhi_Min = -80;
    B0DeltaPhi_Max = 80;
    MissingMass_Tol= 0;
    W_Tol = 0;
  }
  else if(Hadron_Beam_E == 275){
    n_Emin = 120;
    ZDCDeltaTheta_Min = -0.07;
    ZDCDeltaTheta_Max = 0.17;
    ZDCDeltaPhi_Min = -80;
    ZDCDeltaPhi_Max = 80;
    B0DeltaTheta_Min = -0.07;
    B0DeltaTheta_Max = 0.17;
    B0DeltaPhi_Min = -80;
    B0DeltaPhi_Max = 80;
    MissingMass_Tol= 0;
    W_Tol = 0;
  }
}

void SetDirectories(Bool_t EventDist, Bool_t Kin, Bool_t ZDC, Bool_t B0, Bool_t QA, Bool_t Results){
  if(EventDist == kTRUE){
    gDirectory->mkdir("EventDists");
    gDirectory->mkdir("EventDists/MC");
    gDirectory->mkdir("EventDists/Reco");
  }
  if(Kin == kTRUE){
    gDirectory->mkdir("KinematicDists");
    gDirectory->mkdir("KinematicDists/MC");
    gDirectory->mkdir("KinematicDists/Reco");
    if(ZDC == kTRUE){
      gDirectory->mkdir("KinematicDists/MC/ZDC");
      gDirectory->mkdir("KinematicDists/Reco/ZDC");
    }
    if(B0 == kTRUE){
      gDirectory->mkdir("KinematicDists/MC/B0");
      gDirectory->mkdir("KinematicDists/Reco/B0");
    }
  }
  if(ZDC == kTRUE){
    gDirectory->mkdir("ZDCDists");
    gDirectory->mkdir("ZDCDists/MC");
    gDirectory->mkdir("ZDCDists/Reco");
  }
  if(B0 == kTRUE){
    gDirectory->mkdir("B0Dists");
    gDirectory->mkdir("B0Dists/MC");
    gDirectory->mkdir("B0Dists/Reco");
  }
  if(QA == kTRUE){
    gDirectory->mkdir("QADists");
  }
  if(Results == kTRUE){
    gDirectory->mkdir("ResultsDists");
  }
}
