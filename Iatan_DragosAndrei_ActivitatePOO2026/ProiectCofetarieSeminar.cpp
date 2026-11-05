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
	}

	Cofetarie(int id, string denumire, int nrProduse, float* preturi, Zona zona) :id(id){
		//this->id = 0;
		nrCofetarii++;
		this->denumire = denumire;
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

private:
	const int id;
	string denumire;
	int nrProduse;
	float* preturi;
	Zona zona;
};

int Cofetarie::nrCofetarii = 0;

int main() {
	Cofetarie cofetarieGenerala;

	cofetarieGenerala.afisare();

	float* preturi = new float[] {18.5, 24, 15.5};
	Cofetarie* cofetarieRomana = new Cofetarie(2, "Cofetarie Romana", 3, preturi, Centrala);
	cofetarieRomana->afisare();

	Cofetarie* cofetarieTineretului = new Cofetarie(*cofetarieRomana);
	cofetarieTineretului->afisare();

	cofetarieGenerala = *cofetarieTineretului;
	cofetarieGenerala.afisare();

	Cofetarie cofetarieX;
	cofetarieX = cofetarieGenerala;
	cofetarieX.afisare();

	try {
		cofetarieX.setNrProduse(2);
	}
	catch (int cod) {
		cout << endl << cod;
	}
	catch (const char* mesaj) {
		cout << endl << mesaj;
	}
	catch (...) {
		cout << endl << "Valoare negativa!";
	}

	cout << endl << "Noul numar al produselor este: " << cofetarieX.getNrProduse() << endl;

	cofetarieX.setPreturi(new float[] {52.7, 36.7}, 2);

	float* vPreturi = cofetarieX.getPreturi();
	for (int i = 0; i < cofetarieX.getNrProduse(); i++) {
		cout << vPreturi[i] << " lei, ";
	}

	if (cofetarieX < cofetarieGenerala) {
		cout << endl << "CofetariaX are mai putine produse decat cofetariaGenerala!" << endl;
	}
	else {
		cout << endl << "CofetariaGenerala are mai multe produse decat cofetariaX!" << endl;
	}
	
	delete[] vPreturi;
	delete cofetarieRomana;
	delete cofetarieTineretului;

	cout << endl << "Numar Cofetarii: " << Cofetarie::getNrCofetarii()<<endl;

	return 0;
}