//author wanak0 :]
#ifndef SINTACTICO_H
#define SINTACTICO_H
#include "lexico.h"
#include "pila.cpp"

struct staInProd{
    string stack;
    string input;
    string prod;
};

class Sintactico
{

    //Pila para el Analisis Sintactico
    //Pila <std::string>* pila;
    // el arreglo "token" es referencia al conjunto Vt en la gramatica
    // este conjunto contiene todos los terminales
    char token[22][8] = {"x", ";", ",", "*", "Id", "[", "]", "Num", "char", "int", "float",
                         "puts", "(", ")", "Cte.Lit", "{", "}", "=","+","-","/", "Real"};
    // el arreglo varsint hace referencia al conjunto Vn de la gramatica
    // que son los no-terminales de la gramatica
    char varsint[15][3]={"x", "D", "L", "L'", "I", "I'", "A", "A'", "K",
                           "T", "F", "E", "P","K'"};
    // la matriz tablaM es la tabla gramatical, que contiene las producciones dentro de ella
    // es la base para todo el analisis sintactico
    //                         ε
    int tablaM[100][8]= {
        //producciones de D  :9
        {1, 5, 1, 5, 999, 999, 999, 999}, //[ D->I';
        {1, 1, 1, 5, 999, 999, 999, 999}, //; D->I';
        {1, 4, 1, 4, 3, -1, 999, 999}, //id D->IL';
        {1, 7, 1, 5, 3, -1, 999, 999}, //num D->I'L';
        {1, 8, 1, 9, 2, -1, 999, 999}, //char D->TL;
        {1, 9, 1, 9, 2, -1, 999, 999}, //int D->TL;
        {1, 10, 1, 9, 2, -1, 999, 999}, //float D->TL;
        /* 5 */ //producciones de L
        {2, 3, 2, 4, 3, 999, 999, 999}, // * L->IL'
        {2, 4, 2, 4, 3, 999, 999, 999}, //Id L->IL'
        {2, 5, 2, 4, 7, 999, 999, 999}, //[ L->IA'//agregada
        //producciones de L'
        {3, 1, 3, 5, 999, 999, 999, 999}, //; L'->I'
        {3, 1, 3, 999, 999, 999, 999, 999},//; L'->e
        {3, 2, 3, -2, 4, 3, 999, 999}, //, L'->,IL'
/* 10 */{3, 3, 3, -3, 8, 3, 999, 999}, //* L'->*KL'
        {3, 18, 3, -18, 8, 3, 999, 999}, //+ L'->+KL'
        {3, 19, 3, -19, 8, 3, 999, 999}, //- L'->-KL'
        {3, 20, 3, -20, 8, 3, 999, 999}, // / L'->PL'
        {3, 14, 3, -14, 5, 999, 999, 999},// cte. Lit. L'->cte Lit. I'
        //Producciones de I
        {4, 3, 4, -3, -4, 5, 999, 999}, // * I->*Id I'
        {4, 4, 4, -4, 5, 999, 999, 999},// Id I->Id I'
        //producciones de I'
        {5, 1, 5, 999, 999, 999, 999, 999},// ; I'->e
/* 15 */{5, 2, 5, 999, 999, 999, 999, 999},// , I'->e
        {5, 5, 5, 6, 999, 999, 999, 999}, // [ I' -> A
        {5, 14, 5, -14, 999, 999, 999, 999}, //cte lit I'->cte lit
/* -> */{5, 17, 5, -17, 8, 999, 999, 999}, //= I'->=K
        {5, 15, 5, -17, 7, 999,999,999},//{ I'->=A'
        //producciones de A
        {6, 5, 6, -5, 8, 11, 999, 999}, //[ A->[ KE
        //Producciones de A'
/* 20 */{7, 1, 7, 999, 999, 999, 999, 999},//; A'->e
        {7, 2, 7, 999, 999, 999, 999, 999},//, A'->e
        {7, 5, 7, -5, 8, -6, 7, 999}, //[ A' -> [K]A'
        {7, 12, 7, -12, 999, 999, 999, 999}, //( A' -> (
        {7, 15, 7, -15,  1,  -16,999,999},  //{ A'->{D}
        //Producciones de K

        {8, 4, 8, -4, 999, 999, 999, 999}, //Id K -> Id
        {8, 5, 8, -5, 8, 11, 999, 999}, //[ K -> [ KE
        {8, 7, 8, -7, 999, 999, 999, 999}, //Num K -> Num
        {8, 21, 8, -21, 999, 999, 999, 999}, //Real K -> Num
        {8, 12, 8, -12, 8, 11, 999, 999}, //( K -> ( KE
        {8, 15, 8, -15, 8, 10, 999, 999}, //{ K -> { KF
        //Producciones de T
        {9, 8, 9, -8, 999, 999, 999, 999}, //char T->Char
        {9, 9, 9, -9, 999, 999, 999, 999}, //int T->int
        {9, 10, 9, -10, 999, 999, 999, 999},//float T->float
        /*segunda gramatica */
        /* 25 */
        {10, 11, 10, -11, 11, -1, 999, 999},//puts F-> puts E;
        {10, 16, 10, -16, -1/*999*/, 999, 999, 999},//} F-> }; (se le pone el ;?)
        //Producciones de E
        {11, 6, 11, -6, 5, 999, 999, 999},//] E -> ]
        {11, 12, 11, -12, 12, -13, 999, 999},//( E -> (P)
        {11, 13, 11, -13, 999, 999, 999, 999},//)E -> )
        //producciones de Pn
        {12, 14, 12, -14, 999, 999, 999, 999},//cte lit P->cte lit
        //producciones de K'
        {13, 18, 13, -18, 8, 999, 999, 999},//+ K' -> + K
        {13, 19, 13, -19, 8, 999, 999, 999},//- k' -> - K
        {13, 20, 13, -20, 8, 999, 999, 999},// / k' ->/ K
    };


    //Metodo para checar
    int isToken(char x[]);
    //Metodo para buscar en la tabla de
    int buscaTabla(char a[],char x[]);
    string obtInp();
public:
    Sintactico();
    vector <staInProd> si;
    //objeto lexico de donde se obtendran los tokens
    Lexico *lex;
    bool analizar();

};

#endif // SINTACTICO_H
