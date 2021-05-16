#ifndef	KOHONEN_H
#define	KOHONEN_H

#include "constant.h"

float frand(int xmin, int xmax);
void set_weight_range(float wmin, float wmax);
void set_learning_range(float ini, float fin);
void set_radius_range(float ini, float fin);
void set_learn_decay(float v);
void set_radius_decay(float v);
void set_examples(float ex[MAXEXE][MAXINP], int n);
float get_learning_rate();
float* get_example(int k);
float get_input(int i);
float get_output(int j);
float get_weight(int j, int i);

void init_net(int ni, int no, int topo);
void learn_ts(int epochmax);

#endif