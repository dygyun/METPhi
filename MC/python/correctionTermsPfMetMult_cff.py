import FWCore.ParameterSet.Config as cms

##____________________________________________________________________________||
from JetMETCorrections.Type1MET.pfMETmultShiftCorrections_cfi import *

##____________________________________________________________________________||
corrPfMetMult = pfMETMultShiftCorr.clone()
#corrPfMetXYMult = pfMETMultShiftCorr.clone()

##____________________________________________________________________________||
correctionTermsPfMetMult = cms.Sequence(
    corrPfMetMult
    #corrPfMetXYMult
    )
##__________________________________________________
#corrPfMetMult = pfMETMultShiftCorr.clone()

#correctionTermsPfMetMult = cms.Sequence(
#    corrPfMetMult
#   )

pfMETMultShiftCorrSequence = cms.Sequence(
   #pfMEtMultShiftCorr 
    pfMETMultShiftCorr
    )


##____________________________________________________________________________||
