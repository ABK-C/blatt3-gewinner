#include <iostream>
#include <fstream>
#include <vector>


double poisson(double mu, int k) {
    return 0;
}

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    int n_i;
    vector<int> zaehler(11);
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] +=1;
        
    }
    fin.close();
    int m = 0;
    for(std::vector<int>::const_iterator n = zaehler.begin(); n != zaehler.end(); ++n){
      
      std::cout << *n << ' ';

      fout << m << ' ' << *n << endl;
      ++m;
    }

    
    

}