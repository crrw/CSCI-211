#include <iostream> 
#include<cmath>
using namespace std;

bool isok(int q[], int c, int n) {
	for (int i = 0; i < c; ++i)
		if ((q[c] / n - q[i] / n) == abs(q[c] % n - q[i] % n))
			return false;
	return true;
}

int bishops(int n, int k) {
	int *q = new int[k];
	q[0] = 0;
	int c = 0, count = 0;
	while (c >= 0) {
		c++;
		if (c == k) {
			count++;
			c--;
		}
		else
			q[c] = q[c - 1];

		while (c >= 0) {
			q[c]++;
			if (q[c] == n * n) {
				c--;
			}
			else if (isok(q, c, n)) {
				break;
			}
		}
	}
	delete[]q;
	return count;
}


int main() {
	int n, k;
	cout << "enter the nxn board:";
	cin >> n;
	cout << endl;
	cout << "enter the number of pieces";
	cin >> k;

	cout << "solutions: " << bishops(n, k) << endl;

	return 0;
}