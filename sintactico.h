//author wanak0 :]
#ifndef SINTACTICO_H
#define SINTACTICO_H
#include "lexico.h"
#include "pila.h"

struct staInProd{
    string stack;
    string input;
    string prod;
};

class Sintactico
{

    //Pila para el Analisis Sintactico
    Pila <string> *pila;
    // el arreglo "token" es referencia al conjunto Vt en la gramatica
    // este conjunto contiene todos los terminales
    char token[22][8] = {"x", ";", ",", "*", "Id", "[", "]", "Num", "char", "int", "float",
                         "puts", "(", ")", "Cte.Lit", "{", "}", "=","+","-","/", "numreal"};
    // el arreglo varsint hace referencia al conjunto Vn de la gramatica
    // que son los no-terminales de la gramatica
    char varsint[15][3]={"x", "D", "L", "L'", "I", "I'", "A", "A'", "K",
                           "T", "F", "E", "P"};
    // la matriz tablaM es la tabla gramatical, que contiene las producciones dentro de ella
    // es la base para todo el analisis sintactico
    //                         ε
    int tablaM[100][8] = {
        // Producciones para D
        {1,  8,  1,  9,  2,  -1, 999, 999},  // D → TL; cuando char
        {1,  9,  1,  9,  2,  -1, 999, 999},  // D → TL; cuando int
        {1, 10, 1,  9,  2,  -1, 999, 999},   // D → TL; cuando float
        {1, 12, 1, 12, 13, 999, 999},        // D → F; cuando (
        // Producciones para E
        {11, 12, 11, -12, 13, 999, 999, 999},  // E → (P) cuando (
        // Producciones para F
        {10, 11, 10, -11, 1, 999, 999, 999},   // F → putsE  cuando puts
        // Producciones para T
        {9, 8, 9, -8, 999, 999, 999, 999},   // T → char
        {9, 9, 9, -9, 999, 999, 999, 999},   // T → int
        {9, 10, 9, -10, 999, 999, 999, 999}, // T → float
        {9, 1, 999, 999, 999, 999, 999, 999},// T → ε
        // Producciones para K
        {8, 4, 8, -4, 999, 999, 999, 999},    // K → id
        {8, 7, 8, -7, 999, 999, 999, 999},    // K → num
        {8, 15, 8, -15, 999, 999, 999, 999},  // K → numreal
        // Producciones para K'
        {13, 1, 999, 999, 999, 999, 999, 999},  // K' → ε
        {13, 3, 13, -3, 13, 999, 999, 999},     // K' → *K'
        {13, 7, 13, -7, 13, 999, 999, 999},     // K' → numK'
        {13, 15, 13, -15, 13, 999, 999, 999},   // K' → numreal K'
        {13, 17, 13, -17, 13, 999, 999, 999},   // K' → =K'
        {13, 18, 13, -18, 13, 999, 999, 999},   // K' → ==K'
        {13, 19, 13, -19, 13, 999, 999, 999},   // K' → !=K'
        {13, 20, 13, -20, 13, 999, 999, 999},   // K' → >=K'
        {13, 21, 13, -21, 13, 999, 999, 999},   // K' → <=K'
        {13, 22, 13, -22, 13, 999, 999, 999},   // K' → >K'
        {13, 23, 13, -23, 13, 999, 999, 999},   // K' → <K'
        {13, 12, 13, -12, 13, 8, -13, 999},     // K' → (K')K'
        // Producciones para L
        {2, 4, 2, 4, 3, 999, 999, 999},   // L → I' cuando id
        {2, 3, 2, 4, 3, 999, 999, 999},   // L → I' cuando *
        // Producciones para L'
        {3, 1, 3, 999, 999, 999, 999, 999},    // L' → ε cuando ;
        {3, 2, 3, -2, 4, 3, 999, 999},         // L' → ,I' cuando ,
        // Producciones para I
        {4, 4, 4, -4, 5, 999, 999, 999},       // I → idI' cuando id
        {4, 4, 4, -4, 3, 999, 999, 999},       // I → id* cuando id
        // Producciones para I'
        {5, 1, 5, 999, 999, 999, 999, 999},    // I' → ε cuando ;
        {5, 2, 5, 999, 999, 999, 999, 999},    // I' → ε cuando ,
        {5, 16, 5, -16, 13, 999, 999, 999},    // I' → =K' cuando =
        {5, 17, 5, -17, 13, 999, 999, 999},    // I' → ==K' cuando ==
        {5, 18, 5, -18, 13, 999, 999, 999},    // I' → !=K' cuando !=
        {5, 19, 5, -19, 13, 999, 999, 999},    // I' → >=K' cuando >=
        {5, 20, 5, -20, 13, 999, 999, 999},    // I' → <=K' cuando <=
        {5, 21, 5, -21, 13, 999, 999, 999},    // I' → >K' cuando >
        {5, 22, 5, -22, 13, 999, 999, 999},    // I' → <K' cuando <
        {5, 23, 5, -23, 13, 999, 999, 999},    // I' → +K' cuando +
        {5, 24, 5, -24, 13, 999, 999, 999},    // I' → -K' cuando -
        {5, 3, 5, -3, 13, 999, 999, 999},      // I' → *K' cuando *
        {5, 25, 5, -25, 13, 999, 999, 999},    // I' → /K' cuando /
        // Producciones para A
        {6, 5, 6, -5, 8, -6, 7, 999},          // A → [K]A' cuando [
        // Producciones para A'
        {7, 1, 7, 999, 999, 999, 999, 999},    // A' → ε cuando ;
        {7, 2, 7, 999, 999, 999, 999, 999},    // A' → ε cuando ,
        {7, 5, 7, -5, 8, -6, 7, 999},          // A' → [K]A
        // Producciones para P
        {12, 14,12, -14, 999, 999, 999, 999}   //P Cte.Lit = P ->Cte.Lit
    };

    //Metodo para checar
    int isToken(char x[]);
    //Metodo para buscar en la tabla de
    int buscaTabla(char a[],char x[]);
public:
    Sintactico();
    vector <staInProd> si;
    //objeto lexico de donde se obtendran los tokens
    Lexico *lex;
    bool analizar();

};

#endif // SINTACTICO_H
