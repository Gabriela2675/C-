#include <iostream>
using namespace std;

class Clase{
    int varEntera;
    float varFlotante;
    public:
        Clase() { varEntera = 0; varFlotante = 0; }
        int getVarEntera() { return this -> varEntera; }
        float getVarFlotante() { return this -> varFlotante; }
        
        Clase& sumaEnteros(int n){
            varEntera += n;
            return *this;
        }
        Clase& sumaFlotantes(float n){
            varFlotante += n;
            return *this;
        }
};

int main(){
    int x = 3;
    float y = 3.5;
    int z = 4;
    float w = 3.3;
    Clase objeto;
    cout<<objeto.getVarEntera()<<endl<<objeto.getVarFlotante()<<endl;
    objeto.sumaEnteros(x).sumaFlotantes(y);
    cout<<objeto.getVarEntera()<<endl<<objeto.getVarFlotante()<<endl;
    x = 3;
    y = 3.7;
    objeto.sumaEnteros(x).sumaFlotantes(y).sumaEnteros(z).sumaFlotantes(w);
    cout<<objeto.getVarEntera()<<endl<<objeto.getVarFlotante()<<endl;
    return 0;
}