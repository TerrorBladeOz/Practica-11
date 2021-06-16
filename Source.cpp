#include <iostream>
#include <ctime>
using namespace std;

const int l = 5, h = 5;

template <typename T1>
void print_arr(T1* arr_ptr, int size)
{
	cout << "{ ";
	for (int i = 0; i < size; i++)
	{
		*(arr_ptr + i) = rand() % 100;
		cout<< *(arr_ptr + i) <<", " ;
	}
	cout << "}";
}

template <typename T1>
T1 sum_arr(T1* arr_ptr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(arr_ptr + i);
	}
	return sum;
}

void right(double** Neo, int n)//вправо
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < h; i++) {
			double t = Neo[i][l - 1];
			int j;
			for (j = h - 1; j > 0; j--) {
				Neo[i][j] = Neo[i][j - 1];
			}
			Neo[i][j] = t;
		}
	}
}

void down(double** Neo, int n)//вниз
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < h; i++) {
			double t = Neo[l - 1][i];
			int j;
			for (j = l - 1; j > 0; j--) {
				Neo[j][i] = Neo[j - 1][i];
			}
			Neo[j][i] = t;
		}
	}
}

void left(double** Neo, int n)//долго пытался, но так и не додумался  
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < h; i++) {
			double t = Neo[i][l - 1];
			int j;
			for (j = l - 1; j > 0; j--) {
				Neo[i][j] = Neo[i][j- 1];
			}
			Neo[i][j] = t;
		}
	}
}

void up(double** Neo, int n)//вверх
{
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < h; ++i) {
			double t = Neo[l - 1][i];
			int j;
			for (j = l - 1; j > 0; --j)
				Neo[j][i] = Neo[j - 1][i];
			Neo[0][i] = t;

		}
	}
}

void a1()
{
	int n;
	int a;
	double** Neo;
	Neo = new double* [l];
	for (int i = 0; i < l; i++) {
		Neo[i] = new double[h];
	}
	cout << "Массив >>>\n";
	for (int i = 0; i < h; i++) {
		cout << "{  ";
		for (int j = 0; j < l; j++) {
			Neo[i][j] = 0 + rand() % 25;
			cout << Neo[i][j] << ", ";
		}
		cout << "}";
		cout << endl;
	}

	cout << "На сколько сдвинуть: \n";
	cin >> n;
	cout << "Куда сдвинуть 0 - вправо, 1 - влево, 2 - вниз, 3 - вверх >>> ";
	cin >> a;
	if (a == 0) {
		right(Neo, n);
	}
	else if (a == 1) {
		left(Neo, n);

	}
	else if (a == 2) {
		down(Neo, n);
	}
	else if (a == 3) {
		up(Neo, n);
	}
	cout << "\n" << "Вывод матрицы с сдвигом > > >" << "\n";
	for (int i = 0; i < l; i++)
	{
		cout << "{ ";
		for (int j = 0; j < h; j++) {
			cout << Neo[i][j] << ", ";
		}
		cout << "}";
		cout << "\n";
	}
	for (int i = 0; i < l; i++)
	{
		delete[]Neo[i];
	}
	delete[] Neo;
	
}

void a2()
{
	double a, b, max;
	cout << "Введите первое число:  "; cin >> a;
	cout << "Введите второе число:  "; cin >> b;
	max = (*&a < *&b) ? b : a;
	cout << "Наибольшое число " << max << endl;

}

void a3()
{
	double a, max = 0;
	cout << "Введите первое число:  "; cin >> a;
	max = (*&a < 0) ? 1 : 0;
	if (max == 0)
		cout << "Число больше нуля или равно нулю\n";
	else cout << "Число меньше нулю\n";
}

void a4()
{
	int a, b, max;
	cout << "Введите a:  "; cin >> a;
	cout << "Введите b:  "; cin >> b;
	cout << "Было >> a = " << *&a << ", b = " << *&b << endl;
	int* temp = new int();
	*temp = a;
	int* numb = &b;
	a = *numb;
	b = *temp;
	cout << "Стало >> a = " << *&a << ", b = " << *&b << endl;
	delete temp;
}

void a5()
{
	int num1, num2, res;
	char key;
	char* a = &key;
	cout << "Введите первое число: ";
	cin >> num1;
	cout << "Введите второе число: ";
	cin >> num2;
	int* F = &num1, * S = &num2, * Res = &res;
	cout << "Введите операцию символом +, -, *, /, которую хотите выполнить ";
	do {
		cin >> *a;
		switch (*a)
		{
		case '+':
			*Res = *F + *S;
			cout << *F << " + " << *S << " = " << *Res << "\n";
			break;
		case '-':
			*Res = *F - *S;
			cout << *F << " - " << *S << " = " << *Res << "\n";
			break;
		case '*':
			*Res = *F * *S;
			cout << *F << " * " << *S << " = " << *Res << "\n";
			break;
		case '/':
			*Res = *F / *S;
			cout << *F << " / " << *S << " = " << *Res << "\n";
			break;
		default:
			cout << "Вы ввели неправильный символ, повторите ввод операции: ";
			break;
		}
	} while (*a != '+' && *a != '-' && *a != '*' && *a != '/');
}

void a6()
{
	const int size = 10;
	int arr[size];
	int* arr_ptr = arr;
	cout << "Массив >>>\n";
	print_arr(arr_ptr, size);
	cout << "\n";
	cout << "Сумма = " << sum_arr(arr_ptr, size) << "\n";

}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int f;
	do {
		cout << "Первая 1 - 6  >>> "; cin >> f;
		switch (f)
		{
		case 1:
			a1();
			break;
		case 2:
			a2();
			break;
		case 3:
			a3();
			break;
		case 4:
			a4();
			break;
		case 5:
			a5();
			break;
		case 6:
			a6();
			break;
		}
	} while (f != 0);
}
















