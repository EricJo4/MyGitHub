#include "Food.h"
using namespace sdds;
int main() {
	Food A;
	A.setEmpty();
	A.display();
	A.set("Cheerios Cereal with 2% milk", 170, 1);
	A.display();
	return 0;
}