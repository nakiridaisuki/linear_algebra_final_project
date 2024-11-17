#include <stdio.h>
#include <stdlib.h>
#include "../headers/vector.h"
#include "../headers/debug.h"
#define VSIZE sizeof(vector)
#define MSUCCESS(v) if(!v){\
    printf("Malloc error");\
    return NULL;\
}


vector *vector_init(int x, int y){
    vector *v = malloc(VSIZE);
    MSUCCESS(v);
    v->p = malloc(sizeof(double*)*x);
    MSUCCESS(v->p);
    for(int i=0;i<x;i++){
        v->p[i] = malloc(sizeof(double)*y);
        MSUCCESS(v->p[i]);
    }
    return v;
}

vector *transpose(const vector *v){
    vector *t = vector_init(v->y,v->x);
    MSUCCESS(t);
    for(int i=0;i<v->y;i++){
        for(int j=0;j<v->x;j++){
            t->p[i][j] = v->p[j][i];
        }
    }
    // TODO: Check if this is correct.

}


double dot(const vector *a, const vector *b);
void multiply(const vector *a, vector *b);