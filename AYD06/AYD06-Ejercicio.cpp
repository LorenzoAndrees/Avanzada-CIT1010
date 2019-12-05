#include <iostream>
#include<map>
#include<utility>
#include <string>
using namespace std;

class Animal{
  private:
    string nombre;
    string codigo;
  public:
  Animal(string nombre,string codigo){
    this->nombre = nombre;
    this->codigo = codigo;
  }
  Animal(){
  }
  string getNombre(){
    return nombre;
  }
  string getCodigo(){
    return codigo;
  }
};

class Zoo{
  private:
    string nombre;
    map <string,Animal *> directorio;
  public:
    Zoo(){
    }
    void agregarAnimal(Animal *a){
      directorio[a->getCodigo()]=a;
    }
    void consultarAnimal(string c){
      cout << "Consultando por el código de jaula " << c << " ..." << endl;
      if(directorio.find(c)!=directorio.end()){
        cout << "El animal que está dentro de la jaula " << c << " es un " << directorio[c]->getNombre() << "." << endl;
      }
      else{
        cout << "La jaula " << c << " no existe." << endl;
      }
    }
    void imprimirDirectorio(){
      cout << "Actualmente hay " << directorio.size() << " animales registrados. Estos son: " << endl;
      for(map <string,Animal *>::iterator i=directorio.begin();i!=directorio.end();i++){
        cout << (i->second)->getNombre() << endl;
      }
    }
};

int main() {
  Zoo z;
  Animal *e = new Animal("Elefante","1");
  Animal *f = new Animal("Foca","2");
  Animal *l = new Animal("León","231415");
  Animal *zo = new Animal("Zorro","49");
  Animal *m = new Animal("Mono","311");
  z.agregarAnimal(e);
  z.agregarAnimal(f);
  z.agregarAnimal(l);
  z.agregarAnimal(zo);
  z.agregarAnimal(m);
  z.imprimirDirectorio();
  z.consultarAnimal("59");
  z.consultarAnimal("311");
}
