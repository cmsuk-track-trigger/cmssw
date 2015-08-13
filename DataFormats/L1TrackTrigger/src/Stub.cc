#include "DataFormats/L1TrackTrigger/interface/Stub.h"




l1t::Stub::Stub(
                                unsigned int S,
                                int phiS,
                                int rT,
                                int z,
        int dphi,
        unsigned int rho,
        int dphi_reduced,
        unsigned int m_bin,
        unsigned int c_bin

                                )
  : 
    S_(S),
    phiS_(phiS),
    rT_(rT),
    z_(z),
    dphi_(dphi),
    rho_(rho),
    dphi_reduced_(dphi_reduced),
    m_bin_(m_bin),
    c_bin_(c_bin)

{
  
}

l1t::Stub::~Stub() 
{

}

 
