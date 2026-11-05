#include <iostream>
using namespace std;

class Cartez {
public:
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int dist(int x, int y) {
		return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
	}
private:
	int x, y;
};
int main() {
	Cartez p1, p2;
	int a, b;
	cout << "Coordonatele punctului P1: ";
	cin >> a >> b;
	p1.setX(a);
	p1.setY(b);
	cout << endl << "Coordonatele punctului P2: ";
	cin >> a >> b;
	p2.setX(a);
	p2.setY(b);
	cout << endl << "Distanta dintre punctele p1(" << p1.getX() << "," << p1.getY() << ") si p2(" << p2.getX() << "," << p2.getY() << ") este: " << p1.dist(p2.getX(), p2.getY()) << endl;
}