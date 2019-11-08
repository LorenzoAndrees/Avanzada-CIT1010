#include <iostream>
using namespace std;

class Complex{
	private:
		int a,b;
	public:
		Complex(int a,int b){
			this->a = a;
			this->b = b;
		}
		Complex(){
		}
		void setA(int a){
			this->a = a;
		}
		void setB(int b){
			this->b = b;
		}
		int getA(){
			return a;
		}
		int getB(){
			return b;
		}
		bool esReal(){
			return !b==0;
		}
		Complex *suma(Complex *i){
			return new Complex(a+i->getA(),b+i->getB());
		}
		Complex *resta(Complex *i){
			return new Complex(a-i->getA(),b-i->getB());
		}
		Complex *multiplica(Complex *i){
			int real = a*i->getA() - b*i->getB();
			int img = a*i->getB() + b*i->getA();
			return new Complex(real,img);
		}
		Complex *clonar(){
			return new Complex(a,b);
		}
		void print(){
			cout << a << " + " << b << "i" << endl;
		}
		Complex *divide(Complex *i){
			
		}
};

int main(){
	return 0;
}
