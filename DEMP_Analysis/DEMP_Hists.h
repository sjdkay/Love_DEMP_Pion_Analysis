// Stephen JD Kay - University of York
// Stephen.Kay@york.ac.uk
// 28/03/25
// Header file for new DEMP Analysis script, this contains histogram definitions and filling functions

void DefHists(TString InBeamE, Bool_t EventDists, Bool_t Kinematics, Bool_t ZDC, Bool_t B0, Bool_t Tracking, Bool_t QA, Bool_t Results){

  // Fix number of energy, theta and phi bins in subsequent plots
  Int_t NBins_Energy = 200;
  Int_t NBins_Theta = 200;
  Int_t NBins_Phi = 200;

  Double_t ElecBeamE = ((TObjString *)((InBeamE.Tokenize("on"))->At(0)))->String().Atof();
  Double_t HadBeamE = ((TObjString *)((InBeamE.Tokenize("on"))->At(1)))->String().Atof();

  if (EventDists == kTRUE){
    TH2D* h2_eSc_pTheta_MC_NoAB = new TH2D("h2_eSc_pTheta_MC_NoAB", "e' MC Truth, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCMatched_NoAB = new TH2D("h2_eSc_pTheta_MCMatched_NoAB", "e' MC Truth (matched track), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCAccept_NoAB = new TH2D("h2_eSc_pTheta_MCAccept_NoAB", "e' MC Truth Accepted, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCDEMPAccept_NoCuts_NoAB = new TH2D("h2_eSc_pTheta_MCDEMPAccept_NoCuts_NoAB", "e' MC Truth DEMP Accepted, No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCDEMPAccept_NoAB = new TH2D("h2_eSc_pTheta_MCDEMPAccept_NoAB", "e' MC Truth DEMP Accepted, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MC = new TH2D("h2_eSc_pTheta_MC", "e' MC Truth; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCMatched = new TH2D("h2_eSc_pTheta_MCMatched", "e' MC Truth (matched track); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCAccept = new TH2D("h2_eSc_pTheta_MCAccept", "e' MC Truth Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCDEMPAccept_NoCuts = new TH2D("h2_eSc_pTheta_MCDEMPAccept_NoCuts", "e' MC Truth DEMP Accepted, No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_MCDEMPAccept = new TH2D("h2_eSc_pTheta_MCDEMPAccept", "e' MC Truth DEMP Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_Reco = new TH2D("h2_eSc_pTheta_Reco", "e' Reconstructed ; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_RecoAccept = new TH2D("h2_eSc_pTheta_RecoAccept", "e' Reconstructed Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_RecoDEMPAccept_NoCuts = new TH2D("h2_eSc_pTheta_RecoDEMPAccept_NoCuts", "e' Reconstructed DEMP Accepted, No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_eSc_pTheta_RecoDEMPAccept = new TH2D("h2_eSc_pTheta_RecoDEMPAccept", "e' Reconstructed DEMP Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
  
    TH2D* h2_Pi_pTheta_MC_NoAB = new TH2D("h2_Pi_pTheta_MC_NoAB", "#pi MC Truth, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCMatched_NoAB = new TH2D("h2_Pi_pTheta_MCMatched_NoAB", "#pi MC Truth (matched track), No Beam Effets; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCAccept_NoAB = new TH2D("h2_Pi_pTheta_MCAccept_NoAB", "#pi MC Truth Accepted, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCDEMPAccept_NoCuts_NoAB = new TH2D("h2_Pi_pTheta_MCDEMPAccept_NoCuts_NoAB", "#pi MC Truth DEMP Accepted, NoCuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCDEMPAccept_NoAB = new TH2D("h2_Pi_pTheta_MCDEMPAccept_NoAB", "#pi MC Truth DEMP Accepted, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MC = new TH2D("h2_Pi_pTheta_MC", "#pi MC Truth; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCMatched = new TH2D("h2_Pi_pTheta_MCMatched", "#pi MC Truth (matched track); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCAccept = new TH2D("h2_Pi_pTheta_MCAccept", "#pi MC Truth Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCDEMPAccept_NoCuts = new TH2D("h2_Pi_pTheta_MCDEMPAccept_NoCuts", "#pi MC Truth DEMP Accepted, No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_MCDEMPAccept = new TH2D("h2_Pi_pTheta_MCDEMPAccept", "#pi MC Truth DEMP Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_Reco = new TH2D("h2_Pi_pTheta_Reco", "#pi Reconstructed; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_RecoAccept = new TH2D("h2_Pi_pTheta_RecoAccept", "#pi Reconstructed Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_RecoDEMPAccept_NoCuts = new TH2D("h2_Pi_pTheta_RecoDEMPAccept_NoCuts", "#pi Reconstructed DEMP Accepted, No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_Pi_pTheta_RecoDEMPAccept = new TH2D("h2_Pi_pTheta_RecoDEMPAccept", "#pi Reconstructed DEMP Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);

    // Hard coding the +50 here is a bit odd, should maybe re-define this in terms of bin widths
    TH2D* h2_n_pTheta_MC_NoAB = new TH2D("h2_n_pTheta_MC_NoAB", "Neutron MC Truth, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCAccept_NoAB = new TH2D("h2_n_pTheta_MCAccept_NoAB", "Neutron MC Truth Accepted, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCDEMPAccept_NoCuts_NoAB = new TH2D("h2_n_pTheta_MCDEMPAccept_NoCuts_NoAB", "Neutron MC Truth DEMP Accepted, No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCDEMPAccept_NoAB = new TH2D("h2_n_pTheta_MCDEMPAccept_NoAB", "Neutron MC Truth DEMP Accepted, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MC = new TH2D("h2_n_pTheta_MC", "Neutron MC Truth; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCAccept = new TH2D("h2_n_pTheta_MCAccept", "Neutron MC Truth Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCDEMPAccept_NoCuts = new TH2D("h2_n_pTheta_MCDEMPAccept_NoCuts", "Neutron MC Truth DEMP Accepted, No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCDEMPAccept = new TH2D("h2_n_pTheta_MCDEMPAccept", "Neutron MC Truth DEMP Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_Reco = new TH2D("h2_n_pTheta_Reco", "Neutron Reconstructed ; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_RecoAccept = new TH2D("h2_n_pTheta_RecoAccept", "Neutron Reconstructed Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_nRot_pTheta_Reco = new TH2D("h2_nRot_pTheta_Reco", "Neutron Reconstructed (Rotated 25 mrad); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_nRot_pTheta_RecoAccept = new TH2D("h2_nRot_pTheta_RecoAccept", "Neutron Reconstructed (Rotated 25 mrad) Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_RecoDEMPAccept_NoCuts = new TH2D("h2_n_pTheta_RecoDEMPAccept_NoCuts", "Neutron Reconstructed DEMP Accepted, No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_nRot_pTheta_RecoDEMPAccept_NoCuts = new TH2D("h2_nRot_pTheta_RecoDEMPAccept_NoCuts", "Neutron Reconstructed (Rotated 25 mrad) DEMP Accepted, No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_RecoDEMPAccept = new TH2D("h2_n_pTheta_RecoDEMPAccept", "Neutron Reconstructed DEMP Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_nRot_pTheta_RecoDEMPAccept = new TH2D("h2_nRot_pTheta_RecoDEMPAccept", "Neutron Reconstructed (Rotated 25 mrad) DEMP Accepted; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
  }
  
  if (Kinematics == kTRUE){
    TH1D* h1_Q2_MC = new TH1D("h1_Q2_MC", "Q^{2} MC Truth; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
    TH1D* h1_t_MC = new TH1D("h1_t_MC", "-t MC Truth; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
    TH1D* h1_W_MC = new TH1D("h1_W_MC", "W MC Truth; W (GeV); Rate/bin (Hz)", 150, -50, 100);
    TH1D* h1_eps_MC = new TH1D("h1_eps_MC", "#epsilon MC Truth; #epsilon; Rate/bin (Hz)", 100, 0, 1);
    TH1D* h1_y_MC = new TH1D("h1_y_MC", "y MC Truth; y; Rate/bin (Hz)", 120, -0.2, 1);
    TH2D* h2_tQ2_MC = new TH2D("h2_tQ2_MC", "-t vs Q^{2} MC Truth; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
    TH2D* h2_WQ2_MC = new TH2D("h2_WQ2_MC", "W vs Q^{2} MC Truth; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

    TH1D* h1_Q2_MC_NoAB = new TH1D("h1_Q2_MC_NoAB", "Q^{2} MC Truth, No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
    TH1D* h1_t_MC_NoAB = new TH1D("h1_t_MC_NoAB", "-t MC Truth, No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
    TH1D* h1_W_MC_NoAB = new TH1D("h1_W_MC_NoAB", "W MC Truth, No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
    TH1D* h1_eps_MC_NoAB = new TH1D("h1_eps_MC_NoAB", "#epsilon MC Truth, No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
    TH1D* h1_y_MC_NoAB = new TH1D("h1_y_MC_NoAB", "y MC Truth, No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
    TH2D* h2_tQ2_MC_NoAB = new TH2D("h2_tQ2_MC_NoAB", "-t vs Q^{2} MC Truth, No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
    TH2D* h2_WQ2_MC_NoAB = new TH2D("h2_WQ2_MC_NoAB", "W vs Q^{2} MC Truth, No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

    TH1D* h1_Q2_MCDEMPAccept_NoCuts = new TH1D("h1_Q2_MCDEMPAccept_NoCuts", "Q^{2} MC Truth DEMP Accepted, No Cuts; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
    TH1D* h1_t_MCDEMPAccept_NoCuts = new TH1D("h1_t_MCDEMPAccept_NoCuts", "-t MC Truth DEMP Accepted, Q^{2} Cut Only; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
    TH1D* h1_W_MCDEMPAccept_NoCuts = new TH1D("h1_W_MCDEMPAccept_NoCuts", "W MC Truth DEMP Accepted, No Cuts; W (GeV); Rate/bin (Hz)", 150, -50, 100);
    TH1D* h1_eps_MCDEMPAccept_NoCuts = new TH1D("h1_eps_MCDEMPAccept_NoCuts", "#epsilon MC Truth DEMP Accepted, No Cuts; #epsilon; Rate/bin (Hz)", 100, 0, 1);
    TH1D* h1_y_MCDEMPAccept_NoCuts = new TH1D("h1_y_MCDEMPAccept_NoCuts", "y MC Truth DEMP Accepted, No Cuts; y; Rate/bin (Hz)", 120, -0.2, 1);
    TH2D* h2_tQ2_MCDEMPAccept_NoCuts = new TH2D("h2_tQ2_MCDEMPAccept_NoCuts", "-t vs Q^{2} MC Truth DEMP Accepted, Q^{2} Cut Only; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
    TH2D* h2_WQ2_MCDEMPAccept_NoCuts = new TH2D("h2_WQ2_MCDEMPAccept_NoCuts", "W vs Q^{2} MC Truth DEMP Accepted, No Cuts; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

    TH1D* h1_Q2_MCDEMPAccept_NoCuts_NoAB = new TH1D("h1_Q2_MCDEMPAccept_NoCuts_NoAB", "Q^{2} MC Truth DEMP Accepted, No Cuts, No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
    TH1D* h1_t_MCDEMPAccept_NoCuts_NoAB = new TH1D("h1_t_MCDEMPAccept_NoCuts_NoAB", "-t MC Truth DEMP Accepted, Q^{2} Cut Only, No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
    TH1D* h1_W_MCDEMPAccept_NoCuts_NoAB = new TH1D("h1_W_MCDEMPAccept_NoCuts_NoAB", "W MC Truth DEMP Accepted, No Cuts, No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
    TH1D* h1_eps_MCDEMPAccept_NoCuts_NoAB = new TH1D("h1_eps_MCDEMPAccept_NoCuts_NoAB", "#epsilon MC Truth DEMP Accepted, No Cuts, No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
    TH1D* h1_y_MCDEMPAccept_NoCuts_NoAB = new TH1D("h1_y_MCDEMPAccept_NoCuts_NoAB", "y MC Truth DEMP Accepted, No Cuts, No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
    TH2D* h2_tQ2_MCDEMPAccept_NoCuts_NoAB = new TH2D("h2_tQ2_MCDEMPAccept_NoCuts_NoAB", "-t vs Q^{2} MC Truth DEMP Accepted, Q^{2} Cut Only, No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
    TH2D* h2_WQ2_MCDEMPAccept_NoCuts_NoAB = new TH2D("h2_WQ2_MCDEMPAccept_NoCuts_NoAB", "W vs Q^{2} MC Truth DEMP Accepted, No Cuts, No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

    TH1D* h1_Q2_MCDEMPAccept = new TH1D("h1_Q2_MCDEMPAccept", "Q^{2} MC Truth DEMP Accepted; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
    TH1D* h1_t_MCDEMPAccept = new TH1D("h1_t_MCDEMPAccept", "-t MC Truth DEMP Accepted; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
    TH1D* h1_W_MCDEMPAccept = new TH1D("h1_W_MCDEMPAccept", "W MC Truth DEMP Accepted; W (GeV); Rate/bin (Hz)", 150, -50, 100);
    TH1D* h1_eps_MCDEMPAccept = new TH1D("h1_eps_MCDEMPAccept", "#epsilon MC Truth DEMP Accepted; #epsilon; Rate/bin (Hz)", 100, 0, 1);
    TH1D* h1_y_MCDEMPAccept = new TH1D("h1_y_MCDEMPAccept", "y MC Truth DEMP Accepted; y; Rate/bin (Hz)", 120, -0.2, 1);
    TH2D* h2_tQ2_MCDEMPAccept = new TH2D("h2_tQ2_MCDEMPAccept", "-t vs Q^{2} MC Truth DEMP Accepted; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
    TH2D* h2_WQ2_MCDEMPAccept = new TH2D("h2_WQ2_MCDEMPAccept", "W vs Q^{2} MC Truth DEMP Accepted; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

    TH1D* h1_Q2_MCDEMPAccept_NoAB = new TH1D("h1_Q2_MCDEMPAccept_NoAB", "Q^{2} MC Truth DEMP Accepted, No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
    TH1D* h1_t_MCDEMPAccept_NoAB = new TH1D("h1_t_MCDEMPAccept_NoAB", "-t MC Truth DEMP Accepted, No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
    TH1D* h1_W_MCDEMPAccept_NoAB = new TH1D("h1_W_MCDEMPAccept_NoAB", "W MC Truth DEMP Accepted, No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
    TH1D* h1_eps_MCDEMPAccept_NoAB = new TH1D("h1_eps_MCDEMPAccept_NoAB", "#epsilon MC Truth DEMP Accepted, No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
    TH1D* h1_y_MCDEMPAccept_NoAB = new TH1D("h1_y_MCDEMPAccept_NoAB", "y MC Truth DEMP Accepted, No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
    TH2D* h2_tQ2_MCDEMPAccept_NoAB = new TH2D("h2_tQ2_MCDEMPAccept_NoAB", "-t vs Q^{2} MC Truth DEMP Accepted, No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
    TH2D* h2_WQ2_MCDEMPAccept_NoAB = new TH2D("h2_WQ2_MCDEMPAccept_NoAB", "W vs Q^{2} MC Truth DEMP Accepted, No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);
    
    if (B0 == kTRUE){
      TH1D* h1_Q2_MCAcceptB0 = new TH1D("h1_Q2_MCAcceptB0", "Q^{2} MC Truth Accepted (B0 events only); Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCAcceptB0 = new TH1D("h1_t_MCAcceptB0", "-t MC Truth Accepted (B0 events only); -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCAcceptB0 = new TH1D("h1_W_MCAcceptB0", "W MC Truth Accepted (B0 events only); W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCAcceptB0 = new TH1D("h1_eps_MCAcceptB0", "#epsilon MC Truth Accepted (B0 events only); #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCAcceptB0 = new TH1D("h1_y_MCAcceptB0", "y MC Truth Accepted (B0 events only); y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCAcceptB0 = new TH2D("h2_tQ2_MCAcceptB0", "-t vs Q^{2} MC Truth Accepted (B0 events only); -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCAcceptB0 = new TH2D("h2_WQ2_MCAcceptB0", "W vs Q^{2} MC Truth Accepted (B0 events only); W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCAcceptB0_NoAB = new TH1D("h1_Q2_MCAcceptB0_NoAB", "Q^{2} MC Truth Accepted (B0 events only), No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCAcceptB0_NoAB = new TH1D("h1_t_MCAcceptB0_NoAB", "-t MC Truth Accepted (B0 events only), No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCAcceptB0_NoAB = new TH1D("h1_W_MCAcceptB0_NoAB", "W MC Truth Accepted (B0 events only), No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCAcceptB0_NoAB = new TH1D("h1_eps_MCAcceptB0_NoAB", "#epsilon MC Truth Accepted (B0 events only), No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCAcceptB0_NoAB = new TH1D("h1_y_MCAcceptB0_NoAB", "y MC Truth Accepted (B0 events only), No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCAcceptB0_NoAB = new TH2D("h2_tQ2_MCAcceptB0_NoAB", "-t vs Q^{2} MC Truth Accepted (B0 events only), No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCAcceptB0_NoAB = new TH2D("h2_WQ2_MCAcceptB0_NoAB", "W vs Q^{2} MC Truth Accepted (B0 events only), No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCDEMPAcceptB0_NoCuts = new TH1D("h1_Q2_MCDEMPAcceptB0_NoCuts", "Q^{2} MC Truth DEMP Accepted (B0 Events only), No Cuts; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptB0_NoCuts = new TH1D("h1_t_MCDEMPAcceptB0_NoCuts", "-t MC Truth DEMP Accepted (B0 Events only), Q^{2} Cut Only; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptB0_NoCuts = new TH1D("h1_W_MCDEMPAcceptB0_NoCuts", "W MC Truth DEMP Accepted (B0 Events only), No Cuts; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptB0_NoCuts = new TH1D("h1_eps_MCDEMPAcceptB0_NoCuts", "#epsilon MC Truth DEMP Accepted (B0 Events only), No Cuts; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptB0_NoCuts = new TH1D("h1_y_MCDEMPAcceptB0_NoCuts", "y MC Truth DEMP Accepted (B0 Events only), No Cuts; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptB0_NoCuts = new TH2D("h2_tQ2_MCDEMPAcceptB0_NoCuts", "-t vs Q^{2} MC Truth DEMP Accepted (B0 Events only), Q^{2} Cut Only; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptB0_NoCuts = new TH2D("h2_WQ2_MCDEMPAcceptB0_NoCuts", "W vs Q^{2} MC Truth DEMP Accepted (B0 Events only), No Cuts; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCDEMPAcceptB0_NoCuts_NoAB = new TH1D("h1_Q2_MCDEMPAcceptB0_NoCuts_NoAB", "Q^{2} MC Truth DEMP Accepted (B0 Events only), No Cuts, No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptB0_NoCuts_NoAB = new TH1D("h1_t_MCDEMPAcceptB0_NoCuts_NoAB", "-t MC Truth DEMP Accepted (B0 Events only), Q^{2} Cut Only, No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptB0_NoCuts_NoAB = new TH1D("h1_W_MCDEMPAcceptB0_NoCuts_NoAB", "W MC Truth DEMP Accepted (B0 Events only), No Cuts, No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptB0_NoCuts_NoAB = new TH1D("h1_eps_MCDEMPAcceptB0_NoCuts_NoAB", "#epsilon MC Truth DEMP Accepted (B0 Events only), No Cuts, No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptB0_NoCuts_NoAB = new TH1D("h1_y_MCDEMPAcceptB0_NoCuts_NoAB", "y MC Truth DEMP Accepted (B0 Events only), No Cuts, No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptB0_NoCuts_NoAB = new TH2D("h2_tQ2_MCDEMPAcceptB0_NoCuts_NoAB", "-t vs Q^{2} MC Truth DEMP Accepted (B0 Events only), Q^{2} Cut Only, No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptB0_NoCuts_NoAB = new TH2D("h2_WQ2_MCDEMPAcceptB0_NoCuts_NoAB", "W vs Q^{2} MC Truth DEMP Accepted (B0 Events only), No Cuts, No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);
      
      TH1D* h1_Q2_MCDEMPAcceptB0 = new TH1D("h1_Q2_MCDEMPAcceptB0", "Q^{2} MC Truth DEMP Accepted (B0 events only); Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptB0 = new TH1D("h1_t_MCDEMPAcceptB0", "-t MC Truth DEMP Accepted (B0 events only); -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptB0 = new TH1D("h1_W_MCDEMPAcceptB0", "W MC Truth DEMP Accepted (B0 events only); W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptB0 = new TH1D("h1_eps_MCDEMPAcceptB0", "#epsilon MC Truth DEMP Accepted (B0 events only); #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptB0 = new TH1D("h1_y_MCDEMPAcceptB0", "y MC Truth DEMP Accepted (B0 events only); y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptB0 = new TH2D("h2_tQ2_MCDEMPAcceptB0", "-t vs Q^{2} MC Truth DEMP Accepted (B0 events only); -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptB0 = new TH2D("h2_WQ2_MCDEMPAcceptB0", "W vs Q^{2} MC Truth DEMP Accepted (B0 events only); W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCDEMPAcceptB0_NoAB = new TH1D("h1_Q2_MCDEMPAcceptB0_NoAB", "Q^{2} MC Truth DEMP Accepted (B0 events only), No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptB0_NoAB = new TH1D("h1_t_MCDEMPAcceptB0_NoAB", "-t MC Truth DEMP Accepted (B0 events only), No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptB0_NoAB = new TH1D("h1_W_MCDEMPAcceptB0_NoAB", "W MC Truth DEMP Accepted (B0 events only), No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptB0_NoAB = new TH1D("h1_eps_MCDEMPAcceptB0_NoAB", "#epsilon MC Truth DEMP Accepted (B0 events only), No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptB0_NoAB = new TH1D("h1_y_MCDEMPAcceptB0_NoAB", "y MC Truth DEMP Accepted (B0 events only), No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptB0_NoAB = new TH2D("h2_tQ2_MCDEMPAcceptB0_NoAB", "-t vs Q^{2} MC Truth DEMP Accepted (B0 events only), No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptB0_NoAB = new TH2D("h2_WQ2_MCDEMPAcceptB0_NoAB", "W vs Q^{2} MC Truth DEMP Accepted (B0 events only), No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);
    }
    
    if (ZDC == kTRUE){
      TH1D* h1_Q2_MCAcceptZDC = new TH1D("h1_Q2_MCAcceptZDC", "Q^{2} MC Truth Accepted (ZDC events only); Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCAcceptZDC = new TH1D("h1_t_MCAcceptZDC", "-t MC Truth Accepted (ZDC events only); -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCAcceptZDC = new TH1D("h1_W_MCAcceptZDC", "W MC Truth Accepted (ZDC events only); W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCAcceptZDC = new TH1D("h1_eps_MCAcceptZDC", "#epsilon MC Truth Accepted (ZDC events only); #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCAcceptZDC = new TH1D("h1_y_MCAcceptZDC", "y MC Truth Accepted (ZDC events only); y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCAcceptZDC = new TH2D("h2_tQ2_MCAcceptZDC", "-t vs Q^{2} MC Truth Accepted (ZDC events only); -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCAcceptZDC = new TH2D("h2_WQ2_MCAcceptZDC", "W vs Q^{2} MC Truth Accepted (ZDC events only); W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCAcceptZDC_NoAB = new TH1D("h1_Q2_MCAcceptZDC_NoAB", "Q^{2} MC Truth Accepted (ZDC events only), No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCAcceptZDC_NoAB = new TH1D("h1_t_MCAcceptZDC_NoAB", "-t MC Truth Accepted (ZDC events only), No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCAcceptZDC_NoAB = new TH1D("h1_W_MCAcceptZDC_NoAB", "W MC Truth Accepted (ZDC events only), No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCAcceptZDC_NoAB = new TH1D("h1_eps_MCAcceptZDC_NoAB", "#epsilon MC Truth Accepted (ZDC events only), No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCAcceptZDC_NoAB = new TH1D("h1_y_MCAcceptZDC_NoAB", "y MC Truth Accepted (ZDC events only), No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCAcceptZDC_NoAB = new TH2D("h2_tQ2_MCAcceptZDC_NoAB", "-t vs Q^{2} MC Truth Accepted (ZDC events only), No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCAcceptZDC_NoAB = new TH2D("h2_WQ2_MCAcceptZDC_NoAB", "W vs Q^{2} MC Truth Accepted (ZDC events only), No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCDEMPAcceptZDC_NoCuts = new TH1D("h1_Q2_MCDEMPAcceptZDC_NoCuts", "Q^{2} MC Truth DEMP Accepted (ZDC Events only), No Cuts; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptZDC_NoCuts = new TH1D("h1_t_MCDEMPAcceptZDC_NoCuts", "-t MC Truth DEMP Accepted (ZDC Events only), Q^{2} Cut Only; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptZDC_NoCuts = new TH1D("h1_W_MCDEMPAcceptZDC_NoCuts", "W MC Truth DEMP Accepted (ZDC Events only), No Cuts; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptZDC_NoCuts = new TH1D("h1_eps_MCDEMPAcceptZDC_NoCuts", "#epsilon MC Truth DEMP Accepted (ZDC Events only), No Cuts; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptZDC_NoCuts = new TH1D("h1_y_MCDEMPAcceptZDC_NoCuts", "y MC Truth DEMP Accepted (ZDC Events only), No Cuts; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptZDC_NoCuts = new TH2D("h2_tQ2_MCDEMPAcceptZDC_NoCuts", "-t vs Q^{2} MC Truth DEMP Accepted (ZDC Events only), Q^{2} Cut Only; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptZDC_NoCuts = new TH2D("h2_WQ2_MCDEMPAcceptZDC_NoCuts", "W vs Q^{2} MC Truth DEMP Accepted (ZDC Events only), No Cuts; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCDEMPAcceptZDC_NoCuts_NoAB = new TH1D("h1_Q2_MCDEMPAcceptZDC_NoCuts_NoAB", "Q^{2} MC Truth DEMP Accepted (ZDC Events only), No Cuts, No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptZDC_NoCuts_NoAB = new TH1D("h1_t_MCDEMPAcceptZDC_NoCuts_NoAB", "-t MC Truth DEMP Accepted (ZDC Events only), Q^{2} Cut Only, No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptZDC_NoCuts_NoAB = new TH1D("h1_W_MCDEMPAcceptZDC_NoCuts_NoAB", "W MC Truth DEMP Accepted (ZDC Events only), No Cuts, No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptZDC_NoCuts_NoAB = new TH1D("h1_eps_MCDEMPAcceptZDC_NoCuts_NoAB", "#epsilon MC Truth DEMP Accepted (ZDC Events only), No Cuts, No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptZDC_NoCuts_NoAB = new TH1D("h1_y_MCDEMPAcceptZDC_NoCuts_NoAB", "y MC Truth DEMP Accepted (ZDC Events only), No Cuts, No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptZDC_NoCuts_NoAB = new TH2D("h2_tQ2_MCDEMPAcceptZDC_NoCuts_NoAB", "-t vs Q^{2} MC Truth DEMP Accepted (ZDC Events only), Q^{2} Cut Only, No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptZDC_NoCuts_NoAB = new TH2D("h2_WQ2_MCDEMPAcceptZDC_NoCuts_NoAB", "W vs Q^{2} MC Truth DEMP Accepted (ZDC Events only), No Cuts, No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);
      
      TH1D* h1_Q2_MCDEMPAcceptZDC = new TH1D("h1_Q2_MCDEMPAcceptZDC", "Q^{2} MC Truth DEMP Accepted (ZDC events only); Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptZDC = new TH1D("h1_t_MCDEMPAcceptZDC", "-t MC Truth DEMP Accepted (ZDC events only); -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptZDC = new TH1D("h1_W_MCDEMPAcceptZDC", "W MC Truth DEMP Accepted (ZDC events only); W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptZDC = new TH1D("h1_eps_MCDEMPAcceptZDC", "#epsilon MC Truth DEMP Accepted (ZDC events only); #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptZDC = new TH1D("h1_y_MCDEMPAcceptZDC", "y MC Truth DEMP Accepted (ZDC events only); y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptZDC = new TH2D("h2_tQ2_MCDEMPAcceptZDC", "-t vs Q^{2} MC Truth DEMP Accepted (ZDC events only); -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptZDC = new TH2D("h2_WQ2_MCDEMPAcceptZDC", "W vs Q^{2} MC Truth DEMP Accepted (ZDC events only); W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);

      TH1D* h1_Q2_MCDEMPAcceptZDC_NoAB = new TH1D("h1_Q2_MCDEMPAcceptZDC_NoAB", "Q^{2} MC Truth DEMP Accepted (ZDC events only), No Beam Effects; Q^{2} (GeV^{2}); Rate/bin (Hz)", 160, 0, 40);
      TH1D* h1_t_MCDEMPAcceptZDC_NoAB = new TH1D("h1_t_MCDEMPAcceptZDC_NoAB", "-t MC Truth DEMP Accepted (ZDC events only), No Beam Effects; -t (GeV^{2}); Rate/bin (Hz)", 150, 0, 1.5);
      TH1D* h1_W_MCDEMPAcceptZDC_NoAB = new TH1D("h1_W_MCDEMPAcceptZDC_NoAB", "W MC Truth DEMP Accepted (ZDC events only), No Beam Effects; W (GeV); Rate/bin (Hz)", 150, -50, 100);
      TH1D* h1_eps_MCDEMPAcceptZDC_NoAB = new TH1D("h1_eps_MCDEMPAcceptZDC_NoAB", "#epsilon MC Truth DEMP Accepted (ZDC events only), No Beam Effects; #epsilon; Rate/bin (Hz)", 100, 0, 1);
      TH1D* h1_y_MCDEMPAcceptZDC_NoAB = new TH1D("h1_y_MCDEMPAcceptZDC_NoAB", "y MC Truth DEMP Accepted (ZDC events only), No Beam Effects; y; Rate/bin (Hz)", 120, -0.2, 1);
      TH2D* h2_tQ2_MCDEMPAcceptZDC_NoAB = new TH2D("h2_tQ2_MCDEMPAcceptZDC_NoAB", "-t vs Q^{2} MC Truth DEMP Accepted (ZDC events only), No Beam Effects; -t (GeV^{2}); Q^{2} (GeV^{2}); Rate/bin (Hz)", 40, 0, 1.4, 40, 0, 40);
      TH2D* h2_WQ2_MCDEMPAcceptZDC_NoAB = new TH2D("h2_WQ2_MCDEMPAcceptZDC_NoAB", "W vs Q^{2} MC Truth DEMP Accepted (ZDC events only), No Beam Effects; W (GeV); Q^{2} (GeV^{2}); Rate/bin (Hz)", 150, -50, 100, 40, 0, 40);
    }
  }
  
  if (ZDC == kTRUE){

    TH2D* h2_n_pTheta_MCAcceptZDC_NoAB = new TH2D("h2_n_pTheta_MCAcceptZDC_NoAB", "Neutron MC Truth Accepted (ZDC), No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCAcceptZDC = new TH2D("h2_n_pTheta_MCAcceptZDC", "Neutron MC Truth Accepted (ZDC); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));

    TH2D* h2_eSc_pTheta_MCDEMPAcceptZDC_NoCuts_NoAB = new TH2D("h2_eSc_pTheta_MCDEMPAcceptZDC_NoCuts_NoAB", "e' MC Truth DEMP Accepted (ZDC), No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptZDC_NoCuts_NoAB = new TH2D("h2_Pi_pTheta_MCDEMPAcceptZDC_NoCuts_NoAB", "#pi MC Truth DEMP Accepted (ZDC), No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptZDC_NoCuts_NoAB = new TH2D("h2_n_pTheta_MCDEMPAcceptZDC_NoCuts_NoAB", "Neutron MC Truth DEMP Accepted (ZDC), No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_eSc_pTheta_MCDEMPAcceptZDC_NoCuts = new TH2D("h2_eSc_pTheta_MCDEMPAcceptZDC_NoCuts", "e' MC Truth DEMP Accepted (ZDC), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptZDC_NoCuts = new TH2D("h2_Pi_pTheta_MCDEMPAcceptZDC_NoCuts", "#pi MC Truth DEMP Accepted (ZDC), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptZDC_NoCuts = new TH2D("h2_n_pTheta_MCDEMPAcceptZDC_NoCuts", "Neutron MC Truth DEMP Accepted (ZDC), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));

    TH2D* h2_eSc_pTheta_MCDEMPAcceptZDC_NoAB = new TH2D("h2_eSc_pTheta_MCDEMPAcceptZDC_NoAB", "e' MC Truth DEMP Accepted (ZDC), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptZDC_NoAB = new TH2D("h2_Pi_pTheta_MCDEMPAcceptZDC_NoAB", "#pi MC Truth DEMP Accepted (ZDC), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptZDC_NoAB = new TH2D("h2_n_pTheta_MCDEMPAcceptZDC_NoAB", "Neutron MC Truth DEMP Accepted (ZDC), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_eSc_pTheta_MCDEMPAcceptZDC = new TH2D("h2_eSc_pTheta_MCDEMPAcceptZDC", "e' MC Truth DEMP Accepted (ZDC); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptZDC = new TH2D("h2_Pi_pTheta_MCDEMPAcceptZDC", "#pi MC Truth DEMP Accepted (ZDC); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptZDC = new TH2D("h2_n_pTheta_MCDEMPAcceptZDC", "Neutron MC Truth DEMP Accepted (ZDC); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));

    TH2D* h2_eSc_pTheta_RecoDEMPAcceptZDC_NoCuts = new TH2D("h2_eSc_pTheta_RecoDEMPAcceptZDC_NoCuts", "e' Reconstructed DEMP Accepted (ZDC), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_RecoDEMPAcceptZDC_NoCuts = new TH2D("h2_Pi_pTheta_RecoDEMPAcceptZDC_NoCuts", "#pi Reconstructed DEMP Accepted (ZDC), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_RecoDEMPAcceptZDC_NoCuts = new TH2D("h2_n_pTheta_RecoDEMPAcceptZDC_NoCuts", "Neutron Reconstructed DEMP Accepted (ZDC), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_eSc_pTheta_RecoDEMPAcceptZDC = new TH2D("h2_eSc_pTheta_RecoDEMPAcceptZDC", "e' Reconstructed DEMP Accepted (ZDC); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_RecoDEMPAcceptZDC = new TH2D("h2_Pi_pTheta_RecoDEMPAcceptZDC", "#pi Reconstructed DEMP Accepted (ZDC); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_RecoDEMPAcceptZDC = new TH2D("h2_n_pTheta_RecoDEMPAcceptZDC", "Neutron Reconstructed DEMP Accepted (ZDC); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    
    TH2D* h2_n_XY_Reco = new TH2D("h2_n_XY_Reco", "Neutron reconstructed XY position at ZDC;x (mm) ;y (mm); Rate/bin (Hz)", 150,-1200,-600,150,-300,300);
    TH2D* h2_n_XY_RecoAccept = new TH2D("h2_n_XY_RecoAccept", "Neutron reconstructed XY position at ZDC;x (mm) ;y (mm); Rate/bin (Hz)", 150,-1200,-600,150,-300,300); 
    TH2D* h2_nRot_XY_Reco = new TH2D("h2_nRot_XY_Reco", "Neutron reconstructed (Rotated 25 mrad) XY position at ZDC;x (mm) ;y (mm); Rate/bin (Hz)", 100,-200,200,100,-200,200);
    TH2D* h2_nRot_XY_RecoAccept = new TH2D("h2_nRot_XY_RecoAccept", "Neutron reconstructed (Rotated 25 mrad) XY position at ZDC;x (mm) ;y (mm); Rate/bin (Hz)", 100,-200,200,100,-200,200);
    TH2D* h2_n_pTheta_RecoAcceptZDC = new TH2D("h2_n_pTheta_RecoAcceptZDC", "ZDC Reconstructed;#theta (Deg); p (GeV/c)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_nRot_pTheta_RecoAcceptoZDC = new TH2D("h2_nRot_pTheta_RecoAcceptZDC", "ZDC Reconstructed (Rotated 25 mrad);#theta (Deg); p (GeV/c)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    
  }
  
  if (B0 == kTRUE){
    TH1D* h1_B0_nClusters = new TH1D("h1_B0_nClusters", "B0 Hit Multiplicity; N_{Clus}", 30, 0, 30);
    TH2D* h2_B0_XY_Raw = new TH2D("h2_B0_XY_Raw", "B0 XY Hit Position, raw all clusters; x (mm); y(mm)", 75, -325, -25, 75, -150, 150);
    TH2D* h2_B0_XY_Raw_EWeight = new TH2D("h2_B0_XY_Raw_EWeight", "B0 XY Hit Position, raw all clusters, energy weighted; x (mm); y(mm)", 75, -325, -25, 75, -150, 150);
    TH1D* h1_B0_nClusters_AcceptRaw = new TH1D("h1_B0_nClusters_AcceptRaw", "B0 Hit Multiplicity, number of clusters in event; N_{Clus}", 30, 0, 30);
    TH1D* h1_B0_nClusters_Accept = new TH1D("h1_B0_nClusters_Accept", "B0 Hit Multiplicity, number of accepted cluters; N_{Clus}", 30, 0, 30);
    TH2D* h2_B0_XY_Accept = new TH2D("h2_B0_XY_Accept", "B0 Reconstructed XY Hit Position; x (mm); y(mm)", 75, -325, -25, 75, -150, 150);
    TH2D* h2_B0_XY_AcceptWeighted = new TH2D("h2_B0_XY_AcceptWeighted", "B0 Reconstructed XY Hit Position; x (mm); y(mm); Rate/bin (Hz)", 75, -325, -25, 75, -150, 150);
    TH2D* h2_n_ETheta_RecoAccept_B0 = new TH2D("h2_n_ETheta_RecoAccept_B0", "B0 Reconstructed;#theta (Deg); E (GeV)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_RecoAcceptB0 = new TH2D("h2_n_pTheta_RecoAcceptB0", "B0 Reconstructed;#theta (Deg); p (GeV/c)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_nRot_pTheta_RecoAcceptB0 = new TH2D("h2_nRot_pTheta_RecoAcceptB0", "B0 Reconstructed (Rotated 25 mrad);#theta (Deg); p (GeV/c)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    
    TH2D* h2_n_pTheta_MCAcceptB0 = new TH2D("h2_n_pTheta_MCAcceptB0", "Neutron MC Truth Accepted (B0); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_n_pTheta_MCAcceptB0_NoAB = new TH2D("h2_n_pTheta_MCAcceptB0_NoAb", "Neutron MC Truth Accepted (B0), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    
    TH2D* h2_eSc_pTheta_MCDEMPAcceptB0_NoCuts_NoAB = new TH2D("h2_eSc_pTheta_MCDEMPAcceptB0_NoCuts_NoAB", "e' MC Truth DEMP Accepted (B0), No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptB0_NoCuts_NoAB = new TH2D("h2_Pi_pTheta_MCDEMPAcceptB0_NoCuts_NoAB", "#pi MC Truth DEMP Accepted (B0), No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptB0_NoCuts_NoAB = new TH2D("h2_n_pTheta_MCDEMPAcceptB0_NoCuts_NoAB", "Neutron MC Truth DEMP Accepted (B0), No Cuts, No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_eSc_pTheta_MCDEMPAcceptB0_NoCuts = new TH2D("h2_eSc_pTheta_MCDEMPAcceptB0_NoCuts", "e' MC Truth DEMP Accepted (B0), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptB0_NoCuts = new TH2D("h2_Pi_pTheta_MCDEMPAcceptB0_NoCuts", "#pi MC Truth DEMP Accepted (B0), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptB0_NoCuts = new TH2D("h2_n_pTheta_MCDEMPAcceptB0_NoCuts", "Neutron MC Truth DEMP Accepted (B0), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    
    TH2D* h2_eSc_pTheta_MCDEMPAcceptB0_NoAB = new TH2D("h2_eSc_pTheta_MCDEMPAcceptB0_NoAB", "e' MC Truth DEMP Accepted (B0), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptB0_NoAB = new TH2D("h2_Pi_pTheta_MCDEMPAcceptB0_NoAB", "#pi MC Truth DEMP Accepted (B0), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptB0_NoAB = new TH2D("h2_n_pTheta_MCDEMPAcceptB0_NoAB", "Neutron MC Truth DEMP Accepted (B0), No Beam Effects; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_eSc_pTheta_MCDEMPAcceptB0 = new TH2D("h2_eSc_pTheta_MCDEMPAcceptB0", "e' MC Truth DEMP Accepted (B0); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_MCDEMPAcceptB0 = new TH2D("h2_Pi_pTheta_MCDEMPAcceptB0", "#pi MC Truth DEMP Accepted (B0); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_MCDEMPAcceptB0 = new TH2D("h2_n_pTheta_MCDEMPAcceptB0", "Neutron MC Truth DEMP Accepted (B0); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));

    TH2D* h2_eSc_pTheta_RecoDEMPAcceptB0_NoCuts = new TH2D("h2_eSc_pTheta_RecoDEMPAcceptB0_NoCuts", "e' Reconstructed DEMP Accepted (B0), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_RecoDEMPAcceptB0_NoCuts = new TH2D("h2_Pi_pTheta_RecoDEMPAcceptB0_NoCuts", "#pi Reconstructed DEMP Accepted (B0), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_RecoDEMPAcceptB0_NoCuts = new TH2D("h2_n_pTheta_RecoDEMPAcceptB0_NoCuts", "Neutron Reconstructed DEMP Accepted (B0), No Cuts; #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    TH2D* h2_eSc_pTheta_RecoDEMPAcceptB0 = new TH2D("h2_eSc_pTheta_RecoDEMPAcceptB0", "e' Reconstructed DEMP Accepted (B0); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 120, 180, NBins_Energy, ElecBeamE-1, ElecBeamE+2);
    TH2D* h2_Pi_pTheta_RecoDEMPAcceptB0 = new TH2D("h2_Pi_pTheta_RecoDEMPAcceptB0", "#pi Reconstructed DEMP Accepted (B0); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta, 0, 60, NBins_Energy, 0, 100);
    TH2D* h2_n_pTheta_RecoDEMPAcceptB0 = new TH2D("h2_n_pTheta_RecoDEMPAcceptB0", "Neutron Reconstructed DEMP Accepted (B0); #theta (deg); P(GeV/C); Rate/bin (Hz)", NBins_Theta+50, 0, 2.5, NBins_Energy, 0, HadBeamE+(0.2*HadBeamE));
    
    TH2D* h2_B0_XY_MCAccept = new TH2D("h2_B0_XY_MCAccept", "B0 MC Accepted XY Hit Position; x (mm); y(mm); Rate/bin (Hz)", 75, -325, -25, 75, -150, 150);
        
  }
  if (Tracking == kTRUE){
  }
  if (QA == kTRUE){
  }
  if (Results == kTRUE){
  }
  
}

// Histogram filling functions, avoids needing histograms defined in main file. Additionally, makes it so the main code doesn't actually care if the histogram is defined or not. If it doesn't exist, nothing happens
void FillHist1D(TString Histname, Double_t Value){
  if(gDirectory->FindObject(Histname) != 0){ // Check histogram exists, if it does, fill it
    ((TH1D*)gDirectory->FindObject(Histname))->Fill(Value);
  }
}

void FillHist1D(TString Histname, Double_t Value, Double_t W){
  if(gDirectory->FindObject(Histname) != 0){ // Check histogram exists, if it does, fill it
    ((TH1D*)gDirectory->FindObject(Histname))->Fill(Value, W);
  }
}

void FillHist2D(TString Histname, Double_t Value, Double_t Value2){
  if(gDirectory->FindObject(Histname) != 0){ // Check histogram exists, if it does, fill it
    ((TH2D*)gDirectory->FindObject(Histname))->Fill(Value, Value2);
  }
}
void FillHist2D(TString Histname, Double_t Value, Double_t Value2, Double_t W){
  if(gDirectory->FindObject(Histname) != 0){ // Check histogram exists, if it does, fill it
    ((TH2D*)gDirectory->FindObject(Histname))->Fill(Value, Value2, W);
  }
}
