# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <iostream>
#include <cmath>

#include "TGraph.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TF1.h"

using namespace std;

int main()
{
    TCanvas c;

    FILE * dati=fopen("guadagni_miscela_2.txt", "r");
    float v_m[7],gain[7];
    float rv_m,rgain;

    for(int i=0 ; i<=6 ; i++){
        fscanf(dati,"%f %f \n", &rv_m,&rgain);
        v_m[i]=rv_m;
        gain[i]=rgain;
    }

    TGraph * gr1 = new TGraph(7, v_m, gain);
    TF1 *fnx1 = new TF1("fnx1","exp([0]+[1]*x)",480,570);
    TFitResultPtr ptr = gr1->Fit("fnx1","S","",480,570);

    gr1->Draw("A*"); c.SaveAs("gr_100.png");
}