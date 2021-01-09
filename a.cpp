// 2021.01.09 2020 IUPC - A
// by HYOSITIVE

#include <iostream>
#include <string>
using namespace std;

int main() {
	string myMBTI;
	cin >> myMBTI;

	// E, I
	if (myMBTI[0] == 'E') {
		cout << 'I';
	}

	else if (myMBTI[0] == 'I') {
		cout << 'E';
	}

	// S, N
	if (myMBTI[1] == 'S') {
		cout << 'N';
	}

	else if (myMBTI[1] == 'N') {
		cout << 'S';
	}

	// T, F
	if (myMBTI[2] == 'T') {
		cout << 'F';
	}

	else if (myMBTI[2] == 'F') {
		cout << 'T';
	}

	// J, P
	if (myMBTI[3] == 'J') {
		cout << 'P';
	}

	else if (myMBTI[3] == 'P') {
		cout << 'J';
	}

	cout << endl;
}