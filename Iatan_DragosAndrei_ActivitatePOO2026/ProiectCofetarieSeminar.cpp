#include <iostream>
#include <string>
using namespace std;

enum Zona { Centrala = 1, Periferica = 2 };

class Cofetarie {

public:
	static int nrCofetarii;

	Cofetarie() :id(++nrCofetarii) {
		//this->id = 0;
		this->denumire = "Cofetarie Generala";
		this->nrProduse = 0;
		this->preturi = nullptr;
		this->zona = Periferica;
		this->vanzariTotale = 0;
	}

	Cofetarie(int id, string denumire, float vanzariTotale, int nrProduse, float* preturi, Zona zona) :id(id){
		//this->id = 0;
		nrCofetarii++;
		this->denumire = denumire;
		this->vanzariTotale = vanzariTotale;
		this->nrProduse = nrProduse;
		this->preturi = new float[nrProduse];
		for (int i = 0;i < this->nrProduse;i++) {
			this->preturi[i] = preturi[i];
		}
		this->zona = zona;
		delete[] preturi;
	}

	Cofetarie(const Cofetarie& copie) :id(++nrCofetarii) {
		this->denumire = copie.denumire;
		this->nrProduse = copie.nrProduse;
		this->vanzariTotale = copie.vanzariTotale;
		this->zona = copie.zona;

		if (copie.preturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = copie.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}
	}
	
	void operator=(const Cofetarie& copie) {
		this->denumire = copie.denumire;
		this->nrProduse = copie.nrProduse;
		this->vanzariTotale = copie.vanzariTotale;
		this->zona = copie.zona;

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}
		if (copie.preturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0;i < this->nrProduse;i++) {
				this->preturi[i] = copie.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}
	}

	int getNrProduse() {
		return this->nrProduse;
	}

	void setNrProduse(int valoareNoua) {
		if (valoareNoua >= 0) {
			this->nrProduse = valoareNoua;
		}else{
			throw exception();
		}
	}

	float* getPreturi() {
		//return this->preturi;
		float* vPreturi = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			vPreturi[i] = this->preturi[i];
		}
		return vPreturi;
	}

	void setPreturi(float* vPreturi, int dim) {
		setNrProduse(dim);

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}

		if (vPreturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0; i < this->nrProduse;i++) {
				this->preturi[i] = vPreturi[i];
			}
			delete[] vPreturi;
		}
		else {
			this->preturi = nullptr;
		}
	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Vanzari totale: " << this->vanzariTotale;
		cout << endl << "Zona: ";
		if (this->zona == 1) {
			cout << "Centrala";
		}
		else {
			cout << "Periferica";
		}
		cout << endl << "Numar produse: " << this->nrProduse;
		if (this->nrProduse > 0) {
			cout << ", cu urmatoarele preturi: ";
			for (int i = 0;i < this->nrProduse - 1;i++) {
				cout << this->preturi[i] << " lei, ";
			}
			cout << this->preturi[nrProduse - 1] << " lei." << endl;
		}
		else {
			cout << ", nu sunt produse!" << endl;
		}
	}

	bool operator<(const Cofetarie& c) {
		return this->nrProduse < c.nrProduse;
	}

	static int getNrCofetarii() {
		return nrCofetarii;
	}

	~Cofetarie() {
		cout << endl << "S-a apelat destructorul pentru cofetaria cu id: " << this->id << endl;
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}

	void operator+=(float vanzariTotaleDeAdunat) {
		this->vanzariTotale += vanzariTotaleDeAdunat;
	}

	bool operator!() {
		return this->vanzariTotale > 0;
	}

	float operator()(float valoareDeAdaugat) {
		return this->vanzariTotale + valoareDeAdaugat;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrProduse){
			return this->preturi[index];
		}else{
			throw exception();
		}
	}

	friend void operator<<(ostream& out, Cofetarie c) {
		out << endl << "Operator de afisare: ";
		out << endl << "Id: " << c.id;
		out << endl << "Denumire: " << c.denumire;
		out << endl << "Vanzari totale: " << c.vanzariTotale;
		out << endl << "Zona: ";
		if (c.zona == Centrala) out << "Centrala";
		if (c.zona == Periferica) out << "Periferica";
		out << endl << "Nr Produse: " << c.nrProduse;
		if (c.preturi != nullptr) {
			out << endl << "Preturi: ";
			for (int i = 0; i < c.nrProduse - 1; i++) {
				out << c.preturi[i] << " grame, ";
			}
			out << c.preturi[c.nrProduse - 1] << "grame." << endl;
		}
	}

	friend void operator >> (istream& in, Cofetarie& c);

	Cofetarie operator++(int) {
		Cofetarie copie = *this;
		this->vanzariTotale++;
		return copie;
	}

	Cofetarie operator++() {
		this->vanzariTotale++;
		return *this;
	}

	explicit operator int() {
		return this->nrProduse;
	}

private:
	const int id;
	string denumire;
	int nrProduse;
	float* preturi;
	Zona zona;
	float vanzariTotale;
};

void operator>>(istream& in, Cofetarie& c) {
	cout << endl << "Vanzari totale: ";
	in >> c.vanzariTotale;

	cout << endl << "Denumire: ";
	in >> c.denumire;

	cout << endl << "Zona: ";
	int zona;
	in >> zona;
	if (zona == 1) c.zona = Centrala;
	if (zona == 2) c.zona = Periferica;

	cout << endl << "Nr produse: ";
	in >> c.nrProduse;

	if (c.preturi != nullptr) {
		delete[] c.preturi;
		c.preturi = nullptr;
	}

	c.preturi = new float[c.nrProduse];
	for (int i = 0; i < c.nrProduse; i++) {
		cout << endl << "preturi[" << i << "]: ";
		in >> c.preturi[i];
	}
}

int Cofetarie::nrCofetarii = 0;

int main() {
	Cofetarie cofetarieGenerala;

	if (!cofetarieGenerala) {
		cout << endl << "Vanzarile totale sunt pozitive!";
	}
	else {
		cout << endl << "Nu exista vanzari!";
	}

	cout << endl << cofetarieGenerala(100);
	cout << cofetarieGenerala;

	float* preturi = new float[] {18.5, 24, 15.5};
	Cofetarie* cofetarieRomana = new Cofetarie(7, "Cofetarie Romana", 97000, 3, preturi, Centrala);
	(*cofetarieRomana) += 100;

	if (cofetarieGenerala < *cofetarieRomana) {
		cout << endl << "Cofetaria Generala are mai putine produse decat cofetaria Romana!";
	}
	else {
		cout << endl << "Cofetaria Romana are mai putine produse decat cofetaria Generala!";
	}

	(*cofetarieRomana)[0] = 20;

	cout << endl << (*cofetarieRomana)[0];
	cout << *cofetarieRomana;

	Cofetarie cofetarie1 = cofetarieGenerala++;

	cout << cofetarie1;	
	cout << cofetarieGenerala;

	Cofetarie cofetarie2 = ++cofetarieGenerala;
	cout << cofetarie2;
	cout << cofetarieGenerala;
	
	cout << endl << "Cast cofetarie -> int: " << int(*cofetarieRomana);

	delete cofetarieRomana;
	cout << endl << "Numar Cofetarii: " << Cofetarie::nrCofetarii;
}