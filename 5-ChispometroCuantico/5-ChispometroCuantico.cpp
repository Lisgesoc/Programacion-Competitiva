#include <iostream>
#include <vector>
using namespace std;




bool resuelve() {
	int n, a, b ,c, y;
	cin >> n;
	vector<int> v(n + 1, 0);
	if (n == 0) return false;

	cout << "? 1 2" << endl << flush;
	if (!(cin >> a)) return 0;
	cout << "? 1 3" << endl << flush;
	if (!(cin >> b)) return 0;
	cout << "? 2 3" << endl << flush;
	if (!(cin >> c)) return 0;

	v[1] = (a + b - c) / 2;
	v[2] = a - v[1];
	v[3] = b - v[1];

	//y = a / 2 - b / 2 - c;
	//v[1] = y;
	for (int i = 4; i <= n; ++i) {
		long long int m;
		cout << "? 1 " << i << endl <<flush;
		if (!(cin >> m)) return 0;
		v[i] = m - v[1];

	}
	cout << "Respuesta: ";
	for (int i = 1; i <= n; ++i) {
		if (i > 1) cout << ' ';
		cout << v[i];
	}
	cout << endl;


	return true;
}


int main() {
	while (resuelve())
		;
	return 0;
}
