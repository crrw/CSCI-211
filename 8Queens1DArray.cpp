#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int col) {
	for (int i = 0; i<col; i++) {
		if ((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i)))
		{
			return false;
		}
	}
	return true;
}
//backtrack
void backtrack(int &col) {
	col--;
	if (col == -1) exit(1);
}

void print(int q[])
{
	static int count = 0;
	count++;
	cout << "solution number " << count << endl;
	for (int i = 0; i<8; i++) {
		cout << q[i];
	}
	cout << endl;
}

int main()
{
	int q[8]; q[0] = 0;
	int c = 1;
	bool check = false;
	while (1) {
		while (c<8) {
			if (!check)
				q[c] = -1;
			check = false;
			while (q[c]<8) {
				q[c]++;

				while (q[c] == 8)
				{
					backtrack(c);
					q[c]++;

				}

				if (ok(q, c))
					break;
			}

			c++;
		}
		print(q);
		system("pause");
		backtrack(c);
		check = true;
	}
}