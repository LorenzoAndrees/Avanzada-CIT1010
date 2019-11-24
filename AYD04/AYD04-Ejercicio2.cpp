#include <iostream>
#include <vector>
using namespace std;

class Song{
	private:
		string name;
		string artist;
	public:
		Song(string n, string a){
			name=n;
			artist=a;
		}
		Song(){
		}
		string getName(){
			return name;
		}
		string getArtist(){
			return artist;
		}
};

//(RECOMENDABLE HACERLO) COMO EJERCICIO SUGIERO RESOLVER ESTE MISMO ENUNCIADO PERO UTILIZANDO ITERADORES
//SI LO REALIZAN O TIENEN CUALQUIER DUDA, CONSULTENME VÍA EMAIL.

int main(){
	vector <Song *> v;
	Song *m = new Song("Morning","Beck");
	Song *r = new Song("Recuerdame","Pixar");
	Song *l = new Song("LaIncondicional","LuisMiguel");
	Song *lf = new Song("LightMyFire","TheDoors");
	v.push_back(m);
	v.push_back(r);
	v.push_back(l);
	v.push_back(lf); //CREAR 4 CANCIONES Y REGISTRARLAS
	cout << "Se tienen registradas " << v.size() << " canciones." << endl; //IMPRIMIR CUÁNTAS CANCIONES SE TIENEN REGISTRADAS
	for(int i=0;i<v.size();i++){
		cout << "Nombre de la cancion numero " << i+1 << ": " << (v.at(i))->getName() << "." << endl; //IMPRIMIR EL NOMBRE DE CADA CANCION REG.
		/* O bien:
		cout << "Nombre de la cancion numero " << i+1 << ": " << v[i]->getName() << endl;
		*/
	}
	cout << "La primera cancion registrada es: " << (v.front())->getName() << ", y la ultima es " << (v.back())->getName() << "." << endl; //MOSTRAR LA PRIMERA Y ÚLTIMA
	string song;
	bool encontrar = false;
	int pos;
	cout << "Ingrese el nombre de la cancion a eliminar: "; cin >> song;
	for(int i=0;i<v.size();i++){
		if(v[i]->getName()==song){
			encontrar = true;
			pos=i;
			break;
		}
	}
	if(encontrar){
		v.erase(v.begin()+pos); //BORRAR LA CANCION EN CASO DE QUE ESTE REGISTRADA
	}
	else{
		cout << "No hay registro de la cancion " << song << "." << endl;
	}
	Song *lb = new Song("Liebestraum","FranzLiszt");
	v.push_back(lb);
	v.erase(v.end()-2); //AGREGAR UNA CANCIÓN Y ELIMINAR LA PENULTIMA
	string artist;
	int count=0;
	cout << "Indique nombre del artista: "; cin >> artist;
	for(int i=0;i<v.size();i++){
		if(v[i]->getArtist()==artist){
			count++;
		}
	}
	cout << "Hay " << count << " canciones registradas del artista " << artist << "." << endl; //INDICAR CUANTAS CANCIONES DEL ARTISTA HAY
}
