#ifdef __PLOT_H__
#define __PLOT_H__

#include "vector.h"

typedef struct plot{
    int x, y;
    char **canva;
    double **depth;
} plot;

void plot_init(int x, int y);
void plot_add(const vector *v);
void plot_show(const plot p);

#endif