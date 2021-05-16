#include "kohonen.h"
#include "constant.h"

int main()
{
int i, j;
int nex, ni, no, topo, epochmax;
float wmin, wmax, lini, lfin, rini, rfin, lv, rv;
float ex[MAXEXE][MAXINP], exmin, exmax;

    nex = 50;
    ni = 72;
    no = 36;
    topo = LINE;
    epochmax = 1000;
    wmin = 1;   // a caso
    wmax = 10;  // a caso
    lini = 10;  //a caso
    lfin = 0;
    rini = 0;   //tanto lo reinizializza da solo con init_net() 
    rfin = 0;
    lv = 0.95;
    rv = 0.95;
    exmin = 0;
    exmax = 1;
    for(i=0; i<nex; i++)
        for(j=0; j<ni; j++)
            ex[i][j] = frand(exmin, exmax);

    set_weight_range(wmin, wmax);
    set_learning_range(lini, lfin);
    set_radius_range(rini, rfin);
    set_learn_decay(lv);
    set_radius_decay(rv);

    set_examples(ex, nex);
    init_net(ni, no, topo);
    learn_ts(epochmax);
}