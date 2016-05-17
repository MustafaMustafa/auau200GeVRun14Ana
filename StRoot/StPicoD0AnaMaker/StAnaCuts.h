#ifndef StAnaCuts_H
#define StAnaCuts_H

/* **************************************************
 *
 *  Authors: Guannan Xie <guannanxie@lbl.gov>
 *           Mustafa Mustafa <mmustafa@lbl.gov>
 *
 * **************************************************
 */

#include "Rtypes.h"
#include <string>
#include <array>

namespace anaCuts
{
   // path to lists of triggers prescales
   // lists are obtained from http://www.star.bnl.gov/protected/common/common2014/trigger2014/plots_au200gev/
   std::string const prescalesFilesDirectoryName = "./run14AuAu200GeVPrescales";
   //event
   std::array<unsigned int, 5> const triggers = { 450050,    // vpdmb-5-p-nobsmd-hlt
                                                  450060,    // vpdmb-5-p-nobsmd-hlt
                                                  450005,    // vpdmb-5-p-nobsmd
                                                  450015,    // vpdmb-5-p-nobsmd
                                                  450025};    // vpdmb-5-p-nobsmd

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
   int   const nPtBins = 5;
   float const PtBinsEdge[nPtBins+1] = {0., 1., 2., 3., 5., 15.};//this is for optimaized cut

   float const minPt = 0.6;//1.2
   int const nHitsFit = 20;

   //track eta cut
   float const Eta = 1.0;
   //pions
   float const nSigmaPion = 3.0;
   float const pTofBetaDiff = 0.03;

   //kaons
   float const nSigmaKaon = 2.0;
   float const kTofBetaDiff = 0.03;

   float const RapidityCut = 1.0;
   //D0 candidate cut// Ultimate2
   // float const dcaV0ToPv[nPtBins] = {0.0061, 0.0049, 0.0038, 0.0038, 0.0040};
   // float const decayLength[nPtBins] = {0.0145, 0.0181, 0.0212, 0.0247, 0.0259};
   // float const cosTheta[nPtBins] = {0.0000, 0.0000, 0.0000, 0.0000, 0.0000};//0.995
   // float const dcaDaughters[nPtBins] = {0.0084, 0.0066, 0.0057, 0.0050, 0.0060}; //0.0050;
   // float const kDca[nPtBins] = {0.0103, 0.0091, 0.0095, 0.0079, 0.0058};//0.008, // minimum
   // float const pDca[nPtBins] = {0.0110, 0.0111, 0.0086, 0.0081, 0.0062};//0.008

   float const dcaV0ToPv[nPtBins] = {0.0072, 0.0072, 0.0072, 0.0072, 0.0072};
   float const decayLength[nPtBins] = {0.0105, 0.0105, 0.0105, 0.0105, 0.0105};
   float const cosTheta[nPtBins] = {0.9500, 0.9500, 0.9500, 0.9500, 0.9500};//0.995
   float const dcaDaughters[nPtBins] = {0.0084, 0.0066, 0.0057, 0.0050, 0.0060}; //0.0050;
   float const kDca[nPtBins] = {0.0080, 0.0080, 0.0080, 0.0080, 0.0080};//0.008, // minimum
   float const pDca[nPtBins] = {0.0080, 0.0080, 0.0080, 0.0080, 0.0080};//0.008

   //D0 candidate cut// Ultimate1
//   float const dcaV0ToPv[nPtBins] = {0.0062, 0.0047, 0.0040, 0.0041, 0.0042};
//   float const decayLength[nPtBins] = {0.0149, 0.0205, 0.0216, 0.0233, 0.0282};
//   float const cosTheta[nPtBins] = {0.0000, 0.0000, 0.0000, 0.0000, 0.0000};//0.995
//   float const dcaDaughters[nPtBins] = {0.0082, 0.0070, 0.0056, 0.0065, 0.0065}; //0.0050;
//   float const kDca[nPtBins] = {0.0123, 0.0097, 0.0091, 0.0075, 0.0053};//0.008, // minimum
//   float const pDca[nPtBins] = {0.0109, 0.0108, 0.0100, 0.0074, 0.0067};//0.008

   //next are mostly for QA parts, Dca and HFT ratio
   int const nParticles=2;
   char const ParticleName[nParticles][256]={"Pion","Kaon"};

   int const nEtasDca = 5;
   float const EtaEdgeDca[nEtasDca + 1] = { -1.0, -0.6, -0.2, 0.2, 0.6, 1.0};
   int const nPhisDca = 11;
   float const PhiEdgeDca[nPhisDca + 1] =
   {
      // -3.14159 , -2.51327 , -1.88496 , -1.25664 , -0.628319 , 0 , 0.628319 , 1.25664 , 1.88496 , 2.51327 , 3.14159 //Uniform
      -3.14159 , -2.80359 , -2.17527 , -1.54696 , -0.918637 , -0.290319 , 0.338 , 0.966319 , 1.59464 , 2.22296 , 2.85127 , 3.14159 //Sector by Sector
   };

   float const rightHalfLowEdge = -1.54696;
   float const rightHalfHighEdge = 1.59464;

   int const nVzsDca = 4;
   float const VzEdgeDca[nVzsDca + 1] = { -6., -3., 0, 3., 6.};

   int const nCentsDca = 1;
   float const CentEdgeDca[nCentsDca + 1] = { -1.5, 8.5};

   int const nZdcxs = 11;
   float const ZdcxEdge[nZdcxs + 1] = {0., 10., 20., 30., 35., 40., 45., 50., 55., 60., 80., 100.0 };

   int const nPtsDca = 17;
   float const PtEdgeDca[nPtsDca + 1] =
   {
      0.6,  0.7 , 0.8 , 0.9 ,
      1. , 1.25 , 1.5 , 1.75 , 2.  , 2.25 , 2.5 , 2.75 , 3.0 , 3.5,
      // 3. , 3.5 , 4.  , 4.5 , 5. , 6. , 8.0 , 10. , 12.0
      4.  , 4.5 , 5. , 12.0
   };

   int const nEtasRatio = 10;
   float const EtaEdgeRatio[nEtasRatio + 1] = { -1.0, -0.8, -0.6, -0.4, -0.2, 0.0, 0.2, 0.4 , 0.6, 0.8, 1.0};

   int const nPhisRatio = 11;
   float const PhiEdgeRatio[nPhisRatio + 1] =
   {
      -3.14159 , -2.80359 , -2.17527 , -1.54696 , -0.918637 , -0.290319 , 0.338 , 0.966319 , 1.59464 , 2.22296 , 2.85127 , 3.14159 //Sector by Sector  // sector number 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3
      // -3.14159 , -2.93215 , -2.72271 , -2.51327 , -2.30383 , -2.0944 , -1.88496 , -1.67552 , -1.46608 , -1.25664 , -1.0472 , -0.837758 , -0.628319 , -0.418879 , -0.20944 , 0.0 , 0.20944 , 0.418879 , 0.628319 , 0.837758 , 1.0472 , 1.25664 , 1.46608 , 1.67552 , 1.88496 , 2.0944 , 2.30383 , 2.51327 , 2.72271 , 2.93215 , 3.14159
   };

   int const nVzsRatio = 6;
   float const VzEdgeRatio[nVzsRatio + 1] = { -6., -4., -2.,  0., 2.,  4.,  6.};

   int const nCentsRatio = 10;
   float const CentEdgeRatio[nCentsRatio + 1] = { -1.5, -0.5, 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5};

   int const nPtsRatio = 46;
   float const PtEdgeRatio[nPtsRatio + 1] =
   {
      0.6 , 0.7 , 0.8 , 0.9 ,
      1. , 1.1 , 1.2 , 1.3 , 1.4 , 1.5 , 1.6 , 1.7 , 1.8 , 1.9 ,
      2. , 2.2 , 2.4 , 2.6 , 2.8 , 3.0 , 3.2 , 3.4 , 3.6 , 3.8 ,
      4. , 4.2 , 4.4 , 4.6 , 4.8 , 5.0 , 5.2 , 5.4 , 5.6 , 5.8 ,
      6. , 6.5 , 7.0 , 7.5 , 8.0 , 8.5 , 9.0 , 9.5 , 10. , 10.5,
      11.0 , 11.5 , 12.0
   };

   int const nDcasDca = 140;
   float const DcaEdgeDca[nDcasDca + 1] =
   {
      -1 , -0.97 , -0.94 , -0.91 , -0.88 , -0.85 , -0.82 , -0.79 , -0.76 , -0.73 , -0.7 , -0.67 , -0.64 , -0.61 , -0.58 , -0.55 , -0.52 , -0.49 , -0.46 , -0.43 , -0.4 , -0.37 , -0.34 , -0.31 , -0.28 , -0.25 , -0.22 , -0.19 , -0.16 , -0.13 , // 30 //0.03cm/perbin
      -0.1 , -0.0975 , -0.095 , -0.0925 , -0.09 , -0.0875 , -0.085 , -0.0825 , -0.08 , -0.0775 , -0.075 , -0.0725 , -0.07 , -0.0675 , -0.065 , -0.0625 , -0.06 , -0.0575 , -0.055 , -0.0525 , -0.05 , -0.0475 , -0.045 , -0.0425 , -0.04 , -0.0375 , -0.035 , -0.0325 , -0.03 , -0.0275 , -0.025 , -0.0225 , -0.02 , -0.0175 , -0.015 , -0.0125 , -0.01 , -0.0075 , -0.005 , -0.0025 , 0 , 0.0025 , 0.005 , 0.0075 , 0.01 , 0.0125 , 0.015 , 0.0175 , 0.02 , 0.0225 , 0.025 , 0.0275 , 0.03 , 0.0325 , 0.035 , 0.0375 , 0.04 , 0.0425 , 0.045 , 0.0475 , 0.05 , 0.0525 , 0.055 , 0.0575 , 0.06 , 0.0625 , 0.065 , 0.0675 , 0.07 , 0.0725 , 0.075 , 0.0775 , 0.08 , 0.0825 , 0.085 , 0.0875 , 0.09 , 0.0925 , 0.095 , 0.0975 , 0.1 , //80 //0.0025/perbin
      0.13 , 0.16 , 0.19 , 0.22 , 0.25 , 0.28 , 0.31 , 0.34 , 0.37 , 0.4 , 0.43 , 0.46 , 0.49 , 0.52 , 0.55 , 0.58 , 0.61 , 0.64 , 0.67 , 0.7 , 0.73 , 0.76 , 0.79 , 0.82 , 0.85 , 0.88 , 0.91 , 0.94 , 0.97 , 1 //30 //0.03cm/perbin
   };

}
#endif
