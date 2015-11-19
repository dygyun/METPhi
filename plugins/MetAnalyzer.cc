#include <iostream>
#include "TTree.h"
#include "Demo/MetAnalyzer/interface/MetAnalyzer.h"
// constructors and destructor
using namespace std;
using namespace reco;

MetAnalyzer::MetAnalyzer(const edm::ParameterSet& iConfig)
:
MetTag(       iConfig.getParameter<edm::InputTag>("metTag") ),
MetCorrectTag(iConfig.getParameter<edm::InputTag>("metCorrectTag") ),
MetegammaHFMinusTag( iConfig.getParameter<edm::InputTag>("egammaHFMinusTag") ),
MetegammaHFPlusTag( iConfig.getParameter<edm::InputTag>("egammaHFPlusTag") ),
MetgammaBarrelTag( iConfig.getParameter<edm::InputTag>("gammaBarrelTag") ),
MetgammaEndcapMinusTag( iConfig.getParameter<edm::InputTag>("gammaEndcapMinusTag") ),
MetgammaEndcapPlusTag( iConfig.getParameter<edm::InputTag>("gammaEndcapPlusTag") ),
//MethTag( iConfig.getParameter<edm::InputTag>("hTag") ),
MethEtaPlusTag( iConfig.getParameter<edm::InputTag>("hEtaPlusTag") ),
MethEtaMinusTag( iConfig.getParameter<edm::InputTag>("hEtaMinusTag") ),
Meth0BarrelTag( iConfig.getParameter<edm::InputTag>("h0BarrelTag") ),
Meth0EndcapMinusTag( iConfig.getParameter<edm::InputTag>("h0EndcapMinusTag") ),
Meth0EndcapPlusTag( iConfig.getParameter<edm::InputTag>("h0EndcapPlusTag") ),
MethHFMinusTag( iConfig.getParameter<edm::InputTag>("hHFMinusTag") ),
MethHFPlusTag( iConfig.getParameter<edm::InputTag>("hHFPlusTag") )
{
   //now do what ever initialization is needed
}

MetAnalyzer::~MetAnalyzer()
{
   // do anything here that needs to be done at desctruction time
}
// member functions
// ------------ method called for each event  ------------
void
MetAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
//   MET_index=0;
   Handle<METCollection> met;
   iEvent.getByLabel( MetTag, met );
 
   int numMet =0;
   for (METCollection::const_iterator itMet = met->begin() ; itMet != met->end(); itMet++)
   {
       MET =  (itMet)->pt();     
       METphi =  (itMet)->phi();     
      // METphi_arc= (TMath::ATan((itMet)->px()/(itMet)->py()));
       MET_x = (itMet)->px();
       MET_y = (itMet)->py();
       MET_sumEt = (itMet)->sumEt();
       numMet++;
//       cout << "Met_pt:"<<  (itMet)->pt()  << "met phii___" << (itMet)->phi() << "MET_x________" << (itMet)->px() << "MET_sumEt___"<<  (itMet)->sumEt()  << endl;
//       ssbtreeManager->Fill( "MET" ,(*itMet).pt(), 0, (*itMet).phi(), 0, MET_index);      
//       MET_index++;
//        cout << "Met_pt:"<<  itMet->pt() << endl;
   }
   Handle<METCollection> metcorrect;
   iEvent.getByLabel( MetCorrectTag, metcorrect );
 
   for (METCollection::const_iterator itMet_corr = metcorrect->begin() ; itMet_corr != metcorrect->end(); itMet_corr++)
   {
       METcorrect = (itMet_corr)->pt();     
       METcorrectphi =  (itMet_corr)->phi();     
       METcorrect_x = (itMet_corr)->px();
       METcorrect_y = (itMet_corr)->py();
       METcorrect_sumEt = (itMet_corr)->sumEt();
   }
   // cout << "numMet " << numMet << endl;

   Handle<CorrMetdataCollection> corr;
   iEvent.getByLabel( MetegammaHFMinusTag, corr );
   
   METegammaHFMinus_x = corr->mex;
   METegammaHFMinus_y = corr->mey;
   //METegammaHFMinus_phi = (TMath::ATan(corr->mex/corr->mey));
//   cout << "mex:" << corr->mex << "--phi____ "  << corr->phi << endl;
   //cout << "mex:" << corr->mex << "--DY mey:____ "  << corr->mey <<"___sumet___" <<  corr->sumet << "__signi__"  << corr.significance  << endl;
//   cout << "-- ?? DY mey : " << corr->mey << endl;
   Handle<CorrMetdataCollection> corr1;
   iEvent.getByLabel( MetegammaHFPlusTag, corr1 );
    
   METegammaHFPlus_x= corr1->mex;
   METegammaHFPlus_y= corr1->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr2;
   iEvent.getByLabel( MetgammaBarrelTag, corr2 );
    
   METgammaBarrel_x= corr2->mex;
   METgammaBarrel_y= corr2->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr3;
   iEvent.getByLabel( MetgammaEndcapMinusTag, corr3 );
    
   METgammaEndcapMinus_x= corr3->mex;
   METgammaEndcapMinus_y= corr3->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr4;
   iEvent.getByLabel( MetgammaEndcapPlusTag, corr4 );
    
   METgammaEndcapPlus_x= corr4->mex;
   METgammaEndcapPlus_y= corr4->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr5;
   iEvent.getByLabel( MethEtaPlusTag, corr5 );
    
   METhEtaPlus_x= corr5->mex;
   METhEtaPlus_y= corr5->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr6;
   iEvent.getByLabel( MethEtaMinusTag, corr6 );
    
   METhEtaMinus_x= corr6->mex;
   METhEtaMinus_y= corr6->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr7;
   iEvent.getByLabel( Meth0BarrelTag, corr7 );
    
   METh0Barrel_x= corr7->mex;
   METh0Barrel_y= corr7->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr8;
   iEvent.getByLabel( Meth0EndcapMinusTag, corr8 );
    
   METh0EndcapMinus_x= corr8->mex;
   METh0EndcapMinus_y= corr8->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr9;
   iEvent.getByLabel( Meth0EndcapPlusTag, corr9 );
    
   METh0EndcapPlus_x= corr9->mex;
   METh0EndcapPlus_y= corr9->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr10;
   iEvent.getByLabel( MethHFMinusTag, corr10 );
    
   METh0EndcapPlus_x= corr10->mex;
   METhHFMinus_y= corr10->mey;
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr11;
   iEvent.getByLabel( MethHFPlusTag, corr11 );
    
   METhHFPlus_x= corr11->mex;
   METhHFPlus_y= corr11->mey;
///////////////////////////////////

      dytree->Fill();
       //dytree->Write();

#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}
// ------------ method called once each job just before starting event loop  ------------
void 
MetAnalyzer::beginJob()
{
      dytree =  metfile->make<TTree> ("met","Met");
      Book();
   //ssbtree = ssbfs->make<TTree>("SSBTree", "Tree for Physics Analyses at CMS");  
}
// ------------ method called once each job just after ending the event loop  ------------
void 
MetAnalyzer::endJob() 
{
}
void 
MetAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
MetAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
MetAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
MetAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
void
MetAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
void 
MetAnalyzer::Book()
{
  dytree->Branch("MET",&MET,"MET/D");
  dytree->Branch("METphi",&METphi,"METphi/D");
  dytree->Branch("METphi_arc",&METphi_arc,"METphi_arc/D");
  dytree->Branch("MET_x",&MET_x,"MET_x/D");
  dytree->Branch("MET_y",&MET_x,"MET_y/D");
  dytree->Branch("MET_sumEt",&MET_sumEt,"MET_sumEt/D");
  dytree->Branch("METcorrect",&METcorrect,"METcorrect/D");
  dytree->Branch("METcorrectphi",&METcorrectphi,"METcorrectphi/D");
  dytree->Branch("METcorrect_x",&METcorrect_x,"METcorrect_x/D");
  dytree->Branch("METcorrect_y",&METcorrect_x,"METcorrect_y/D");
  dytree->Branch("METcorrect_sumEt",&METcorrect_sumEt,"METcorrect_sumEt/D");
  dytree->Branch("METegammaHFMinus_x",&METegammaHFMinus_x,"METegammaHFMinus_x/D");
  dytree->Branch("METegammaHFMinus_y",&METegammaHFMinus_y,"METegammaHFMinus_y/D");
//  dytree->Branch("METegammaHFMinus_phi",&METegammaHFMinus_phi,"METegammaHFMinus_phi/D");
  dytree->Branch("METegammaHFPlus_x",&METegammaHFPlus_x,"METegammaHFPlus_x/D");
  dytree->Branch("METegammaHFPlus_y",&METegammaHFPlus_y,"METegammaHFPlus_y/D");
  dytree->Branch("METgammaBarrel_x",&METgammaBarrel_x,"METgammaBarrel_x/D");
  dytree->Branch("METgammaBarrel_y",&METgammaBarrel_y,"METgammaBarrel_y/D");
  dytree->Branch("METgammaEndcapMinus_x",&METgammaEndcapMinus_x,"METgammaEndcapMinus_x/D");
  dytree->Branch("METgammaEndcapMinus_y",&METgammaEndcapMinus_y,"METgammaEndcapMinus_y/D");
  dytree->Branch("METgammaEndcapPlus_x",&METgammaEndcapPlus_x,"METgammaEndcapPlus_x/D");
  dytree->Branch("METgammaEndcapPlus_x",&METgammaEndcapPlus_x,"METgammaEndcapPlus_x/D");
  //dytree->Branch("METh_x",&METh_x,"METh_x/D");
 // dytree->Branch("METh_y",&METh_y,"METh_y/D");
  dytree->Branch("METhEtaPlus_x",&METhEtaPlus_x,"METhEtaPlus_x/D");
  dytree->Branch("METhEtaPlus_y",&METhEtaPlus_y,"METhEtaPlus_y/D");
  dytree->Branch("METhEtaMinus_x",&METhEtaMinus_x,"METhEtaMinus_x/D");
  dytree->Branch("METhEtaMinus_y",&METhEtaMinus_y,"METhEtaMinus_y/D");
  dytree->Branch("METh0Barrel_x",&METh0Barrel_x,"METh0Barrel_x/D");
  dytree->Branch("METh0Barrel_y",&METh0Barrel_y,"METh0Barrel_y/D");
  dytree->Branch("METh0EndcapMinus_x",&METh0EndcapMinus_x,"METh0EndcapMinus_x/D");
  dytree->Branch("METh0EndcapMinus_y",&METh0EndcapMinus_y,"METh0EndcapMinus_y/D");
  dytree->Branch("METh0EndcapPlus_x",&METh0EndcapPlus_x,"METh0EndcapPlus_x/D");
  dytree->Branch("METh0EndcapPlus_y",&METh0EndcapPlus_y,"METh0EndcapPlus_y/D");
  dytree->Branch("METhHFMinus_x",&METhHFMinus_x,"METhHFMinus_x/D");
  dytree->Branch("METhHFMinus_y",&METhHFMinus_y,"METhHFMinus_y/D");
  dytree->Branch("METhHFPlus_x",&METhHFPlus_x,"METhHFPlus_x/D");
  dytree->Branch("METhHFPlus_y",&METhHFPlus_y,"METhHFPlus_y/D");


}
void
MetAnalyzer::Reset()
{
  MET =-999;
  METphi =-999;
  METphi_arc =-999;
  MET_x=-999;
  MET_y=-999;
  MET_sumEt=-999;
  METcorrect =-999;
  METcorrectphi =-999;
  METcorrect_x=-999;
  METcorrect_y=-999;
  METcorrect_sumEt=-999;
  METegammaHFMinus_x=-999;
  METegammaHFMinus_y=-999;
//  METegammaHFMinus_phi=-999;
  METegammaHFPlus_x=-999;
  METegammaHFPlus_y=-999;
  METgammaBarrel_x=-999;      
  METgammaBarrel_y=-999;
  METgammaEndcapMinus_x=-999;
  METgammaEndcapMinus_y=-999;
  METgammaEndcapPlus_x=-999;
  METgammaEndcapPlus_y=-999;
//  METh_x=-999;
  METhEtaPlus_x=-999;
  METhEtaPlus_y=-999;
  METhEtaMinus_x=-999;
  METhEtaMinus_y=-999;
  METh0Barrel_x=-999;
  METh0Barrel_y=-999;
  METh0EndcapMinus_x=-999;
  METh0EndcapMinus_y=-999;
  METh0EndcapPlus_x=-999;
  METh0EndcapPlus_y=-999;
  METhHFMinus_x=-999;
  METhHFMinus_y=-999;
  METhHFPlus_x=-999;
  METhHFPlus_y=-999;
}

//define this as a plug-in
DEFINE_FWK_MODULE(MetAnalyzer);
