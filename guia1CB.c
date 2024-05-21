#include <stdio.h>
#include <stdlib.h>

int len(char* s)
{
int contador = 0;
for(contador; s[contador]!= '\0'; contador++){
}
    return contador;
};

int main()
{
    char *s = "Juani";
    printf("El string \"%s\" mide %i\n", s, len(s));

    return 0;

}
