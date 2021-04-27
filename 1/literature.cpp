#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Book
{
public:
    string name, author;
    int cyear;
    Book(string name, string author, int cyear)
    {
        this->name = name;
        this->author = author;
        this->cyear = cyear;
    }
    Book(){};
};

class Type : public Book
{
public: 
    string genre, type;
    Type(string name, string author, int cyear, string genre, string type)
    {
        this->name = name;
        this->author = author;
        this->cyear = cyear;
        this->genre=genre;
        this->type=type;
    }
    
    /*Type(ofstream ofs, fstream::app)
    {
        ofs<<name<<" "<<author<<" "<<cyear<<" "<<genre<<" "type<<endl;
    }*/
    void print();
    Type(){};
};
void Type::print()
    {
        ofstream ofs("work.txt");
        ofs<<name<<" "<<author<<" "<<cyear<<" "<<genre<<" "<<type;
    }
int main()
{
    Type t;
    cin>>t.name>>t.author>>t.cyear>>t.genre>>t.type;
    //Type t("name 1","author1",2021,"genre1","proza");
    t.print();
    //ofstream aaa("work.txt");
    //aaa<<t.name<<t.author<<t.cyear<<t.genre<<t.type;
    //int a;
    //cin>>a;
    return 0;
}