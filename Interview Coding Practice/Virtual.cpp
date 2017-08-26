#include<iostream.h>
using namespace std;
#include<conio.h>
class Base
{
    public:
        Base()
        {cout<<"Base Constructor\n";}
        virtual ~Base()
        {cout<<"Base Destructor\n";}
};

class Derived:public Base
{
    public:
        Derived()
        {cout<<"Derived Constructor\n";}
        ~Derived()
        {cout<<"Derived Destructor\n";}
};

int main(int argc,char *argv[])
{
    Base *var=new Derived();
    delete var;
    getch();
}
