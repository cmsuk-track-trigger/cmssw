///
/// Description: Firmware header Track Trigger
///
///
/// \author: Tom James
///

#ifndef Phase2TrackTriggerFirmware_H
#define Phase2TrackTriggerFirmware_H

#include "L1Trigger/L1TrackTrigger/interface/Phase2TrackTrigger.h"
#include "CondFormats/L1TObjects/interface/TrackTriggerParams.h"


namespace l1t {

class Phase2TrackTriggerFirmware;
  class Phase2TrackTriggerFirmware : public Phase2TrackTrigger {
  
 std::vector<int> m_axis_max_;
 std::vector<int> m_axis_min_;
 std::vector<int> m_axis_av_;

std::vector<unsigned int> c_axis_max_;
std::vector<unsigned int> c_axis_min_;
std::vector<unsigned int> c_axis_av_;

int T_;

  public:
    Phase2TrackTriggerFirmware(TrackTriggerParams* params);
    virtual ~Phase2TrackTriggerFirmware();
    virtual void processEvent(const std::vector<l1t::Stub> & stubs, 
    std::vector<l1t::Stub> & outstubs);

void readout_cell(Cell cell, int x, int y, std::vector<l1t::Stub> outstubs){

if (cell.ram_stubs.size() > 4){

//Should be fixed to match firmware marking of cell
if(rbin_calc(cell.ram_stubs)){

std::cout << "candidate found at x = " <<  x << " y = " << y << std::endl;
std::cout << "stub list: phiS: dphi: z: rT" << std::endl;

for (unsigned int cand_stub=0; cand_stub < cell.ram_stubs.size(); ++cand_stub){
std::cout << cell.ram_stubs.back().phiS() << "\t" << cell.ram_stubs.back().dphi() << "\t" <<
cell.ram_stubs.back().z() << "\t" << cell.ram_stubs.back().rT() << std::endl;
}
}
}

for (unsigned int segment=0; segment<64; ++segment){
for (unsigned int int_stub=0; int_stub<cell.ram_stubs.size(); ++int_stub){

if(cell.ram_stubs.at(int_stub).S()==segment){
outstubs.push_back(cell.ram_stubs.at(int_stub));
}

}
}
}

bool bend_filter(Cell cell, Stub stub, const int T)
{
int test = 1024*stub.dphi() - (stub.rT()+T)*cell.mav();
if (std::abs(test) < 1024*stub.rho()){
return true;
}
return false;
}

bool nw_cell_entry(Cell cell, Stub stub)
{
int test_min = 64*stub.phiS() + (stub.rT())*(cell.mmin());
int test_max = stub.phiS() + (stub.rT())*(cell.mmax());
if(test_max > int(32*cell.cmax()) && test_max < int(32*cell.cmax()) && stub.rT() > 0
&& !(test_min> int(32*cell.cmin()) && test_min > int(32*cell.cmax()))){
return true;
}
return false;
}

bool w_cell_entry(Cell cell, Stub stub)
{
int test_max = 64*stub.phiS() + (stub.rT())*(cell.mmax());
if((test_max> int(32*cell.cmin()) && test_max< int(32*cell.cmax()))){
return true;
}
return false;
}

bool sw_cell_entry(Cell cell, Stub stub)
{
int test_min = 64*stub.phiS() + (stub.rT())*(cell.mmin());
int test_max = 64*stub.phiS() + (stub.rT())*(cell.mmax());
if(test_max > int(32*cell.cmax()) && test_max < int(32*cell.cmax()) && stub.rT() < 0
&& !(test_min> int(32*cell.cmin()) && test_min > int(32*cell.cmax()))){ 
return true;
}
return false;
}

bool rbin_calc(std::vector<Stub> stubs){
std::vector<int> r_register(15, 0);

for(unsigned int stub =0; stub<stubs.size(); ++stub){

int r_dsp=295*stubs[stub].rT()+2200;

if (r_dsp < -24619 ){r_register[0]=1; continue;}
if (r_dsp < -20489 ){r_register[1]=1; continue;}
if (r_dsp < -16654 ){r_register[2]=1; continue;}
if (r_dsp < -12524 ){r_register[3]=1; continue;}
if (r_dsp < -8394 ){r_register[4]=1; continue;}
if (r_dsp < -4264 ){r_register[5]=1; continue;}
if (r_dsp < -134 ){r_register[6]=1; continue;}
if (r_dsp < 3996 ){r_register[7]=1; continue;}
if (r_dsp < 8126 ){r_register[8]=1; continue;}
if (r_dsp < 12256 ){r_register[9]=1; continue;}
if (r_dsp < 16091 ){r_register[10]=1; continue;}
if (r_dsp < 20221 ){r_register[11]=1; continue;}
if (r_dsp < 24351 ){r_register[12]=1; continue;}
if (r_dsp < 28481 ){r_register[13]=1; continue;}
if (r_dsp < 32611 ){r_register[14]=1; continue;}
if (r_dsp < 36741 ){r_register[15]=1; continue;}

std::cout << "ERROR: r_dsp outside range" << std::endl;

}
if (std::accumulate(r_register.begin(), r_register.end(), 0) > 4){
return true;}
return false;
}

unsigned int r_inv(int r){
if(r==0){
return 131072;
}else{
double r_inv = 65536*(1/r);
unsigned int r_inv_int = int(65536*(1/r));
if(r_inv-double(r_inv_int) <! 0.5 && r>0){++r_inv_int;}
if(r_inv-double(r_inv_int) < 0.5 && r<0){--r_inv_int;}
return r_inv_int;
}
}
private:
TrackTriggerParams* params_;

     
  };
  
}

#endif
