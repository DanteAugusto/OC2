#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
SC_MODULE(roteamento) {
    sc_in<bool> clk;
    sc_out<sc_uint<1>> arb1;
    sc_out<sc_uint<1>> arb2;
    sc_out<sc_uint<1>> arb3;

    sc_uint<2> requisitionPos;
    sc_uint<1> switching;

    sc_in<sc_uint<1>> eop;
    sc_in<sc_uint<1>> bop; //faca na caveira
    sc_in<sc_uint<3>> rib;


    // racunho:
    // std::bitset<25> instruc = std::bitset<25>(inst.read());
    // unsigned int x = 0;
    // for(int i = 9; i < 25; i++){
    //     x |= (instruc[24-i] ? 1 : 0) << (15-(i-9));        
    // }
    // // std::cout << "x do write " << std::bitset<16>(x) << std::endl;
    // x = (x << 16) + x;
    // // std::cout << "x duplicado do write " << std::bitset<32>(x) << std::endl;
    // op2Out.write(x);
    // exemplos de como inicializar fios
    // sc_in<sc_uint<32>> op2;
    // // sc_in<sc_int<32>> value;
    // sc_in<sc_uint<4>> opcode;
    // sc_out<sc_uint<1>> confirmPC;
    // // sc_out<sc_int<5>> resultPC;
    // sc_out<sc_uint<32>> result;
    SC_CTOR(roteamento) {
        SC_METHOD(compute);
    }
};
