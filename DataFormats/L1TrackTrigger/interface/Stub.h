#ifndef DataFormats_L1TrackTrigger_Stub_h
#define DataFormats_L1TrackTrigger_Stub_h

//#include "DataFormats/L1TrackTrigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

namespace l1t {
  class Cell;
  class Stub;
  typedef BXVector<Stub> StubBxCollection;
    typedef BXVector<Stub> OutStubBxCollection;
    
        class Stub{


    
 public:    

  
    
  Stub(
                unsigned int S=0,
               int phiS=0,
               int rT=0,
               int z=0,
         int dphi=0,
         unsigned int rho=0,
         int dphi_reduced=0,
          unsigned int m_bin=0,
          unsigned int c_bin=0

         );
    
  ~Stub();

	void setS(unsigned int et) { S_ = et;}
  void setphiS( int et) { phiS_ = et;}
  void setrT( int et ) { rT_ = et;}
  void setz( int et ) { z_ = et;}
  void setdphi( int et ) { dphi_ = et;}
  void setrho(unsigned int et) { rho_ = et;}
void setdphi_reduced(int et) { dphi_reduced_ = et;}
  void setm_bin(unsigned int et) { m_bin_ = et;}
  void setc_bin(unsigned int et) { c_bin_ = et;}


    unsigned int S()            const{   return S_;     }
  int phiS()           const{   return phiS_;    }
  int rT()              const{   return rT_;       }
  int z()           const{   return z_;    }
  int dphi()             const{   return dphi_;      }
 unsigned  int rho()           const{   return rho_;     }
  int dphi_reduced()        const{   return dphi_reduced_; }
  unsigned int m_bin()            const{   return m_bin_;     }
 unsigned int c_bin()            const{   return c_bin_;     }




 private:
  
   unsigned int S_;
  int phiS_;
  int rT_;
  int z_; 
  int dphi_;
  unsigned int rho_;
  int dphi_reduced_;
  unsigned int m_bin_;
  unsigned int c_bin_;

  
};
  }


#endif
 
