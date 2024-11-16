#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct vector{
    int x, y;
    double **p;
} vector;

vector *vector_init(int x, int y);
double dot(const vector *a, const vector *b);
void multiply(const vector *a, vector *b);

#endif
