import FWCore.ParameterSet.Config as cms

tracktriggerPhase2Layer1Digis = cms.EDProducer(
    "L1TPhase2Layer1Producer",
    verbosity = cms.int32(2),
    bxFirst    = cms.int32(0),
    bxLast     = cms.int32(0),
    #ecalToken = cms.InputTag("ecalDigis:EcalTriggerPrimitives"),
    #hcalToken = cms.InputTag("hcalDigis"),
    firmware = cms.int32(1)
)
