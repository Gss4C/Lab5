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
#include <TGraphErrors.h>

using namespace std;

void fit_exp()
{
    TCanvas * c = new TCanvas("c","c",650,500);
    TCanvas * c1 = new TCanvas("c","c",650,500);

    FILE * dati=fopen("fit_exp_50_100.txt", "r");
    float v_m[5],g50[5],E_g50[5];
    float rv_m,rg50,rg100,rE_g50;
    for(int i=0 ; i<5 ; i++){
        fscanf(dati,"%f %f  %f \n", &rv_m,&rg50,&rE_g50);
        v_m[i]=rv_m;
        g50[i]=rg50;
        E_g50[i]=rE_g50;
    }

    TF1 *fnx1 = new TF1("fnx1","exp([0]+[1]*x)",466,514);

/*  Double_t b = ptr_50 -> Parameter (0); Double_t e_c = ptr_50 -> ParError (0);
    Double_t a = ptr_50 -> Parameter (1); Double_t e_a = ptr_50 -> ParError (1);*/ 
    //Sta merda sopra serve per PRENDERE i cazzo di parametri del fit

    /*TGraphErrors::TGraphErrors 	( 	Int_t  	n,
		const Float_t *  	x,
		const Float_t *  	y,
		const Float_t *  	ex = 0,
		const Float_t *  	ey = 0 
	) */

    TGraphErrors * gain_50 = new TGraphErrors(5, v_m, g50, 0, E_g50);
    TFitResultPtr ptr_50 = gain_50->Fit("fnx1","S","",460,520);
    gain_50->SetMarkerColor(1);
    gain_50->SetMarkerStyle(20);
    gain_50->SetMarkerSize(1);
    gain_50->SetTitle("Fit esponenziale del guadagno, miscela 1");
    gain_50->GetXaxis()->SetTitle("Tensione di Mesh (V)");
    gain_50->GetYaxis()->SetTitle("Guadagno (V)");
    gain_50->Draw("AP");

}