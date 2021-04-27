#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
class Instrument
{
public: string name, producer;
        int price;
        Instrument(string name, string producer, int price)
        {
            this->name = name;
            this->producer = producer;
            this->price = price;
        }
        Instrument(){}
};
class Cord:public Instrument
{
public: string ptype;
        int numb;
        Cord(string name, string producer, int price, string ptype, int numb)
        {
            this->name = name;
            this->producer = producer;
            this->price = price;
            this->ptype = ptype;
            this->numb = numb;
        }
        Cord(){};
};
class Guitar:public Cord
{
public: string type;
    Guitar(string name, string producer, int price, string ptype, int numb, string type)
    {
            this->name = name;
            this->producer = producer;
            this->price = price;
            this->ptype = ptype;
            this->numb = numb;
            this->type = type;
    }
    Guitar(){}
    void print()
    {
        cout<<name<<"\t"<<producer<<"\t"<<price<<"\t"<<ptype<<"\t"<<numb<<"\t"<<type<<endl;
    }
};
void pricesort(vector<Guitar>a)
{
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a.size()-1; j++)
        {
            if(a[j].price>a[j+1].price)
            swap(a[j], a[j+1]);
        }
    }
}
int main()
{
    ifstream ifs("guitars.txt");
    ofstream ofsbass("bass.txt");
    ofstream ofsac("acoustic.txt");
    ofstream ofel("electric.txt");
    vector<Guitar>a;
    Guitar g;
    while(ifs>>g.name>>g.producer>>g.price>>g.numb>>g.ptype>>g.type)
    {
        a.push_back(g);
    }
    pricesort(a);
    for(int i=0; i<a.size(); i++)
    {
        a[i].print();
        if(a[i].type=="bass")
        ofsbass<<a[i].name<<" "<<a[i].producer<<" "<<a[i].price<<" "<<a[i].numb<<" "<<a[i].ptype<<" "<<a[i].type;
        if(a[i].type=="electric") 
        ofel<<a[i].name<<" "<<a[i].producer<<" "<<a[i].price<<" "<<a[i].numb<<" "<<a[i].ptype<<" "<<a[i].type;
        if(a[i].type=="acoustic")
        ofsac<<a[i].name<<" "<<a[i].producer<<" "<<a[i].price<<" "<<a[i].numb<<" "<<a[i].ptype<<" "<<a[i].type;
    }
    //if(a[i].type=="electric")
    int aaa;
    cin>>aaa;
    return 0;
}