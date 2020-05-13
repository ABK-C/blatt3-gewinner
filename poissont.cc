#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    double uk = pow(mu, k);
    double eu = exp(-mu);
    double f = tgamma(k+1);

    double p = uk*eu/f;


    return p;
}

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream fout2("histpoi.txt");
    int n_i;
    vector<int> zaehler(11);
    
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] +=1;
        
    }
    fin.close();
    int m = 0;
    double mu = 3.11538;
    int h = 234;
    for(std::vector<int>::const_iterator n = zaehler.begin(); n != zaehler.end(); ++n){
      double poi = poisson(mu, m);
      std::cout << *n << endl;

      fout << m << ' ' << *n << endl;
      fout2 << m << ' ' << *n << ' ' << h*poi << endl;
      ++m;
    }

    

}