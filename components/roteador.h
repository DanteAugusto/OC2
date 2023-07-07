#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
//[0000][100100][000100]
SC_MODULE(roteador) {

    // exemplos de como inicializar fios
    // sc_in<sc_uint<32>> op1;
    // sc_in<sc_uint<32>> op2;
    // // sc_in<sc_int<32>> value;
    // sc_in<sc_uint<4>> opcode;
    // sc_out<sc_uint<1>> confirmPC;
    // // sc_out<sc_int<5>> resultPC;
    // sc_out<sc_uint<32>> result;
    SC_CTOR(roteador) {
        SC_METHOD(compute);
        sensitive << op1 << op2 << opcode;
    }
};
