#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
class Drink
{
public:
    string name, company, country;
    int price;
    Drink(string name, string company, string country, int price)
    {
        this->name=name;
        this->company=company;
        this->country=country;
        this->price=price;
    }
    void print()
    {
        cout<<name<<"\t"<<company<<"\t"<<country<<"\t"<<price<<endl;
    }
    Drink(){};
    ~Drink(){};
};
class Cold:public Drink
{
public: 
    string type, ingredients;
    int calories;
    bool sugar;
    Cold(string name, string company, string country, int price, string type, string ingredients, bool sugar, int calories)
    {
        this->name=name;
        this->company=company;
        this->country=country;
        this->price=price;
        this->type=type;
        this->ingredients=ingredients;
        this->sugar=sugar;
        this->calories=calories;
    }
    Cold(){};
    void print()
    {
        cout<<name<<"\t"<<company<<"\t"<<country<<"\t"<<price<<"\t"<<type<<"\t"<<ingredients<<"\t"<<calories;
    }
};
class Alcoholic:public Drink
{
public: 
    string type;
    int percentage;
    Alcoholic(string name, string company, string country, int price, string type, int percentage)
    {
        this->name=name;
        this->company=company;
        this->country=country;
        this->price=price;
        this->type=type;
        this->percentage=percentage;
    }
    void print()
    {
        cout<<name<<"\t"<<company<<"\t"<<country<<"\t"<<price<<"\t"<<type<<"\t"<<percentage<<endl;
    }
    Alcoholic(){}
};
void Alcsort(vector<Alcoholic> a)
{
    for(int i=0; i<a.size(); i++)
    {
    for(int j=0; j<a.size()-1; j++)
    {
        if(a[i].percentage>a[i+1].percentage)
        swap(a[i], a[i+1]);
    }
    }
}
void Coldsort(vector<Cold> c)
{
    for(int i=0; i<c.size(); i++)
    {
    for(int j=0; j<c.size()-1; j++)
    {
        if(c[i].calories>c[i+1].calories)
        swap(c[i], c[i+1]);
    }
    }
}
int main()
{
    ifstream ifs("coldDrinks.txt");
    ofstream ofs("coldDrinks.txt", fstream::app);
    ifstream ifs1("alcoholicdrinks.txt");
    ofstream ofs1("alcoholicdrinks.txt", fstream::app);
    vector<Cold> c;
    vector<Alcoholic> a;
    Cold cold;
    Alcoholic alcoholic;
    while(ifs>>cold.name>>cold.company>>cold.country>>cold.price>>cold.type>>cold.ingredients>>cold.sugar>>cold.calories)
    {
        if(cold.sugar==false)
        c.push_back(cold);
    }
    while(ifs1>>alcoholic.name>>alcoholic.company>>alcoholic.country>>alcoholic.price>>alcoholic.type>>alcoholic.percentage)
    {
        a.push_back(alcoholic);
    }
    Coldsort(c);
    Alcsort(a);
    for (int i=0; i<c.size(); i++)
    {
        c[i].print();
    }
    cout<<endl<<endl<<endl;
    for (int i=0; i<a.size(); i++)
    {
        a[i].print();
    }
    int aaa;
    cin>>aaa;
    return 0;
}