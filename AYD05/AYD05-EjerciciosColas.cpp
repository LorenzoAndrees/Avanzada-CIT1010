#include <iostream>
#include <queue>
using namespace std;

//c)
void multiplos(queue <int> numeros){
	while(!numeros.empty()){
		if(numeros.front()%7==0 & numeros.front()!=0){
			cout << numeros.front() << endl;
		}
		numeros.pop();
	}
}

//d)
void desencolarNombres(queue <string> nombres){
	int n=nombres.size();
	int i=0;
	while(i<nombres.size()){
		if(nombres.front()=="Matias"){
			nombres.push(nombres.front());
		}
		nombres.pop();
		i++;
	}
}

//e)
void encolarIntercalado(queue <string> q1,queue <string> q2){
	int i=2;
	while(!q2.empty()){
		if(i%2==0){
			if(q1.back()!=q2.front()){
				q1.push(q2.front());
			}
		}
		q2.pop();
		i++;
	}
}

int main(){
	//a)
	queue <string> nombres;
	string nombre;
	while(true){
		cout << "Ingrese nombre: "; cin >> nombre;
		if(nombre=="exit"){
			break;
		}
		nombres.push(nombre);
	}
	//b)
	queue <int> pares;
	queue <int> impares;
	int numero;
	while(true){
		cout << "Ingrese número: "; cin >> numero;
		if(numero==666){
			break;
		}
		else{
			if(numero%2==0){
				pares.push(numero);
			}
			else{
				impares.push(numero);
			}
		}
	}
	return 0;
}
