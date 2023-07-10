#include <systemc.h>
#include <iostream>
#include <bitset> 
#include <unistd.h>
#include "entrada.h"
#include "saida.h"


SC_MODULE(roteador) {
    sc_in<bool> clk;


    //entrada local
    sc_in<sc_uint<34>> in_dataL; //34 bits
    sc_signal<sc_uint<34>> sig_out_dataL; //34 bits
    sc_in<bool> in_valL;
    sc_out<bool> in_ackL;
    

    // saídas para o árbitro
    sc_signal<bool> arbLL;
    sc_signal<bool> arbAL;
    sc_signal<bool> arbHL;
    sc_signal<bool> arbTL;
    
    
    // vêm do chaveamento
    sc_signal<bool> readOkLL;
    sc_signal<bool> readOkAL;
    sc_signal<bool> readOkHL;
    sc_signal<bool> readOkTL;
    
    
    //entrada anti-horária
    sc_in<sc_uint<34>> in_dataA; //34 bits
    sc_signal<sc_uint<34>> sig_out_dataA; //34 bits
    sc_in<bool> in_valA;
    sc_out<bool> in_ackA;


    // saídas para o árbitro
    sc_signal<bool> arbLA;
    sc_signal<bool> arbAA;
    sc_signal<bool> arbHA;
    sc_signal<bool> arbTA;
    
    
    // vêm do chaveamento
    sc_signal<bool> readOkLA;
    sc_signal<bool> readOkAA;
    sc_signal<bool> readOkHA;
    sc_signal<bool> readOkTA;
    
    
    //entrada horária
    sc_in<sc_uint<34>> in_dataH; //34 bits
    sc_signal<sc_uint<34>> sig_out_dataH; //34 bits
    sc_in<bool> in_valH;
    sc_out<bool> in_ackH;


    // saídas para o árbitro
    sc_signal<bool> arbLH;
    sc_signal<bool> arbAH;
    sc_signal<bool> arbHH;
    sc_signal<bool> arbTH;


    // vêm do chaveamento
    sc_signal<bool> readOkLH;
    sc_signal<bool> readOkAH;
    sc_signal<bool> readOkHH;
    sc_signal<bool> readOkTH;


    //entrada transversal (de frente)
    sc_in<sc_uint<34>> in_dataT; //34 bits
    sc_signal<sc_uint<34>> sig_out_dataT; //34 bits
    sc_in<bool> in_valT;
    sc_out<bool> in_ackT;


    // saídas para o árbitro
    sc_signal<bool> arbLT;
    sc_signal<bool> arbAT;
    sc_signal<bool> arbHT;
    sc_signal<bool> arbTT;


    // vêm do chaveamento
    sc_signal<bool> readOkLT;
    sc_signal<bool> readOkAT;
    sc_signal<bool> readOkHT;
    sc_signal<bool> readOkTT;
    
    
    //saída local
    // sc_in<bool> rotmn1 vai ser o sc_signal<bool> arbLA;
    // sc_in<bool> rotmn2 vai ser o sc_signal<bool> arbLH;
    // sc_in<bool> rotmn3 vai ser o sc_signal<bool> arbLT;


    // sc_in<sc_uint<34>> in_data1 vai ser o sc_signal<sc_uint<34>> out_dataA;
    // sc_in<sc_uint<34>> in_data2 vai ser o sc_signal<sc_uint<34>> out_dataH;
    // sc_in<sc_uint<34>> in_data3 vai ser o sc_signal<sc_uint<34>> out_dataT;
    sc_out<sc_uint<34>> out_dataL;

    sc_out<bool> out_valL;
    sc_in<bool> out_ackL;
    sc_signal<bool> x_rdL;


    //saída anti-horaria
    // sc_in<bool> rotmn1 vai ser o sc_signal<bool> arbAL;
    // sc_in<bool> rotmn2 vai ser o sc_signal<bool> arbAH;
    // sc_in<bool> rotmn3 vai ser o sc_signal<bool> arbAT;


    // sc_in<sc_uint<34>> in_data1 vai ser o sc_signal<sc_uint<34>> out_dataL;
    // sc_in<sc_uint<34>> in_data2 vai ser o sc_signal<sc_uint<34>> out_dataH;
    // sc_in<sc_uint<34>> in_data3 vai ser o sc_signal<sc_uint<34>> out_dataT;
    sc_out<sc_uint<34>> out_dataA;

    sc_out<bool> out_valA;
    sc_in<bool> out_ackA;
    sc_signal<bool> x_rdA;


    //saída horaria
    // sc_in<bool> rotmn1 vai ser o sc_signal<bool> arbHA;
    // sc_in<bool> rotmn2 vai ser o sc_signal<bool> arbHL;
    // sc_in<bool> rotmn3 vai ser o sc_signal<bool> arbHT;


    // sc_in<sc_uint<34>> in_data1 vai ser o sc_signal<sc_uint<34>> out_dataA;
    // sc_in<sc_uint<34>> in_data2 vai ser o sc_signal<sc_uint<34>> out_dataL;
    // sc_in<sc_uint<34>> in_data3 vai ser o sc_signal<sc_uint<34>> out_dataT;
    sc_out<sc_uint<34>> out_dataH;

    sc_out<bool> out_valH;
    sc_in<bool> out_ackH;
    sc_signal<bool> x_rdH;


    //saída transversal
    // sc_in<bool> rotmn1 vai ser o sc_signal<bool> arbTA;
    // sc_in<bool> rotmn2 vai ser o sc_signal<bool> arbTH;
    // sc_in<bool> rotmn3 vai ser o sc_signal<bool> arbTL;


    // sc_in<sc_uint<34>> in_data1 vai ser o sc_signal<sc_uint<34>> out_dataA;
    // sc_in<sc_uint<34>> in_data2 vai ser o sc_signal<sc_uint<34>> out_dataH;
    // sc_in<sc_uint<34>> in_data3 vai ser o sc_signal<sc_uint<34>> out_dataL;
    sc_out<sc_uint<34>> out_dataT;

    sc_out<bool> out_valT;
    sc_in<bool> out_ackT;
    sc_signal<bool> x_rdT;


    entrada inL;
    entrada inA;
    entrada inH;
    entrada inT;

    saida outL;
    saida outA;
    saida outH;
    saida outT;




    SC_CTOR(roteador) : inL("inL"), inA("inA"), inH("inH"), inT("inT"), outL("outL"), outA("outA"), outH("outH"), outT("outT"){
        //inicializando os sinais:
        arbLL.write(false);
        arbAL.write(false);
        arbHL.write(false);
        arbTL.write(false);
        readOkLL.write(false);
        readOkAL.write(false);
        readOkHL.write(false);
        readOkTL.write(false);
        arbLA.write(false);
        arbAA.write(false);
        arbHA.write(false);
        arbTA.write(false);
        readOkLA.write(false);
        readOkAA.write(false);
        readOkHA.write(false);
        readOkTA.write(false);
        arbLH.write(false);
        arbAH.write(false);
        arbHH.write(false);
        arbTH.write(false);
        readOkLH.write(false);
        readOkAH.write(false);
        readOkHH.write(false);
        readOkTH.write(false);
        arbLT.write(false);
        arbAT.write(false);
        arbHT.write(false);
        arbTT.write(false);
        readOkLT.write(false);
        readOkAT.write(false);
        readOkHT.write(false);
        readOkTT.write(false);
        out_valL.write(false);
        x_rdL.write(false);
        out_valA.write(false);
        x_rdA.write(false);
        out_valH.write(false);
        x_rdH.write(false);
        out_valT.write(false);
        x_rdT.write(false);


        //entrada local
        inL.clk(clk);
        inL.in_data(in_dataL);
        inL.out_data(sig_out_dataL);
        inL.in_val(in_valL);
        inL.in_ack(in_ackL);
        inL.arbL(arbLL);
        inL.arbA(arbAL);
        inL.arbH(arbHL);
        inL.arbT(arbTL);
        inL.readOkL(readOkLL);
        inL.readOkA(readOkAL);
        inL.readOkH(readOkHL);
        inL.readOkT(readOkTL);

        
        //entrada anti-horaria
        inA.clk(clk);
        inA.in_data(in_dataA);
        inA.out_data(sig_out_dataA);
        inA.in_val(in_valA);
        inA.in_ack(in_ackA);
        inA.arbL(arbLA);
        inA.arbA(arbAA);
        inA.arbH(arbHA);
        inA.arbT(arbTA);
        inA.readOkL(readOkLA);
        inA.readOkA(readOkAA);
        inA.readOkH(readOkHA);
        inA.readOkT(readOkTA);


        //entrada horaria
        inH.clk(clk);
        inH.in_data(in_dataH);
        inH.out_data(sig_out_dataH);
        inH.in_val(in_valH);
        inH.in_ack(in_ackH);
        inH.arbL(arbLH);
        inH.arbA(arbAH);
        inH.arbH(arbHH);
        inH.arbT(arbTH);
        inH.readOkL(readOkLH);
        inH.readOkA(readOkAH);
        inH.readOkH(readOkHH);
        inH.readOkT(readOkTH);


        //entrada transversal
        inT.clk(clk);
        inT.in_data(in_dataT);
        inT.out_data(sig_out_dataT);
        inT.in_val(in_valT);
        inT.in_ack(in_ackT);
        inT.arbL(arbLT);
        inT.arbA(arbAT);
        inT.arbH(arbHT);
        inT.arbT(arbTT);
        inT.readOkL(readOkLT);
        inT.readOkA(readOkAT);
        inT.readOkH(readOkHT);
        inT.readOkT(readOkTT);


        // saida local
        outL.clk(clk);
        outL.rotmn1(arbLA);
        outL.rotmn2(arbLH);
        outL.rotmn3(arbLT);
        outL.in_data1(sig_out_dataA);
        outL.in_data2(sig_out_dataH);
        outL.in_data3(sig_out_dataT);
        outL.out_data(out_dataL);
        outL.out_val(out_valL);
        outL.out_ack(out_ackL);
        outL.x_rd(x_rdL);


        // saida antihoraria
        outA.clk(clk);
        outA.rotmn1(arbAL);
        outA.rotmn2(arbAH);
        outA.rotmn3(arbAT);
        outA.in_data1(sig_out_dataL);
        outA.in_data2(sig_out_dataH);
        outA.in_data3(sig_out_dataT);
        outA.out_data(out_dataA);
        outA.out_val(out_valA);
        outA.out_ack(out_ackA);
        outA.x_rd(x_rdA);


        // saida horaria
        outH.clk(clk);
        outH.rotmn1(arbHA);
        outH.rotmn2(arbHL);
        outH.rotmn3(arbHT);
        outH.in_data1(sig_out_dataA);
        outH.in_data2(sig_out_dataL);
        outH.in_data3(sig_out_dataT);
        outH.out_data(out_dataH);
        outH.out_val(out_valH);
        outH.out_ack(out_ackH);
        outH.x_rd(x_rdH);


        // saida transversal
        outT.clk(clk);
        outT.rotmn1(arbTA);
        outT.rotmn2(arbTH);
        outT.rotmn3(arbTL);
        outT.in_data1(sig_out_dataA);
        outT.in_data2(sig_out_dataH);
        outT.in_data3(sig_out_dataL);
        outT.out_data(out_dataT);
        outT.out_val(out_valT);
        outT.out_ack(out_ackT);
        outT.x_rd(x_rdT);
    }
};
