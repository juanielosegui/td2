#include <stdio.h>
#include <stdlib.h>
#include "parkingFinder.h"
#include "parkingFinder.c"

int main() {
    // strDuplicate
    char* dup = strDuplicate("hola");
    printf("strDuplicate(\"hola\") -> \"%s\"\n", dup);
    free(dup);

    char* juani = strDuplicate("");
    printf("strDuplicate(\"\") -> \"%s\"\n", juani);
    free(juani);

    char* juan = strDuplicate("i");
    printf("strDuplicate(\"i\") -> \"%s\"\n", juan);
    free(juani);

    char* iara = strDuplicate("abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    printf("strDuplicate(\"abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\") -> \"%s\"\n", iara);
    free(iara);


    // strCompare
    printf("strCompare(\"\",\"\") -> %i\n", strCompare("",""));
    printf("strCompare(\"c\",\"c\") -> %i\n", strCompare("c","c"));
    printf("strCompare(\"pato\",\"pata\") -> %i\n", strCompare("pata","pato"));
    printf("strCompare(\"luz\",\"ingeniosa\") -> %i\n", strCompare("ingeniosa","luz"));

    // strConcatenate
    char* concat = strConcatenate(strDuplicate(""),strDuplicate("456"));
    printf("strConcatenate(\"\",\"456\") -> \"%s\"\n", concat);
    free(concat);

    char* concat1 = strConcatenate(strDuplicate("123"),strDuplicate(""));
    printf("strConcatenate(\"123\",\"\") -> \"%s\"\n", concat1);
    free(concat1);

    char* concat2 = strConcatenate(strDuplicate("1"),strDuplicate("1"));
    printf("strConcatenate(\"1\",\"1\") -> \"%s\"\n", concat2);
    free(concat2);

    char* concat3 = strConcatenate(strDuplicate("abcde"),strDuplicate("abcde"));
    printf("strConcatenate(\"abcde\",\"abcde\") -> \"%s\"\n", concat3);
    free(concat3);



    // Estructura parkingFinder
    struct parkingFinder* pf = parkingFinderNew("Zapiola 400");

    // Crear una parkingFinder con distintos autos ubicados
    parkingFinderAddLast(pf, FREE, 100, 0);
    parkingFinderAddLast(pf, TAKEN, 100, "AAA123");

    parkingFinderAddLast(pf, TAKEN, 100, "CCC123");
    parkingFinderAddLast(pf, FREE, 100, 0);

    parkingFinderAddLast(pf, FREE, 100, 0);
    parkingFinderAddLast(pf, FREE, 100, 0);

//    // Imprimir un parkingFinder
    char * plates = parkingFinderGetPlates(pf);
    printf("%s\n",plates);
    free(plates);

    // Imprimir un parkingFinder
    parkingFinderPrint(pf);

    // Liberar algunos
    printf("DEL AAA123 = %i\n",parkingFinderReleaseSpace(pf, "AAA123"));
    printf("DEL XXX000 = %i\n",parkingFinderReleaseSpace(pf, "XXX000"));
    printf("DEL DDD123 = %i\n",parkingFinderReleaseSpace(pf, "DDD123"));

    // Imprimir un parkingFinder
    parkingFinderPrint(pf);

//    // Ubicar dos mas
//    printf("ADD MRP170 = %i\n",parkingFinderFindSpace(pf, "MRB170", 5.2));
//    printf("ADD XXXXXX = %i\n",parkingFinderFindSpace(pf, "XXXXXX", 1000));
//
//    // Imprimir un parkingFinder
    plates = parkingFinderGetPlates(pf);
    printf("%s\n",plates);
    free(plates);
//
//    // Imprimir un parkingFinder
        parkingFinderPrint(pf);
//
//    // Borrar un parkingFinder
//    parkingFinderDelete(pf);

    return 0;
}

//int main(){
//    printf("%i\n", strCompare("", ""));
//}
