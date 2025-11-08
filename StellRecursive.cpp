#include <iostream>
using namespace std;

//Задание 1
//1.1 НОД
void gcd(int a, int b, int& results) {
	if (b == 0) {
		results = a;
		return;
	}
	gcd(b, a % b, results);
}

//1.2 Фибонначи
void fibonacci(int n, int& result) {
	if (n <= 1) {
		result = n;
		return;
	}
	int fib1, fib2;
	fibonacci(n - 1, fib1);
	fibonacci(n - 2, fib2);
	result = fib1 + fib2;
}

//1.3 Переворот числа
void reversedNumber(int n, int& reversed) {
	if (n == 0)
		return;
	reversed = reversed * 10 + n % 10;
	reversedNumber(n / 10, reversed);
}

//Задание 2

//2.1 Представление
void findSumma(int n, int m, int start, int current[], int pos) {
	if (m == 0) {
		if (n == 0) {
			for (int i = 0; i < pos; i++) {
				cout << current[i];
				if (i < pos - 1)
					cout << " + ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = start; i <= n; i++) {
		current[pos] = i;
		findSumma(n - i, m - 1, i, current, pos + 1);
	}
}

//2.1 Двойной факториал
void doubleFactorial(int n, int& result) {
	if (n <= 1) {
		result = 1;
		return;
	}
	int temp;
	doubleFactorial(n - 2, temp);
	result = n * temp;
}

//2.2 Количество единиц
void countOnes(int n, int& result) {
	if (n == 0)
		return;
	if (n % 2 == 1)
		result++;
	countOnes(n / 2, result);
}

//2.3 Умножение
void multiply(int a, int b, int& result) {
	if (b == 0) {
		result = 0;
		return;
	}
	multiply(a, b - 1, result);
	result += a;
}

//2.4 Сложение
void add(int a, int b, int& result) {
	if (b == 0) {
		result = a;
		return;
	}
	add(a + 1, b - 1, result);
}

//2.5 Палиндром

void Palindrome(char str[], int i, int j, bool& result) {
	if (i >= j) {
		result = true;
		return;
	}
	if (str[i] != str[j]) {
		result = false;
		return;
	}
	Palindrome(str, i + 1, j - 1, result);
}

//2.6 Количество цифр
void countDigits(int n, int& count) {
	if (n == 0)
		return;
	count++;
	countDigits(n / 10, count);
}

//главная программа

int main() {
	setlocale(LC_ALL, "ru");
	int choice;
	cout << "1.1 - НОД двух чисел" << endl;
	cout << "1.2 - Число Фибоначчи" << endl;
	cout << "1.3 - Переворот числа" << endl;
	cout << "2.1 - Представления в виде суммы" << endl;
	cout << "2.2 - Количество единиц в двоичном" << endl;
	cout << "2.3 - Сложение через +1" << endl;
	cout << "2.4 - Умножение через сложение" << endl;
	cout << "2.5 - Проверка на палиндром" << endl;
	cout << "2.6 - Количество цифр" << endl;
	cout << "Введите номер задания: ";
	cin >> choice;

	switch (choice) {
	case 1: {
		int a, b, result;
		cout << "Введите два числа: ";
		cin >> a >> b;
		gcd(a, b, result);
		cout << "НОД(" << a << " , " << b << ") = " << result << endl;
		break;
		}
	case 2: {
		int n, result;
		cout << "Введите номер числа: ";
		cin >> n;
		fibonacci(n, result);
		cout << "F(" << n << ") = " << result << endl;
		break;
	}
	case 3: {
		int n, reversed = 0;
		cout << "Введите число: ";
		cin >> n;
		reversedNumber(n, reversed);
		cout << "Перевернутое: " << reversed << endl;
		break;
	}
	case 4: {
		int n, m;
		cout << "Введите число n: ";
		cin >> n;
		cout << "Введите m: ";
		cin >> m;
		int current[100];
		cout << "Представление: " << endl;
		findSumma(n, m, 1, current, 0);

		int dfResult;
		doubleFactorial(n, dfResult);
		cout << n << "!! = " << dfResult << endl;
		break;
	}
	case 5: {
		int n, result = 0;
		cout << "Введите число: ";
		cin >> n;
		countOnes(n, result);
		cout << "Единиц в двоичном: " << result << endl;
		break;
	}
	case 6: {
		int a, b, result;
		cout << "Введите два числа: ";
		cin >> a >> b;
		add(a, b, result);
		cout << a << " * " << b << " = " << result << endl;
		break;
	}
	case 7: {
		int a, b, result;
		cout << "Введите два числа: ";
		cin >> a >> b;
		multiply(a, b, result);
		cout << a << " * " << b << " = " << result << endl;
		break;
	}
	case 8: {
		char str[100];
		int i, j;
		bool result;
		cout << "Введите строку: ";
		cin >> str;
		cout << "Введите i и j: ";
		cin >> i >> j;
		Palindrome(str, i, j, result);
		cout << (result ? "Палиндром" : "Не палиндром") << endl;
		break;
	}
	case 9: {
		int n, count = 0;
		cout << "Введите число: ";
		cin >> n;
		if (n == 0) count = 1;
		else countDigits(n, count);
		cout << "Количество цифр: " << count << endl;
		break;
	}
	default:
		cout << "Неверный выбор!" << endl;
	}
	return 0;

}