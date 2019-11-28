#include <iostream>
#include <vector>
using namespace std;

#define EXIT_PROGRAM return 0

class Plato{
	private:
		string nombre;
	public:
		Plato(string nombre){
			this->nombre= nombre;
		}
		Plato(){
		}
		string getNombre(){
			return nombre;
		}
};

class MasterChef{
	private:
		vector <Plato *> platos;
	public:
		MasterChef(){
		}
		void agregarPlato(Plato *p){
			platos.push_back(p);
		}
		int cantidadPlatos(){
			return platos.size();
		}
		void listadoPlatos(){
			for(int i=0;i<platos.size();i++){
				cout << "Plato n°" << i+1 << ": " << (platos.at(i))->getNombre() << endl;
			}
		}
		bool hayPlatos(){
			if(platos.empty()){
				return false;
			}
			return true;
		}
		/* O bien
		bool hayPlatos(){
			return !platos.empty();
		}
		*/
		Plato ultimoPlato(){
			return *platos.back();
		}
		Plato primerPlato(){
			return *platos.front();
		}
		Plato posicionPlato(int n){
			return *platos.at(n);
		}
		void eliminarPlato(string nombre){
			for(int i=0;i<platos.size();i++){
				if ((platos.at(i))->getNombre()==nombre){
					platos.erase(platos.begin()+i);
					break;
				}
			}
		}
};
int main(){
	EXIT_PROGRAM;
}
