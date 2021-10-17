#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>

using namespace std;
void fit_exp_misc2()
{
    TCanvas * c = new TCanvas("c","c",650,500);
    FILE * dati=fopen("dati_fit.txt","r");
    float v_m[8],g50[8],E_g50[8];
    float rv_m,rg50,rE_g50;
    for(int i=0 ; i<8 ; i++){
        fscanf(dati,"%f %f  %f \n", &rv_m,&rg50,&rE_g50);
        v_m[i]=rv_m;
        g50[i]=rg50;
        E_g50[i]=rE_g50;
    }

    TF1 *fnx1 = new TF1("fnx1","exp([0]+[1]*x)",480,570);

    TGraphErrors * gain_50 = new TGraphErrors(8, v_m, g50, 0, E_g50);
    TFitResultPtr ptr_50 = gain_50->Fit("fnx1","S","",485,565);
    gain_50->SetMarkerColor(1);
    gain_50->SetMarkerStyle(20);
    gain_50->SetMarkerSize(1);
    gain_50->SetTitle("Fit esponenziale del guadagno, miscela 2");
    gain_50->GetXaxis()->SetTitle("Tensione di Mesh (V)");
    gain_50->GetYaxis()->SetTitle("Guadagno (V)");
    gain_50->Draw("AP");
}