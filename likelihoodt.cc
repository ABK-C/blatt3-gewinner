#include<cmath>
#include <iostream>
#include <fstream>
#include <vector>


double prob(int k, double mu){
    double p = 1;
    double uk = pow(mu, k);
    double eu = exp(-mu);
    double f = tgamma(k+1);
    p = uk*eu/f;
    return p;
  }

int main(){
  using namespace std;
  vector<int> daten;
  

  ifstream fin("datensumme.txt");
  int n_i;
  for(int i = 0; i < 234; i++){
    fin >> n_i;
    daten.push_back(n_i);
  }

  double mu = 3.11538;
  double li = 1;
  double l = 1;
  for(int k : daten){
    double li = prob(k, mu);
    l *= li;
  }

  cout << l << endl;

  ofstream fout("likelihood.txt");
  ofstream fout2("likelihood2.txt");
  for(double u = 0; u < 6;){
    double h = 1;
    for(int n : daten){
      double hi = prob(n, u);
      h *= hi;
    }

    fout << u <<' '<< h << endl;
    fout2 << h << endl;
    u += 0.01;
  }




}