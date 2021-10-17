# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <iostream>
#include <cmath>

#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TFitResult.h"

using namespace std;

int main()
{
    TCanvas c;
    
    TH1F * h_530_100 = new TH1F("h_510_100", "Picco ferro + Cosmici", 17000, 0, 17000);
    TH1F * h_530_100_old = new TH1F("h_510_100_old", "Picco", 8192, 0, 8192);
    TH1F * h_cr = new TH1F("h_cr", "Picco", 700, 0, 7);

    FILE * f1=fopen("cosmici.lvm", "r");
    FILE * f_530_100=fopen("510V_mesh_10V_100.txt", "r");
    int cnt_530_100[8192];
    float V_in[8119], rV_in;
    int ccnt_530_100;
    
    for(int i=0 ; i<=8191 ; i++){ //Lettura ferro
        fscanf(f_530_100,"%i \n", &ccnt_530_100);
        cnt_530_100[i]=ccnt_530_100;
    }
    for(int i=1 ; i<=8119 ; i++){ //Lettura cosmici
        fscanf(f1,"%f \n", &rV_in);
        V_in[i]=rV_in;
    }

    for(int i=1 ; i<=8119 ; i++){
        h_cr->Fill(V_in[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_530_100->SetBinContent(i*3.5,cnt_530_100[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_530_100_old->SetBinContent(i,cnt_530_100[i]);
    }
    
    TFitResultPtr b_5=h_530_100->Fit("gaus","S","",7500,10500);
    Double_t b5 = b_5 -> Parameter(1);
    Double_t e_b5 = b_5 -> ParError (1);
    double V_b5,V_e_b5;
    V_b5 = b5*0.00122;
    V_e_b5 = e_b5*0.00122;
    cout<<"Valor medio in volt: "<< V_b5 << " +/- " << V_e_b5<<endl;

    h_530_100_old->Rebin(35);
    h_530_100->Rebin(25);

    h_530_100->Draw();  h_cr->Draw("SAME");    c.SaveAs("h_510_100.png");
    h_530_100_old->Draw();    c.SaveAs("h_510_100_old.png");
}