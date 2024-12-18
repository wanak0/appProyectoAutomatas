#ifndef PILA_H
#define PILA_H
#include <string.h>
#include <string>
template <class T>
class Pila
{
public:

    Pila(int n);
    ~Pila();
    void push(T valor);
    T pop();
    bool isEmpt();
    bool isFull();
    T top();
    std::string mostrar();
private:
    int tam,t;
    T *vec;
    bool empt,full;
};

#endif // PILA_H
