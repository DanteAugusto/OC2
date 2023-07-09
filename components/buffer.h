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


    void consuming(){
        if(rd.read()){
            qtt = qtt - 1;
            idxb++;
        }
    }
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
        SC_METHOD(consuming);
		sensitive << rd;
        SC_METHOD(hasSomething);
		sensitive << clk;
        SC_METHOD(storing);
		sensitive <<in_val;
        SC_METHOD(dataOut);
		sensitive << clk;
        
    }
};
