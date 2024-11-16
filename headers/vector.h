#ifdef __VECTOR_H__
#define __VECTOR_H__

typedef struct vector{
    int x, y;
    double **p;
} vector;

double dot(const vector *a, const vector *b);
double cross(const vector *a, const vector *b);
vector *multiply(vector *a, vector b);
void vector_init(int x, int y);

#endif
