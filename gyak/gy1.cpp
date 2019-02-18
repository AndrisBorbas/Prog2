#include <iostream>

using namespace std;

struct halmaz {
    int db;
    double* adat;
};

bool benne_van_e(const halmaz& h);
int elemszam(const halmaz& h);
void init(halmaz& h) {
    h.db=0;
    h.adat=malloc(sizeof(double)*0);
}
void betesz(halmaz& h, double e){
  double* ujadat=malloc(sizeof(double)*1);
}
void kivesz(halmaz& h, int e);
void kiir(const halmaz& h);
halmaz metszet(const halmaz& h1, const halmaz& h2);
halmaz beolvas(char const* f);


int& kisebb(int& a, int& b) {
    if(a<b) return a;
    else return b;
}

void fajlbe(const char* fajlnev);

int main() {
    int* p = NULL;
    //int& p = NULL;
    int i = 314;
    int j = 5;
    int& r=i;
    int& r2=r;
    cout<<i<<" "<<r<<endl;
    r2=278;
    cout<<i<<" "<<r2<<endl;
    //kisebb(i,100);
    cout<<kisebb(i,j);


    const double pi = 3.141592;
    //const char=char const
}
