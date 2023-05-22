#include <iostream>


int fib(int n) {

	if (n < 1) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	else { // рекурсивный случай
		return fib(n - 1) + fib(n - 2);
	}
}

int main() {
	int n; // вычисляем 10-ое число Фибоначчи
	std::cout << "Enter n" << std::endl;
	std::cin >> n;
	int result = fib(n);
	std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
	return 0;
}