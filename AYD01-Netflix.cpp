#include <iostream>
using namespace std;

class Pelicula{
	private:
		string nombre;
		int lanzamiento;
		string genero;
	public:
		Pelicula(string nombre,int lanzamiento,string genero){
			this->nombre=nombre;
			this->lanzamiento = lanzamiento;
			this->genero = genero;
		}
		Pelicula(){
		}
		string getNombre(){
			return nombre;
		}
		int getLanzamiento(){
			return lanzamiento;
		}
		string getGenero(){
			return genero;
		}
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		void setLanzamiento(int lanzamiento){
			this->lanzamiento = lanzamiento;
		}
		void setGenero(string genero){
			this->genero = genero;
		}
		
};

class Netflix{
	private:
		Pelicula *pel[9999];
	public:
		Netflix(){
		}
		void agregarPelicula(Pelicula *p){
			for(int i=0;i<9999;i++){
				if(pel[i]==NULL){
					pel[i] = p;
					break;
				}
			}
		}
		void infoPelicula(Pelicula *p){
			for(int i=0;i<9999;i++){
				if(pel[i]==p){
					cout << p->getGenero() << endl;
					cout << p->getNombre() << endl;
					cout << p->getLanzamiento() << endl;
					break;
				}
			}
		}		
};

int main(){
	Pelicula *p= new Pelicula("El camino",2019,"Drama");
	Pelicula *p2= new Pelicula("El hobbit",2014,"Ficcion");
	Netflix *net = new Netflix;
	net->agregarPelicula(p);
	net->agregarPelicula(p2);
	net->infoPelicula(p);
}
