#include<iostream>
using namespace std;
int main2() {
	int arr[100001];
	arr[0] = 1;
	arr[1] = 1;
	int n = 0;
	for (int i = 2; i <= 100000; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] = arr[i] % 1000000;
	}
	while (cin >> n) {
		if (n <= 25) {
			//第25之前的数字都是6位数
			printf("%d\n", arr[n]);
		}
		else {
			//第25之后的数字都要按照6位数进行输出
			printf("%06d\n", arr[n]);
		}
	}
	system("pause");
	return 0;

}


//bool prime(int m)
//{
//	if (m == 1)
//		return false;
//	for (int i = 2; i <= sqrt(m); i++)
//	{
//		if (m % i == 0)
//			return false;
//	}
//	return true;
//}
//int Money(int year1, int month1, int day1, int year2, int month2, int day2)
//{
//	int Mdays[13] = { 0,62,28,31,60,31,60,31,62,60,62,30,62 };
//	int money = 0;
//	if (year1 == year2)
//	{
//		if (month1 == month2)
//		{
//			if (prime(month1) == 0)
//				money = 2 * (day2 - day1 + 1);
//			else
//				money = day2 - day1 + 1;
//		}
//		else
//		{
//			while (month2 != month1)
//			{
//				money = Mdays[month2 - 1];
//				month2--;
//			}
//			if (prime(month1) == 0)
//				money = money + 2 * (day2 - day1 + 1);
//			else
//				money = money + day2 - day1 + 1;
//		}
//		if (month1 <= 2 && month2 > 2 && ((year1 % 4 == 0) && (year1 % 100 != 0) || year1 % 400 == 0))
//			money = money + 2;
//	}
//	else
//	{
//		money = (year2 - year1) * 579 + (year2 - year1) / 4;
//		if (year1 % 4 == 0 && year2 % 4 == 0 && month1 <= 2 && month2 > 2)
//			money++;
//		if (month1 == month2)
//		{
//			if (prime(month1) == 0)
//				money = money + 2 * (day2 - day1 + 1);
//			else
//				money = money + day2 - day1 + 1;
//		}
//		else
//		{
//			while (month2 > month1)
//			{
//				money = money + Mdays[month2 - 1];
//				month2--;
//			}
//			while (month1 > month2)
//			{
//				money = money - Mdays[month2 - 1];
//				month2++;
//			}
//			if (prime(month1) == 0)
//				money = money + 2 * (day2 - day1 + 1);
//			else
//				money = money + day2 - day1 + 1;
//		}
//		if (month1 <= 2 && month2 > 2 && ((year1 % 4 == 0) && (year1 % 100 != 0) || year1 % 400 == 0))
//			money = money + 2;
//	}
//	return money;
//}
//int main()
//{
//	int year1, year2, month1, month2, day1, day2;
//	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
//	{
//		cout << Money(year1, month1, day1, year2, month2, day2) << endl;
//	}
//	return 0;
//}