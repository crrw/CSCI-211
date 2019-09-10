#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


bool ok(int q[], int col) {
	for (int i = 0; i<col; i++)
		if (q[col] == q[i] || (col - i) == abs(q[col] - q[i]))
			return false;
	return true;
};

int main() {
	int n;
	cout << "How Many Queens? ";
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int *q = new int[i]; /
			q[0] = 1;
		int count = -1;
		int c = 0;
		bool from_backtrack = false;

		while (true) {

			while (c<i) {

				if (!from_backtrack)q[c] = -1;
				from_backtrack = true;

				while (q[c]<i) {
					q[c]++;

					if (q[c] == i) {
						from_backtrack = true;
						c--;
						break;
					}

					if (ok(q, c)) {
						from_backtrack = false;
						c++;
						break;
					}

				}
				if (c == -1)break;
			}
			count++;
			c--;
			from_backtrack = true;
			if (c <= -1)break;

		}
		delete[]q;
		cout << "There is/are " << count << " solution(s) to the " << i << " Queen(s) problem." << endl;

	}
	return 0;
}