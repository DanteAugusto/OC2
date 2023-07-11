# Projeto de Organização de Computadores
Segundo projeto de Organizacao de Computadores
Para compilar o programa, é necessário ter a biblioteca SystemC e realizar o seguinte comando que gera o executável:

* g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o main main.cpp -lsystemc -lm 
Infelizmente não foi possível implementar em main.cpp a rede em chip que una os 8 roteadores e os testes, por tanto o executável possuirá comportamento inesperado.
