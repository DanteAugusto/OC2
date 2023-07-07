#include <systemc.h>
#include <iostream>
#include <bitset> 
#include <unistd.h>
#include "buffer.h"
#include "roteamento.h"
SC_MODULE(entrada) {
    sc_in<bool> clk;
    // vai ter:
    // fios internos:
    sc_signal<sc_uint<1>> eop;
    sc_signal<sc_uint<1>> bop; //faca na caveira
    sc_signal<sc_uint<3>> rib;
    
    
    // o fluxo de entrada
    
    // o buffer
    std::queue<sc_uint<34>> memo;
    buffer bf("bf");
    bf.memo("memo");
    bf.eop("eop");
    bf.bop("bop");
    bf.rib("rib");
    
    // o roteamento
    sc_out<sc_uint<1>> arb1;
    sc_out<sc_uint<1>> arb2;
    sc_out<sc_uint<1>> arb3;
    sc_uint<2> requisitionPos;
    sc_uint<1> switching;
    roteamento rtmnt("rtmnt")
    rtmnt.arb1("arb1")
    rtmnt.arb2("arb2")
    rtmnt.arb3("arb3")
    rtmnt.requisitionPos("requisitionPos")
    rtmnt.switching("switching")

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
    SC_CTOR(entrada) {
        SC_METHOD(compute);
    }
};