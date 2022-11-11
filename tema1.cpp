#include <iostream>
using namespace std;

class cladire {
int nrCamere,dimensiune,geamuri;//dimensiune m^2
public:
cladire(); // constructor
~cladire(); // destructor
cladire(int n,int d,int g) {nrCamere=n; dimensiune=d; geamuri=g;}
void setCladire(int n,int d,int g);
void cameraRatio();
private:
cladire(const cladire&);
cladire& operator=(const cladire&);
};

cladire::cladire()
{
nrCamere= dimensiune =geamuri= 0;
cout << "cladire initializata.\n";
}

cladire::~cladire()
{
cout << "cladire distrusa.\n";
}
void cladire::setCladire(int n,int d,int g)
{
    nrCamere=n; dimensiune=d; geamuri=g;
}
void cladire::cameraRatio()
{
    float ratio;
    ratio=(float)dimensiune/nrCamere;
    cout<<"cladire ratio="<<ratio<<"\n";
}
int main()
{
     cladire c1,c2;
     // c1=c2;
     // cladire c3(c1);
     c1.setCladire(6,250,5);
     c2.setCladire(5,200,4);
     c1.cameraRatio();
     c2.cameraRatio();
    return 0;
}
