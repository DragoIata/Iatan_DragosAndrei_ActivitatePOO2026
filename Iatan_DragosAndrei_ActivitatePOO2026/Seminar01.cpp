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

int main() {
	cout << "Bună Dimineața soare!" << endl;
	int a, b, c;
	cout << "a: ";
	cin << a;
	cout << "/n b: ";
	cin << b;
	c = a + b;
	cout << "/n c=" << c;
	return 0;
	
}