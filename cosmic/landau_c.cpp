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

void landau_c()
{
    TCanvas c;

    TH1F * h_cr = new TH1F("h_cr", "Picco", 700, 0.8, 6.8);

    FILE * f1=fopen("cosmici.lvm", "r");

    float V_in[8119];
    float rV_in;  

    //-----ACQUISIZIONE DATI-----//
    for(int i=1 ; i<=8119 ; i++){
        fscanf(f1,"%f \n", &rV_in);
        V_in[i]=rV_in;
    }
    //-----RIEMPIO GLI ISTOGRAMMI, LI SALVO-----//
    for(int i=1 ; i<=8119 ; i++){
        h_cr->Fill(V_in[i]);
    }
    gStyle->SetOptStat(0);
    h_cr->SetTitle("Spettro Raggi Cosmici");
    h_cr->GetXaxis()->SetTitle("Tensione (V)");
    h_cr->GetYaxis()->SetTitle("Conteggi");
    h_cr->Draw();   c.SaveAs("h_cr.png");
    TFitResultPtr par_cr=h_cr->Fit("landau","S","",1,6.5); 
    h_cr->Draw();   c.SaveAs("h_cr_fit.png");
    
    /*Double_t l1 = k_1 -> Parameter(1);  Double_t r1 = k_1 -> ParError (1); double V_l1,V_r1;
    V_l1 = l1*0.00122;  V_r1 = r1*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_l1<< "+-" <<V_r1<< " V" <<endl<<endl;*/
    
}