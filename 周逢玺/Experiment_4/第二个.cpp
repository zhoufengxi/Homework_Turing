#include<iostream>
using namespace std;
float checkAgeScore(int age, float score);
int main()
{
	int age;
	float score;
	char name[20];
	cout<<"�������������䣬��ֳɼ�"<<endl;
	cin >> name;
	cin >> age >> score;
	try
	{
		cout<<"������"<<name<<"  ����"<<age<<"   �ٷ��Ƴɼ�"<<checkAgeScore(age,score)<<endl;
	}
	catch (int)
	{
		cout << "���䳬����Χ\n";
	}
	catch (float)
	{
		cout << "����������Χ\n";

	}
	return 0;
}
float checkAgeScore(int age,float score)
{
	
	if (age < 16 || age>25) throw age;
	if (score< 0 || score>5) throw score;
	return 20 * score;
}