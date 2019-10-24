#include <iostream>
#include <math.h>
using namespace std;
//PREGUNTA 1
class Domicilio{
	protected:
		string calle;
		int numero;
		string comuna;
		int m2h;
		int dormitorios;
		int banios;
	public:
		Domicilio(string calle,int numero,string comuna,int m2h,int dormitorios,int banios){
			this->calle = calle;
			this->numero = numero;
			this->comuna = comuna;
			this->m2h = m2h;
			this->dormitorios = dormitorios;
			this->banios = banios;
		}
		Domicilio(){
		}
};

class Casa : public Domicilio{
	private:
		int pisos;
		int m2t;
		string patio;
		string jardin;
	public:
		Casa(string calle,int numero,string comuna,int m2h,int dormitorios,int banios,int pisos,int m2t,string patio,string jardin):Domicilio(calle,numero,comuna,m2h,dormitorios,banios){
			this->pisos = pisos;
			this->m2t = m2t;
			this->patio = patio;
			this->jardin = jardin;
		}
		Casa(){
		}
};

class Departamento : public Domicilio{
	protected:
		int depto;
		int piso;
	public:
		Departamento(string calle,int numero,string comuna,int m2h,int dormitorios,int banios,int depto,int piso):Domicilio(calle,numero,comuna,m2h,dormitorios,banios){
			this->depto = depto;
			this->piso = piso;
		}
		Departamento(){
		}
};

class Duplex : public Departamento{
	private:
		int entrada;
	public:
		Duplex(string calle,int numero,string comuna,int m2h,int dormitorios,int banios,int depto,int piso,int entrada): Departamento(calle,numero,comuna,m2h,dormitorios,banios,depto,piso){
			this->entrada = entrada;
		}
		Duplex(){
		}
};

//PREGUNTA 2
class Posicion{
	private:
		int x,y,z; //Establecemos como atributos, cada coordenada.
	public:
		Posicion(int x,int y,int z){
			this->x = x;
			this->y = y;
			this->z = z; 
		}
		Posicion(){	//Si instanciamos una clase Posicion sin ningún parámetro, este objeto debe tener cada coordenada en 0.
			x=0;
			y=0;
			z=0;
		}
//Como se visualiza en el enunciado, el método sumar posee 2 formas distintas de recibir parámetros, por lo tanto,
//se deben crear dos métodos distintos. Uno que reciba un objeto y otro que reciba cada coordenada.

		void sumar(Posicion *p){ //Aquí recibimos el objeto p. Cada coordenada de la clase debe ser sumada con cada coordenada de p. Coordenada x de p: p->x, coordenada y de p: p->, coordenada z de p: p->z
			//En particular no necesitamos hacer un get() de cada coordenada, ya que los atributos (en private) están siendo manejados dentro de la misma clase.
			x += p->x;
			y += p->y;
			z += p->z;
		}
		void sumar(int x,int y,int z){//Aquí recibimos cada coordenada, por lo que es intuitivo que debemos sumar cada coordenada correspondiente con las que recibimos respectivamente.
			this->x += x;
			this->y += y;
			this->z += z; 
		}
		Posicion *clonar(){//El enunciado nos señala que el método clonar que se usa para p1, debe retornar un objeto Posicion como puntero.
			Posicion *p = new Posicion(x,y,z);//Inicializamos una instancia de Posicion con las coordenadas que tenemos.
			return p; //Retornamos ese objeto.
		}
};


int main() {
	
	Domicilio *dd = new Domicilio("Arturo Prat", 33, "Santiago", 730, 5, 3);
	Casa *cc = new Casa("Alameda", 777, "Santiago", 243, 2, 1, 1, 450, "si", "no");
	Departamento *pp;
	Duplex *xx = new Duplex("Bilbao", 2476, "Providencia", 250, 3, 2, 1701, 17, 1);
	pp = static_cast<Departamento *> (xx);
	
	Posicion *p1 = new Posicion(14, 5, 73);
	Posicion *p2 = new Posicion(23, 62, 0);
	Posicion *p3 = new Posicion(); // Se crea p3 con valores (0, 0, 0)
	Posicion *p4 = p1->clonar(); // Ahora p4 es una copia de p1
	p1->sumar(p2); // Ahora p1 = (37, 67, 73)
	p2->sumar(23, 7, 48); // Ahora p2 = (46, 69, 48)
}
