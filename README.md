##D<sup>0</sup> Spectra and Nuclear Modification Factor Analysis
LBNL - STAR Experiment, Relativistic Heavy Ion Collider (RHIC), BNL  
RHIC year 2014 Run, with Heavy Flavor Tracker
  
###Code Authors:  
	Guannan Xie (guannanxie@lbl.gov)  
	Mustafa Mustafa (mmustafa@lbl.gov)  

- - -
### Pico production monitors:
[Pico production monitor](http://portal.nersc.gov/project/star/mustafa/picoProductionMonitor/)  
[Pico D0 production monitor](http://www.star.bnl.gov/protected/heavy/mstftsm/run14/picoD0ProductionMonitor/)  
- - -
### Presentations:  
#### STAR Protected:  
- [Introduction to data production and pipeline](http://www.star.bnl.gov/protected/heavy/mstftsm/run14/talks/2015-04-02.pdf), Mustafa, HF PWG, 2015-04-02  
- [D0 Production for Run14 AuAu200 GeV](https://drupal.star.bnl.gov/STAR/system/files/2015May14_Run14_200GeV_D0_HF.pdf), Guannan, HF PWG, 2015-05-14  
- [D0 analysis status](https://drupal.star.bnl.gov/STAR/system/files/2015May18_Run14_200GeV_D0_SoftHadron.pdf), Guannan, Soft Hadron, 2015-05-18  
- [D0 Production for Run14 AuAu200 GeV (update)](https://drupal.star.bnl.gov/STAR/system/files/2015June2_Run14_200GeV_D0_STARCollMeeting.pdf), Guannan, Collaboration meeting, 2015-06-02  

- - -
### Preliminary results:
![](PR_D0_official.png)

- - -
###How to build this code:  
```bash
mkdir myAnalysis
cd myAnalysis

# Replace address below with your own fork if you have one
git clone git@github.com:MustafaMustafa/auau200GeVRun14Ana.git

# Clone LBNL PicoHFLib
git clone git@github.com:rnc-lbl/auau200GeVRun14.git

# Now you need to get StPicoDstMaker
# If compiling at PDSF you need to get a klog token as below.
# - You don't need this step at RCF - 
# You will need to enter your RCF password.
klog -principal YOURRCFUSERNAME
cvs co -r Run14_AuAu200_physics2 offline/users/dongx/pico/source/StPicoDstMaker

# Clone StRefMultCorr
git clone git@github.com:GuannanXie/Run14AuAu200GeV_StRefMultCorr.git

# Link all needed code under one StRoot directory:
mkdir StRoot
ln -s `pwd`/auau200GeVRun14Ana/StRoot/StPicoD0AnaMaker StRoot
ln -s `pwd`/auau200GeVRun14/StRoot/StPicoD0EventMaker StRoot
ln -s `pwd`/auau200GeVRun14/StRoot/StPicoPrescales StRoot
ln -s `pwd`/offline/users/dongx/pico/source/StPicoDstMaker StRoot
ln -s `pwd`/Run14AuAu200GeV_StRefMultCorr/VPDMB5/StRefMultCorr StRoot
ln -s `pwd`/auau200GeVRun14/StRoot/StPicoKFVertexFitter StRoot
cp -r -p auau200GeVRun14/run14AuAu200GeVPrescales/ .

# Compile
starver SL15c
cons
```

###How to get a list of files:  
```bash
# Clone the file list repo:
git clone git@github.com:rnc-lbl/fileLists.git

# The list of daily D0 production will be under:
ls fileLists/Run14/AuAu/200GeV/physics2/picoD0Lists/daily

# To update your local copy of the list of files (recommended to do daily):
git pull origin master
```

###How to run this code:  
```bash
# For testing we can run the code on one file:
tail -n1 fileLists/Run14/AuAu/200GeV/physics2/picoD0Lists/daily/picoD0List_2015-05-21.list > test.list
ln -s `pwd`/auau200GeVRun14Ana/StRoot/macros/runPicoD0AnaMaker.C
root4star -l -b -q -x runPicoD0AnaMaker.C\(\"test.list\",\"test_out\"\)
```

###How to submit jobs:
```bash
# You cah find STAR Scheduler XML file under:
cp -p auau200GeVRun14/starSubmit/submitPicoD0AnaMaker.xml .
# auau200GeVRun14/starSubmit/uREADME contains a how to use.
```
