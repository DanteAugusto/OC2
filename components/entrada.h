#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
SC_MODULE(entrada) {
    sc_in<bool> clk;
    // vai ter:
    // o fluxo de entrada
    // o buffer
    std::queue<sc_uint<32>> buffer;
    // o roteamento

    // exemplos de como inicializar fios
    // sc_in<sc_uint<32>> op1;
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
