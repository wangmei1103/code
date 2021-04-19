#include<stdio.h>
void test1()
{
	int a = 10 | 11;
	//printf("%d \n", a);//11

	int year = 1009;
	int *p = &year;
	//可以将变量year变为1010
	//(*p)++;
	//++(*p);
	//*p += 1;
	//不可以将变量year变为1010
	//*p++;
}
void test2()
{
	int x, y;
	for (x = 0, y = 0; (y = 123) && (x < 4); x++)
	{
		printf("1");
	}
	
	
}
//int main()
//{
//	//test1();
//	//printf("%s,%5.3s\n", "computer", "computer");
//	test2();
//	return 0;
//}