#!/bin/sh
if [ -n "$1" ]; then
    argum=$1
  else
    argum="tmp"
fi
outputTextFile="multPhiCorr_${argum}_cfi.py"
rm -rf $outputTextFile
echo "import FWCore.ParameterSet.Config as cms">>$outputTextFile
echo "multPhiCorr_${argum} = cms.VPSet(">>$outputTextFile
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./hEtaPlus_DYmult.pdf" --map=hEtaPlus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,500 --rebin=0 --yZoomRange=-5,5 --xZoomRange=0,800
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./hEtaMinus_DYmult.pdf" --map=hEtaMinus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,500 --rebin=0 --yZoomRange=-5,5 --xZoomRange=0,800
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./h0Barrel_DYmult.pdf" --map=h0Barrel --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,30  --rebin=0 --yZoomRange=-3,3 --xZoomRange=0,50
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./h0EndcapPlus_DYmult.pdf" --map=h0EndcapPlus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,55 --rebin=0 --yZoomRange=-3,3 --xZoomRange=0,50
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./h0EndcapMinus_DYmult.pdf" --map=h0EndcapMinus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,50 --rebin=0 --yZoomRange=-3,3 --xZoomRange=0,50
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./gammaBarrel_DYmult.pdf" --map=gammaBarrel --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,250 --rebin=0 --yZoomRange=-2,2 --xZoomRange=0,500
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./gammaEndcapPlus_DYmult.pdf" --map=gammaEndcapPlus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,80 --yZoomRange=-3,3 --xZoomRange=0,100
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./gammaEndcapMinus_DYmult.pdf" --map=gammaEndcapMinus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,70 --yZoomRange=-3,3 --xZoomRange=0,100
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./h_HF_Plus_DYmult.pdf" --map=h_HF_Plus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=20,250 --rebin=0 --yZoomRange=-4,4 --xZoomRange=0,300
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./h_HF_Minus_DYmult.pdf" --map=h_HF_Minus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,250 --rebin=0 --yZoomRange=-4,4 --xZoomRange=0,300
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./egamma_HF_Plus_DYmult.pdf" --map=egamma_HF_Plus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,170 --rebin=0 --yZoomRange=-4,4 --xZoomRange=0,300
python multiplicityFit.py --textFileName=$outputTextFile --input=histo_25ns_runD.root --rootGDir=metPhiCorrInfoWriter --plotFileName="./egamma_HF_Minus_DYmult.pdf" --map=egamma_HF_Minus --mode=multiplicity --func='(x*[0]+x**2*[1])' --fitRange=0,180 --rebin=0 --yZoomRange=-4,4 --xZoomRange=0,300
echo ")">>$outputTextFile
echo "Outputs written to: $outputTextFile"
