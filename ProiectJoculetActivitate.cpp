#include <iostream>
#include <string>
using namespace std;

enum Zona { Padure = 1, Desert = 2, Tundra = 3, Vulcan = 4, Castel = 5 };
enum Rol { Razboinic = 1, Vrajitor = 2, Arcas = 3 };
enum Talent { Agil = 1, Indemanat = 2, Oportunist = 3, Academic = 4 };
class jucator {
	const int id;
	string nume;
	float viata;
	int nivel;
	string arma;
	string armura;
	Rol rol;
	Talent talent;
public:
	static int nrSaves;

	jucator() :id(++nrSaves) {
		this->nume = "Erou";
		this->viata = 20;
		this->nivel = 1;
		this->arma = "N/A";
		this->armura = "N/A";
		this->rol = Razboinic;
		this->talent = Agil;
	}
	
	jucator(int id, string nume, float viata, int nivel, string arma, string armura, Rol rol, Talent talent) :id(id) {
		nrSaves++;
		this->nume = nume;
		this->viata = 20;
		this->nivel = 1;
		this->arma = "N/A";
		this->armura = "N/A";
		this->rol = rol;
		this->talent = talent;
	}

	void afisare() {
		cout << endl << "Id: " << id;
		cout << endl << "Nume: " << nume;
		cout << endl << "Viata: " << viata;
		cout << endl << "LVL: " << nivel;
		cout << endl << "Arma: " << arma;
		cout << endl << "Armura: " << armura;
		cout << endl << "Rol: " << rol;
		cout << endl << "Talent: " << talent;
	}
};

class inamic {
	string nume;
	float viata;
	float atac;
};

int main() {
	cout << "--Aventura Orientata pe Obiect!--";
	cout << endl << "[1] Incepe jocul";
	cout << endl << "[2] Continua jocul";
	cout << endl << "[3] Vizualizare Saves";
	cout << endl << "[9] Sterge Saves";
	cout << endl << "[0] Iesire";
	cout << endl << "Introduce alegerea: ";

	int alegere0, alegere1, alegere2, alegere3, ident=0;
	string nume;
	cin >> alegere0;

	switch (alegere0) {
	case 1: {
		cout << "Introdu numele: ";
		getline(cin, nume);
		cout << endl << "Alege rolul: ";
		cout << endl << "[1]Razboinic: foloseste sabii si scuturi";
		cout << endl << "[2]Vrajitor: foloseste magie si mana";
		cout << endl << "[3]Arcas: foloseste arcuri si sageti";
		cout << endl << "Introduce alegerea: ";
		cin >> alegere1;
		Rol rolul;
		switch (alegere1) {
		case 1:
			rolul = Razboinic;
			break;
		case 2:
			rolul = Vrajitor;
			break;
		case 3:
			rolul = Arcas;
			break;
		default:
			cout << "Alegere invalida";
			break;
		}
		cout << endl << "Alege talentul: ";
		cout << endl << "[1]Agil: sansa de 15% s-a evadezi un atac";
		cout << endl << "[2]Indemanat: sansa de 20% s-a primesti bani in plus";
		cout << endl << "[3]Oportunist: sansa de 10% s-a lovesti un atac critic";
		cout << endl << "[4]Academic: sansa de 40% s-a primesti un mana inapoi in plus la inceput fiecarei runde";
		cout << endl << "Introduce alegerea: ";
		cin >> alegere2;
		Talent talentul;
		switch (alegere2) {
		case 1:
			talentul = Agil;
			break;
		case 2:
			talentul = Indemanat;
			break;
		case 3:
			talentul = Oportunist;
			break;
		case 4:
			talentul = Academic;
			break;
		default:
			cout << "Alegere invalida";
			break;
		}
		cout << endl << "Confirma alegerile: ";
		cout << endl << "Nume: " << nume;
		cout << endl << "Rol: " << rolul;
		cout << endl << "Talent: " << talentul;
		cout << endl << "[1]Da";
		cout << endl << "[2]Nu";
		cout << endl << "Introduce alegerea: ";
		cin >> alegere3;
		switch (alegere3) {
		case 1: {
			cout << endl << "Alegerea a fost confirmata!";
			ident++;
			jucator Erou(ident, nume, 20, 1, "N/A", "N/A", rolul, talentul);
			break;
		}
		case 2:
			cout << endl << "Alegerea a fost anulata!";
			break;
		}
	}
	case 2:

	case 3:

	case 9:

	case 0:
		cout << "hai pa";
		break;
	default:
		cout << "Alegere invalida";
		break;
	}
}