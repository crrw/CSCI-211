// recursive stable marriage queens
#include <iostream>
#include <cmath>
using namespace std;



bool ok(int q[], int c)
{
	int mp[3][3] = { 0,2,1,
		0,2,1,
		1,2,0 };
	int wp[3][3] = { 2,1,0,
		0,1,2,
		2,0,1 };

	for (int i = 0; i < c; i++) {
		if (q[c] == q[i]) {
			return false;
		}
		if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) {
			return false;
		}
		if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) {
			return false;
		}
	}
	return true;
}
void print(int *q)
{
	static int count = 0;
	cout << ++count << endl;

	for (int k = 0; k < 3; k++)
		cout << "m" << k << " " << "w" << q[k];
}
void move(int* q, int i) // try place in col i
{
	if (i == 3)
	{
		print(q);
		return;
	}

	for (int j = 0; j<3; j++) // j is the row value
	{
		q[i] = j;
		if (ok(q, i)) // try and place a queen in row j of col i,if yes
			move(q, i + 1); // go to next column otherwise try next j
	}

	// no value of j worked so return;
};
int main()
{
	int q[8];
	move(q, 0);
	system("pause");
}