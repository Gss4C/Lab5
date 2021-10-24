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
    TCanvas *c = new TCanvas("c", "c", 600, 500);
    TCanvas *c1 = new TCanvas("c1", "c1", 600, 500);

    FILE *kapton_data = fopen("kapton_relrate_t.txt", "r");
    FILE *mylar_data = fopen("Mylar_relrate_t.txt", "r");
    float rk[15], tk[15],erk[15], etk[15], rm[8], tm[8],erm[8],etm[8];
    float rrk, rtk,errk, ertk, rrm, rtm,errm, ertm;
    for (int i = 0; i < 15; i++)
    {
        fscanf(kapton_data, "%f %f  %f   %f\n", &rrk,&errk,&rtk,&ertk);
        rk[i] = rrk;
        tk[i] = rtk;
        erk[i] = errk;
        etk[i] = ertk;
    }
    for (int i = 0; i < 8; i++)
    {
        fscanf(mylar_data, "%f  %f  %f  %f\n", &rrm, &errm ,&rtm, &ertm);
        rm[i] = rrm;
        tm[i] = rtm;
        erm[i] = errm;
        etm[i] = ertm;
    }

    TGraphErrors *g_kapt = new TGraphErrors(15, tk, rk, etk, erk); //(N, x, y, ex, ey)
    TGraphErrors *g_myl = new TGraphErrors(8, tm, rm, etm, erm);

    TF1 *tofit = new TF1("tofit", "exp([0]+[1]*x)", 0, 0.3);
    tofit->SetLineColor(4);

    cout<<"Fit per il Kapton:";
    TFitResultPtr par_k = g_kapt->Fit("tofit", "S", "", 0, 0.3);
    cout<<"\n Fit per il Mylar:";
    TFitResultPtr par_m = g_myl->Fit("tofit", "S", "", 0, 0.3);

    g_kapt->SetTitle("Andamento Rate Relativo per il Kapton;t (g/cm^2); Rate Relativo");
    g_kapt->SetMarkerStyle(23);
    g_kapt->SetMarkerColor(1);

    g_myl->SetTitle("Andamento Rate Relativo per il Mylar;t (g/cm^2); Rate Relativo");
    g_myl->SetMarkerStyle(23);
    g_myl->SetMarkerColor(1);

    c->cd(); g_myl->Draw("AP");
    c->SaveAs("relrate_m.png");

    c1->cd(); g_kapt->Draw("AP");
    c1->SaveAs("relrate_k.png");

}