#include <iostream>
#include <fstream>
#include <vector>


double poisson(double mu, int k) {
    return 0;
}

int main() {
    using namespace std;

    ifstream fin("datensumme.txt");
    vector<int> zaehler(11);
    int zahl;
    int i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> zahl;
        zaehler[zahl] += 1;
    }
    
    for(auto it = zaehler.begin(); it != zaehler.end(); ++it) 
      cout << *it << endl;
    //for (i = 200; i <230; ++i) {
    //cout << zaehler[i] << endl;
    //}
    
    fin.close();
}
