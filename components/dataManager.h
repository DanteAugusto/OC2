#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
SC_MODULE(dataManager) {
    sc_in<sc_uint<2>> pos;
    sc_in<sc_bv<34>> in_data1;
    sc_in<sc_bv<34>> in_data2;
    sc_in<sc_bv<34>> in_data3;
    sc_out<sc_bv<34>> out_data;


    void dataOut(){
        if(pos.read() == 1){
            out_data.write(in_data1.read())
        }
        else if(pos.read() == 2){
            out_data.write(in_data2.read())
        }
        else if(pos.read() == 3){
            out_data.write(in_data3.read())
        }
    }
    SC_CTOR(dataManager) {
        SC_METHOD(dataOut);
		sensitive << pos;
        

    }
};
