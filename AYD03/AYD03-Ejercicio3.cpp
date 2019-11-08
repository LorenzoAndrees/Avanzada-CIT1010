#include <iostream>
using namespace std;

class Ingrediente{
	private:
		string nombre;
	public:
		Ingrediente(string nombre){
			this->nombre = nombre;
		}
		Ingrediente(){
		}
		string getNombre(){
			return nombre;
		}
};

class Sandwich{
	protected:
		int tiempo;
		Ingrediente *I[4];
	public:
		Sandwich(int tiempo){
			this->tiempo = tiempo;
		}
		Sandwich(){
		}
		virtual void setIngrediente(){
		}
		virtual Ingrediente *iPrincipal(){
		}
		int getTiempo(){
			return tiempo;
		}
		void setTiempo(int tiempo){
			this->tiempo = tiempo;
		}
};

class Pizza: public Sandwich{
	private:
		string descripcion;
	public:
		Pizza(int tiempo,string descripcion):Sandwich(tiempo){
			this->descripcion = descripcion;
			I[3] = new Ingrediente("Pepperoni");
		}
		Pizza(){
		}
		void setIngrediente(){
			string nombre;
			for(int i=0;i<3;i++){
				cout << "Inserte ingrediente n°" << i << ": ";cin >> nombre;
				I[i] = new Ingrediente(nombre);
			}
			cout << "Inserte ingrediente base nuevo: "; cin >> nombre;
			I[3] = new Ingrediente(nombre);
		}
		Ingrediente *iPrincipal(){
			return I[3];
		}
};

class Vegetariano: public Sandwich{
	private:
		string cliente;
	public:
		Vegetariano(int tiempo,string cliente):Sandwich(tiempo){
			this->cliente = cliente;
			I[3] = new Ingrediente("Champinion");
		}
		Vegetariano(){
		}
		void setIngrediente(){
			string nombre;
			for(int i=0;i<3;i++){
				cout << "Inserte ingrediente n°" << i+1 << ": ";cin >> nombre;
				I[i] = new Ingrediente(nombre);
			}
			cout << "Inserte ingrediente base nuevo: "; cin >> nombre;
			if(esCarne(nombre)==false){ //funcion esCarne() no está implementada en el código.
				I[3] = new Ingrediente(nombre);
			}
			else{
				cout << "No se puede actualizar el ingrediente..." << endl;
			}
		}
		Ingrediente *iPrincipal(){
			return I[3];
		}
};

class Metro{
	private:
		Sandwich *H[5];
	public:
		Metro(){
			for(int i=0;i<5;i++){
				H[i] = NULL;
			}
		}
		void hornear(Sandwich *s){
			for(int i=0;i<5;i++){
				if(H[i]==NULL){
					H[i] = s;
					cout << "Sandwich agregado al horno " << i+1 << "." << endl;
					break;
				}
				else{
					cout << "Horno " << i+1 << " ocupado." << endl;
				}
			}
		}
		void avanzar(){
			for(int i=0;i<5;i++){
				if(H[i]!=NULL){
					H[i]->setTiempo(H[i]->getTiempo()-10);
					if(H[i]->getTiempo()<=0){
						cout << "Listo el sandwich de " << H[i]->iPrincipal()->getNombre() << "." << endl;
						H[i] = NULL;
						break;
					}
				}
			}
		}
		void status(){
			for(int i=0;i<5;i++){
				if(H[i]==NULL){
					cout << "Horno " << i+1 << " vacio." << endl;
				}
			}
		}
};

int main(){
	return 0;
}
