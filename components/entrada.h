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
    sc_signal<bool> rok;
    sc_signal<bool> rd;
    

    sc_in<sc_uint<34>> in_data; //34 bits
    sc_out<sc_uint<34>> out_data; //34 bits
    sc_in<bool> in_val;
    sc_out<bool> in_ack;


    // saídas para o árbitro
    sc_out<bool> arbL;
    sc_out<bool> arbA;
    sc_out<bool> arbH;
    sc_out<bool> arbT;


    // vêm do chaveamento
    sc_in<bool> readOkL;
    sc_in<bool> readOkA;
    sc_in<bool> readOkH;
    sc_in<bool> readOkT;
    
    // o buffer
    sc_uint<34> memo[4];
    buffer bf;
    
    // o roteamento
    sc_uint<2> requisitionPos; //2 bits
    bool switching;
    roteamento rtmnt;

    SC_CTOR(entrada) : bf("bf"), rtmnt("rtmnt") {
        rok.write(false);
        rd.write(false);
        bf.clk(clk);
        bf.in_val(in_val);
        bf.in_ack(in_ack);
        bf.in_data(in_data);
        bf.out_data(out_data);
        bf.rok(rok);
        bf.rd(rd);


        rtmnt.clk(clk);
        rtmnt.readOkA(readOkA);
        rtmnt.readOkH(readOkH);
        rtmnt.readOkT(readOkT);
        rtmnt.readOkL(readOkL);
        rtmnt.in_data(in_data);
        rtmnt.out_data(out_data);
    }
};
