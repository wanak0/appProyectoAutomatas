#include "lexico.h"

bool Lexico::isId()
{

}

Lexico::Lexico() {}

bool Lexico::accptStt()
{
    switch (actStt){
    case 8: case 5: case 7: case 6: case 3:
    case 12: case 15: case 17: case 19: case 21:
    case 23 : case 26: case 28: case 30: case 32:
    case 34: case 36: case 40:
        return true;
    default : return false;
    }
}

void Lexico::fail()
{
    switch (initStt)
    {
    case 0 : initStt=4;
        i=tokenBeg;
        break;

    case 4 : initStt=9;
        i=tokenBeg;
        break;

    case 9 : initStt=13;
        i=tokenBeg;
        break;

    case 13 : initStt=16;
        i = tokenBeg;
        break;

    case 16 : initStt=18;
        i = tokenBeg;
        break;

    case 18 : initStt=20;
        i=tokenBeg;
        break;

    case 20 : initStt=22;
        i = tokenBeg;
        break;

    case 22 : initStt=24;
        i = tokenBeg;
        break;

    case 24 : initStt=27;
        i = tokenBeg;
        break;

    case 27 : initStt=29;
        i = tokenBeg;
        break;

    case 29: initStt = 31;
        i = tokenBeg;
        break;

    case 31: initStt = 33;
        i = tokenBeg;
        break;

    case 33: initStt = 35;
        i = tokenBeg;
        break;

    case 35: retrieveErr();
    }
    actStt=initStt;
}

void Lexico::iniStts()
{
    actStt=initStt=0;
}

char Lexico::nxtChar()
{
    return cad[i++];
}

void Lexico::prevChar()
{
    i--;
}

void Lexico::retrieveErr()
{
    tokenBeg=i;
    iniStts();
}

void Lexico::scanner()
{
    char cCarent;

    i = tokenBeg = k = 0;
    iniStts();

    while(i < (int)strlen(cad) || accpStt()){
        switch(actStt){
        case 0: cCarent=nextChar();
            if (strchr(non,cCarent))
                actStt = 1;
            else
                if(strchr(par,cCarent))
                    actStt = 2;
                else
                    if(cCarent == '.')
                        actStt = 37;
                    else
                        fail();
            break;

        case 1: cCarent=nextChar();
            if(strchr(non,cCarent))
                actStt=1;
            else
                if(strchr(par,cCarent))
                    actStt = 2;
                else if(cCarent== '.')
                    actStt = 37;
                else
                    fail();
            break;

        case 2: cCarent=nextChar();
            if(strchr(non,cCarent))
                actStt=1;
            else
                if (strchr(par,cCarent))
                    actStt=2;
                else if(cCarent== '.')
                    actStt = 37;
                else
                    actStt=3;
            break;

        case 3: prevChar();
            strcpy(asTokens[k++],"Num");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 4: cCarent=nextChar();
            switch(cCarent){
            case '+': actStt=5; break;
            case '-': actStt=6; break;
            case '*': actStt=7; break;
            case '/': actStt=8; break;
            default: fail();
            }
            break;

        case 5: strcpy(asTokens[k++], "+");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 6: strcpy(asTokens[k++], "-");
            if (i>=(int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 7: strcpy(asTokens[k++], "*");
            if (i>=(int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 8: strcpy(asTokens[k++], "/");
            if (i>=(int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;


        case 9: cCarent=nextChar();
            if (strchr(par,cCarent))
                actStt=10;
            else
                if(strchr(non,cCarent))
                    actStt=11;
                else if(cCarent== '.')
                    actStt = 37;
                else
                    fail();
            break;

        case 10: cCarent=nextChar();
            if (strchr(par,cCarent))
                actStt=10;
            else
                if(strchr(non,cCarent))
                    actStt=11;
                else if(cCarent== '.')
                    actStt = 37;
                else
                    fail();
            break;

        case 11 : cCarent=nextChar();
            if (strchr(non,cCarent))
                actStt=11;
            else
                if(strchr(par,cCarent))
                    actStt=10;
                else if(cCarent== '.')
                    actStt = 37;
                else
                    actStt=12;
            break;

            // NON - PAR
        case 12: prevChar();
            strcpy(asTokens[k++],"Num");
            if (i>=(int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 13: cCarent=nextChar();
            if ((isalpha(cCarent)|| cCarent=='_'))
                actStt=14;
            else
                fail();
            break;

        case 14: cCarent=nextChar();
            if ((isalpha(cCarent)|| cCarent=='_') || isdigit(cCarent))
                actStt=14;
            else
                actStt= 15;
            break;

        case 15: prevChar();
            if(isId())
                strcpy(asTokens[k++], "Id");
            else
                strcpy(asTokens[k++],sLexema);

            if(i>=(int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;


        case 16: cCarent=nextChar();
            if(cCarent==';')
                actStt=17;
            else
                fail();
            break;

            /* Al encontrar el caracter ';' , que indica fin de linea,
                 Se copia el caracter '$' al fin del arreglo astokens
                 */
        case 17: strcpy(asTokens[k++], ";");
            strcpy(asTokens[k], "$");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 18: cCarent=nextChar();
            if(cCarent=='[')
                actStt=19;
            else
                fail();
            break;

        case 19: strcpy(asTokens[k++], "[");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 20: cCarent=nextChar();
            if(cCarent==']')
                actStt=21;
            else
                fail();
            break;

        case 21: strcpy(asTokens[k++], "]");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg = i;
            iniStts();
            break;

        case 22: cCarent = nextChar();
            if(cCarent == ',')
                actStt=23;
            else
                fail();
            break;

        case 23: strcpy(asTokens[k++], ",");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 24: cCarent = nextChar();
            if (('"' == cCarent) && cCarent)
                actStt=25;
            else
                fail();
            break;

        case 25: cCarent=nextChar();
            if (('"' != cCarent) && cCarent)
                actStt=25;
            else
                if(cCarent)
                    actStt=26;
            break;

        case 26: strcpy(asTokens[k++],"Cte.Lit");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 27: cCarent=nextChar();
            if(cCarent == '(')
                actStt=28;
            else
                fail();
            break;

        case 28: strcpy(asTokens[k++], "(");
            if (i>=(int)strlen(cad))
                return;
            tokenBeg = i;
            iniStts();
            break;

        case 29:cCarent=nextChar();
            if(cCarent == ')')
                actStt=30;
            else
                fail();
            break;

        case 30: strcpy(asTokens[k++], ")");
            if (i>=(int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;

        case 31: cCarent = nextChar();
            if(cCarent == '{')
                actStt = 32;
            else
                fail();
            break;

        case 32: strcpy(asTokens[k++], "{");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg = i;
            iniStts();
            break;

        case 33: cCarent = nextChar();
            if(cCarent == '}')
                actStt = 34;
            else
                fail();
            break;

        case 34: strcpy(asTokens[k++], "}");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg = i;
            iniStts();
            break;

        case 35: cCarent = nextChar();
            if(cCarent == '=')
                actStt = 36;
            else
                fail();
            break;

        case 36: strcpy(asTokens[k++], "=");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg = i;
            iniStts();
            break;

        case 37: cCarent=nextChar();
            if (strchr(non,cCarent))
                actStt = 38;
            else
                if(strchr(par,cCarent))
                    actStt = 39;
                else
                    fail();
            break;
        case 38: cCarent=nextChar();
            if(strchr(non,cCarent))
                actStt=38;
            else
                if(strchr(par,cCarent))
                    actStt = 39;
                else
                    actStt=40;
            break;

        case 39: cCarent=nextChar();
            if(strchr(non,cCarent))
                actStt=38;
            else
                if (strchr(par,cCarent))
                    actStt=39;
                else
                    actStt=40;
            break;
        case 40: prevChar();
            strcpy(asTokens[k++],"Real");
            if (i >= (int)strlen(cad))
                return;
            tokenBeg=i;
            iniStts();
            break;
        }/*switch*/
    } /*while*/
}

void Lexico::setCad(string s)
{
    strcpy(cad,s.c_str());
}
