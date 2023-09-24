#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
	
#define Max 20				//顶点的最大个数
#define VRType int			//表示顶点之间的关系的变量类型
#define InfoType char		 //存储弧或者边额外信息的指针变量类型
#define VertexType int		//图中顶点的数据类型

typedef enum { DG, DN, UDG, UDN }GraphKinde;		//图中顶点的数据类型

typedef struct
{
	VRType adj;
	InfoType* info;
}ArcCell, AdjMatrix[Max][Max];

typedef struct
{
	VertexType vexs[Max];	 //存储图中顶点数据
	AdjMatrix arcs;			//二维数组，记录顶点之间的关系
	int vexnum, arcnum;		//记录图的顶点数和弧（边）数
	GraphKinde Kind;		//记录图的种类
}MGraph;

//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph* G, VertexType v);

//构造有向图
void CreateDG(MGraph* G);

//构造无向图
void CreateDN(MGraph* G);

//构造有向网，和有向图不同的是二阶矩阵中存储的是权值。
void CreateUDG(MGraph* G);

//构造无向网。和无向图唯一的区别就是二阶矩阵中存储的是权值
void CreateUDN(MGraph* G);

//创造图
void CreateGraph(MGraph* G);

//输出函数
void PrintGrapth(MGraph G);

