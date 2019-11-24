#include <iostream>
#include <vector>
using namespace std;
/*
	Para entender la realizaci�n de los ejercicios de la ayudant�a es necesario conocer las funciones .begin() y .end(), las cuales devuelven un iterador.
	Deben saber que un iterador es COMO un puntero (ES NECESARIO QUE INVESTIGUEN)
	Si tenemos un vector v, v.begin() nos devolver� un iterador al comienzo del vector y v.end() retornar� un iterador al final, el cual ser� siempre NULL.
	(EJEMPLO) Forma de declarar un iterador de un vector de strings:
	vector <string> v;
	vector <string>::iterator i=v.begin(); INICIALIZAMOS UN ITERADOR AL COMIENZO DE NUESTRO VECTOR
	!!!!!!! Tambi�n es importante destacar que la funcion .erase(position) recibe un iterador como posici�n y NO un n�mero como estamos acostumbrados.
*/
int main(){
	vector <int> v; //Declaramos un vector de enteros
	int number;
	for(int i=0;i<100;i++){
		cout << "Ingrese n�mero: "; cin >> number; //Pedimos un n�mero
		v.push_back(number);	//Guardamos el n�mero en el vector
	}
	cout << "Los 100 n�meros son: " << endl;
	for(int i=0;i<v.size();i++){ //Imprimimos los 100 n�meros
		cout << v[i] << endl;
	}
	for(vector <int>::iterator i=v.begin() ; i != v.end() ; i++){ // FORMA DE RECORRER UN VECTOR, PARA IR BORRANDO ELEMENTOS DENTRO DE �L.
		if((*i)%2!=0){								// NOTAR QUE COMO UN ITERADOR ES PARECIDO A UN PUNTERO, LA EXPRESI�N *i DEVUELVE EL ELEMENTO EN S�
			v.erase(i);											  // ESTUDIE !! ANAL�CE
		}
	}
	cout << "---------------------------------------" << endl;
	cout << "Los n�meros pares son" << endl;
	for(int i=0;i<v.size();i++){ //Imprimimos todos los n�meros (pares) que quedaron
		cout << v[i] << endl;
	}
}
