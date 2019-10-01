#include <iostream>
using namespace std;

//El item 1 tiene asignado un puntaje total de 2 puntos
//El item 2 tiene asignado un puntaje total de 4 puntos
//Lo que suman 6, sin considerar el punto base.

class Perezoso{
	private: //0,1
		int periodo;//0,2
		bool estado; //0,2       puede ser string o char también
		bool tipo; //0,2         puede ser string o char también
	public: //0,1
		Perezoso(int periodo, bool estado, bool tipo){		//0,6 en total por el constructor bien hecho
			this->periodo = periodo;
			this->estado = estado;
			this->tipo = tipo;
		}
		bool getEstado(){
			return estado;	//0,3 por el get
		}
		bool getTipo(){
			return tipo;	//0,3 por el get
		}
};

//----------------------------------------------------------------------

class Pieza{
	private:	//0,1
		string nombre;	//0,2
		string color;	//0,2
	public:		//0,1
		Pieza(string nombre, string color){ //el constructor no es necesario de evaluar ya que no se pide
			this->nombre = nombre;
			this->color = color;
		}
		Pieza(){
		}
};

class Tablero{
	private:	//0,1
		Pieza *matriz[8][8];	//0,7
	public:		//0,1
		void agregarPieza(Pieza *p,int x,int y){	//1,0 por la asignacion correcta de parametros
			if(matriz[x][y]==NULL){ // 1,5 este if es ultra importante
				matriz[x][y] = p; //2,0
			}
			else{
				cout << "El tablero ya tiene una pieza asignada en las coordenadas " << x << "," << y << endl;
			}
		}
};

int main(){
	return 0;
}
