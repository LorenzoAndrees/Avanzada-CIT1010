#include <iostream>
#include <queue>
#include <stack>

#define EXIT_PROGRAM return 0

using namespace std;

class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string nombre,int edad){
			this->nombre=nombre;
			this->edad=edad;
		}
		string getNombre(){
			return nombre;
		}
		int getEdad(){
			return edad;
		}
};

class Cine{
	private:
		stack <Persona *> sala;
		queue <Persona *> fila;
	public:
		Cine(){
		}
		void addSala(){ //SE CONSIDERA LA COLA DE LA SALA, DEPENDIENTE DE LA FILA DE ESPERA.
			while(!fila.empty()){ //Agregamos a la cola de la sala la gente que está en la fila, solamente si hay gente en la fila o hasta exceder la capacidad.
				if(sala.size()<=55){ //Considerar que el máximo de personas en la sala es 55.
					sala.push(fila.front());
					fila.pop();
				}
				else{
					break;
				}
			}
		}
		void addFila(Persona *p){ //Agregamos a la fila de espera, solo personas mayores de 5 años.
			if(p->getEdad()>=5){
				fila.push(p);
			}
			else{
				cout << "No puede ingresar, debido a la restricción de edad";
			}
		}
		void vaciarSala(){
			while(!sala.empty()){
				sala.pop();
			}
		}
		void verificarArthur(){
			stack <Persona *> aux; //Creamos una pila auxiliar para no perder los datos.
			while(!sala.empty()){
				if((sala.top())->getNombre()=="Arthur"){
					sala.pop();
				}
				else{
					aux.push(sala.top());
					sala.pop();
				}
			}
			sala=aux;
		}
		/*O bien:
		void verificarArthur(){
			stack <Persona *> aux; //Creamos una pila auxiliar para no perder los datos.
			while(!sala.empty()){
				if((sala.top())->getNombre()!=="Arthur"){
					aux.push(sala.top());
				}
				sala.pop();
			}
			sala=aux;
		}
		*/
		bool verificarEspera(){
			return !fila.empty(); //Retornamos True si es que hay gente esperando en la fila.
		}
		void verificarBruce(){
			stack <Persona *> aux; //Creamos una pila auxiliar para no perder los datos.
			while(!sala.empty()){
				if((sala.top())->getNombre()=="Bruce"){
					fila.push(sala.top());
				}
				else{
					aux.push(sala.top());
				}
				sala.pop();
			}
			sala=aux;
		}
};

int main(){
	EXIT_PROGRAM;
}
