#include <iostream>
using namespace std;

class Cartez {
public:
	static int nrPuncte;

	Cartez() :id{ ++nrPuncte } {
		this->x = 0;
		this->y = 0;
	}

	Cartez(float x, float y) :id{ ++nrPuncte } {
		this->x = x;
		this->y = y;
	}
	float getX() {
		return this->x;
	}
	float getY() {
		return this->y;
	}
	void setX(float x) {
		this->x = x;
	}
	void setY(float y) {
		this->y = y;
	}
	float dist(float x, float y) {
		return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
	}
private:
	float x, y;
	const int id;
};

int Cartez::nrPuncte = 0;

int main() {
	Cartez p1, p2;
	float a, b;
	Cartez* Origine = new Cartez(0, 0);
	cout << "Coordonatele punctului P1: ";
	cin >> a >> b;
	p1.setX(a);
	p1.setY(b);
	cout << endl << "Coordonatele punctului P2: ";
	cin >> a >> b;
	p2.setX(a);
	p2.setY(b);
	cout << endl << "Distanta dintre punctele p1(" << p1.getX() << "," << p1.getY() << ") si p2(" << p2.getX() << "," << p2.getY() << ") este: " << p1.dist(p2.getX(), p2.getY()) << endl;
	cout << "Distanta dintre punctul p1(" << p1.getX() << "," << p1.getY() << ") si Origine(0,0) este: " << p1.dist(Origine->getX(), Origine->getY()) << endl;
	cout << "Distanta dintre punctul p2(" << p2.getX() << "," << p2.getY() << ") si Origine(0,0) este: " << p2.dist(Origine->getX(), Origine->getY()) << endl;

	delete Origine;
	return 0;
}