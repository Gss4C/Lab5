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

    TH1F * h_510_50_w = new TH1F("h_510_50_w", "Picco", 8192, 0, 8192);
    TH1F * h_510_50_wo = new TH1F("h_510_50_wo", "Picco", 8192, 0, 8192);
    TH1F * h_510_100_w = new TH1F("h_510_100_w", "Picco", 8192, 0, 8192);
    TH1F * h_510_100_wo = new TH1F("h_510_100_wo", "Picco", 8192, 0, 8192);

    TH1F * h_500_100_w = new TH1F("h_500_100_w", "Picco", 8192, 0, 8192);
    TH1F * h_500_100_wo = new TH1F("h_500_100_wo", "Picco", 8192, 0, 8192);
    TH1F * h_500_50_w = new TH1F("h_500_50_w", "Picco", 8192, 0, 8192);
    TH1F * h_500_50_wo = new TH1F("h_500_50_wo", "Picco", 8192, 0, 8192);

    TH1F * h_490_100_w = new TH1F("h_490_100_w", "Picco", 8192, 0, 8192);
    TH1F * h_490_100_wo = new TH1F("h_490_100_wo", "Picco", 8192, 0, 8192);
    TH1F * h_490_50_w = new TH1F("h_490_50_w", "Picco", 8192, 0, 8192);
    TH1F * h_490_50_wo = new TH1F("h_490_50_wo", "Picco", 8192, 0, 8192);

    TH1F * h_480_100_w = new TH1F("h_480_100_w", "Picco", 8192, 0, 8192);
    TH1F * h_480_100_wo = new TH1F("h_480_100_wo", "Picco", 8192, 0, 8192);
    TH1F * h_480_50_w = new TH1F("h_480_50_w", "Picco", 8192, 0, 8192);
    TH1F * h_480_50_wo = new TH1F("h_480_50_wo", "Picco", 8192, 0, 8192);

    TH1F * h_470_50_w = new TH1F("h_470_50_w", "Picco 470 ampl 50 con ", 8192, 0, 8192);
    TH1F * h_470_50_wo = new TH1F("h_470_50_wo", "Picco 470 ampl 50 senza ", 8192, 0, 8192);
    TH1F * h_470_100_w= new TH1F("h_470_100_w", "Picco 470 ampl 100 con ", 8192, 0, 8192);
    TH1F * h_470_100_wo= new TH1F("h_470_100_wo", "Picco 470 ampl 100 senza ", 8192, 0, 8192);

    TH1F * h_460_100_w = new TH1F("h_460_100_w", "Picco 460 ampl 100 con", 8192, 0, 8192);
    TH1F * h_460_100_wo = new TH1F("h_460_100_wo", "Picco 460 ampl 100 senza", 8192, 0, 8192);

    FILE * infile_4=fopen("510Ampl50_con.txt", "r");
    FILE * infile_5=fopen("510Ampl50_senza.txt", "r");
    FILE * infile_6=fopen("510Ampl100_con.txt", "r");
    FILE * infile_7=fopen("510Ampl100_senza.txt", "r");

    FILE * infile_0=fopen("500Ampl100_con.txt", "r");
    FILE * infile_1=fopen("500Ampl100_senza.txt", "r");
    FILE * infile_2=fopen("500Ampl50_con.txt", "r");
    FILE * infile_3=fopen("500Ampl50_senza.txt", "r");

    FILE * infile0=fopen("490Ampl100_con.txt", "r");
    FILE * infile1=fopen("490Ampl100_senza.txt", "r");
    FILE * infile2=fopen("490Ampl50_con.txt", "r");
    FILE * infile3=fopen("490Ampl50_senza.txt", "r");

    FILE * infile4=fopen("480Ampl100_con.txt", "r");
    FILE * infile5=fopen("480Ampl100_senza.txt", "r");
    FILE * infile6=fopen("480Ampl50_con.txt", "r");
    FILE * infile7=fopen("480Ampl50_senza.txt", "r");

    FILE * infile_f=fopen("470_100_wo.txt", "r");
    FILE * infile_e=fopen("470_100_w.txt", "r");
    FILE * infile_d=fopen("470_50_wo.txt", "r");
    FILE * infile_c=fopen("470_50_w.txt", "r");

    FILE * infile_b=fopen("460_100_wo.txt", "r");
    FILE * infile_a=fopen("460_100_w.txt", "r");

    int cnt_490_100_w[8192],cnt_490_100_wo[8192],cnt_490_50_w[8192],cnt_490_50_wo[8192],cnt_480_100_w[8192],cnt_480_100_wo[8192],cnt_480_50_w[8192],cnt_480_50_wo[8192];
    int cnt_500_100_w[8192],cnt_500_100_wo[8192],cnt_500_50_w[8192],cnt_500_50_wo[8192];
    int cnt_460_100_w[8192],cnt_460_100_wo[8192],cnt_470_50_w[8192],cnt_470_50_wo[8192],cnt_470_100_w[8192],cnt_470_100_wo[8192];
    int cnt_510_50_w[8192],cnt_510_50_wo[8192],cnt_510_100_w[8192],cnt_510_100_wo[8192];
    int ccnt_490_100_w,ccnt_490_100_wo,ccnt_490_50_w,ccnt_490_50_wo,ccnt_480_100_w,ccnt_480_100_wo,ccnt_480_50_w,ccnt_480_50_wo,ccnt_500_100_w,ccnt_500_100_wo,ccnt_500_50_w,ccnt_500_50_wo;
    int ccnt_460_100_w,ccnt_460_100_wo,ccnt_470_50_w,ccnt_470_50_wo,ccnt_470_100_w,ccnt_470_100_wo,ccnt_510_50_w,ccnt_510_50_wo,ccnt_510_100_w,ccnt_510_100_wo;  

    //-----ACQUISIZIONE DATI-----//

    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_4,"%i\n", &ccnt_510_50_w );
        cnt_510_50_w[i]=ccnt_510_50_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_5,"%i \n", &ccnt_510_50_wo);
        cnt_510_50_wo[i]=ccnt_510_50_wo;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_6,"%i \n", &ccnt_510_100_w);
        cnt_510_100_w[i]=ccnt_510_100_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_7,"%i \n", &ccnt_510_100_wo);
        cnt_510_100_wo[i]=ccnt_510_100_wo;
    }

    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_0,"%i \n", &ccnt_500_100_w);
        cnt_500_100_w[i]=ccnt_500_100_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_1,"%i \n", &ccnt_500_100_wo);
        cnt_500_100_wo[i]=ccnt_500_100_wo;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_2,"%i \n", &ccnt_500_50_w);
        cnt_500_50_w[i]=ccnt_500_50_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_3,"%i \n", &ccnt_500_50_wo);
        cnt_500_50_wo[i]=ccnt_500_50_wo;
    }

    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile0,"%i \n", &ccnt_490_100_w);
        cnt_490_100_w[i]=ccnt_490_100_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile1,"%i \n", &ccnt_490_100_wo);
        cnt_490_100_wo[i]=ccnt_490_100_wo;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile2,"%i \n", &ccnt_490_50_w);
        cnt_490_50_w[i]=ccnt_490_50_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile3,"%i \n", &ccnt_490_50_wo);
        cnt_490_50_wo[i]=ccnt_490_50_wo;
    }

    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile4,"%i \n", &ccnt_480_100_w);
        cnt_480_100_w[i]=ccnt_480_100_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile5,"%i \n", &ccnt_480_100_wo);
        cnt_480_100_wo[i]=ccnt_480_100_wo;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile6,"%i \n", &ccnt_480_50_w);
        cnt_480_50_w[i]=ccnt_480_50_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile7,"%i \n", &ccnt_480_50_wo);
        cnt_480_50_wo[i]=ccnt_480_50_wo;
    }

    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_a,"%i \n", &ccnt_460_100_w);
        cnt_460_100_w[i]=ccnt_460_100_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_b,"%i \n", &ccnt_460_100_wo);
        cnt_460_100_wo[i]=ccnt_460_100_wo;
    }

    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_c,"%i \n", &ccnt_470_50_w);
        cnt_470_50_w[i]=ccnt_470_50_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_d,"%i \n", &ccnt_470_50_wo);
        cnt_470_50_wo[i]=ccnt_470_50_wo;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_e,"%i \n", &ccnt_470_100_w);
        cnt_470_100_w[i]=ccnt_470_100_w;
    }
    for(int i=0 ; i<=8191 ; i++){
        fscanf(infile_f,"%i \n", &ccnt_470_100_wo);
        cnt_470_100_wo[i]=ccnt_470_100_wo;
    }

    //-----RIEMPIO GLI ISTOGRAMMI, LI SALVO-----//

    for(int i=0 ; i<=8191 ; i++){
        h_510_50_w->SetBinContent(i,cnt_510_50_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_510_50_wo->SetBinContent(i,cnt_510_50_wo[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_510_100_w->SetBinContent(i,cnt_510_100_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_510_100_wo->SetBinContent(i,cnt_510_100_wo[i]);
    }

    for(int i=0 ; i<=8191 ; i++){
        h_500_100_w->SetBinContent(i,cnt_500_100_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_500_100_wo->SetBinContent(i,cnt_500_100_wo[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_500_50_w->SetBinContent(i,cnt_500_50_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_500_50_wo->SetBinContent(i,cnt_500_50_wo[i]);
    }

    for(int i=0 ; i<=8191 ; i++){
        h_490_100_w->SetBinContent(i,cnt_490_100_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_490_100_wo->SetBinContent(i,cnt_490_100_wo[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_490_50_w->SetBinContent(i,cnt_490_50_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_490_50_wo->SetBinContent(i,cnt_490_50_wo[i]);
    }

    for(int i=0 ; i<=8191 ; i++){
        h_480_100_w->SetBinContent(i,cnt_480_100_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_480_100_wo->SetBinContent(i,cnt_480_100_wo[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_480_50_w->SetBinContent(i,cnt_480_50_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_480_50_wo->SetBinContent(i,cnt_480_50_wo[i]);
    }

    for(int i=0 ; i<=8191 ; i++){
        h_460_100_w->SetBinContent(i,cnt_460_100_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_460_100_wo->SetBinContent(i,cnt_460_100_wo[i]);
    }

    for(int i=0 ; i<=8191 ; i++){
        h_470_50_w->SetBinContent(i,cnt_470_50_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_470_50_wo->SetBinContent(i,cnt_470_50_wo[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_470_100_w->SetBinContent(i,cnt_470_100_w[i]);
    }
    for(int i=0 ; i<=8191 ; i++){
        h_470_100_wo->SetBinContent(i,cnt_470_100_wo[i]);
    }

    h_510_50_w->Draw();    c.SaveAs("h_510_50_w.png");
    h_510_50_wo->Draw();    c.SaveAs("h_510_50_wo.png");
    h_510_100_w->Draw();    c.SaveAs("h_510_100_w.png");
    h_510_100_wo->Draw();    c.SaveAs("h_510_100_wo.png");

    h_500_50_w->Draw();    c.SaveAs("h_500_50_w.png");
    h_500_50_wo->Draw();    c.SaveAs("h_500_50_wo.png");
    h_500_100_w->Draw();    c.SaveAs("h_500_100_w.png");
    h_500_100_wo->Draw();    c.SaveAs("h_500_100_wo.png");

    h_490_100_w->Draw();    c.SaveAs("h_490_100_w.png");
    h_490_100_wo->Draw();    c.SaveAs("h_490_100_wo.png");
    h_490_50_w->Draw();    c.SaveAs("h_490_50_w.png");
    h_490_50_wo->Draw();    c.SaveAs("h_490_50_wo.png");

    h_480_100_w->Draw();    c.SaveAs("h_480_100_w.png");
    h_480_100_wo->Draw();    c.SaveAs("h_480_100_wo.png");
    h_480_50_w->Draw();    c.SaveAs("h_480_50_w.png");
    h_480_50_wo->Draw();    c.SaveAs("h_480_50_wo.png");

    h_460_100_w->Draw();    c.SaveAs("h_460_100_w.png");
    h_460_100_wo->Draw();   c.SaveAs("h_460_100_wo.png");

    h_470_50_w->Draw();     c.SaveAs("h_470_50_w.png");
    h_470_50_wo->Draw();    c.SaveAs("h_470_50_wo.png");
    h_470_100_w->Draw();    c.SaveAs("h_470_100_w.png");
    h_470_100_wo->Draw();   c.SaveAs("h_470_100_wo.png");

    //-------FIT-------//
    //510

    cout<<"Fit per 510_50_w"<<endl; //creare funzione TF1 di gauss a mano (chat teams)
    TFitResultPtr k_1=h_510_50_w->Fit("gaus","S","",3000,4000); 
    Double_t l1 = k_1 -> Parameter(1);  Double_t r1 = k_1 -> ParError (1); double V_l1,V_r1;
    V_l1 = l1*0.00122;  V_r1 = r1*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_l1<< "+-" <<V_r1<< " V" <<endl<<endl;

    cout<<"Fit per 510_50_wo"<<endl;
    TFitResultPtr k_2=h_510_50_wo->Fit("gaus","S","",3000,4000);
    Double_t l2 = k_2 -> Parameter(1);  Double_t r2 = k_2 -> ParError (1); double V_l2,V_r2;
    V_l2 = l2*0.00122;  V_r2 = r2*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_l2<< "+-" <<V_r2<< " V" <<endl<<endl;

    cout<<"Fit per 510_100_w"<<endl;
    TFitResultPtr k_3=h_510_100_w->Fit("gaus","S","",6200,8000);
    Double_t l3 = k_3 -> Parameter(1);  Double_t r3 = k_3 -> ParError (1); double V_l3,V_r3;
    V_l3 = l3*0.00122;  V_r3 = r3*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_l3<< "+-" <<V_r3<< " V" <<endl<<endl;

    cout<<"Fit per 510_100_wo"<<endl;
    TFitResultPtr k_4=h_510_100_wo->Fit("gaus","S","",6200,8000);
    Double_t l4 = k_4 -> Parameter(1);  Double_t r4 = k_4 -> ParError (1); double V_l4,V_r4;
    V_l4 = l4*0.00122;  V_r4 = r4*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_l4<< "+-" <<V_r4<< " V" <<endl<<endl;
    

    //500

    cout<<"Fit per 500_100_w"<<endl;
    TFitResultPtr b_1=h_500_100_w->Fit("gaus","S","",4800,6000);
    Double_t y1 = b_1 -> Parameter(1);  Double_t t1 = b_1 -> ParError (1); double V_y1,V_t1;
    V_y1 = y1*0.00122;  V_t1 = t1*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_y1<< "+-" <<V_t1<< " V" <<endl<<endl;

    cout<<"Fit per 500_100_wo"<<endl;
    TFitResultPtr b_2=h_500_100_wo->Fit("gaus","S","",4800,6000);
    Double_t y2 = b_2 -> Parameter(1);  Double_t t2 = b_2 -> ParError (1); double V_y2,V_t2;
    V_y2 = y2*0.00122;  V_t2 = t2*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_y1<< "+-" <<V_t1<< " V" <<endl<<endl;
    
    cout<<"Fit per 500_50_w"<<endl;
    TFitResultPtr b_3=h_500_50_w->Fit("gaus","S","",2300,2900);
    Double_t y3 = b_3 -> Parameter(1);  Double_t t3 = b_3 -> ParError (1); double V_y3,V_t3;
    V_y3 = y3*0.00122;  V_t3 = t3*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_y3<< "+-" <<V_t3<< " V" <<endl<<endl;

    cout<<"Fit per 500_50_wo"<<endl;
    TFitResultPtr b_4=h_500_50_wo->Fit("gaus","S","",2300,2900);
    Double_t y4 = b_4 -> Parameter(1);  Double_t t4 = b_4 -> ParError (1); double V_y4,V_t4;
    V_y4 = y4*0.00122;  V_t4 = t4*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_y4<< "+-" <<V_t4<< " V" <<endl<<endl;
    
    
    //490

    cout<<"Fit per 490_100_w"<<endl;
    TFitResultPtr h_1=h_490_100_w->Fit("gaus","S","",3500,4500);
    Double_t p1 = h_1 -> Parameter(1);  Double_t e1 = h_1 -> ParError (1); double V_p1,V_e1;
    V_p1 = p1*0.00122;  V_e1 = e1*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p1<< "+-" <<V_e1<< " V" <<endl<<endl;

    cout<<"Fit per 490_100_wo"<<endl;
    TFitResultPtr h_2=h_490_100_wo->Fit("gaus","S","",3500,4500);
    Double_t p2 = h_2 -> Parameter(1);  Double_t e2 = h_2 -> ParError (1); double V_p2,V_e2;
    V_p2 = p2*0.00122;  V_e2 = e2*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p1<< "+-" <<V_e1<< " V" <<endl<<endl;
    
    /*cout<<"Fit per 490_50_w"<<endl;
    TFitResultPtr h_3=h_490_50_w->Fit("gaus","S","",3500,4500);
    Double_t p3 = h_3 -> Parameter(1);  Double_t e3 = h_3 -> ParError (1); double V_p3,V_e3;
    V_p3 = p3*0.00122;  V_e3 = e3*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p3<< "+-" <<V_e3<< " V" <<endl<<endl; */

    cout<<"Fit per 490_50_wo"<<endl;
    TFitResultPtr h_4=h_490_50_wo->Fit("gaus","S","",1800,2200);
    Double_t p4 = h_4 -> Parameter(1);  Double_t e4 = h_4 -> ParError (1); double V_p4,V_e4;
    V_p4 = p4*0.00122;  V_e4 = e4*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p4<< "+-" <<V_e4<< " V" <<endl<<endl;

    //480

    cout<<"Fit per 480_100_w"<<endl;
    TFitResultPtr h_5=h_480_100_w->Fit("gaus","S","",2600,3500);
    Double_t p5 = h_5 -> Parameter(1);  Double_t e5 = h_5 -> ParError (1); double V_p5,V_e5;
    V_p5 = p5*0.00122;  V_e5 = e5*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p5<< "+-" <<V_e5<< " V" <<endl<<endl;

    cout<<"Fit per 480_100_wo"<<endl;
    TFitResultPtr h_6=h_480_100_wo->Fit("gaus","S","",2700,3600);
    Double_t p6 = h_6 -> Parameter(1);  Double_t e6 = h_6 -> ParError (1); double V_p6,V_e6;
    V_p6 = p6*0.00122;  V_e6 = e6*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p6<< "+-" <<V_e6<< " V" <<endl<<endl;

    /*cout<<"Fit per 480_50_w"<<endl;
    TFitResultPtr h_7=h_480_50_w->Fit("gaus","S","",3500,4500);
    Double_t p7 = h_7 -> Parameter(1);  Double_t e7 = h_7 -> ParError (1); double V_p7,V_e7;
    V_p7 = p7*0.00122;  V_e7 = e7*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p7<< "+-" <<V_e7<< " V" <<endl<<endl;*/

    cout<<"Fit per 480_50_wo"<<endl;
    TFitResultPtr h_8=h_480_50_wo->Fit("gaus","S","",1200,1800);
    Double_t p8 = h_8 -> Parameter(1);  Double_t e8 = h_8 -> ParError (1); double V_p8,V_e8;
    V_p8 = p8*0.00122;  V_e8 = e8*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_p8<< "+-" <<V_e8<< " V" <<endl<<endl;

    //460

    /*cout<<"Fit per 460_100_w"<<endl;
    TFitResultPtr a_1=h_460_100_w->Fit("gaus","S","",3500,4500);
    Double_t z1 = a_1 -> Parameter(1);
    Double_t u1 = a_1 -> ParError (1);
    double V_z1,V_u1;
    V_z1 = z1*0.00122;
    V_u1 = u1*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_z1<< "+-" <<V_u1<< " V" <<endl<<endl;
*/
    cout<<"Fit per 460_100_wo"<<endl;
    TFitResultPtr a_2=h_460_100_wo->Fit("gaus","S","",1600,2000);
    Double_t z2 = a_2 -> Parameter(1);
    Double_t u2 = a_2 -> ParError (1);
    double V_z2,V_u2;
    V_z2 = z2*0.00122;
    V_u2 = u2*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_z2<< "+-" <<V_u2<< " V" <<endl<<endl;
    
    //470

    /*cout<<"Fit per 470_50_w"<<endl;
    TFitResultPtr a_3=h_470_50_w->Fit("gaus","S","",1600,2000);
    Double_t z3 = a_3 -> Parameter(1);
    Double_t u3 = a_3 -> ParError (1);
    double V_z3,V_u3;
    V_z3 = z3*0.00122;
    V_u3 = u3*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_z3<< "+-" <<V_u3<< " V" <<endl<<endl;*/

    cout<<"Fit per 470_50_wo"<<endl;
    TFitResultPtr a_4=h_470_50_wo->Fit("gaus","S","",1100,1300);
    Double_t z4 = a_4 -> Parameter(1);
    Double_t u4 = a_4 -> ParError (1);
    double V_z4,V_u4;
    V_z4 = z4*0.00122;
    V_u4 = u4*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_z4<< "+-" <<V_u4<< " V" <<endl<<endl;

    cout<<"Fit per 470_100_w"<<endl;
    TFitResultPtr a_5=h_470_100_w->Fit("gaus","S","",2000,2800);
    Double_t z5 = a_5 -> Parameter(1);
    Double_t u5 = a_5 -> ParError (1);
    double V_z5,V_u5;
    V_z5 = z5*0.00122;
    V_u5 = u5*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_z5<< "+-" <<V_u5<< " V" <<endl<<endl;

    cout<<"Fit per 470_100_wo"<<endl;
    TFitResultPtr a_6=h_470_100_w->Fit("gaus","S","",2100,2600);
    Double_t z6 = a_6 -> Parameter(1);
    Double_t u6 = a_6 -> ParError (1);
    double V_z6,V_u6;
    V_z6 = z6*0.00122;
    V_u6 = u6*0.00122;
    cout<<"Valor medio Picco Auger = "<<V_z6<< "+-" <<V_u6<< " V" <<endl<<endl;
}

