#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <iostream>
#include "arranjo.h"
using namespace std;

class Aluno
{
private:
    string nome;
    string mat;
public:
    Aluno() {}
    Aluno(const char * nome, const char * mat) : nome(nome), mat(mat) {}

    friend class Arranjo<Aluno>;
};

template<>
void Arranjo<Aluno>::set(int idx, const Aluno & aluno)
{
    //atribua nome e mat do item do  array a partir de aluno
    itens[idx].nome = aluno.nome;
    itens[idx].mat = aluno.mat;
}

template<>
void Arranjo<Aluno>::exibir()
{
    //exiba cada aluno do array no formato "idx : mat = nome"
    cout<<"Turma:"<<endl<<endl;
    for(int i=0; i<3; i++)
    {
        cout<<"<"<<i<<">" << itens[i].mat << " = "<< itens[i].nome <<endl<<endl;
    }
}

#endif // ALUNO_H_INCLUDED