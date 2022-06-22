#include <iostream>
using namespace std;

int main()
{
	cout << "Perfect Squares\n";
	bool found = false;
	int base = 4;
	int square;

	//Start loop
	while (found == false) {
		
		//New Square
		square = base * base;
		int temp = square;

		//Mod numbers
		if (square > 99) temp = square % 100;
		
		//Check values
		if (temp % 2 == 1 && (temp / 10) % 2 == 1) found = true;
		
		cout << "Base: " << base << " | " << " Square: " << square << " |" << " Temp " << temp << endl;
		base++;
	}
	//Answer
	cout << square;
	return 0;

}
