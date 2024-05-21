#include <stdio.h>
#include <stdlib.h>


    char* strDuplicate(char* src){
        int espacio = len(src);
        char* res = (char*)malloc(espacio);
        for (int i=0; src[i]!='/0'; i++){
            printf(src[i]);
            res[i] = src[i];
        };
        return res;
    };

    int len(char* s){
        int contador = 0;
        for(contador; s[contador]!= '\0'; contador++){
        }
        return contador;
    };

int main()
{
    char* as = "aaaa";
    printf("La string \"%s\" mide %i",as, len(as));
    return 0;
}
