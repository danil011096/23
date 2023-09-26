#include <iostream>
#include <ctime>
#include <cstdlib>

void three_max(int& b, int& n, int& m) {
	int max = std::max(b, std::max(n, m));
	b = n = m = max;
}

int& array(int arr[], const int length) {
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0)
			return arr[i];
	}
	return arr[0];

}

void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << '\t';
	std::cout << std::endl;
}

void fill_arr(int arr[], const int length, int right, int left) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void null_arr(T* arr1[], const int length1, T* arr2[], const int length2) {
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			if (*arr1[i] == *arr2[j]) {
				*arr2[j] = 0;
			}
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "Задача 1.\nВведи 3 числа -> ";
	int b, n, m;
	std::cin >> b >> n >> m;
	three_max(b, n, m);
	std::cout << b << ' ' << n << ' ' << m << std::endl;

	std::cout << "Задача 2.\n";
	srand(time(NULL));
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (50 + 50) - 50;

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
	int& result = array(arr, size);
	std::cout << "Первый отрицательный элемент = " << result << std::endl;

	std::cout << "Задача 3.\n";

	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, 11, 0);
	print_arr(arr3, size3);
	const int size4 = 10;
	int arr4[size4];
	fill_arr(arr4, size4, 11, 0);
	print_arr(arr4, size4);
	null_arr(arr3, size3, arr4, size4);
	print_arr(arr4, size4);


	return 0;
}