#include <iostream>
#include <string.h>
#include <stdlib.h> //SRAND RAND
#include <time.h>   // TIME

class Empregado
{

    friend int cadastro_Alet();

  public:
    //Empregado(std::string nome = "Anônimo", int tamanho = 0);
    Empregado(int tamanho, std::string a)
    {
        set_nome(a);
        set_aloca_vetor(tamanho);
        cadastro++;
    }
    ~Empregado() { delete[] lista; }

    //MÉTODOS SET
    void set_aloca_vetor(int);
    void set_nome(std::string);
    void set_lista();
    void show() const;
    void set_salario();

    //MÉTODOD GET
    int get_cadastro() const{return cadastro;}
    int get_tamanho() const {return tamanho;}
    std::string get_nome() const {return nome;}
    double get_salario() const {return salario;}
  private:
    std::string nome;
    static int cadastro;//NUMERO SEQUENCIAL DE CADASTRO DE CADA FUNCIONÁRIO
    int tamanho; // TAMANHO DA LISTA
    double salario;
    std::string *lista; // PONTEIRO PARA PRIMEIRA POSIÇÃO DA LISTA
};

int Empregado::cadastro = 0;

/*
    OBJ     LER O NOME DO EMPREGADO
    @PARAM      _NAME       NOME DO EMPREGADO
*/
void Empregado::set_nome(std::string _name)
{
    nome = _name;
}
/*
     OBJ     ALOCAR ESPAÇO DE MEMORIA PARA O VETOR CASO O SEU TAMANHO SEJA VÁLIDO
    @PARAM      _tam        TAMANHO DO VETOR QUE VAI SER VERIFICADO
    */
void Empregado::set_aloca_vetor(int _tam)
{
    if (_tam > 0)
    {
        lista = new std::string[_tam];
        tamanho = _tam;
    }
    else
        std::cout << "Vetor nao alocado!" << std::endl;
}

/*
    OBJ:        LER O NOME DAS EMPRESAS QUE O FUNCIONÁRIO JA TRABALHOU

    */
/*
    OBJ         SETAR OS ELEMENTOS DA LISTA
    */
void Empregado::set_lista()
{
    std::cout << "Digite o nome da(s) empresas que trabalhou: " << std::endl;
    for (int i = 0; i < get_tamanho(); i++)
    {
        std::cout << "#" << i + 1 << " Empresa" << std::endl;
        std::cin >> lista[i];
        //std::getline(std::cin, lista[i]);
    }
}
/*
    MOSTRAR A LISTA DE EMPRESAS QUE O FUNCINÁRIO TRABALHOU
    */
void Empregado::show() const
{
    std::cout << "Empregado: " << get_cadastro() << std::endl;
    std::cout << "Nome: " << get_nome() << std::endl;
    std::cout << "Salario: " << get_salario() << std::endl;
    for (int i = 0; i < get_tamanho(); i++)
        std::cout << lista[i] << std::endl;
}
/*
OBJ     VÁLIDAR SALÁRIO 
*/
void Empregado::set_salario()
{
    double salary;
    std::cout<< "Digite o salario: " << std::endl;
    std::cin >> salary;
    if (salary > 0)
        this->salario = salary;
}

int main()
{

    Empregado e1(5, "JONATHAN"); // CRIAÇÃO DO OBJETO

    int aux = 5;
    while (aux != 0)
    {
        std::cout << "1)Inserir o nome das empresas que o funcionario ja trabalhou" << std::endl;
        std::cout << "2)Salario" << std::endl;
        std::cout << "3)Informaçoes do funcinario" << std::endl;
        std::cout << "0)Sair" << std::endl;
        std::cin >> aux;
        if (aux == 1)
            e1.set_lista();
        if (aux == 2)
            e1.set_salario();
        if (aux == 3)
            e1.show();
    }
    
}