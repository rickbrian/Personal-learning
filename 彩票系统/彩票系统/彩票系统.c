#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�������
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


//ð������
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

//��ӡ
void printfarr(int arr[],int red)
{
	printf("����:\t");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("����%d\t", red);
}

int main()
{
	srand((unsigned int)time(0));

	int arr[6] = {2000,2000,2000,2000,2000,2000};
	int red=0;
	int n = 0;
	int select = 0;

	printf("----------------��Ʊϵͳ------------------\n ");
	printf("\t\t1.��ѡ\n");
	printf("\t\t2.��ѡ\n");
	printf("��ѡ��");

	scanf("%d", &select);
	printf("��ע��");
	scanf("%d", &n);

	switch (select)
	{
	case 1:
		{
			for (int x = 0; x < n; x++)//��nע��ѭ��n��
			{
				Randomnumber(arr);//�������
				red = rand() % 16 + 1;//����
				Bubblesorting(arr);//����
				printfarr(arr, red);//��ӡ
				printf("\n");
			}
		}
		break;
	case 2:
		{
			for (int y = 0; y < n; y++)//��nע��ѭ��n��
			{
				printf("����6������");
				for (int i = 0; i < 6; i++)//��������ÿ����
				{
					scanf("%d", &arr[i]);
				}
				printf("����1������");
				scanf("%d", &red);
				Bubblesorting(arr);//����
				printfarr(arr, red);//��ӡ
				printf("\n");
			}
		}
		break;
	}

	return 0;
}