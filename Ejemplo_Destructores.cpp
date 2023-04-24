#include <iostream>
using namespace std;

class NewClass{
    private:
        int x;
    public:
        NewClass(int _x): x(_x){}
        ~NewClass();
};

NewClass::~NewClass(){ cout<<"Ejecutando destructor...obj"<<x<<endl; }

NewClass obj1(1);

int main(){
    NewClass obj2(2);
    {
        NewClass obj3(5);
    }
    NewClass obj3(3);
    NewClass obj4(4);
    return 0;
}