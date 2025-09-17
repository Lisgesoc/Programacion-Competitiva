#include <iostream>
using namespace std;


int query(int x, int y) {
	int pixel;
	cout << "? " << x << " " << y << endl;
	cin >> pixel;
	return pixel;
}

void sol(int max) {
	cout << "! " << max << endl;
}


bool resuelve(int n) {
	int pixel, x = 0, y = 0, max=0, current=0;
	pixel = query(x, y);
	while (pixel!=-1) {

		if (pixel == 1) {
			current++;
			if (y < n - 1) {
				y++;
			}
			else {
				sol(current);
				return true;
			}
		}
		else if (pixel == 0) {
			if (x < n - 1) {
				x++;
			}
			else {
				sol(max);
				return true;
			}
		}

		if (current > max) {
			max = current;
		}
		pixel = query(x, y);
	}
	return false;

}




int main() {
	int n;
	cin >> n;
	resuelve(n);
	return 0;
}

