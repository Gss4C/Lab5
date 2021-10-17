#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>

#include "TGraph.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TGaxis.h"
#include "TF1.h"

using namespace std;
void coeff() 
{
    TCanvas *c = new TCanvas("c", "c", 500, 500);
    TCanvas *c1 = new TCanvas("c1", "c1", 500, 500);

    FILE *kapton_data = fopen("kapton_relrate_t.txt", "r");
    FILE *mylar_data = fopen("Mylar_relrate_t.txt", "r");
    float rk[15], tk[15], rm[8], tm[8];
    float rrk, rtk, rrm, rtm;
    for (int i = 0; i < 15; i++)
    {
        fscanf(kapton_data, "%f %f\n", &rrk, &rtk);
        rk[i] = rrk;
        tk[i] = rtk;
    }
    for (int i = 0; i < 8; i++)
    {
        fscanf(mylar_data, "%f %f\n", &rrm, &rtm);
        rm[i] = rrm;
        tm[i] = rtm;
    }

    TGraph *g_kapt = new TGraph(15, tk, rk); //(N, x, y, ex, ey)
    TGraph *g_myl = new TGraph(8, tm, rm);
   
    //TGraphErrors * g_kapt = new TGraph(15,tk,rk); //(N, x, y, ex, ey)
    //TGraphErrors * g_myl = new TGraph(8,tm,rm);

    TF1 *tofit = new TF1("tofit", "exp([0]+[1]*x)", 0, 0.3);

    cout<<"Fit per il Kapton: \n";
    TFitResultPtr par_k = g_kapt->Fit("tofit", "S", "", 0, 0.3);
    cout<<"\n Fit per il Mylar: \n";
    TFitResultPtr par_m = g_myl->Fit("tofit", "S", "", 0, 0.3);

    g_kapt->SetTitle("Andamento Rate Relativo per il Kapton;t (g/cm^2); Rate Relativo");
    g_myl->SetTitle("Andamento Rate Relativo per il Mylar;t (g/cm^2); Rate Relativo");
    c->cd(); g_myl->Draw("A*");
    c1->cd(); g_kapt->Draw("A*");

}