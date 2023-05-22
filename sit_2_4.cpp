#include<iostream>
using namespace std;

void fib(int n) {
	int x0 = 0;
	int x1 = 1;
	cout << x0 << endl;
	if (n >= 1) cout << x1 << endl;
	for (int i = 2; i <= n; i++) {
		if (x0 < x1) {
			x0 += x1;

			cout << x0 << endl;
		}
		else {
			x1 += x0;
			cout << x1 << endl;
		}
	}
}

int main() {
	int n;

	cin >> n;

	fib(n);
}