#include <iostream>
#include <stack>
using namespace std;

class Libro{
	private:
		int numero;
	public:
		Libro(int n){
			numero =n;
		}
		Libro(){
		}
		int getNumero(){
			return numero;
		}
};

class Biblioteca{
    private:
        stack <Libro *> calculo;
        stack <Libro *> fisica;
    public:
        Biblioteca(){}
        void agregarCalculo(Libro c){
            calculo.push(&c);
        }
        void agregarFisica(Libro f){
            fisica.push(&f);
        }
        bool verificarFisica(){
            return !fisica.empty();
        }
        void eliminarCalculo(int n){
            stack <Libro *> aux;
            while(!calculo.empty()){
                if((calculo.top())->getNumero()==n){
                    calculo.pop();
                    if(calculo.empty()){
                        break;
                    }
                }
                aux.push(calculo.top());
                calculo.pop();
            }
            while(!aux.empty()){
                calculo.push(aux.top());
                aux.pop();
            }
        }
};

int main(){
	return 0;
}
