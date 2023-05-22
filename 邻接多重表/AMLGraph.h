#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define VertexType char
#define Status int


typedef enum { unvisited, visited }VisitIf;

typedef struct EBox
{
	VisitIf mark;
	int ivex, jvex;
	struct EBox* ilink, * jlink;
}EBox;

typedef struct VexBox
{
	VertexType data;
	EBox* firstedge;
}VexBox;

typedef struct
{
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum;
}AMLGraph;

//��ȡ v ������˳����е�λ���±�
int LocateVex(AMLGraph* G, VertexType v);
//�����ڽӶ��ر�
Status CreateDN(AMLGraph* G);
//��(V1,V2)���뵽�ڽӶ��ر���
Status InsertEdge(AMLGraph* G, VertexType V1, VertexType V2);
//���ڽӶ��ر���ɾ�� (V1,V2)����(V2,V1)
Status DeleteEdge(AMLGraph* G, VertexType V1, VertexType V2);
//����ڽӶ��ر��а��������б�
void PrintEdges(AMLGraph* G);
//���ø�������еı�־��
void InitMarks(AMLGraph* G);
//�ͷ��ڽӶ��ر�������Ķѿռ�
Status DeleteDN(AMLGraph* G);