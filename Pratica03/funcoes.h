#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
void trocar(T & a, T & b)
{
    T aux = a;
    a=b;
    b=aux;

}

template <class T>
T maximo(const T a, const T b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <class T>
T minimo(const T a, const T b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }

}

template <>
char * maximo<char *>(char * a, char * b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

#endif // FUNCOES_H_INCLUDED
