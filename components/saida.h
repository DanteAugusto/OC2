#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
#include "arbitragem.h"
#include "dataManager.h"
SC_MODULE(saida) {
    sc_in<bool> clk;

    sc_in<bool> rotmn1;
    sc_in<bool> rotmn2;
    sc_in<bool> rotmn3;


    sc_in<sc_uint<34>> in_data1;
    sc_in<sc_uint<34>> in_data2;
    sc_in<sc_uint<34>> in_data3;
    sc_out<sc_uint<34>> out_data;

    sc_out<bool> out_val;
    sc_in<bool> out_ack;
    sc_out<bool> x_rd;


    sc_signal<sc_uint<2>> pos;

    arbitragem arb;    
    dataManager dM;    

    SC_CTOR(saida) : arb("arb"), dM("dM") {
        pos.write(0);
        arb.rotmn1(rotmn1);
        arb.rotmn2(rotmn2);
        arb.rotmn3(rotmn3);
        arb.clk(clk);
        arb.pos(pos);
        arb.eop(out_data);
        arb.val(out_val);

        dM.pos(pos);
        dM.in_data1(in_data1);
        dM.in_data2(in_data2);
        dM.in_data3(in_data3);
        dM.out_data(out_data);
    }
};
