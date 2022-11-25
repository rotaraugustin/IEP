#include <iostream>
using namespace std;
void message(char *s)
{
    cout<<s<<"\n";
}
class usa{
int nrUsi;
public:
int getUsi()
{
    return nrUsi;
}
void setUsi(int u)
{
    nrUsi=u;
}
};
class cladire {
int nrCamere,dimensiune,geamuri;//dimensiune m^2
usa * usi;
public:
cladire& operator=(const cladire& c)
{
    message("cladire copy assignment");
    if (this == &c) return *this;
    nrCamere=c.nrCamere;
    dimensiune=c.dimensiune;
    geamuri=c.geamuri;
    delete usi;
    usi=new usa(*c.usi);
    return *this;
}
cladire(const cladire& c){
  message("cladire copy constructor");
  nrCamere=c.nrCamere;
  dimensiune=c.dimensiune;
  geamuri=c.geamuri;
  usi=c.usi;
}
cladire(); // constructor
~cladire(); // destructor
void setCladire(int n,int d,int g,int u);
void cameraRatio();
void cladireUsi()
{
    cout<<usi->getUsi()<<"\n";
}
};

cladire::cladire()
{
nrCamere= dimensiune =geamuri= 0;
usi=new usa();
cout << "cladire initializata.\n";
}

cladire::~cladire()
{
cout << "cladire distrusa.\n";
}
void cladire::setCladire(int n,int d,int g,int u)
{
    nrCamere=n; dimensiune=d; geamuri=g;
    usi->setUsi(u);
}
void cladire::cameraRatio()
{
    float ratio;
    ratio=(float)dimensiune/nrCamere;
    cout<<"cladire ratio="<<ratio<<"\n";
}
class casa:public cladire
{
public:
   casa(){cout << "casa initializata.\n";}
   ~casa(){cout << "casa distrusa.\n";}
   casa(const casa &cs):cladire(cs){
    message("casa copy constructor");
   }
   casa& operator=(const casa &cs)
   {
    message("casa copy assignment");
    cladire::operator=(cs);
    return *this;
   }
};
int main()
{
     cladire c1,c2,c3;
     casa cs1,cs3;
     cs1.setCladire(3,100,4,5);
     c1.setCladire(6,250,5,9);
     c1=c1;
     cladire c4(c1);
     casa cs2(cs1);
     cs3=cs1;
     c2=c3=c1;
     c1.cameraRatio();
     c2.cameraRatio();
     c4.cameraRatio();
     c1.cladireUsi();
     c2.cladireUsi();
     c3.cladireUsi();
     c4.cladireUsi();
     cs2.cladireUsi();
     cs3.cladireUsi();
    return 0;
}
