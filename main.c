#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "headers/plot.h"
#include "headers/vector.h"

#define max(a, b) (a > b ? a : b);

double R = 10, r = 5;
double A = 0, B = 0, C = 0;
double dA = 0.05, dB = 0.08, dC = 0;
int H = 30, W = 80;

struct matrix{
    double a, b, c, d, e, f, g, h, i;
}M;

// the Fast Inverse Square Root 
float Q_Inv_sqrt(float x){
    float x2 = 0.5f * x;
    int i = *(int*)&x;       // evil floating point bit level hacking
    i = 0x5f3759df - (i>>1); // what the fuck?
    x = *(float*)&i;
    x = x * (1.5f - x2*x*x); // 1st iteration
    return x;
}

double value(vector *v){
    double sum = 0;
    for(int i=0; i<v->x; i++)
        for(int j=0; j<v->y; j++)
            sum += v->p[i][j] * v->p[i][j];
    return Q_Inv_sqrt(sum);
}

vector *make_matrix(double A, double B, double C){
    double sA = sin(A), sB = sin(B), sC = sin(C);
    double cA = cos(A), cB = cos(B), cC = cos(C);

    vector *M = vector_init(3, 3);
    M->p[0][0] = cC*cB;
    M->p[0][1] = -sC*cA + cC*sB*sA;
    M->p[0][2] = sC*sA + cC*sB*cA;
    M->p[1][0] = sC*cB;
    M->p[1][1] = cC*cA + sC*sB*sA;
    M->p[1][2] = -cC*sA + sC*sB*cA;
    M->p[2][0] = -sB;
    M->p[2][1] = cB*sA;
    M->p[2][2] = cB*cA;
    return M;
}

int main(){

    double depth[H][W];
    vector *light = vector_init(3, 1);
    light->p[0][0] = -1;
    light->p[1][0] = 0;
    light->p[2][0] = 1;
    plot *canva = plot_init(H, W);

    printf("\x1b[2J");
    while(1){
        plot_clean(canva);
        memset(depth, 0, sizeof(depth));

        vector *M = make_matrix(A, B, C);
        
        for(double i=0; i<6.28; i+=0.07){
            for(double j=0; j<6.28; j+=0.02){
                double ci = cos(i), cj = cos(j);
                double si = sin(i), sj = sin(j);

                vector *point, *normal;
                point = vector_init(3, 1);
                point->p[0][0] = (R + r*ci) * cj;
                point->p[1][0] = (R + r*ci) * sj;
                point->p[2][0] = r * si;

                normal = vector_init(3, 1);
                normal->p[0][0] = ci * cj;
                normal->p[1][0] = ci * sj;
                normal->p[2][0] = si;

                vector *tmp = point;
                point = multiply(M, point);
                vector_free(tmp);

                tmp = normal;
                normal = multiply(M, normal);
                vector_free(tmp);

                int D = 12 * (dot(normal, light) * value(normal) * value(light));

                int x = H/2 + point->p[0][0], y = W/2 + point->p[1][0] * 2;
                double z = point->p[2][0] + 100;
                if(0 <= x && x < H && 0 <= y && y < W && z > depth[x][y]){
                    depth[x][y] = z;
                    plot_add(canva, x, y, ".,-~:;=!*#$@"[D > 0 ? D : 0]);
                }
                // plot_add(canva, x, y, '.');
            }
        }
        M = vector_free(M);
        plot_show(canva);
        A += dA;
        B += dB;
        C += dC;
    }



    return 0;
}