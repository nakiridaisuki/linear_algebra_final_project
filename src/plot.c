#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/plot.h"

// creat a x * y plot and initialize it with all whitespace
plot *plot_init(int x, int y){
    plot *ptr = malloc(sizeof(plot));
    ptr->x = x;
    ptr->y = y;
    ptr->canva = malloc(x * y * sizeof(char));
    memset(ptr->canva, ' ', x * y * sizeof(char));
    return ptr; 
}

// add a "c" onto plot at position (u, v)
void plot_add(plot *p, int u, int v, char c){
    int y = p->y;
    p->canva[u * y + v] = c;
}

// clean the screen and show the plot
void plot_show(const plot *p){
    int x = p->x, y = p->y;
    printf("\033[?25l"); // hide the cursor
    printf("\x1b[H");    // move the cursor to home position
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++)
            printf("%c", p->canva[i * y + j]);
        printf("\n");
    }
}

void plot_clean(plot *p){
    int x = p->x, y = p->y;
    memset(p->canva, ' ', x * y * sizeof(char));
}
