///
/// \class l1t::Phase2MainProcessor
///
/// Description: interface for the main processor
///
/// Implementation:
///
/// \author: Tom James
///

#ifndef Phase2MainProcessor_h
#define Phase2MainProcessor_h

#include "CondFormats/L1TObjects/interface/TrackTriggerParams.h"
#include "DataFormats/L1TrackTrigger/interface/Cell.h"

namespace l1t {
    
  class Phase2MainProcessor { 
  public:
    virtual void processEvent(
    const std::vector<l1t::Stub> & inStubs,
    std::vector<l1t::Stub> & outStubs
    ) = 0;    

    virtual ~Phase2MainProcessor(){};

  }; 
  
} 

#endif
