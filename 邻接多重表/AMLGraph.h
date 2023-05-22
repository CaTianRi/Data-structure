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

//获取 v 顶点在顺序表中的位置下标
int LocateVex(AMLGraph* G, VertexType v);
//创建邻接多重表
Status CreateDN(AMLGraph* G);
//将(V1,V2)插入到邻接多重表中
Status InsertEdge(AMLGraph* G, VertexType V1, VertexType V2);
//从邻接多重表中删除 (V1,V2)或者(V2,V1)
Status DeleteEdge(AMLGraph* G, VertexType V1, VertexType V2);
//输出邻接多重表中包含的所有边
void PrintEdges(AMLGraph* G);
//重置各个结点中的标志域
void InitMarks(AMLGraph* G);
//释放邻接多重表中申请的堆空间
Status DeleteDN(AMLGraph* G);