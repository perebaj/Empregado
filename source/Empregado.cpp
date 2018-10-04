#include <iostream>
#include <string.h>
#include <stdlib.h> //srand  rand
#include <time.h> // time 
//using namespace std;


int cadastro_Alet(){
    srand(time(NULL));
    int cadastro = rand() % 1000;
    return cadastro;
}

/*
 Verificar se o numero gerado para cadastro já existe

 @param cadastro - Cadatro que vai ser comparado
 @param new_cadastro -  Novo cadastro gerado

return 1 se os cadastros forem iguas
return 0 se os cadastros forem diferentes
 */
bool num_REP(int cadastro, int new_cadastro){
    if  ( cadastro == new_cadastro){
        return true;
    }
    else 
        return false;
}

class Empregado{

    friend int cadastro_Alet();
    public:
        Empregado(std::string = "Anônimo", int tam  = 0);
        Empregado();
        void aloca_vetor(int _tam){
            if(_tam > 0){
                lista  = new std::string[_tam];
                tamanho = _tam;
            }
            
        }
        void set_nome(std::string);

        
        
    private:
        std::string nome;
        static int  cadastro ;
        int tamanho; // tamanho da lista
        double salario;
        std::string *lista; // ponteira para primeira posição da lista de trabalhos do empregado

};

    int Empregado::cadastro = 0;
    /*
     Le Nome
    */
    void Empregado::set_nome(std::string _name){
        std::getline(std::cin, _name);
        nome = _name;
    }




