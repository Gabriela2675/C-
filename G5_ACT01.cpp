#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Constructores, destructores, objetos como atributos de clase y autorreferencias

class Producto{
    private:
        string nombre;
        string descripcion;
        int cantidad;
        int precio;
    public:
        Producto(string nm, string dc, int ct, int pr){
            this->nombre=nm;
            this->descripcion=dc;
            this->cantidad=ct;
            this->precio=pr;
        }
        void setNombre(string nm){ nombre = nm; }
        void setDescripcion(string dc){ descripcion = dc; }
        void setCantidad(int ct){ cantidad = ct; }
        void setPrecio(int pr){ precio = pr; }
        string getNombre(){ return nombre; }
        string getDescripcion(){ return descripcion; }
        int getCantidad(){ return cantidad; }  
        int getPrecio(){ return precio; }
        Producto& sumaTotal(){
            int total = 0;
            total += cantidad;
            return *this;
        }
        ~Producto(){
            cout<<"Liberando memoria de Producto..."<<endl;
        }
};

class Compra{
    private:
        vector<Producto> productos;
        vector<Producto> compra;
    public:
        void agregarProducto(Producto p) {
            productos.push_back(p);
        }
        void eliminarProducto(int i) {
            productos.erase(productos.begin() + i);
        }
        void imprimirInventario() {
            for (int i = 0; i < productos.size(); i++) {
                cout<<"Producto: "<<productos[i].getNombre()<<endl;
                cout<<"Descripción: "<<productos[i].getDescripcion()<<endl;
                cout<<"Cantidad: "<<productos[i].getCantidad()<<endl;
                cout<<"Precio: "<<productos[i].getPrecio()<<endl;
            }
        }
        void carrito(Compra com){
            while (true) {
                string prod;
                int cant;
                int op;
                cout<<"========MENU DE OPCIONES========"<<endl;
                cout<<"1. Ingresar producto al carrito."<<endl;
                cout<<"2. Eliminar producto del carrito."<<endl;
                cout<<"3. Mostrar carrito y Salir."<<endl;
                cin>>op;
                if (op == 1){
                    for (int i = 0; i < com.productos.size(); i++) {
                        cout<<"Producto: "<<com.productos[i].getNombre()<<endl;
                        cout<<"Descripción: "<<com.productos[i].getDescripcion()<<endl;
                        cout<<"Cantidad: "<<com.productos[i].getCantidad()<<endl;
                        cout<<"Precio: "<<com.productos[i].getPrecio()<<endl;
                    }
                    cout<<"Seleccione su producto: "<<endl;
                    cin>>prod;
                    bool encontrado = false;
                    for (int i = 0; i < com.productos.size(); i++) {
                        if(prod == com.productos[i].getNombre()){
                            cout<<"Ingrese cantidad deseada: "<<endl;
                            cin>>cant;
                            if(cant <= com.productos[i].getCantidad()){
                                cout<<"Cantidad suficiente."<<endl;
                                compra.push_back(com.productos[i]);
                                int nc;
                                nc = com.productos[i].getCantidad()-cant;
                                com.productos[i].setCantidad(nc);
                            }
                            else{
                                cout<<"Cantidad insuficiente."<<endl;
                            }
                            encontrado = true;
                            break;
                        }
                    }
                    if(!encontrado) {
                        cout<<"El producto no existe."<<endl;
                    }
                }
                if (op == 2){
                    cout<<"Ingrese el producto que desea sacar del carrito: "<<endl;
                    cin>>prod;
                    bool encontrado = false;
                    for (int i = 0; i < compra.size(); i++) {
                        if(prod == compra[i].getNombre()){
                            encontrado = true;
                            compra.erase(compra.begin() + i);
                            break;
                        }
                    }
                    if(!encontrado) {
                        cout<<"El producto no existe en el carrito."<<endl;
                    }
                }
                else if (op == 3){
                    int ttl = 0;
                    for (int i = 0; i < compra.size(); i++) {
                        cout<<"Producto: "<<compra[i].getNombre()<<endl;
                        cout<<"Descripción: "<<compra[i].getDescripcion()<<endl;
                        cout<<"Cantidad: "<<compra[i].getCantidad()<<endl;
                        cout<<"Precio: "<<compra[i].getPrecio()<<endl;
                        ttl += compra[i].getPrecio();
                    }
                    cout<<"TOTAL: "<<ttl<<endl;
                    cout<<"FIN DEL PROGRAMA"<<endl;
                    break;
                }
                else{
                    cout<<"Opción invalida"<<endl;
                }
            }
        }
        ~Compra(){
            cout<<"Liberando memoria de Compra..."<<endl;
        }
};

class Usuario {
    private:
        string nombreU;
        int dni;
        string correo;
    public:
        Usuario(string nmU, int _dni, string cr){
            this->nombreU=nmU;
            this->dni=_dni;
            this->correo=cr;
        }
        void setNombreU(string nmU){ nombreU = nmU; }
        void setDni(int _dni){ dni = _dni; }
        void setCorreo(string cr){ correo = cr; }
        string getNombreU(){ return nombreU; }
        int getDni(){ return dni; }
        string getCorreo(){ return correo; }
        void realizarCompra(Compra c){
            c.carrito(c);
        }   
        ~Usuario(){
            cout<<"Liberando memoria de Usuario..."<<endl;
        }
};

int main() {
    Producto p1("Lapicero", "Tinta negra", 50, 1.5);
    Producto p2("Cuaderno", "Cuadriculado", 20, 5.0);
    Producto p3("Calculadora", "Calculadora cientifica", 10, 10.0);
    Compra com;
    com.agregarProducto(p1);
    com.agregarProducto(p2);
    com.agregarProducto(p3);
    Usuario u1("Alexa", 18965412, "alexa@gmail.com");
    u1.realizarCompra(com);
    return 0;
}
