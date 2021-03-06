#ifndef StPicoVtxAnaMaker_h
#define StPicoVtxAnaMaker_h

/* **************************************************
 *  A Maker that reads StPicoEvents' and creates 
 *  StPicoD0Events and stores them.
 *
 *  Authors:  Xin Dong        (xdong@lbl.gov)
 *            **Mustafa Mustafa (mmustafa@lbl.gov)
 *
 *  **Code Maintainer
 *
 * **************************************************
 */

#include <bitset>
#include <climits>
#include <vector>

#include "StMaker.h"
#include "StThreeVectorF.hh"
#include "../StPicoKFVertexFitter/StPicoKFVertexFitter.h"
#include "StPicoVtxAnaEvent.h"

class TTree;
class TFile;
class StPicoDstMaker;
class StPicoEvent;
class StPicoTrack;

class StPicoVtxAnaMaker : public StMaker 
{
  public:
    StPicoVtxAnaMaker(char const* makerName, StPicoDstMaker* picoMaker, char const* fileBaseName);
    virtual ~StPicoVtxAnaMaker();
    
    virtual Int_t Init();
    virtual Int_t Make();
    virtual void  Clear(Option_t *opt="");
    virtual Int_t Finish();
    
  private:
    bool  isGoodEvent();
    bool  isGoodForVertexFit(StPicoTrack const*,StThreeVectorF const& vtx) const;
    size_t popcount(size_t) const;

    StPicoDstMaker* mPicoDstMaker;
    StPicoEvent*    mPicoEvent;
    StPicoKFVertexFitter mKfVertexFitter;
    StPicoVtxAnaEvent mVtxEvent;

    ClassDef(StPicoVtxAnaMaker, 0)
};
inline size_t StPicoVtxAnaMaker::popcount(size_t n) const
{
    std::bitset<sizeof(size_t) * CHAR_BIT> b(n);
    return b.count();
}
#endif
