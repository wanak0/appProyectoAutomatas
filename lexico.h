//Author: wanak0 :]
#ifndef LEXICO_H
#define LEXICO_H
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Lexico
{
    //Este arreglo de caracteres es usado para
    //el analisis lexico, sin necesidad de leer
    //directamente del archivo en estos metodos
    //(realmente seria muy dificil que llegue hasta
    //aqui si no son caracteres)
    char cad[500];
    //Arreglo de numeros pares y nones
    char non[6]="13579", par[6]="24680";
    //este Lexema es utilizado en el metodo isId()
    char sLexema[127];
    // variable indice, estado actual (Actual State)
    // estado inicial (initial State), inicio token (token beggining)
    // y k que en este caso lleva el indice del arreglo de tokens
    int i, actStt, initStt, tokenBeg;
    //Arreglo de Palabras Reservadas
    char rsvWrd[5][10]={"char","float","int","puts"};
    //Metodo para saber si una palabra es un
    //identificador
    bool isId();
    //Metodo para saber si una palabra pertenece
    //a las palabras reservadas
    bool isRsvWrd();
public:
    Lexico();
    //Arreglo de Tokens (se manda al Sintactico)
    char asTokens [100][100];
    int k;
    //El metodo Tokens es para usarlo para hacer display de
    //los tokens que se encuentran en el arreglo
    string Tokens();
    // Metodo Estado Aceptacion
    bool accptStt();
    //Metodo de fallo para el automata
    void fail();
    //Metodo que inicializa a 0 los estados
    void iniStts();
    //Metodo para leer el siguiente caracter
    char nxtChar();
    //metodo para regresar el cursos al caracter
    //previo
    void prevChar();
    //metodo para recuperar error
    void retrieveErr();
    //Metodo Scanner (de analisis Lexico)
    void scanner();
    //este metodo recibe como parametro un string
    //el cual asigna al arreglo de caracteres "cad"
    //asi es mucho mas facil manipular las cadenas que
    //con un objeto std::string
    void setCad(string);
};

#endif // LEXICO_H
