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
    
    TH1F * h_490_100 = new TH1F("h_490_100", "Picco", 8192, 0, 8192);
    TH1F * h_500_100 = new TH1F("h_500_100", "Picco", 8192, 0, 8192);
    TH1F * h_510_100 = new TH1F("h_510_100", "Picco", 8192, 0, 8192);
    TH1F * h_520_100 = new TH1F("h_520_100", "Picco", 8192, 0, 8192);
    TH1F * h_530_100 = new TH1F("h_530_100", "Picco", 8192, 0, 8192);
    TH1F * h_540_100 = new TH1F("h_540_100", "Picco", 8192, 0, 8192);
    TH1F * h_550_100 = new TH1F("h_550_100", "Picco", 8192, 0, 8192);
    TH1F * h_560_100 = new TH1F("h_560_100", "Picco", 8192, 0, 8192);

    TH1F * h_490_50 = new TH1F("h_490_50", "Picco", 8192, 0, 8192);
    TH1F * h_500_50 = new TH1F("h_500_50", "Picco", 8192, 0, 8192);
    TH1F * h_510_50 = new TH1F("h_510_50", "Picco", 8192, 0, 8192);
    TH1F * h_520_50 = new TH1F("h_520_50", "Picco", 8192, 0, 8192);
    TH1F * h_530_50 = new TH1F("h_530_50", "Picco", 8192, 0, 8192);
    TH1F * h_540_50 = new TH1F("h_540_50", "Picco", 8192, 0, 8192);
    TH1F * h_550_50 = new TH1F("h_550_50", "Picco", 8192, 0, 8192);
    TH1F * h_560_50 = new TH1F("h_560_50", "Picco", 8192, 0, 8192);

    FILE * f_490_50=fopen("490V_mesh_10V_50.txt", "r");
    FILE * f_500_50=fopen("500V_mesh_10V_50.txt", "r");
    FILE * f_510_50=fopen("510V_mesh_10V_50.txt", "r");
    FILE * f_520_50=fopen("520V_mesh_10V_50.txt", "r");
    FILE * f_530_50=fopen("530V_mesh_10V_50.txt", "r");
    FILE * f_540_50=fopen("540V_mesh_10V_50.txt", "r");
    FILE * f_550_50=fopen("550V_mesh_10V_50.txt", "r");
    FILE * f_560_50=fopen("560V_mesh_10V_50.txt", "r");

    FILE * f_490_100=fopen("490V_mesh_10V_100.txt", "r");
    FILE * f_500_100=fopen("500V_mesh_10V_100.txt", "r");
    FILE * f_510_100=fopen("510V_mesh_10V_100.txt", "r");
    FILE * f_520_100=fopen("520V_mesh_10V_100.txt", "r");
    FILE * f_530_100=fopen("530V_mesh_10V_100.txt", "r");
    FILE * f_540_100=fopen("540V_mesh_10V_100.txt", "r");
    FILE * f_550_100=fopen("550V_mesh_10V_100.txt", "r");
    FILE * f_560_100=fopen("560V_mesh_10V_100.txt", "r");

    int cnt_490_100[8192],cnt_500_100[8192],cnt_510_100[8192],cnt_520_100[8192],cnt_530_100[8192],cnt_540_100[8192],cnt_550_100[8192];
    int cnt_490_50[8192],cnt_500_50[8192],cnt_510_50[8192],cnt_520_50[8192],cnt_530_50[8192],cnt_540_50[8192],cnt_550_50[8192],cnt_560_50[8192];
    
    int ccnt_490_100,ccnt_500_100,ccnt_510_100,ccnt_520_100,ccnt_530_100,ccnt_540_100,ccnt_550_100;
    int ccnt_490_50,ccnt_500_50,ccnt_510_50,ccnt_520_50,ccnt_530_50,ccnt_540_50,ccnt_550_50,ccnt_560_50;  

    //-----LETTURA DATI-----//

    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_490_50,"%i \n", &ccnt_490_50);
        cnt_490_50[i]=ccnt_490_50;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_500_50,"%i \n", &ccnt_500_50);
        cnt_500_50[i]=ccnt_500_50;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_510_50,"%i \n", &ccnt_510_50);
        cnt_510_50[i]=ccnt_510_50;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_520_50,"%i \n", &ccnt_520_50);
        cnt_520_50[i]=ccnt_520_50;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_530_50,"%i \n", &ccnt_530_50);
        cnt_530_50[i]=ccnt_530_50;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_540_50,"%i \n", &ccnt_540_50);
        cnt_540_50[i]=ccnt_540_50;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_550_50,"%i \n", &ccnt_550_50);
        cnt_550_50[i]=ccnt_550_50;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_560_50,"%i \n", &ccnt_560_50);
        cnt_560_50[i]=ccnt_560_50;
    }

    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_490_100,"%i \n", &ccnt_490_100);
        cnt_490_100[i]=ccnt_490_100;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_500_100,"%i \n", &ccnt_500_100);
        cnt_500_100[i]=ccnt_500_100;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_510_100,"%i \n", &ccnt_510_100);
        cnt_510_100[i]=ccnt_510_100;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_520_100,"%i \n", &ccnt_520_100);
        cnt_520_100[i]=ccnt_520_100;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_530_100,"%i \n", &ccnt_530_100);
        cnt_530_100[i]=ccnt_530_100;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_540_100,"%i \n", &ccnt_540_100);
        cnt_540_100[i]=ccnt_540_100;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(f_550_100,"%i \n", &ccnt_550_100);
        cnt_550_100[i]=ccnt_550_100;
    }


    //-----RIEMPIO GLI ISTOGRAMMI, LI SALVO-----//

    for(int i=0 ; i<=8191 ; i++){
        h_490_50->SetBinContent(i,cnt_490_50[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_500_50->SetBinContent(i,cnt_500_50[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_510_50->SetBinContent(i,cnt_510_50[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_520_50->SetBinContent(i,cnt_520_50[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_530_50->SetBinContent(i,cnt_530_50[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_540_50->SetBinContent(i,cnt_540_50[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_550_50->SetBinContent(i,cnt_550_50[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_560_50->SetBinContent(i,cnt_560_50[i]);
    }

    for(int i=0 ; i<=8191 ; i++){
        h_490_100->SetBinContent(i,cnt_490_100[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_500_100->SetBinContent(i,cnt_500_100[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_510_100->SetBinContent(i,cnt_510_100[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_520_100->SetBinContent(i,cnt_520_100[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_530_100->SetBinContent(i,cnt_530_100[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_540_100->SetBinContent(i,cnt_540_100[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_550_100->SetBinContent(i,cnt_550_100[i]);
    }

    cout<<"Fit per 500_100"<<endl;
    TFitResultPtr b_2=h_500_100->Fit("gaus","S","",1600,2200);
    Double_t b2 = b_2 -> Parameter(1);
    Double_t e_b2 = b_2 -> ParError (1);
    double V_b2,V_e_b2;
    V_b2 = b2*0.00122;
    V_e_b2 = e_b2*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b2<< "+-" <<V_e_b2<< " V" <<endl<<endl;

    h_490_50->Draw();    c.SaveAs("h_490_50.png");
    h_500_50->Draw();    c.SaveAs("h_500_50.png");
    h_510_50->Draw();    c.SaveAs("h_510_50.png");
    h_520_50->Draw();    c.SaveAs("h_520_50.png");
    h_530_50->Draw();    c.SaveAs("h_530_50.png");
    h_540_50->Draw();    c.SaveAs("h_540_50.png");
    h_550_50->Draw();    c.SaveAs("h_550_50.png");
    h_560_50->Draw();    c.SaveAs("h_560_50.png");

    h_490_100->Draw();    c.SaveAs("h_490_100.png");
    h_500_100->Draw();    c.SaveAs("h_500_100.png");
    h_510_100->Draw();    c.SaveAs("h_510_100.png");
    h_520_100->Draw();    c.SaveAs("h_520_100.png");
    h_530_100->Draw();    c.SaveAs("h_530_100.png");
    h_540_100->Draw();    c.SaveAs("h_540_100.png");
    h_550_100->Draw();    c.SaveAs("h_550_100.png");

    //-------FIT-------//

    cout<<"Fit per 490_50"<<endl;
    TFitResultPtr a_1=h_490_50->Fit("gaus","S","",600,900);
    Double_t a1 = a_1 -> Parameter(1);
    Double_t e_a1 = a_1 -> ParError (1);
    double V_a1,V_e_a1;
    V_a1 = a1*0.00122;
    V_e_a1 = e_a1*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a1<< "+-" <<V_e_a1<< " V" <<endl<<endl;

    cout<<"Fit per 500_50"<<endl;
    TFitResultPtr a_2=h_500_50->Fit("gaus","S","",900,1100);
    Double_t a2 = a_2 -> Parameter(1);
    Double_t e_a2 = a_2 -> ParError (1);
    double V_a2,V_e_a2;
    V_a2 = a2*0.00122;
    V_e_a2 = e_a2*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a2<< "+-" <<V_e_a2<< " V" <<endl<<endl;

    cout<<"Fit per 510_50"<<endl;
    TFitResultPtr a_3=h_510_50->Fit("gaus","S","",1100,1500);
    Double_t a3 = a_3 -> Parameter(1);
    Double_t e_a3 = a_3 -> ParError (1);
    double V_a3,V_e_a3;
    V_a3 = a3*0.00122;
    V_e_a3 = e_a3*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a3<< "+-" <<V_e_a3<< " V" <<endl<<endl;
    
    cout<<"Fit per 520_50"<<endl;
    TFitResultPtr a_4=h_520_50->Fit("gaus","S","",1400,1800);
    Double_t a4 = a_4 -> Parameter(1);
    Double_t e_a4 = a_4 -> ParError (1);
    double V_a4,V_e_a4;
    V_a4 = a4*0.00122;
    V_e_a4 = e_a4*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a4<< "+-" <<V_e_a4<< " V" <<endl<<endl;
    
    cout<<"Fit per 530_50"<<endl;
    TFitResultPtr a_5=h_530_50->Fit("gaus","S","",1800,2800);
    Double_t a5 = a_5 -> Parameter(1);
    Double_t e_a5 = a_5 -> ParError (1);
    double V_a5,V_e_a5;
    V_a5 = a5*0.00122;
    V_e_a5 = e_a5*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a5<< "+-" <<V_e_a5<< " V" <<endl<<endl;
    
    cout<<"Fit per 540_50"<<endl;
    TFitResultPtr a_6=h_540_50->Fit("gaus","S","",2400,3400);
    Double_t a6 = a_6 -> Parameter(1);
    Double_t e_a6 = a_6 -> ParError (1);
    double V_a6,V_e_a6;
    V_a6 = a6*0.00122;
    V_e_a6 = e_a6*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a6<< "+-" <<V_e_a6<< " V" <<endl<<endl;
    
    cout<<"Fit per 550_50"<<endl;
    TFitResultPtr a_7=h_550_50->Fit("gaus","S","",3000,4800);
    Double_t a7 = a_7 -> Parameter(1);
    Double_t e_a7 = a_7 -> ParError (1);
    double V_a7,V_e_a7;
    V_a7 = a7*0.00122;
    V_e_a7 = e_a7*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a7<< "+-" <<V_e_a7<< " V" <<endl<<endl;
    
    cout<<"Fit per 560_50"<<endl;
    TFitResultPtr a_8=h_560_50->Fit("gaus","S","",4000,6000);
    Double_t a8 = a_8 -> Parameter(1);
    Double_t e_a8 = a_8 -> ParError (1);
    double V_a8,V_e_a8;
    V_a8 = a8*0.00122;
    V_e_a8 = e_a8*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_a8<< "+-" <<V_e_a8<< " V" <<endl<<endl;


    cout<<"Fit per 490_100"<<endl;
    TFitResultPtr b_1=h_490_100->Fit("gaus","S","",1200,1800);
    Double_t b1 = b_1 -> Parameter(1);
    Double_t e_b1 = b_1 -> ParError (1);
    double V_b1,V_e_b1;
    V_b1 = b1*0.00122;
    V_e_b1 = e_b1*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b1<< "+-" <<V_e_b1<< " V" <<endl<<endl;

   /* cout<<"Fit per 500_100"<<endl;
    TFitResultPtr b_2=h_500_100->Fit("gaus","S","",1600,2200);
    Double_t b2 = b_2 -> Parameter(1);
    Double_t e_b2 = b_2 -> ParError (1);
    double V_b2,V_e_b2;
    V_b2 = b2*0.00122;
    V_e_b2 = e_b2*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b2<< "+-" <<V_e_b2<< " V" <<endl<<endl;*/

    cout<<"Fit per 510_100"<<endl;
    TFitResultPtr b_3=h_510_100->Fit("gaus","S","",2000,3000);
    Double_t b3 = b_3 -> Parameter(1);
    Double_t e_b3 = b_3 -> ParError (1);
    double V_b3,V_e_b3;
    V_b3 = b3*0.00122;
    V_e_b3 = e_b3*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b3<< "+-" <<V_e_b3<< " V" <<endl<<endl;
    
    cout<<"Fit per 520_100"<<endl;
    TFitResultPtr b_4=h_520_100->Fit("gaus","S","",1600,3900);
    Double_t b4 = b_4 -> Parameter(1);
    Double_t e_b4 = b_4 -> ParError (1);
    double V_b4,V_e_b4;
    V_b4 = b4*0.00122;
    V_e_b4 = e_b4*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b4<< "+-" <<V_e_b4<< " V" <<endl<<endl;
    
    cout<<"Fit per 530_100"<<endl;
    TFitResultPtr b_5=h_530_100->Fit("gaus","S","",3400,5000);
    Double_t b5 = b_5 -> Parameter(1);
    Double_t e_b5 = b_5 -> ParError (1);
    double V_b5,V_e_b5;
    V_b5 = b5*0.00122;
    V_e_b5 = e_b5*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b5<< "+-" <<V_e_b5<< " V" <<endl<<endl;
    
    cout<<"Fit per 540_100"<<endl;
    TFitResultPtr b_6=h_540_100->Fit("gaus","S","",4400,6600);
    Double_t b6 = b_6 -> Parameter(1);
    Double_t e_b6 = b_6 -> ParError (1);
    double V_b6,V_e_b6;
    V_b6 = b6*0.00122;
    V_e_b6 = e_b6*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b6<< "+-" <<V_e_b6<< " V" <<endl<<endl;
    
    cout<<"Fit per 550_100"<<endl;
    TFitResultPtr b_7=h_550_100->Fit("gaus","S","",7800,8190);
    Double_t b7 = b_7 -> Parameter(1);
    Double_t e_b7 = b_7 -> ParError (1);
    double V_b7,V_e_b7;
    V_b7 = b7*0.00122;
    V_e_b7 = e_b7*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_b7<< "+-" <<V_e_b7<< " V" <<endl<<endl;
}