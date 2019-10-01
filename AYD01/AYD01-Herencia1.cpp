#include <iostream>
using namespace std;

class Animal{
	protected:
		int edad;
		float peso;
	public:
		Animal(int edad,float peso){
			this->edad = edad;
			this->peso = peso;
		}
		Animal(){
		}
		int getEdad(){
			return edad;
		}
		float getPeso(){
			return peso;
		}
};

class Perro: public Animal{
	private:
		string raza;
	public:
		Perro(int edad,float peso,string raza):Animal(edad,peso){
			this->raza = raza;
		}
		Perro(){
		}
		string getRaza(){
			return raza
		}
};

class Koala: public Animal{
	private:
		int cantidad;
	public:
		Koala(int edad,float peso,int cantidad):Animal(edad,peso){
			this->cantidad = cantidad;
		}
		int getCantidad(){
			return cantidad;
		}
};

int main(){
	Perro *p = new Perro(7,20,"Pastor aleman");
	Koala *k = new Koala(2,5,16);
	cout << "Los datos del perro son: " << endl;
	cout <<	p->getEdad() << endl;
	cout << p->getPeso() << endl;
	cout << p->getRaza() << endl;
	cout << "Los datos del koala son: " << endl;
	cout << k->getEdad() << endl;
	cout << k->getPeso() << endl;
	cout << k->getCantidad() << endl;
}
