#include <systemc.h>
#include <iostream>
#include <bitset> 
#include<unistd.h>
SC_MODULE(roteamento) {
    sc_in<bool> clk;


    sc_out<bool> arbA;
    sc_out<bool> arbH;
    sc_out<bool> arbT;
    sc_out<bool> arbL;

    sc_out<bool> consume;


    sc_in<bool> rok;
    sc_in<bool> readOkA;
    sc_in<bool> readOkH;
    sc_in<bool> readOkT;
    sc_in<bool> readOkL;
    

    sc_uint<2> requisitionPos; //2 bits
    bool switching;

    sc_in<sc_bv<34>> in_data;
    sc_out<sc_bv<34>> out_data;
    sc_signal<bool> eop;
    sc_signal<bool> bop; //faca na caveira
    sc_signal<sc_bv<3>> rib; //3 bits

    void consuming(){
        if(switching &&((requisitionPos == 0 && readOkL.read()) || 
                        (requisitionPos == 1 && readOkH.read()) ||
                        (requisitionPos == 2 && readOkT.read()) ||
                        (requisitionPos == 3 && readOkA.read()))){
            consume.write(true);
        }else{
            consume.write(false);
        }
    }
    void routing(){
        if(!switching){
            if(rok.read()){
                if(rib == "000"){
                    requisitionPos = 0;
                    arbL.write(true);
                    arbA.write(false);
                    arbH.write(false);
                    arbT.write(false);
                }else if(rib == "001" || rib == "010"){
                    requisitionPos = 1;
                    arbH.write(true);
                    arbA.write(false);
                    arbL.write(false);
                    arbT.write(false);
                }else if(rib == "011" || rib == "100" || rib == "101"){
                    requisitionPos = 2;
                    arbT.write(true);
                    arbA.write(false);
                    arbH.write(false);
                    arbL.write(false);
                }else if(rib == "110" || rib == "111"){
                    requisitionPos = 3;
                    arbA.write(true);
                    arbL.write(false);
                    arbH.write(false);
                    arbT.write(false);
                }
                if(bop)switching = true;
            }
        }else{
            if(eop)switching = false;
        }
    }
    void dataing(){
        eop = in_data.read()[0];
        bop = in_data.read()[1];
        rib[0] = memo[idxb][31];
        rib[1] = memo[idxb][32];
        rib[2] = memo[idxb][33];
    }
    void dataOut(){
        sc_signal<sc_bv<34>> changeData = in_data.read();
        if(bop){
            if(requisitionPos == 1){
                sc_signal<sc_bv<3>> changeRib = rib;
                if(changeRib == "001"){
                    changeRib = "000";
                }else if(changeRib == "010"){
                    changeRib = "001";
                }
            }else if(requisitionPos == 2){
                if(changeRib == "011"){
                    changeRib = "111";
                }else if(changeRib == "100"){
                    changeRib = "000";
                }else if(changeRib == "101"){
                    changeRib = "001";
                }
            }else if(requisitionPos == 3){
                if(changeRib == "110"){
                    changeRib = "111";
                }else if(changeRib == "111"){
                    changeRib = "000";
                }
            }
            changeData[32] = changeRib[1];
            changeData[31] = changeRib[0];
            changeData[33] = changeRib[2];
        }
        out_data.write(changeData);
    }
    SC_CTOR(roteamento) {
        switching = false;
        requisitionPos = 0;
        SC_METHOD(consuming);
        sensitive << swtching << requisitionPos << readOkL << readOkH << readOkA << readOkT;
    }
};
