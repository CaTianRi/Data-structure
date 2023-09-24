#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
	
#define Max 20				//�����������
#define VRType int			//��ʾ����֮��Ĺ�ϵ�ı�������
#define InfoType char		 //�洢�����߱߶�����Ϣ��ָ���������
#define VertexType int		//ͼ�ж������������

typedef enum { DG, DN, UDG, UDN }GraphKinde;		//ͼ�ж������������

typedef struct
{
	VRType adj;
	InfoType* info;
}ArcCell, AdjMatrix[Max][Max];

typedef struct
{
	VertexType vexs[Max];	 //�洢ͼ�ж�������
	AdjMatrix arcs;			//��ά���飬��¼����֮��Ĺ�ϵ
	int vexnum, arcnum;		//��¼ͼ�Ķ������ͻ����ߣ���
	GraphKinde Kind;		//��¼ͼ������
}MGraph;

//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph* G, VertexType v);

//��������ͼ
void CreateDG(MGraph* G);

//��������ͼ
void CreateDN(MGraph* G);

//������������������ͼ��ͬ���Ƕ��׾����д洢����Ȩֵ��
void CreateUDG(MGraph* G);

//������������������ͼΨһ��������Ƕ��׾����д洢����Ȩֵ
void CreateUDN(MGraph* G);

//����ͼ
void CreateGraph(MGraph* G);

//�������
void PrintGrapth(MGraph G);

