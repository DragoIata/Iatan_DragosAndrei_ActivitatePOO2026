#include <iostream>
#include <string>
using namespace std;

class Cofetarie {
public:
	Cofetarie() :id(++nrCofetarii) {
		this->id = 0;
		this->denumire = "Cofetarie Generala";
		this->nrProduse;
		this->preturi = nullptr;
	}

	Cofetarie(int id, string denumire, int nrProduse, float* preturi) :id(id), denumire(denumire) {
		this->id = 0;
		nrCofetarii++;
		this->denumire = denumire;
		this->nrProduse = nrProduse;
		this->preturi = new float[nrProduse];
		for (i = 0;i < this->nrProduse;i++) {
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;
	}
	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Numar produse: " << this->nrProduse;
		if (this->nrProduse > 0) {
			cout << ", cu urmatoarele preturi: ";
			for (int i = 0;i < this->nrProduse - 1;i++) {
				cout << this->preturi[i] << " lei, ";
			}
			cout << this->preturi[nrProduse] << " lei.";
		}
		else {
			cout << ", nu sunt produse!";
		}

		cout << endl << "Denumire: " << this->denumire;
	}
private:
	const int id;
	string denumire;
	int nrProduse;
	float* preturi;
	static int nrCofetarii;
};

int Cofetarie::nrCofetarii = 0;

void main() {
	Cofetarie cofetarieGenerala;

	cofetarieGenerala.afisare();

	float* preturi = new float[] {18.5, 24, 15.5};
	Cofetarie* cofetarieRomana = new Cofetarie(2, "Cofetarie Romana", 3, preturi);
	cofetarieRomana->afisare();

	delete cofetarieRomana;

	cout << endl << "Numar Cofetarii: " << Cofetarie::nrCofetarii;
}