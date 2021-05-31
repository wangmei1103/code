#include<iostream>
using namespace std;

int YearFirstDay(int year)
{
	int day = 6;
	int yearday = (year - 2000) * 365 + (year - 2000 - 1) / 4 + 1;
	int firstday = (day + yearday) % 7;
	if (firstday == 0)
		firstday = 7;
	return firstday;
}

void NewYear(int year)
{
	cout << year << "-";
	cout << "01-01" << endl;
}
void MartinLutherKing(int year)
{
	cout << year << "-";
	int day = 14;
	int firstday = YearFirstDay(year);
	int n = 3;
	day = day + (7 - firstday) + 2;
	if (day > 21)
		day = day - 7;
	cout << "01-" << day << endl;
}
void President(int year)
{
	cout << year << "-";
	int Febfirstday = (YearFirstDay(year) + 31) % 7;
	int day = 14;
	day = day + (7 - Febfirstday) + 2;
	if (day > 21)
		day = day - 7;
	cout << "02-" << day << endl;
}
void Martyr(int year)
{
	cout << year << "-";
	int tmp = 120;
	int day = 21;
	if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
		tmp++;
	int MayFirstday = (YearFirstDay(year) + tmp) % 7;
	day = day + (7 - MayFirstday) + 2;
	if (day + 7 <= 31)
		day = day + 7;
	cout << "05-" << day << endl;
}
void USNationalDay(int year)
{
	cout << year << "-";
	cout << "07-04" << endl;
}
void LaborDay(int year)
{
	cout << year << "-";
	int tmp = 243;
	int day = 0;
	if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
		tmp++;
	int SepFirstday = (YearFirstDay(year) + tmp) % 7;
	day = day + (7 - SepFirstday) + 2;
	day = day % 7;
	if (day == 0)
		day = 7;
	cout << "09-0" << day << endl;
}
void Thanksgiving(int year)
{
	cout << year << "-";
	int tmp = 304;
	int day = 21;
	if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
		tmp++;
	int NovFirstday = (YearFirstDay(year) + tmp) % 7;
	day = day + (7 - NovFirstday) + 5;
	if (day > 30)
		day = day - 7;
	cout << "11-" << day << endl;
}
void Christmas(int year)
{
	cout << year << "-";
	cout << "12-25" << endl;
}
int main()
{
	int year;
	while (cin >> year)
	{
		NewYear(year);
		MartinLutherKing(year);
		President(year);
		Martyr(year);
		USNationalDay(year);
		LaborDay(year);
		Thanksgiving(year);
		Christmas(year);
		cout << endl;
	}
	return 0;
}

//bool prime(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//void factor(int n)
//{
//	cout << n << " = ";
//	int tmp = 1;
//	int m = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		while (n != i)
//		{
//			if (n % i == 0 && prime(i) == 1)
//			{
//				cout << i << " * ";
//				n /= i;
//			}
//			else
//				break;
//		}
//	}
//	cout << n << endl;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		factor(n);
//	}
//	return 0;
//}


//int main()
//{
//	int i, n;
//	while (cin>>n)
//	{
//		cout << n << " = ";
//		for (i = 2; i <= sqrt(n); i++)
//			while (n != i)
//			{
//				if (n%i == 0)
//				{
//					cout << i << " * ";
//					n /= i;
//				}
//				else
//					break;
//			}
//		cout << n << endl;
//	}
//	return 0;
//}
