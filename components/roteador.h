#include <systemc.h>
#include <iostream>
#include <bitset> 
#include <unistd.h>
#include "entrada.h"
#include "saida.h"


SC_MODULE(roteador) {
    entrada in1("in1");
    entrada in2("in2");
    entrada in3("in3");
    entrada in4("in4");

    saida out1("out1");
    saida out2("out2");
    saida out3("out3");
    saida out4("out4");
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
