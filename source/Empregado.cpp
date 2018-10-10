#include <iostream>
#include <string.h>
#include <stdlib.h> //srand  rand
#include <time.h> // time 
//using namespace std;


int salario_Alet(){
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
        Empregado(std::string nome = "Anônimo", int tamanho  = 0);
        Empregado(int tamanho, std::string a){
            set_nome(a);
            aloca_vetor(tamanho);
        }
        ~Empregado(){delete[] lista;}
        void aloca_vetor(int _tam){
            if(_tam > 0){
                lista  = new std::string[_tam];
                tamanho = _tam;
                std::cout <<  "Vetor !!"<< std::endl;
            }
            std::cout << "Vetor nao alocado!" << std::endl;
        }
        void set_nome(std::string);
        void set_lista();
        void show_lista();

        //Metodos get

        int get_tamanho(){
            return tamanho;
        }
        
        
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
    
    void Empregado::set_lista(){
        std::cout<<"Digite o nome da(s) empresas que trabalhou" <<std::endl;
        for(int i = 0; i < get_tamanho(); i++){
            std::cout<< "#" << i+1 << "Empresa" << std::endl;
            std::getline(std::cin, lista[i]);
        }
    }
    void Empregado::show_lista(){
        for(int i = 0; i < get_tamanho(); i++)
            std::cout<< lista[i] << std::endl;
    }

int main(){
    int aux;
    while (aux != 0){    
        std::cout << " 1) Cadastrar um novo empregado?" << std::endl;
        std::cout << " 0) Sair" << std::endl;
        std::cin >>  aux;
        std::string a;
        int tam;
        if(aux == 1){
            std::cout << "Digite o nome do empregado"<<  std::endl;
            std::getline(std::cin,a);
            std::cout <<"Em quantas empresas ele(a) ja trabalhou?" << std::endl;
            std::cin >> tam;
            Empregado e1(a,tam);
        }
        if(tam > 0){
            //e1.set_lista();
        }
    }

}



