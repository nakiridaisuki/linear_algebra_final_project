#include <stdio.h>
#include <stdlib.h>
#include "../headers/vector.h"
#include "../headers/debug.h"
#define VSIZE sizeof(vector)
#define MSUCCESS(v) if(!v){\
    printf("Malloc error");\
    return NULL;\
}


vector* vector_init(int x, int y){
    vector *v = malloc(VSIZE);
    MSUCCESS(v);
    v->x = x;
    v->y = y;
    v->p = malloc(sizeof(double*)*x);
    MSUCCESS(v->p);
    for(int i=0;i<x;i++){
        v->p[i] = malloc(sizeof(double)*y);
        MSUCCESS(v->p[i]);
    }
    for(int i=0;i<v->x;i++){
        for(int j=0;j<v->y;j++){
            v->p[i][j] = 0;
        }
    }
    return v;
}

vector* transpose(const vector *v){
    vector *t = vector_init(v->y,v->x);
    MSUCCESS(t);
    for(int i=0;i<v->y;i++){
        for(int j=0;j<v->x;j++){
            t->p[i][j] = v->p[j][i];
        }
    }
    return t;

}


double dot(const vector* a, const vector* b){
    vector *t = transpose(a);
    vector *ans = multiply(a,b);
    return ans->p[0][0];
}

vector* multiply(const vector* a, const vector* b){
    if(a->y!=b->x){
        printf("Matrix multiplication failed!\n");
        return NULL;
    }
    vector *ret = vector_init(a->x,b->y);
    MSUCCESS(ret);
    // FIXME: If anyone have a better alogrithm, fix this shit.
    
    for(int i=0;i<a->x;i++){
        for(int j=0;j<b->y;j++){
            for(int k=0;k<a->y;k++){
                ret->p[i][j] += a->p[i][k]*b->p[k][j];
            }
        }
    }
    return ret;
}

void pvector(const vector* v){
    for(int i=0;i<v->x;i++){
        for(int j=0;j<v->y;j++){
            printf("%lf ",v->p[i][j]);
        }
        printf("\n");
    }
}