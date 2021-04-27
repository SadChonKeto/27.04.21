#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class Furniture
{
public: 
    string material, company, typewhrusd; 
    Furniture(string material, string company, string typewhrusd)
    {
        this->material = material;
        this->company = company;
        this->typewhrusd = typewhrusd;
    }
    Furniture();
};

class Objfurniture : public Furniture
{
public:
    string objtype;
    int numb;
    Objfurniture(string material, string company, string typewhrusd, string objtype, int numb)
    {
        this->material = material;
        this->company = company;
        this->typewhrusd = typewhrusd;
        this->objtype = objtype;
        this->numb = numb;
    }
    void print();
    Objfurniture();
};
/*void Objfurniture::print()
{
    //ifstream ifs("Furniture.txt");
    //ifs>>material>>company>>typewhrusd>>objtype>>numb;
    cout<<material<<" "<<company<<" "<<typewhrusd<<" "<<objtype<<" "<<numb;
}*/
int main()
{
    ifstream ifs("Furniture.txt");
    string wantedType;
    cin>>wantedType;
    Objfurniture objf;
    Furniture f;
    vector<Furniture> bbb;
    vector <Objfurniture> aaa;
    while(ifs>>objf.material>>objf.company>>objf.typewhrusd>>objf.objtype>>objf.numb)
    {
        //aaa.push_back(objf);
        if (wantedType == f.typewhrusd)
        {
        objf.material=f.material;
        objf.company=f.company;
        objf.typewhrusd=f.typewhrusd;
        ifs>> objf.objtype>>objf.numb;
        aaa.push_back(objf);
        //objf.print();
        //cout<<objf.material<<" "<<objf.company<<" "<<objf.typewhrusd<<" "<<objf.objtype<<" "<<objf.numb;}
        }
        else(bbb.push_back(objf));
    }
    for (int i=0; i<aaa.size(); i++)
    {
        if(aaa[i].typewhrusd == wantedType)
        cout<<aaa[i].material<<" "<<aaa[i].company<<" "<<aaa[i].typewhrusd<<" "<<aaa[i].objtype<<" "<<aaa[i].numb;
    }
}