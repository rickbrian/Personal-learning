#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//随机号码
void Randomnumber(int arr[])
{
	for (int i = 0; i < 6; i++)
	{
		int a = rand() % 32 + 1;

		for (int j = 0; j <= i; j++)
		{
			if (a == arr[j])
			{
				i--;
				break;
			}
			if (i == j)
			{
				arr[i] = a;
			}
		}
	}
}


//冒泡排序
void Bubblesorting(int arr[])
{
	for (int i = 0; i < 6 - 1; i++)
	{
		for (int j = 0; j < 6 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int max = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = max;
			}
		}
	}
}

//打印
void printfarr(int arr[],int red)
{
	printf("红球:\t");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("蓝球：%d\t", red);
}

int main()
{
	srand((unsigned int)time(0));

	int arr[6] = {2000,2000,2000,2000,2000,2000};
	int red=0;
	int n = 0;
	int select = 0;

	printf("----------------彩票系统------------------\n ");
	printf("\t\t1.机选\n");
	printf("\t\t2.自选\n");
	printf("请选择：");

	scanf("%d", &select);
	printf("买几注：");
	scanf("%d", &n);

	switch (select)
	{
	case 1:
		{
			for (int x = 0; x < n; x++)//买n注，循环n次
			{
				Randomnumber(arr);//随机号码
				red = rand() % 16 + 1;//红球
				Bubblesorting(arr);//排序
				printfarr(arr, red);//打印
				printf("\n");
			}
		}
		break;
	case 2:
		{
			for (int y = 0; y < n; y++)//买n注，循环n次
			{
				printf("蓝球（6个）：");
				for (int i = 0; i < 6; i++)//持续输入每个数
				{
					scanf("%d", &arr[i]);
				}
				printf("红球（1个）：");
				scanf("%d", &red);
				Bubblesorting(arr);//排序
				printfarr(arr, red);//打印
				printf("\n");
			}
		}
		break;
	}

	return 0;
}