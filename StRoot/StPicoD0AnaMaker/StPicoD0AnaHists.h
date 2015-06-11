#ifndef StPicoD0AnaHists__h
#define StPicoD0AnaHists__h

/* **************************************************
 *  A class to create and save my D0 analysis histograms.
 *
 *  Authors: Mustafa Mustafa (mmustafa@lbl.gov)
 *
 * **************************************************
 */

#include "TObject.h"

class TH1F;
class TH2F;
class TH3F;
class TFile;
class TString;
class StPicoPrescales;
class StPicoEvent;
class StKaonPion;
class TNtuple;


class StPicoD0AnaHists: public TObject
{
  public:
   StPicoD0AnaHists(TString fileBaseName);
   virtual ~StPicoD0AnaHists();
   void addEvent(StPicoEvent const *);
   void addEventBeforeCut(StPicoEvent const *);
   void addCent(const double refmultCor,int centrality, const double reweight);
   void addKaonPion(StKaonPion const*, bool unlike, bool tpc, bool tof, int centrality, const double reweight);
   void addTpcDenom1(double pt, int centrality);
   void addTpcDenom2(double pt, int centrality);
   void addHFTNumer1(double pt, int centrality);
   void addHFTNumer2(double pt, int centrality);
   void addQaNtuple(int, float, float, float, float, float, int, const double, float, int, int);
   void addDcaPtCent(float dca, float dcaXy, float  dcaZ, float pt,  int centrality);
   void closeFile();

  private:
   StPicoD0AnaHists(){}

   StPicoPrescales* mPrescales;
   TFile* mOutFile;
   TH1F* mh1TotalEventsInRun;
   TH1F* mh1TotalEventsInRunBeforeCut;
   TH2F* mh2InvariantMassVsPt;
   TH2F* mh2InvariantMassVsPtLike;
   TH2F* mh2InvariantMassVsPtTof;
   TH2F* mh2InvariantMassVsPtTofLike;
   //centrality
   TH1F* mh1Cent;
   TH1F* mh1CentWg;
   TH1F* mh1gRefmultCor;
   TH1F* mh1gRefmultCorWg;
   TH3F* mh3InvariantMassVsPtVsCent;
   TH3F* mh3InvariantMassVsPtVsCentLike;
   TH3F* mh3InvariantMassVsPtVsCentTof;
   TH3F* mh3InvariantMassVsPtVsCentTofLike;
   //HFT ratio QA
   TH2F* mh2Tpc1PtCent;
   TH2F* mh2Tpc2PtCent;
   TH2F* mh2HFT1PtCent;
   TH2F* mh2HFT2PtCent;
   //HFT Dca 
   TH1F* mh1Dca;
   TH1F* mh1DcaXy;
   TH1F* mh1DcaZ;
   TH3F* mh3DcaPtCent;
   TH3F* mh3DcaXyPtCent;
   TH3F* mh3DcaZPtCent;

   TNtuple* nt;

   ClassDef(StPicoD0AnaHists, 1)
};
#endif
