#include <iostream>
using namespace std;

class Entidad{
	protected:
		int vida,ataque;
		string nombre;
	public:
		Entidad(int vida,int ataque,string nombre){
			this->vida = vida;
			this->ataque = ataque;
			this->nombre = nombre;
		}
		Entidad(){
		}
		void setVida(int vida){
			this->vida = vida;
		}
		void setAtaque(int ataque){
			this->ataque = ataque;
		}
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		int getVida(){
			return vida;
		}
		int getAtaque(){
			return ataque;
		}
		string getNombre(){
			return nombre;
		}
};

class Enemigo: public Entidad{
	private:
		string descripcion;
	public:
		Enemigo(int vida,int ataque,string nombre,string descripcion):Entidad(vida,ataque,nombre){
			this->descripcion = descripcion;
		}
		Enemigo(){
		}
		void setDescripcion(string descripcion){
			this->descripcion = descripcion;
		}
		string getDescripcion(){
			return descripcion;
		}
};

class Heroe: public Entidad{
	public:
		Heroe(int vida,int ataque,string nombre):Entidad(vida,ataque,nombre){
		}
		Heroe(){
		}
};

class Juego{
	private:
		Enemigo *E[50];
		Heroe *h;
		string nombre,descripcion;
	public:
		Juego(string nombre,string descripcion){
			this->nombre = nombre;
			this->descripcion = descripcion;
		}
		Juego(){
		}
		void setDescripcion(string descripcion){
			this->descripcion = descripcion;
		}
		string getDescripcion(){
			return descripcion;
		}
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		string getNombre(){
			return nombre;
		}
		void addEnemigo(Enemigo *e){
			for(int i=0;i<50;i++){
				if(E[i]==NULL){
					E[i]=e;
					break;
				}
			}
		}
		void addHero(Heroe *h){
			this->h = h;
		}
		void atacarEnemigo(string nombre){
			if(h!=NULL){
				for(int i=0;i<50;i++){
					if(E[i]!=NULL){
						if(E[i]->getNombre() == nombre){
							int vidah = h->getVida();
							int vidae = E[i]->getVida();
							int ataqueh = h->getAtaque();
							int ataquee = E[i]->getAtaque();
							E[i]->setVida(vidae-ataqueh);
							h->setVida(vidah-ataquee);
							break;
						}
					}
				}
			}
		}
};

int main(){
	return 0;
}
