#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
SC_MODULE(arbitragem) {    
    sc_in<bool> clk;

    
    sc_uint<2> requisitionPos; //2 bits
    bool switching;
    

    sc_out<sc_uint<2>> pos;//2 bits
    

    sc_in<bool> rotmn1;
    sc_in<bool> rotmn2;
    sc_in<bool> rotmn3;
    

    sc_in<sc_uint<34>> eop; //olhar apenas o primeiro bit


    sc_out<bool> val;
    
    void chaveamento(){
        if(clk){
            std::bitset<34> realEop = std::bitset<34>(eop.read());
            if(switching && realEop[0]){
                switching = false;
            }else if((requisitionPos == 1 && rotmn1.read()) || 
                     (requisitionPos == 2 && rotmn2.read()) || 
                     (requisitionPos == 3 && rotmn3.read())){
                switching = true;
            }
        }
    }    
    void posUpdate(){
        if(clk){
            requisitionPos = (requisitionPos+1)%4;
        }
    }
    void outPos(){
        pos.write(requisitionPos);
    }
    void outVal(){
        if((requisitionPos == 1 && rotmn1.read()) || 
           (requisitionPos == 2 && rotmn2.read()) || 
           (requisitionPos == 3 && rotmn3.read())){
            val.write(true);
        }else{
            val.write(false);
        }
    }


    SC_CTOR(arbitragem) {
        requisitionPos = 0;
        switching = false;
        SC_METHOD(chaveamento);
		sensitive << clk;
        SC_METHOD(posUpdate);
		sensitive << clk;
        SC_METHOD(outPos);
		sensitive << clk;
        SC_METHOD(outVal);
		sensitive << rotmn1 << rotmn2 << rotmn3;
        
        // funções eternas
    }
};
