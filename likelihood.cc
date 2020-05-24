#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double prob(int k, double mu) {
return pow(mu,k)*exp(-mu)/tgamma(k+1);    
}

double mu;
double L = 1;
double y_ges = 1;
int i;

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    ofstream fout("likelihood.txt");
    ofstream fout2("nll.txt");
    ofstream fout3("deltanll.txt");

    vector<int> daten;
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }

    for(int k : daten) {
    double li = prob(k, 3.11538);
    L *= li;

    double y = prob(k, k);
    y_ges *= y;
     } 
    
    cout << L << endl;

    for (mu = 0; mu < 6; mu+=0.01) {
      double L2 = 1;
      
      for(int k : daten) {    
        double li2 = prob(k, mu);
        L2 *= li2;  
      }

      fout << mu << " " << L2 << endl;
      
      fout2 << mu << " " << -2*log(L2) << endl;

      fout3 << mu << " " << -2*log(L2)-(-2*log(3.11538)) << endl;
      
    }
    fout << "Der beste Schätzwert für mu liegt bei ca. 3.12." << endl;
    fout3 << "Das Minimum des negative Log-Likelihood -ln(L) liegt ebenso bei mu = 3.12 und beträgt 446,955. Das Intervall, in dem -ln(L) jm weniger als 1,0 größer als im Minimum ist, beträgt [2.96:3.28]" << endl;

double lambda = L/y_ges;

cout << lambda << endl;

int n_dof = 233;

double z = (-2*log(lambda) - n_dof) / sqrt(2* n_dof);

cout << z << endl;

    fin.close();
    fout.close();
    fout2.close();
    fout3.close();


}
