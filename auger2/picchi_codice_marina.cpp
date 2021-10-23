# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <iostream>
#include <cmath>

#include "TCanvas.h"
#include "TLegend.h"
#include "TFitResult.h"
#include "TGraph.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TAxis.h"
#include "TH1.h"
#include "TArrayD.h"

using namespace std;

int main()
{
    
    TCanvas c;

    TH1F* h_500_100 = new TH1F("h_500_100","Istogramma Ampiezze con HV Mesh -500V",4096, 0, 5);
    FILE * f1=fopen("h_500_100.txt", "r");
    int cnt_500_100[4096];
    int ccnt_500_100;

    for(int i=0 ; i<=4095 ; i++){
        fscanf(f1,"%i \n", &ccnt_500_100);
        cnt_500_100[i]=ccnt_500_100;
    }
    for(int i=0 ; i<=4085 ; i++){
        h_500_100->SetBinContent(i,cnt_500_100[i]);
    }

    Double_t par[6];
    TF1 *g1    = new TF1("g1","gaus",1, 1.6); #genero le funzioni gaussiane
    TF1 *g2    = new TF1("g2","gaus",1.8, 2.9);
    TF1 *total = new TF1("total","gaus(0)+gaus(3)",1, 2.9);
    g1->SetLineColor(8);
    g2->SetLineColor(6);
    total->SetLineColor(2);
    h_500_100->Fit(g1,"R"); #R fa il fit giusto nel range dove la funzione è definita
    h_500_100->Fit(g2,"R+");
  
    g1->GetParameters(&par[0]);
    g2->GetParameters(&par[3]);
    total->SetParameters(par);
    h_500_100->Fit(total,"R+");
    

    h_500_100->GetYaxis()->SetTitle("# Conteggi");
    h_500_100->GetXaxis()->SetTitle("Ampiezza segnale (V)");

    h_500_100->Draw();    

    c.SaveAs("h_500_100.png");

}
    