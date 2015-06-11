#ifndef StAnaCuts_H
#define StAnaCuts_H

/* **************************************************
 *  Cuts namespace.
 *
 *  Authors:  Mustafa Mustafa (mmustafa@lbl.gov)
 *
 * **************************************************
 */

#include "Rtypes.h"
#include <string>

#include "StAnaCuts.h"

namespace anaCuts
{
   // path to lists of triggers prescales
   // lists are obtained from http://www.star.bnl.gov/protected/common/common2014/trigger2014/plots_au200gev/
   std::string const prescalesFilesDirectoryName = "./run14AuAu200GeVPrescales";
   //event
   UShort_t const triggerWord = 0x1F; //first five bits see http://rnc.lbl.gov/~xdong/SoftHadron/picoDst.html
   float const vz = 6.0;// cm.
   float const vzVpdVz = 3.0; // 3 cm.
   float const Verror = 1.0e-5; // 
   float const Vrcut = 2.0; // 

   // QA tracks cuts
   float const qaGPt = 0.20;
   int const qaNHitsFit = 20;
   int const qaNHitsDedx = 12;
   float const qaDca = 1.5;
   float const qaEta = 0.4;

   //tracking
   float const mMinMinPt = 0.7;
   float const mMaxMinPt = 1.2;
   float const mP0MinPt = 0.3;
   float const mP1MinPt = 0.3;
   int   const nPtBins = 5;
   float const PtEdge[nPtBins+1] = {0., 1., 2., 3., 5., 10.};

   float const minPt = 0.6;//1.2
   int const nHitsFit = 20;

   //pions
   float const nSigmaPion = 3.0;
   float const pTofBetaDiff = 0.03;

   //kaons
   float const nSigmaKaon = 2.0;
   float const kTofBetaDiff = 0.03;

   float const dcaV0ToPv[nPtBins] = {0.0061, 0.0049, 0.0038, 0.0038, 0.0040};
   float const decayLength[nPtBins] = {0.0145, 0.0181, 0.0212, 0.0247, 0.0259};
   float const cosTheta[nPtBins] = {0.0000, 0.0000, 0.0000, 0.0000, 0.0000};//0.995
   float const dcaDaughters[nPtBins] = {0.0084, 0.0066, 0.0057, 0.0050, 0.0060}; //0.0050;
   float const kDca[nPtBins] = {0.0103, 0.0091, 0.0095, 0.0079, 0.0058};//0.008, // minimum
   float const pDca[nPtBins] = {0.0110, 0.0111, 0.0086, 0.0081, 0.0062};//0.008
}
#endif
