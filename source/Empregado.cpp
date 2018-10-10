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
    }
    ~Empregado() { delete[] lista; }

    //MÉTODOS SET
    void set_aloca_vetor(int);
    void set_nome(std::string);
    void set_lista();
    void show_lista() const;
    void set_salario();

    //MÉTODOD SET

    int get_tamanho() const { return tamanho; }

  private:
    std::string nome;
    static int cadastro;
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
    std::getline(std::cin, _name);
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
        std::cout << "Vetor !!" << std::endl;
    }
    else
        std::cout << "Vetor nao alocado!" << std::endl;
}
/*
    OBJ:        LER O NOME DAS EMPRESAS QUE O FUNCIONÁRIO JA TRABALHOU

    */
void Empregado::set_lista()
{
    std::cout << "Digite o nome da(s) empresas que trabalhou" << std::endl;
    for (int i = 0; i < get_tamanho(); i++)
    {
        std::cout << "#" << i + 1 << " Empresa" << std::endl;
        std::getline(std::cin, lista[i]);
    }
}
/*
    MOSTRAR A LISTA DE EMPRESAS
    */
void Empregado::show_lista() const
{
    for (int i = 0; i < get_tamanho(); i++)
        std::cout << lista[i] << std::endl;
}
/*
OBJ     VÁLIDAR SALÁRIO 
*/
void Empregado::set_salario()
{
    double salary;
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
        std::cout << "1)Nome das empresas que o funcionário ja trabalhou" << std::endl;
        std::cout << "2)Salario" << std::endl;
        std::cout << "0)Sair" << std::endl;
        std::cin >> aux;
        if (aux == 1)
            e1.set_lista();
        else if (aux == 2)
            e1.set_salario();
    }
}