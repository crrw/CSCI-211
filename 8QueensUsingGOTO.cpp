#include <iostream>
using namespace std;

int main() {

	int b[8][8] = { 0 }, r, c = 0, f = 0;
	b[0][0] = 1;

nc:
	c++;
	if (c == 8) {
		goto print;
	}
	r = -1;
nr:
	r++;
	if (r == 8)
		goto backtrack;

	//row test
	for (int i = 0; i < c; i++) {
		if (b[r][i] == 1) {
			goto nr;
		}
	}

	//diagonal test up
	for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++) {
		if (b[r - i][c - i] == 1) {
			goto nr;
		}
	}

	//diagonal test down 
	for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++) {
		if (b[r + i][c - i] == 1) {
			goto nr;
		}
	}

	//place queen 
	b[r][c] = 1;
	goto nc;

backtrack:
	c--;
	if (c == -1)
		system("pause");

	r = 0;
	while (b[r][c] != 1)
		r++;
	b[r][c] = 0;
	goto nr;


print:
	f++;
	cout << "solution number " << f << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	goto backtrack;

	system("pause");
}