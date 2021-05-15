#include <stdlib.h>
#include "constant.h"

static float    ts[MAXEXE][MAXINP];
static float    kw[MAXOUT][MAXINP];
static float    ki[MAXINP];
static float    ko[MAXOUT];

static int      k_inputs;
static int      k_units;
static int      topology;
static int      nex;

static float    k_radius;
static float    k_r_ini, k_r_fin;
static float    k_r_norm;

static float    k_alpha;
static float    k_a_ini, k_a_fin;
static float    k_a_norm;

static float    learn_decay;
static float    radius_decay;
static float    w_min, w_max;

float frand(int xmin, int xmax)
{
float range;
    range = (xmax - xmin);
    return (xmin + range * rand()/(float)RAND_MAX);
}

float distance(float *x, float *w)
{
int i;
float d, sum = 0.0;
    for(i=0; i<k_inputs; i++){
        d = w[i] - x[i];
        sum = sum + d*d;
    }
}

void set_weight_range(float wmin, float wmax)
{
    w_min = wmin;
    w_max = wmax;
}

void set_learning_range(float ini, float fin)
{
    k_a_ini = ini;
    k_a_fin = fin;
}

void set_radius_range(float ini, float fin)
{
    k_r_ini = ini;
    k_r_fin = fin;
}

void set_learn_decay(float v)
{
    learn_decay = v;
}

void set_radius_decay(float v)
{
    radius_decay = v;
}

float get_radius()
{
    return k_radius;
}

float get_learning_rate()
{
    return k_alpha;
}

float* get_example(int k)
{
    return ts[k];
} 

float get_input(int i)
{
    return ki[i];
}

float get_output(int j)
{
    return ko[j];
}

float get_weight(int j, int i)
{
    return kw[j][i];
}

void init_net(int ni, int no, int topo)
{
int i, j;

    k_inputs = ni;
    k_units = no;
    topology = topo;

    if ((topology == GRID) || (topology == MESH)){
        k_r_ini = sqrt((double)k_units);
    }else {
        k_r_ini = k_units/2 + 1;
    }

    k_alpha = k_a_ini;
    k_radius = k_r_ini;
    k_a_norm = 1.0;
    k_r_norm = 1.0;

    srand(time(NULL));

    for (j=0;j<k_inputs; j++)
        for (i=0; i<k_inputs;i++)
            kw[j][i] = frand(w_min, w_max);
}

void set_input(float *v)
{
int i;
    for (i=0; i<k_inputs; i++)
        ki[i] = v[i];
}

void compute_output()
{
int i, j;
    for (j=0; j<k_units; j++){
        ko[j] = 0.0;
        for (i=0; i<k_inputs; i++)
            ko[j] += kw[j][i] * ki[i];
    }
}