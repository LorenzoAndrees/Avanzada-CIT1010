#include <iostream>
using namespace std;

class Persona{
	protected:
		string nombre;
		string rut;
		string nacionalidad;
		char genero;
	public:
		Persona(string nombre,string rut,string nacionalidad,char genero){
			this->nombre = nombre;
			this->rut = rut;
			this->nacionalidad = nacionalidad;
			this->genero = genero;
		}
		Persona(){
		}
		string getNombre(){
			return nombre;
		}
		string getRut(){
			return rut;
		}
		string getNacionalidad(){
			return nacionalidad;
		}
		char getGenero(){
			return genero;
		}
};

class Pasajero : public Persona{
	private:
		string id;
	public:
		Pasajero(string nombre,string rut,string nacionalidad,char genero,string id):Persona(nombre,rut,nacionalidad,genero){
			this->id = id;
		}
		Pasajero(){
		}
		string getId(){
			return id;
		}
};

class Empleado : public Persona{
	private:
		int sueldo;
		string cargo;
		int experiencia = 0;
	public:
		Empleado(string nombre,string rut,string nacionalidad,char genero,string cargo,int sueldo):Persona(nombre,rut,nacionalidad,genero){
			this->sueldo = sueldo;
			this->cargo = cargo;
		}
		Empleado(){
		}
		int getSueldo(){
			return sueldo;
		}
		string getCargo(){
			return cargo;
		}
		int getExperiencia(){
			return experiencia;
		}
		void setSueldo(int sueldo){
			if(sueldo>this->sueldo){
				this->sueldo = sueldo;
			}
		}
		void setExperiencia(int experiencia){
			if(experiencia>this->experiencia){
				this->experiencia = experiencia;
			}
		}
};

int main(){
	return 0;
}
