#include <systemc.h>
#include <bits/stdc++.h>
#include <map>
#include <bitset>
#include<unistd.h>
#include "roteador.h"

int sc_main(int argc, char* argv[]){
    sc_signal<bool> clk;
    clk.write(true);
    sc_signal<sc_bv<34>>1to2 = "0000000000000000000000000000000000";
    sc_signal<bool>val1to2 = false;
    sc_signal<bool>ack1to2 = false;
    sc_signal<sc_bv<34>>1to5 = "0000000000000000000000000000000000";
    sc_signal<bool>val1to5 = false;
    sc_signal<bool>ack1to5 = false;
    sc_signal<sc_bv<34>>1to8 = "0000000000000000000000000000000000";
    sc_signal<bool>val1to8 = false;
    sc_signal<bool>ack1to8 = false;
    sc_signal<sc_bv<34>>2to1 = "0000000000000000000000000000000000";
    sc_signal<bool>val2to1 = false;
    sc_signal<bool>ack2to1 = false;
    sc_signal<sc_bv<34>>2to3 = "0000000000000000000000000000000000";
    sc_signal<bool>val2to3 = false;
    sc_signal<bool>ack2to3 = false;
    sc_signal<sc_bv<34>>2to6 = "0000000000000000000000000000000000";
    sc_signal<bool>val2to6 = false;
    sc_signal<bool>ack2to6 = false;
    sc_signal<sc_bv<34>>3to2 = "0000000000000000000000000000000000";
    sc_signal<bool>val3to2 = false;
    sc_signal<bool>ack3to2 = false;
    sc_signal<sc_bv<34>>3to4 = "0000000000000000000000000000000000";
    sc_signal<bool>val3to4 = false;
    sc_signal<bool>ack3to4 = false;
    sc_signal<sc_bv<34>>3to7 = "0000000000000000000000000000000000";
    sc_signal<bool>val3to7 = false;
    sc_signal<bool>ack3to7 = false;
    sc_signal<sc_bv<34>>4to3 = "0000000000000000000000000000000000";
    sc_signal<bool>val4to3 = false;
    sc_signal<bool>ack4to3 = false;
    sc_signal<sc_bv<34>>4to5 = "0000000000000000000000000000000000";
    sc_signal<bool>val4to5 = false;
    sc_signal<bool>ack4to5 = false;
    sc_signal<sc_bv<34>>4to8 = "0000000000000000000000000000000000";
    sc_signal<bool>val4to8 = false;
    sc_signal<bool>ack4to8 = false;
    sc_signal<sc_bv<34>>5to1 = "0000000000000000000000000000000000";
    sc_signal<bool>val5to1 = false;
    sc_signal<bool>ack5to1 = false;
    sc_signal<sc_bv<34>>5to4 = "0000000000000000000000000000000000";
    sc_signal<bool>val5to4 = false;
    sc_signal<bool>ack5to4 = false;
    sc_signal<sc_bv<34>>5to6 = "0000000000000000000000000000000000";
    sc_signal<bool>val5to6 = false;
    sc_signal<bool>ack5to6 = false;
    sc_signal<sc_bv<34>>6to2 = "0000000000000000000000000000000000";
    sc_signal<bool>val6to2 = false;
    sc_signal<bool>ack6to2 = false;
    sc_signal<sc_bv<34>>6to5 = "0000000000000000000000000000000000";
    sc_signal<bool>val6to5 = false;
    sc_signal<bool>ack6to5 = false;
    sc_signal<sc_bv<34>>6to7 = "0000000000000000000000000000000000";
    sc_signal<bool>val6to7 = false;
    sc_signal<bool>ack6to7 = false;
    sc_signal<sc_bv<34>>7to3 = "0000000000000000000000000000000000";
    sc_signal<bool>val7to3 = false;
    sc_signal<bool>ack7to3 = false;
    sc_signal<sc_bv<34>>7to6 = "0000000000000000000000000000000000";
    sc_signal<bool>val7to6 = false;
    sc_signal<bool>ack7to6 = false;
    sc_signal<sc_bv<34>>7to8 = "0000000000000000000000000000000000";
    sc_signal<bool>val7to8 = false;
    sc_signal<bool>ack7to8 = false;
    sc_signal<sc_bv<34>>8to1 = "0000000000000000000000000000000000";
    sc_signal<bool>val8to1 = false;
    sc_signal<bool>ack8to1 = false;
    sc_signal<sc_bv<34>>8to4 = "0000000000000000000000000000000000";
    sc_signal<bool>val8to4 = false;
    sc_signal<bool>ack8to4 = false;
    sc_signal<sc_bv<34>>8to7 = "0000000000000000000000000000000000";
    sc_signal<bool>val8to7 = false;
    sc_signal<bool>ack8to7 = false;


    if (argc != 2) {
        std::cout << "Uso: " << argv[0] << " <caminho_para_arquivo>" << std::endl;
        return 1;
    }
    const std::string filePath = argv[1];
    std::ifstream file(filePath);
    if (!file) {
        std::cout << "Não foi possível abrir o arquivo: " << filePath << std::endl;
        return 1;
    }
    std::string line;
    int count = 0;
    sc_signal<sc_bv<34>> locals_data[8];
    sc_signal<sc_bv<34>> locals_val[8];
    locals_val[0].write(false);
    locals_val[1].write(false);
    locals_val[2].write(false);
    locals_val[3].write(false);
    locals_val[4].write(false);
    locals_val[5].write(false);
    locals_val[6].write(false);
    locals_val[7].write(false);
    sc_signal<sc_bv<34>> locals_ack[8];
    locals_ack[0].write(false);
    locals_ack[1].write(false);
    locals_ack[2].write(false);
    locals_ack[3].write(false);
    locals_ack[4].write(false);
    locals_ack[5].write(false);
    locals_ack[6].write(false);
    locals_ack[7].write(false);

    sc_signal<sc_bv<34>> out_locals_data[8];
    sc_signal<sc_bv<34>> out_locals_val[8];
    out_locals_val[0].write(false);
    out_locals_val[1].write(false);
    out_locals_val[2].write(false);
    out_locals_val[3].write(false);
    out_locals_val[4].write(false);
    out_locals_val[5].write(false);
    out_locals_val[6].write(false);
    out_locals_val[7].write(false);
    sc_signal<sc_bv<34>> out_locals_ack[8];
    out_locals_ack[0].write(false);
    out_locals_ack[1].write(false);
    out_locals_ack[2].write(false);
    out_locals_ack[3].write(false);
    out_locals_ack[4].write(false);
    out_locals_ack[5].write(false);
    out_locals_ack[6].write(false);
    out_locals_ack[7].write(false);
    // while (std::getline(file, line) && count < 8) {
    //     locals[count].write(line);
    //     count++;                
    // }

    std::queue<sc_bv<34>> local_data_out[8];
    std::queue<sc_bv<34>> local_data_in[8];
    // std::queue<bool> val_in[8];

    for(int i{0}, i < 8; ++i){
        string line;
        std::getline(file, line);
        int n_lines = std::stoi(line);
        for(int j{0}; j < n_lines; ++j){
            std::getline(file, line);
            sc_bv<34> input = line;
            local_data_out[i].push(input);
        }
    }

    sc_signal<sc_bv<34>> front_local_data_out[8];
    sc_signal<sc_bv<34>> front_local_data_out[8];
    sc_signal<bool> front_val_in[8];
    sc_signal<bool> front_val_out[8];
    sc_signal<bool> front_ack_in[8];
    sc_signal<bool> front_ack_out[8];

    roteador r1("r1");
    r1.in_dataL(front_local_data_in[0]);
    r1.in_valL(front_val_in[0]);
    r1.in_ackL(front_ack_in[0]);
    r1.in_dataA(2to1);
    r1.in_valA(val2to1);
    r1.in_ackA(ack2to1);
    r1.in_dataH(8to1);
    r1.in_valH(val8to1);
    r1.in_ackH(ack8to1);
    r1.in_dataT(5to1);
    r1.in_valT(val5to1);
    r1.in_ackT(ack5to1);
    r1.out_dataL(front_local_data_out[0]);
    r1.out_valL(front_val_out[0]);
    r1.out_ackL(front_ack_out[0]);
    r1.out_dataA(1to8);
    r1.out_valA(val1to8);
    r1.out_ackA(ack1to8);
    r1.out_dataH(1to2);
    r1.out_valH(val1to2);
    r1.out_ackH(ack1to2);
    r1.out_dataT(1to5);
    r1.out_valT(val1to5);
    r1.out_ackT(ack1to5);



    roteador r2("r2");
    r2.in_dataL(front_local_data_in[1]);
    r2.in_valL(front_val_in[1]);
    r2.in_ackL(front_ack_in[1]);
    r2.in_dataA(3to2);
    r2.in_valA(val3to2);
    r2.in_ackA(ack3to2);
    r2.in_dataH(1to2);
    r2.in_valH(val1to2);
    r2.in_ackH(ack1to2);
    r2.in_dataT(6to2);
    r2.in_valT(val6to2);
    r2.in_ackT(ack6to2);
    r2.out_dataL(front_local_data_out[1]);
    r2.out_valL(front_val_out[1]);
    r2.out_ackL(front_ack_out[1]);
    r2.out_dataA(2to1);
    r2.out_valA(val2to1);
    r2.out_ackA(ack2to1);
    r2.out_dataH(2to3);
    r2.out_valH(val2to3);
    r2.out_ackH(ack2to3);
    r2.out_dataT(2to6);
    r2.out_valT(val2to6);
    r2.out_ackT(ack2to6);

    roteador r3("r3");
    r3.in_dataL(front_local_data_in[2]);
    r3.in_valL(front_val_in[2]);
    r3.in_ackL(front_ack_in[2]);
    r3.in_dataA(4to3);
    r3.in_valA(val4to3);
    r3.in_ackA(ack4to3);
    r3.in_dataH(2to3);
    r3.in_valH(val2to3);
    r3.in_ackH(ack2to3);
    r3.in_dataT(7to3);
    r3.in_valT(val7to3);
    r3.in_ackT(ack7to3);
    r3.out_dataL(front_local_data_out[2]);
    r3.out_valL(front_val_out[2]);
    r3.out_ackL(front_ack_out[2]);
    r3.out_dataA(3to2);
    r3.out_valA(val3to2);
    r3.out_ackA(ack3to2);
    r3.out_dataH(3to4);
    r3.out_valH(val3to4);
    r3.out_ackH(ack3to4);
    r3.out_dataT(3to7);
    r3.out_valT(val3to7);
    r3.out_ackT(ack3to7);

    roteador r4("r4");
    r4.in_dataL(front_local_data_in[3]);
    r4.in_valL(front_val_in[3]);
    r4.in_ackL(front_ack_in[3]);
    r4.in_dataA(5to4);
    r4.in_valA(val5to4);
    r4.in_ackA(ack5to4);
    r4.in_dataH(3to4);
    r4.in_valH(val3to4);
    r4.in_ackH(ack3to4);
    r4.in_dataT(8to4);
    r4.in_valT(val8to4);
    r4.in_ackT(ack8to4);
    r4.out_dataL(front_local_data_out[3]);
    r4.out_valL(front_val_out[3]);
    r4.out_ackL(front_ack_out[3]);
    r4.out_dataA(4to3);
    r4.out_valA(val4to3);
    r4.out_ackA(ack4to3);
    r4.out_dataH(4to5);
    r4.out_valH(val4to5);
    r4.out_ackH(ack4to5);
    r4.out_dataT(4to8);
    r4.out_valT(val4to8);
    r4.out_ackT(ack4to8);

    roteador r5("r5");
    r5.in_dataL(front_local_data_in[4]);
    r5.in_valL(front_val_in[4]);
    r5.in_ackL(front_ack_in[4]);
    r5.in_dataA(6to5);
    r5.in_valA(val6to5);
    r5.in_ackA(ack6to5);
    r5.in_dataH(4to6);
    r5.in_valH(val4to6);
    r5.in_ackH(ack4to6);
    r5.in_dataT(1to5);
    r5.in_valT(val1to5);
    r5.in_ackT(ack1to5);
    r5.out_dataL(front_local_data_out[4]);
    r5.out_valL(front_val_out[4]);
    r5.out_ackL(front_ack_out[4]);
    r5.out_dataA(5to4);
    r5.out_valA(val5to4);
    r5.out_ackA(ack5to4);
    r5.out_dataH(5to6);
    r5.out_valH(val5to6);
    r5.out_ackH(ack5to6);
    r5.out_dataT(5to1);
    r5.out_valT(val5to1);
    r5.out_ackT(ack5to1);

    roteador r6("r6");
    r6.in_dataL(front_local_data_in[5]);
    r6.in_valL(front_val_in[5]);
    r6.in_ackL(front_ack_in[5]);
    r6.in_dataA(7to6);
    r6.in_valA(val7to6);
    r6.in_ackA(ack7to6);
    r6.in_dataH(5to6);
    r6.in_valH(val5to6);
    r6.in_ackH(ack5to6);
    r6.in_dataT(2to6);
    r6.in_valT(val2to6);
    r6.in_ackT(ack2to6);
    r6.out_dataL(front_local_data_out[5]);
    r6.out_valL(front_val_out[5]);
    r6.out_ackL(front_ack_out[5]);
    r6.out_dataA(6to5);
    r6.out_valA(val6to5);
    r6.out_ackA(ack6to5);
    r6.out_dataH(6to7);
    r6.out_valH(val6to7);
    r6.out_ackH(ack6to7);
    r6.out_dataT(6to2);
    r6.out_valT(val6to2);
    r6.out_ackT(ack6to2);

    roteador r7("r7");
    r7.in_dataL(front_local_data_in[6]);
    r7.in_valL(front_val_in[6]);
    r7.in_ackL(front_ack_in[6]);
    r7.in_dataA(8to7);
    r7.in_valA(val8to7);
    r7.in_ackA(ack8to7);
    r7.in_dataH(6to7);
    r7.in_valH(val6to7);
    r7.in_ackH(ack6to7);
    r7.in_dataT(3to7);
    r7.in_valT(val3to7);
    r7.in_ackT(ack3to7);
    r7.out_dataL(front_local_data_out[6]);
    r7.out_valL(front_val_out[6]);
    r7.out_ackL(front_ack_out[6]);
    r7.out_dataA(6to6);
    r7.out_valA(val6to6);
    r7.out_ackA(ack6to6);
    r7.out_dataH(7to8);
    r7.out_valH(val7to8);
    r7.out_ackH(ack7to8);
    r7.out_dataT(7to3);
    r7.out_valT(val7to3);
    r7.out_ackT(ack7to3);

    roteador r8("r8");
    r8.in_dataL(front_local_data_in[7]);
    r8.in_valL(front_val_in[7]);
    r8.in_ackL(front_ack_in[7]);
    r8.in_dataA(1to8);
    r8.in_valA(val1to8);
    r8.in_ackA(ack1to8);
    r8.in_dataH(7to8);
    r8.in_valH(val7to8);
    r8.in_ackH(ack7to8);
    r8.in_dataT(4to8);
    r8.in_valT(val4to8);
    r8.in_ackT(ack4to8);
    r8.out_dataL(front_local_data_out[7]);
    r8.out_valL(front_val_out[7]);
    r8.out_ackL(front_ack_out[7]);
    r8.out_dataA(8to7);
    r8.out_valA(val8to7);
    r8.out_ackA(ack8to7);
    r8.out_dataH(8to1);
    r8.out_valH(val8to1);
    r8.out_ackH(ack8to1);
    r8.out_dataT(4to4);
    r8.out_valT(val4to4);
    r8.out_ackT(ack4to4);


    //todo arrumar a condição de parada do while
    while(true){
        for(int i{0}; i < 8; ++i){
            if(front_val_in[i]){
                local_data_in.push(sc_signal<sc_bv<34>> front_local_data_out[i]);
                sc_signal<bool> front_ack_out[i] = true;
            }
            sc_signal<sc_bv<34>> front_local_data_out[i] = local_data_out[i].front();
            sc_signal<bool> front_val_out[i] = !local_data_out[i].empty();
            if(front_ack_in[i]){
                local_data_out[i].pop();
            }
            
        }
    }
}