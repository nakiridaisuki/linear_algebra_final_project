#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct vector{
    int x, y;
    double **p;
} vector;

vector* vector_init(int x, int y);
vector* transpose(const vector* v);
double dot(const vector* a, const vector* b);
vector* multiply(const vector* a,const vector* b);
void pvector(const vector* v);
void *vector_free(vector *a);

#endif
