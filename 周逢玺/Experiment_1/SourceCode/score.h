/*************************************************
* Head File   : SCORE.h
* File Usage  : ѧ������ϵͳͷ�ļ�
/**************************************************/
#pragma once
#ifndef __SCORE_H__
#define __SCORE_H__
#include<iostream>
#include<fstream>
/*-------------����ṹ��----------------------*/
struct Students
{
	char number[20];  //ѧ��
	char name[30];    //����
	float dailyScore;   //ƽʱ�ɼ�
	float expriScore;//ʵ��ɼ�
	float finalScore;   //��ĩ�ɼ�
	float generalScore; //�����ɼ�
};
/*---------------��������-------------------*/

int readData();//�ֶ�����ѧ����Ϣ
int readDataFromFile();//���ļ��ж�ȡ
int calcuScore();//���������ɼ�
float sort(int N);//��ѧ���ɼ��Ӹߵ�������
int printOut();//��һ����ʽ��ӡѧ����Ϣ
int  variance();//����༶�ɼ�����
int analyse();//�ɼ�����
int search();//����ѧ�Ų�ѯѧ����Ϣ
#endif

