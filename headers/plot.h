#ifndef __PLOT_H__
#define __PLOT_H__

typedef struct plot{
    int x, y;
    char *canva;
} plot;

plot *plot_init(int x, int y);
void plot_add(plot *p, int u, int v, char c);
void plot_show(const plot *p);
void plot_clean(plot *p);

#endif