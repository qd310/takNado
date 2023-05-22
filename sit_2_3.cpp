#include <iostream>

int fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int n;
	std::cout << "Enter a number n: ";
	std::cin >> n;

	std::cout << "First " << n << " Fibonacci numbers:" << std::endl;

	for (int i = 0; i < n; i++) {
		std::cout << fib(i) << std::endl;
	}

	return 0;
}