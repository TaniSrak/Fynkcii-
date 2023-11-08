#include <iostream>

int NUM; // глобальная переменная
const double PI = 3.14; // глобальная константа
const int SIZE = 5; // глобальная константа
int ARR[SIZE]; // глобальный массив

void num_inc() 
{
	NUM++;
}
void func()
{
	static int a = 0; //статическая переменная, которая не удаляется при завершении работы программы, создается один единственный раз
	a++;
	std::cout << a << std::endl;
	if (a % 5 == 0)
		std::cout << "---\n";
}
int power(int num1, int num2 = 2)
{
	int result = 1;
	for (int i = 1; i <= num2; i++)
		result *= num1;
	return result;
}
// встраеваемая функция
inline double absolute(double num)
{
	return (num < 0.0 ? -num : num); // нум меньше нуля? если да, то возвращаем возвращаем -нум ( - * - = +), иначе нум
}
// перегруженная функция
int max(int num1, int num2)
{
	std::cout << "TWO INTD\n";
	return num1 > num2 ? num1 : num2; // 1 больше чем 2? если да, то 1 меняем на 2
}
double max(double num1, double num2)
{
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}
char max(char sym1, char sym2)
{
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;
}
int max(int num1, int num2, int num3)
{
	std::cout << "THREE INTS\n";
	return num1 > max(num2, num3) ? num1 : max(num2, num3); // ? - означает вопрос "если да"
}
// шаблонная функция
// type T = int
template <typename T> 
void print_arr(T arr[], const int length)
{
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//все локальные переменные ограничиваются строго тем блоком и теми фигурными скобочками,
	// врамках которых они были созданы

	//Области видимости данных
	
	std::cout << NUM << std::endl;
	num_inc();
	std::cout << NUM << std::endl;
	std::cout << "PI = " << PI << "\n\n";

	for (int i = 0; i < 15; i++)
		func();
		

	//Передачи данных в функцию, параметры по умолчанию
	
	std::cout << "5^3 = " << power(5, 3) << std::endl;
	std::cout << "6 = " << power(6) << std::endl;
	std::cout << "5^5 = " << power(5, 5) << std::endl;
	std::cout << "2 = " << power(2) << std::endl;
	

	//встраеваемая функция
	
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << '|' << n << "| = " << absolute(n) << std::endl;
	

	// Перегруженная функция
	
	std::cout << max(5, 7) << std::endl;
	std::cout << max(1.2, 1.03) << std::endl;
	std::cout << max('k', 'K') << std::endl;
	std::cout << max(5, 6, 7) << std::endl; // параметры должны отличаться по количеству либо по типам данных
	

	// Шаблонная функция
	const int size = 5;
	int arr[size]{ 10, 20, 30, 40, 50 };
	std::cout << "Массив\n";

	print_arr (arr, size); // вызываем функцию. передаем массив и длину

	return 0;
}