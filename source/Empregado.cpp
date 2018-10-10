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
    void show_lista() const;
    void set_salario();

    //MÉTODOD GET

    int get_tamanho() const { return tamanho; }
    int get_cadastro() const { return cadastro; }
    std::string get_nome() const { return nome; }

  private:
    std::string nome;
    static int cadastro; // NÚMERO SEQUENCIAL DE CADASTRO
    int tamanho;         // TAMANHO DA LISTA
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

void Empregado::set_lista()
{
    std::cout << "Digite o nome da(s) empresas que trabalhou" << std::endl;
    for (int i = 0; i < get_tamanho(); i++)
    {
        std::cout << "#" << i + 1 << "Empresa" << std::endl;
        std::getline(std::cin, lista[i]);
    }
    else std::cout << "Vetor nao alocado!" << std::endl;
}
void Empregado::show_lista() const
{
    std::cout << "Empregado: " << get_cadastro() << std::endl;
    std::cout << "Nome: " << get_nome() << std::endl;
    std::cout << "Lista de empresas que trabalhou: " << std::endl;
    for (int i = 0; i < get_tamanho(); i++)
        std::cout << lista[i] << std::endl;
}

int main()
{

    Empregado e1(5, "JONATHAN"); // CRIAÇÃO DO OBJETO

    int aux = 5;
    while (aux != 0)
    {
        std::cout << "1)Iserir nome das empresas que o funcionário ja trabalhou" << std::endl;
        std::cout << "2)Salario" << std::endl;
        std::cout << "0)Sair" << std::endl;
        std::cin >> aux;
        if (aux == 1)
            e1.set_lista();
        else if (aux == 2)
            e1.set_salario();
    }
}
