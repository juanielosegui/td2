#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list{
    struct node *first;
    int size;
};

struct node{
    struct node *next;
    struct elem *data;
};

struct elem {
    float x;
    float y;
    int i;
    char t;
};

float magnitudeAverage(struct list* ls){

}

int main(){
    return 0;
}
