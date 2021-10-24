#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>

#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TFitResult.h"
#include "TF1.h"
#include "TH2.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TGraphErrors.h"

using namespace std;

void graph_town()
{
    TCanvas * c1 = new TCanvas("c","c", 750 , 600);
    //TCanvas * c2 = new TCanvas("c","c", 750 , 600);

    FILE * miscela1 = fopen("graph_misc1.txt", "r");
    FILE * miscela2 = fopen("graph_misc2.txt", "r");
    float v_m1[5],v_m2[8],alpha1[5],dalpha1[5],alpha2[8],dalpha2[8];
    float rv_m1,ra1,ra2,rdra1,rdra2,rv_m2;
    for(int i=0 ; i<5 ; i++){
        fscanf(miscela1,"%f %f %f\n", &rv_m1,&ra1,&rdra1);
        v_m1[i]=rv_m1;
        alpha1[i]=ra1;
        dalpha1[i]=rdra1;
    }
    for(int i=0 ; i<8 ; i++){
        fscanf(miscela2,"%f %f  %f\n", &rv_m2,&ra2,&rdra2);
        v_m2[i]=rv_m2;
        alpha2[i]=ra2;
        dalpha2[i]=rdra2;
    }
    
    TGraphErrors * misc1 = new TGraphErrors(5, v_m1 , alpha1 , 0 , dalpha1);
    TGraphErrors * misc2 = new TGraphErrors(8, v_m2 , alpha2 , 0 , dalpha2);
    


    misc1->SetMarkerColor(4);
    misc1->SetMarkerStyle(22);
    misc1->SetMarkerSize(1);
    misc1->SetTitle("Coefficienti di Townsend miscela 1");
    misc1->GetXaxis()->SetTitle("Tensione di Mesh (V)");
    misc1->GetYaxis()->SetTitle("Coefficiente di Townsend (cm^-1)");
    misc1->Draw("AP");
    c1->SaveAs("coef_misc1.png");


    misc2->SetMarkerColor(4);
    misc2->SetMarkerStyle(22);
    misc2->SetMarkerSize(1);
    misc2->SetTitle("Coefficienti di Townsend miscela 2");
    misc2->GetXaxis()->SetTitle("Tensione di Mesh (V)");
    misc2->GetYaxis()->SetTitle("Coefficiente di Townsend (cm^-1)");
    misc2->Draw("AP");
    c1->SaveAs("coef_misc2.png");

    /*TMultiGraph * tot = new TMultiGraph();
    tot->Add(misc1 , "AP");
    tot->Add(misc2 , "AP");
    misc1->SetMarkerColor(2);
    misc1->SetMarkerStyle(23);
    misc2->SetMarkerColor(3);
    misc2->SetMarkerStyle(22);
    tot->GetXaxis()->SetTitle("Tensione di Mesh (V)");
    tot->GetYaxis()->SetTitle("Coefficiente di Townsend (cm^-1)");
    c1->SetLogy();
    //tot->GetXaxis()->SetRangeUser(450, 570);
    tot->GetYaxis()->SetRangeUser(100, 10000);
    tot->Draw("A");*/
}