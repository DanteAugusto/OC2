#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
SC_MODULE(buffer) {
    sc_in<bool> clk;



    sc_bv<34> memo[4];
    sc_uint<2> idxb;
    sc_uint<3> qtt;
    sc_in<sc_bv<34>> in_data; //34 bits
    sc_out<sc_bv<34>> out_data; //34 bits


    sc_in<bool> in_val;
    sc_out<bool> in_ack;


    sc_out<bool> rok;
    sc_in<bool> rd;


    // vão para o roteamento
    // sc_out<bool> eop;
    // sc_out<bool> bop; //faca na caveira
    // sc_out<sc_bv<3>> rib; //3 bits

    void consuming(){
        if(rd.read()){
            qtt = qtt - 1;
            idxb++;
        }

    }
    // void infoRouding(){
    //     eop.write(memo[idxb][0]);
    //     eop.write(memo[idxb][1]);
    //     sc_bv<3> toRib;
    //     toRib[0] = memo[idxb][31];
    //     toRib[1] = memo[idxb][32];
    //     toRib[2] = memo[idxb][33];
    //     rib.write(toRib);
    //     rok.write(in_val.read());
    // }
    void hasSomething(){
        rok.write(qtt> 0);
    }
    void storing(){
        if(qtt < 4 && in_val.read()){
            memo[(idxb+qtt) % 4] = in_data.read();
            qtt++;
            in_ack.write(true);
        }
    }
    void dataOut(){
        out_data.write(memo[idxb]);
    }
    SC_CTOR(buffer) {
        idxb = 0;
        qtt = 0;
        SC_METHOD(compute);
    }
};
