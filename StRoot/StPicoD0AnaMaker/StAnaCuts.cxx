/* **************************************************
 *  Cuts namespace.
 *
 *  Authors:  Mustafa Mustafa (mmustafa@lbl.gov)
 *
 * **************************************************
 */

#include "StAnaCuts.h"

namespace anaCuts
{
   // path to lists of triggers prescales
   // lists are obtained from http://www.star.bnl.gov/protected/common/common2014/trigger2014/plots_au200gev/
   std::string const prescalesFilesDirectoryName = "./run14AuAu200GeVPrescales";
   //event
   UShort_t const triggerWord = 0x1F; //first five bits see http://rnc.lbl.gov/~xdong/SoftHadron/picoDst.html

   //tracking
   int const nHitsFit = 20;

   //pions
   float const nSigmaPion = 3.0;

   //kaons
   float const nSigmaKaon = 2.0;

   // histograms kaonPion pair cuts
   float const qaNHitsFit = 20;
   float const qaNSigmaKaon = 2.0;
   float const qaCosTheta = 0.995;
   float const qaDcaDaughters = 0.0050;
   float const qaKDca = 0.008; // minimum
   float const qaPDca = 0.008;
}
