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

void right(double** Neo, int n)//������
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

void down(double** Neo, int n)//����
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

void left(double** Neo, int n)//����� �������, �� ��� � �� ���������  
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

void up(double** Neo, int n)//�����
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
	cout << "������ >>>\n";
	for (int i = 0; i < h; i++) {
		cout << "{  ";
		for (int j = 0; j < l; j++) {
			Neo[i][j] = 0 + rand() % 25;
			cout << Neo[i][j] << ", ";
		}
		cout << "}";
		cout << endl;
	}

	cout << "�� ������� ��������: \n";
	cin >> n;
	cout << "���� �������� 0 - ������, 1 - �����, 2 - ����, 3 - ����� >>> ";
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
	cout << "\n" << "����� ������� � ������� > > >" << "\n";
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
	cout << "������� ������ �����:  "; cin >> a;
	cout << "������� ������ �����:  "; cin >> b;
	max = (*&a < *&b) ? b : a;
	cout << "���������� ����� " << max << endl;

}

void a3()
{
	double a, max = 0;
	cout << "������� ������ �����:  "; cin >> a;
	max = (*&a < 0) ? 1 : 0;
	if (max == 0)
		cout << "����� ������ ���� ��� ����� ����\n";
	else cout << "����� ������ ����\n";
}

void a4()
{
	int a, b, max;
	cout << "������� a:  "; cin >> a;
	cout << "������� b:  "; cin >> b;
	cout << "���� >> a = " << *&a << ", b = " << *&b << endl;
	int* temp = new int();
	*temp = a;
	int* numb = &b;
	a = *numb;
	b = *temp;
	cout << "����� >> a = " << *&a << ", b = " << *&b << endl;
	delete temp;
}

void a5()
{
	int num1, num2, res;
	char key;
	char* a = &key;
	cout << "������� ������ �����: ";
	cin >> num1;
	cout << "������� ������ �����: ";
	cin >> num2;
	int* F = &num1, * S = &num2, * Res = &res;
	cout << "������� �������� �������� +, -, *, /, ������� ������ ��������� ";
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
			cout << "�� ����� ������������ ������, ��������� ���� ��������: ";
			break;
		}
	} while (*a != '+' && *a != '-' && *a != '*' && *a != '/');
}

void a6()
{
	const int size = 10;
	int arr[size];
	int* arr_ptr = arr;
	cout << "������ >>>\n";
	print_arr(arr_ptr, size);
	cout << "\n";
	cout << "����� = " << sum_arr(arr_ptr, size) << "\n";

}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int f;
	do {
		cout << "������ 1 - 6  >>> "; cin >> f;
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
















