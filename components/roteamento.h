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

    sc_in<sc_uint<34>> in_data;
    sc_out<sc_uint<34>> out_data;
    sc_signal<bool> eop;
    sc_signal<bool> bop; //faca na caveira
    sc_signal<sc_uint<3>> rib; //3 bits

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
                if(rib.read() == 0){
                    requisitionPos = 0;
                    arbL.write(true);
                    arbA.write(false);
                    arbH.write(false);
                    arbT.write(false);
                }else if(rib.read() == 1 || rib.read() == 2){
                    requisitionPos = 1;
                    arbH.write(true);
                    arbA.write(false);
                    arbL.write(false);
                    arbT.write(false);
                }else if(rib.read() == 3 || rib.read() == 4 || rib.read() == 5){
                    requisitionPos = 2;
                    arbT.write(true);
                    arbA.write(false);
                    arbH.write(false);
                    arbL.write(false);
                }else if(rib.read() == 6 || rib.read() == 7){
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
        std::bitset<34> data = std::bitset<34>(in_data.read());

        eop.write() = data[0];
        bop.write() = data[1];
        rib.write() = (data[31]? 1 : 0) + (data[32]? 2 : 0) + (data[33]? 4 : 0);
    }
    void dataOut(){
        sc_uint<34> changeData = in_data.read();
        if(bop.read()){
            sc_uint<3> changeRib = rib;
            if(rib == 1){
                changeRib = 0;
            }else if(rib == 2){
                changeRib = 1;
            }else if(rib == 3){
                changeRib = 7;
            }else if(rib == 4){
                changeRib = 0;
            }else if(rib == 5){
                changeRib = 1;
            }else if(rib == 6){
                changeRib = 7;
            }else if(rib == 7){
                changeRib = 0;
            }
            std::bitset<34> data = std::bitset<34>(changeData);
            std::bitset<3> rib = std::bitset<3>(changeRib);
            Data[32] = Rib[1];
            Data[31] = Rib[0];
            Data[33] = Rib[2];
            changeData = sc_uint<34>(Data);
        }
        out_data.write(changeData);
    }
    SC_CTOR(roteamento) {
        switching = false;
        requisitionPos = 0;
        SC_METHOD(consuming);
        sensitive << << readOkL << readOkH << readOkA << readOkT;
    }
};
