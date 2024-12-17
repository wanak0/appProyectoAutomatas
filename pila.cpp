#include "pila.h"

template<class T>
Pila<T>::Pila(int n)
{
    tam = n;

    vec = new T[tam];
    t = 0;
    empt = true;
    full = false;
}

template<class T>
Pila<T>::~Pila()
{
    delete []vec;
}

template<class T>
void Pila<T>::push(T valor)
{
    empt = false;
    vec[t++] = valor;
    if (t == tam)
        full = true;

}
template<class T>
T Pila<T>::pop()
{

    full= false;
    if (--t == 0)
    {
        empt= true;

    }

    return vec[t];


}
template<class T>
bool Pila<T>::isEmpt()
{
    return empt;
}
template<class T>
bool Pila<T>::isFull()
{
    return full;
}
// void mostrar() {
//     for (int i = 0;i < t; i++) {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
// }
//SOLICITAMOS INFO. DEL DATO QUE ESTA EN EL TOPE DE LA PILA
template<class T>
T Pila<T>::top()
{
    return vec[t- 1];
}

template<class T>
string Pila<T>::mostrar()
{
    string sal;
    for (int i = 0;i < t; i++) {
        sal.append(vec[i]);
    }
    return sal;
}
