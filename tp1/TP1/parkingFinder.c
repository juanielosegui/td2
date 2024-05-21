#include "parkingFinder.h"

int len(char* s){
    int contador = 0;
    for(int i = 0; s[i] != '\0'; i++){
        contador ++;
    }
    return contador;
}

char* strDuplicate(char* src) {
    int espacio = len(src);
    char* res = (char*)malloc(sizeof(char*)*espacio);
    for (int i=0; src[i]!='\0'; i++){
        res[i] = src[i];
    }
    res[espacio] = '\0';
    return res;
}

int strCompare(char* a, char* b) {
int res = 0;
int stop = 0;
for (int i=0; stop == 0; i++) {
    if (a[i] == b[i]) {
       res = 0;
       if ((a[i] == '\0') || (b[i] == '\0')){
        res = 0;
        stop = 1;
       }
    }
    else if (a[i]<b[i]){
        res = 1;
        stop = 1;
    }
    else if (a[i]>b[i]){
        res = -1;
        stop = 1;
    }
    }
    return res;
}

char* strConcatenate(char* src1, char* src2) {
    int espacio = len(src1) + len(src2);
    char* Res = (char*)malloc(sizeof(char*)*espacio);
    for (int i=0; src1[i]!='\0'; i++) {
        Res[i] = src1[i];
    }
    for (int i=0; src2[i]!='\0'; i++) {
        Res[i + len(src1)] = src2[i];
    }
    Res[espacio] = '\0';
    return Res;
}

struct parkingFinder* parkingFinderNew(char* street) {
    struct parkingFinder* pf = (struct parkingFinder*) malloc(sizeof(struct parkingFinder));
    pf->street = strDuplicate(street);
    pf->first = 0;
    pf->last = 0;
    pf->totalLength = 0.0;
    pf->freeLength = 0.0;
    return pf;
}

//Funciones de structs

void parkingFinderAddLast(struct parkingFinder* parking, int status, float length, char* plate) {
    struct node *prev = 0;
    struct node *curr = parking->first;

for (int i=0; curr->next!=0; i++){
    prev = curr;
    curr = curr->next;
};

if (curr-> next == 0){
    struct node* newLastNode = (struct node*)malloc(sizeof(struct node));
    newLastNode -> status = status;
    newLastNode -> length = length;
    newLastNode -> plate = plate;
}
if (prev->status == 0) {
    curr->length = (curr->length)+(prev->length);
    free(prev);
}
return *parking;
}

int parkingFinderReleaseSpace(struct parkingFinder* parking, char* plate) {
    struct node *prev = 0;
    struct node *curr = parking->first;
    for (int i=0; curr->plate != plate; i++){
        prev = curr;
        curr = curr->next;
        if(curr->plate == 0) {
            return 0;
        } else {
        curr->status = 0;
        curr->plate = 0;
        if (curr->prev->status == 0) {
            curr->length = curr->length + prev->length;
        }
        if (curr->next->status == 0) {
            prev->length = prev->length + curr->length;
        }
        return 1;
        };

    }
    return 0;
}

int parkingFinderFindSpace(struct parkingFinder* parking, char* plate, float length) {
    struct node *prev = 0;
    struct node *curr = parking->first;
    for (int i=0; curr->next!=0; i++){
    prev = curr;
    curr = curr->next;
    if (curr->status==0 && (curr->length)==length){
        curr->status = 1;
        curr->length = length;
        curr->plate = plate;
    }
    if (curr->status==0 && (curr->length)>=length){
        curr->status = 1;
        curr->length = length;
        curr->plate = plate;

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
            newNode->status = 0;
            newNode->length = (curr->length) - length;
            newNode->plate = 0;
    }
    }
        return 1;
    if (curr->status==0 && (curr->length)<length){
        return 0;
    }
}

void parkingFinderSplit (struct parkingFinder* parking, struct parkingFinder** pTaken, struct parkingFinder** pFree) {
    struct parkingFinder* Free;
    Free->street = parking->street;
    Free->totalLength = parking->freeLength;
    Free->freeLength = parking->freeLength;
    struct parkingFinder* Taken;
    Taken->street = parking->street;
    Taken->totalLength = 0;
    Taken->freeLength = 0;
    struct node* prev = 0;
    struct node* curr = parking->first;
    for(int i = 0; curr->next != 0; i++) {
        if (curr-> status == 0) {
            Free->first->status = 0;
            Free->first->length= Free->first->length + curr->length;
            Free->first->plate = 0;
        }
        if (curr->next == 1){
            struct node* prev2 = prev;
            struct node* curr2 = curr;
            Taken->totalLength = Taken->totalLength + curr->length;
            parkingFinderAddLast(Taken, 1, curr->length, curr->plate);
        }
        prev = curr;
        curr = curr->next;

    }
    return Taken;
    return Free;

}

void parkingFinderPrint(struct parkingFinder* parking) {
    printf("%s : %f/%f\n",parking->street, parking->freeLength, parking->totalLength);
    struct node* n = parking->first;
    while(n != 0) {
        if(n->status == 0) {
            printf("(%f)",n->length);
        } else {
            printf("[%f:%s]",n->length,n->plate);
        }
        n = n->next;
    }
    if(parking->first != 0) {
        printf("\n");
    }
}

char* parkingFinderGetPlates(struct parkingFinder* parking) {
    struct node* prev = 0;
    struct node* curr = parking->first;
    char* str = "";
    for(int i=0; curr->next!=0; i++){
        prev = curr;
        curr = curr->next;
        for (int i=0; curr->status == 1; i++)
            str = strConcatenate(str, strConcatenate(prev->plate, ", "));
    }
    return str;
}

void parkingFinderDelete(struct parkingFinder* parking) {
    struct node* n = parking->first;
    while(n != 0) {
        struct node* next = n->next;
        if(n->status == FREE) {
            free(n);
        } else {
            free(n->plate);
            free(n);
        }
        n = next;
    }
    free(parking->street);
    free(parking);
}
