#include "sintactico.h"
#include "pila.h"


int Sintactico::isToken(char x[])
{
    int found=false;
    for(int iJ=0;iJ<=22;iJ++)
        if(strcmp(x,token[iJ])==0)
            found=true;
    return found;
//     int n,m,found = false;
//     fseek(Fd,(long)iniToken,SEEK_SET);
//     for (m=iniToken, n=0; m<indice ; m++, n++)
//         fread(&sLexema[n],sizeof(char),1, Fd);
//     sLexema[n]= '\0';
//     for (m=0 ; m < NUMPALRES && !found ;)
//         if (strcmp(PalRes[m], sLexema)==0)
//             found = true;
//         else
//             m++;
//     return (found ? 0 : 1);
//
}

int Sintactico::buscaTabla(char a[], char x[])
{
    int indx=0, inda=0, i;

    for(i=0; i<23; i++)
        if(strcmp(a, token[i]) == 0)
            inda = i;//9 int

    for(i=0; i<15; i++)
        if(strcmp(x, varsint[i]) == 0)
            indx=i; //1 D

    for(i=0; i<44; i++)
    {
        if(indx == tablaM[i][0])
            if(inda == tablaM[i][1])
                return i;
    }

    return 999;
}


Sintactico::Sintactico() {

}

bool Sintactico::analizar()
{
    pila=new Pila<string>(1000);
    struct staInProd aux;
    int ip=0, i, j;
    int renglon, iast;
    char x[10], a[10];
    pila->push("$");
    string prod;

    if(strcmp(lex->asTokens[ip], "puts") == 0)
        pila->push("F");
    else
        pila->push("D");

    //aux.stack=pila->mostrar();
    for(i=0; strcmp(lex->asTokens[i], "$") != 0; i++){
        printf("%s ", lex->asTokens[i]);
        aux.input=lex->asTokens[i];
    }
    do
    {
        aux.stack=pila->mostrar();
        strcpy(x, pila->top().c_str());
        strcpy(a, lex->asTokens[ip]);

        if(isToken(x) || (strcmp(x, "$") == 0))
        {
            if(strcmp(x, a) == 0)
            {
                pila->pop();
                ip++;
            }
            else
            {
                if(strcmp(lex->asTokens[ip], "puts") == 0)
                    pila->push("F");
                else //Sino
                    pila->push("D");

                strcpy(x, pila->top().c_str());

            }
        }
        else
        {
            renglon = buscaTabla(a, x);

            if(renglon != 999)
            {
                pila->pop();
                iast = 0;
                printf("%-3s -> ", varsint[tablaM[renglon][0]]);
                prod.append("->");
                prod.append(varsint[tablaM[renglon][0]]);


                for(j= 3; iast!=999; j++)
                {
                    iast = tablaM[renglon][j];  //999
                    if(iast < 0)
                    {
                        iast *= -1;
                        printf("%s ",token[iast]);
                        prod.append(token[iast]);
                    }
                    else
                    {
                        if(iast != 999){
                            printf("%s", varsint[iast]);
                            prod.append(varsint[iast]);
                        }
                    }
                }

                aux.prod=prod;
                printf("\n");

                for(i=j-2; i>2; i--)
                {
                    iast = tablaM[renglon][i];
                    if(iast < 0)
                    {
                        iast *= -1;
                        pila->push(token[iast]);
                    }
                    else
                        pila->push(varsint[iast]);
                }
            }
            else
            {
                printf("\n\n Error de Sintaxis");
                return false;
            }
        }
        si.push_back(aux);
    }while(strcmp(x, "$") != 0);
    printf("\n");
    return true;
}

