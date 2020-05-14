#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


int main() {
    using namespace std;

    ifstream fin("likelihood2.txt");
    double b;
    double a;
    b = 0;
    for(int i = 0; i < 602; ++i) {
      fin >> a;
      if(b <= a){
        b = a;
      }

    }
    cout << b << endl;
}