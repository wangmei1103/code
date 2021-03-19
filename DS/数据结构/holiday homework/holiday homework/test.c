#include<stdio.h>
//int main()
//{
//	//1.1
//	//int num, sum;
//	//num = sum = 7;
//	//sum = num++;
//	///*sum++;
//	//++num;*/
//	//printf("%d", sum);
//	//printf("%d", num);
//	//1.2
//	/*int i = 10, j = 10, k = 3;
//	k *= i + j;
//	printf("%d", k);*/
//	//1.3
//	/*int i, j, a[2][3];
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++) {
//			a[i][j] = i * 3 + j + 1;
//			printf("%d,",a[i][j]);
//		}
//	}*/
//	/*int i, j, a[2][3];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++) {
//			a[j][i] = j * 3 + i + 1;
//			printf("%d,", a[i][j]);
//		}
//	}*/
//	/*int i, j, a[2][3];
//	for (i = 0; i < 6; i++)
//	{
//		a[i / 3][i % 3] = i + 1;
//		printf("%d,", a[i / 3][i % 3]);
//	}*/
//	/*int i, j, a[2][3];
//	for (i = 1; i < +6; i++)
//	{
//		a[i][i] = i;
//		printf("%d,", a[i][i]);
//	}*/
//	
//	return 0;
//}
char * toLowerCase(char * str) {
	if (str == NULL)
		return NULL;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'A')
		{
			str[i] += 32;
		}
		printf("%c", str[i]);
	}
}
int main()
{
	char* str ="Hello";
	toLowerCase(&str);
	return 0;
}