#ifndef _PARKINGFINDER_HH_
#define _PARKINGFINDER_HH_

#include <stdio.h>
#include <stdlib.h>

#define FREE 0
#define TAKEN 1

struct node {
    int status;
    float length;
    char* plate;
    struct node* next;
    struct node* prev;
};

struct parkingFinder {
    char* street;
    struct node* first;
    struct node* last;
    float totalLength;
    float freeLength;
};

char* strDuplicate(char* src);

int strCompare(char* str1, char* str2);

char* strConcatenate(char* src1, char* src2);

struct parkingFinder* parkingFinderNew(char* street);

void parkingFinderAddLast(struct parkingFinder* parking, int status, float length, char* plate);

int parkingFinderReleaseSpace(struct parkingFinder* parking, char* plate);

int parkingFinderFindSpace(struct parkingFinder* parking, char* plate, float length);

void parkingFinderSplit(struct parkingFinder* parking, struct parkingFinder** pTaken, struct parkingFinder** pFree);

void parkingFinderPrint(struct parkingFinder* parking);

char* parkingFinderGetPlates(struct parkingFinder* parking);

void parkingFinderDelete(struct parkingFinder* parking);

#endif
