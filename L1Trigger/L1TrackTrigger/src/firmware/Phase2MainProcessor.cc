///
/// \class l1t::Phase2Layer2MainProcessorFirmware
///
/// \author: Tom James
///
/// Description: first iteration of phase 2 processing

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "L1Trigger/L1TrackTrigger/interface/Phase2MainProcessorFirmware.h"
#include "L1Trigger/L1TrackTrigger/interface/Phase2TrackTrigger.h"

#include "CondFormats/L1TObjects/interface/TrackTriggerParams.h"

using namespace std;

l1t::Phase2MainProcessorFirmware::Phase2MainProcessorFirmware
(unsigned fwv, TrackTriggerParams* params) :
  m_params(params)
{
	m_trackTrigger = new Phase2TrackTriggerFirmware(m_params);
}

l1t::Phase2MainProcessorFirmware::~Phase2MainProcessorFirmware()
{ 

};

void l1t::Phase2MainProcessorFirmware::processEvent(
const std::vector<l1t::Stub> & inStubs,
std::vector<l1t::Stub> & outStubs
) { 
  m_trackTrigger->processEvent(inStubs, outStubs);
}


void l1t::Phase2MainProcessorFirmware::print(std::ostream& out) const {

  out << " Track Trigger Phase 2 Main Processor" << std::endl;
    out << "  Track Trigger        : " << (m_trackTrigger?1:0) << std::endl;

}

