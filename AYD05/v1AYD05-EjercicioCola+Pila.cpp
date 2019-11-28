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
		void addSala(Persona *p){ //SE CONSIDERA LA COLA DE LA SALA, INDEPENDIENTE DE LA COLA DE ESPERA.
			if(sala.size()>55){ //Considerar que la sala posee un máximo de 55 personas.
				cout << "No hay más disponibilidad en la sala.";
			}
			else{
				if(p->getEdad()>=5){ //Considerar que la pelicula es para mayores de 5 años.
					sala.push(p);
				}
				else{
					cout << "No puede ingresar, debido a la restricción de edad.";
				}
			}
		}
		void addFila(Persona *p){
			if(p->getEdad()>=5){ //Agregamos a la fila de espera, solo personas mayores de 5 años.
				fila.push(p);	
			}
			else{
				cout << "No puede ingresar, debido a la restricción de edad.";
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
		/* Otra forma "más eficiente":
		void verificarScar(){
			stack <Persona *> aux;
			while(!sala.empty()){
				if((sala.top()->getNombre()!="Arthur"){
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
