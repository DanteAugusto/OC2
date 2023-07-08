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
    sc_signal<bool> eop;
    sc_signal<bool> bop; //faca na caveira
    sc_signal<sc_bv> rib; //3 bits
    

    sc_in<sc_bv> in_data; //34 bits
    sc_in<bool> in_val;
    sc_out<bool> in_ack;


    // saídas para o árbitro
    sc_out<bool> arb1;
    sc_out<bool> arb2;
    sc_out<bool> arb3;


    // vêm do chaveamento
    sc_in<bool> readOk1;
    sc_in<bool> readOk2;
    sc_in<bool> readOk3;
    
    // o buffer
    sc_bv memo[4];
    buffer bf("bf");
    bf.memo("memo");
    bf.eop("eop");
    bf.bop("bop");
    bf.rib("rib");
    
    // o roteamento
    sc_out<bool> arb1;
    sc_out<bool> arb2;
    sc_out<bool> arb3;
    sc_uint<2> requisitionPos; //2 bits
    bool switching;
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
