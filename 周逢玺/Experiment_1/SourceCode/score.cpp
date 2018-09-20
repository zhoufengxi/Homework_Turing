/*************************************************
** Դ�ļ�   : score.cpp
** ����˵�� : Function Definations
/**************************************************/
#include "score.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int N;//ȫ�ֱ���N������˵��ѧ������
struct Students SS[1000];//�ṹ������
/*---------------�ֶ�����ѧ����Ϣ------------------------*/
int readData()
{
	int i;
	cout << "---------����༶����-----------" << endl;
	cin >> N;
printf("----�밴���¸�ʽ����ѧ����Ϣ ѧ�� ���� ƽ���ɼ� ʵ��ɼ� ��ĩ�ɼ� \n");
	for (i = 0; i < N; i++)
	{
		scanf("%s%s%f%f%f", &SS[i].number, &SS[i].name, &SS[i].dailyScore, &SS[i].expriScore, &SS[i].finalScore);
	}
	i = 0;
	FILE* fp;
	
	fp = fopen("data.txt", "w");
	
	fprintf(fp, "%d\n", N); // ����һ����\n��,��֤�����ļ��������ܱ���ȷ����
	for (i; i < N; i++)
	{

		printf("%s %s %3.2f %3.2f %3.2f\n", SS[i].number, SS[i].name, SS[i].dailyScore, SS[i].expriScore, SS[i].finalScore);

	}
	i = 0;
	for (i; i < N; i++)
	{
		fprintf(fp, "%s %s %3.2f %3.2f %3.2f\n", SS[i].number, SS[i].name, SS[i].dailyScore, SS[i].expriScore, SS[i].finalScore);
	}


	fclose(fp);



	return N;
}
/*------------------------���ļ��ж�ȡѧ����Ϣ-------------------------------*/
int readDataFromFile()
{
	printf("\n---------------------��һ�� ���ļ���ȡѧ����Ϣ------------------\n");
	FILE* fp;
	int i,count=0;
	fp = fopen("data.txt", "r");
	fscanf(fp, "%d", &N);
    
	printf("ѧ����ĿΪ%d\n",N);
	for (i = 0; i < N; i++)
	{
		fscanf(fp, "%s%s%f%f%f\n", &SS[i].number, &SS[i].name, &SS[i].dailyScore, &SS[i].expriScore, &SS[i].finalScore);
		printf("ѧ�ţ�%s        ������%-8s           ƽʱ�ɼ���%3.2f        ʵ��ɼ���%3.2f     ��ĩ�ɼ���%3.2f\n", SS[i].number, SS[i].name, SS[i].dailyScore, SS[i].expriScore, SS[i].finalScore);
	}
	
	return N;
}
/*---------------------���������ɼ�-------------------------------------*/
int calcuScore()
{
	printf("\n----------------�ڶ��� �����ѧ���������ɼ�(=0.2*ƽʱ�ɼ�+0.2ʵ��ɼ�+0.6��ĩ�ɼ�)------------\n");
	int i = 0;
	Students *ss;
	ss = SS;
	for (; i < N; i++, ss++)
	{
		ss->generalScore = 0.2*SS[i].dailyScore + 0.2*SS[i].expriScore + 0.6*SS[i].finalScore;
		printf("ѧ�ţ�%s        ������%-8s            �����ɼ���%3.2f\n", SS[i].number, SS[i].name, SS[i].generalScore);
	}
	return 0;
}
/*--------------------����ѧ���ɼ�����-------------------*/
float sort(int N)
{
	int i, j, k;
	Students b;
	for (i = 0; i < N - 1; i++)
	{
		k = i;
		for (j = i + 1; j < N; j++)
			if ((SS[k].generalScore - SS[j].generalScore) < 0) k = j;
		if (k != i)
		{
			b = SS[i]; SS[i] = SS[k]; SS[k] = b;
		}

	}
	return 0;
}
/*-------------------------����ʽ��ӡ��Ϣ-----------------------------------*/
int printOut()
{
	printf("\n-------------------������ �ó�ѧ���ɼ�����-----------------\n");

	int i = 0;
	for (; i < N; i++)
	{
		printf("��%-2d����       ѧ�ţ�%s           ������%-8s        �����ɼ���%3.2f\n",i+1, SS[i].number, SS[i].name, SS[i].generalScore);
	}
	return 0;
}
/*---------------------����ѧ�Ų�ѯѧ����Ϣ-------------------------*/
int search()
{
	printf("\n-----------����ѧ���Ų�ɼ�--------------\n");
	char num[20];
	bool flag = false;
	scanf("%s", num);
	string p = num;
	int i = 0;
	for (; i <= N; i++)
	{
		string q = SS[i].number;
		if (p == q)

		{
			printf("��%-2d����       ѧ�ţ�%s           ������%-8s        �����ɼ���%3.2f\n", i + 1, SS[i].number, SS[i].name, SS[i].generalScore);
				flag = true;
		};
	}
	if (flag==false)
			printf("\n-------error, cann't get anything!---------\n");
	getchar();
		return 0;
}
/*------------------------���㷽�ƽ��ֵ-----------------------------*/
int  variance()
{
	printf("\n-------�༶�ɼ�����---------\n");
	float m, a = 0;
	int i = 0;
	for (; i < N;i++)
	{
		a = a + SS[i].generalScore;

	}
	m = a / N;
	printf("ƽ��ֵ %4.2f        ", m);
	float b, e = 0;
	 i = 0;
	 b = m;
	for (; i < N; i++)
	{
		e = (SS[i].generalScore - b)*(SS[i].generalScore - b) / N;
	}

	printf("���� %4.2f\n", e);
	return 0;
}
/*------------------------�ɼ�����-------------------------*/
int analyse()
{
	int i = 0;
		float j=0,l=0,k=0,n=0,f=0;
	
	for (i = 0; i < N; i++)
	{
		if (SS[i].generalScore >= 90)
			j = j + 1;
		else
		{
			if (SS[i].generalScore >= 80)
				l = l + 1;
			else
			{
				if (SS[i].generalScore >= 70)
					k = k + 1;
				else
				{
					if (SS[i].generalScore >= 60)
						n = n+ 1;
					else f = f + 1;
				}

			}

		}

	}
	printf("�ֶα���:90������%4.2f, 80~90��%4.2f, 70~80��%4.2f,  60~70������%4.2f,  ������%4.2f", j / N, l / N, k / N, n / N, f / N);
	return 0;
}



