#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
SC_MODULE(buffer) {
    sc_in<bool> clk;
    std::queue<sc_uint<34>> memo;
    sc_out<sc_uint<1>> eop;
    sc_out<sc_uint<1>> bop; //faca na caveira
    sc_out<sc_uint<3>> rib;


    // racunho:
    // std::bitset<25> instruc = std::bitset<25>(inst.read());
    // unsigned int x = 0;
    // for(int i = 9; i < 25; i++){
    //     x |= (instruc[24-i] ? 1 : 0) << (15-(i-9));        
    // }
    // // std::cout << "x do write " << std::bitset<16>(x) << std::endl;
    // x = (x << 16) + x;
    // // std::cout << "x duplicado do write " << std::bitset<32>(x) << std::endl;
    SC_CTOR(buffer) {
        SC_METHOD(compute);
    }
};
