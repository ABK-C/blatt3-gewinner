#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double mu, P;
int k;
int i=0;
double poisson(double mu, int k) {
 return pow(mu, k) * exp(-mu) /  tgamma(k+1);
}

int main() {
    using namespace std;

    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream fout2("histpoi.txt");

    vector<int> zaehler(11);
    int zahl;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> zahl;
        zaehler[zahl] += 1;
    }
    

    for(auto it = zaehler.begin(); it != zaehler.end(); ++it) {
      fout << i << " " << *it << endl;
      fout2 << i << " " << *it << " " << 234*poisson(3.11538, i) << endl;
      ++i;
}
    fin.close();
}


