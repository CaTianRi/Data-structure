#include "head.h"

int LocateVex(MGraph* G, VertexType v)
{
	for (int i = 0; i < G->vexnum; ++i)
	{
		if (G->vexs[i] == v)
			return i;
	}
	return -1;
}


void CreateDG(MGraph* G)
{
	printf("输入图的顶点数和弧的个数：\n");
	//输入图的顶点数和弧的个数
	scanf("%d %d", &(G->vexnum), &(G->arcnum));
	
	printf("输入顶点本身的数据：");
	//输入顶点本身的数据
	for (int i = 0; i < G->vexnum; ++i)
	{
		scanf("%d", &(G->vexs[i]));
	}

	//初始化矩阵
	for (int i = 0; i < G->vexnum; ++i)
	{
		for (int j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}

	//在二维数组中添加弧的数据
	for (int i = 0; i < G->arcnum; ++i)
	{
		int v1 = 0, v2 = 0;
		int n = 0, m = 0;
		//输入弧头和弧尾
		scanf("%d %d", &v1, &v2);

		//确定顶点位置
		n = LocateVex(G, v1);
		m = LocateVex(G, v2);

		if (m == -1 || n == -1)
		{
			printf("no such vertex\n");
			return;
		}

		G->arcs[n][m].adj = 1;
	}
}

void CreateDN(MGraph* G)
{
	printf("输入图的顶点数和弧的个数：\n");
						//顶点数		//弧数
	scanf("%d %d", &(G->vexnum), &(G->arcnum));

	printf("输入顶点本身的数据：");
	for (int i = 0; i < G->vexnum; ++i)
	{
		scanf("%d", &(G->vexs[i]));
	}

	for (int i = 0; i < G->vexnum; ++i)
	{
		for (int j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}

	for (int i = 0; i < G->arcnum; ++i)
	{
		int v1, v2;
		int n, m;
		printf("请输入弧头和弧尾:>");
		scanf("%d %d", &v1, &v2);

		n = LocateVex(G, v1);
		m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("没有这个坐标.\n");
			return;
		}
		G->arcs[n][m].adj = 1;
		G->arcs[m][n].adj = 1;
	}
}

void CreateUDN(MGraph* G)
{
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i < G->vexnum; ++i)
	{
		scanf("%d", &(G->vexs[i]));
	}

	for (int i = 0; i < G->vexnum; ++i)
	{
		for (int j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}

	for (int i = 0; i < G->arcnum; ++i)
	{
		int v1, v2, w;
		int n, m;
		scanf("%d,%d,%d", &v1, &v2, &w);

		n = LocateVex(G, v1);
		m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("没有这个坐标.\n");
			return;
		}

		G->arcs[n][m].adj = w;
		G->arcs[m][n].adj = w;
	}
}

void CreateUDG(MGraph* G) {
	int i, j;
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	for (i = 0; i < G->vexnum; i++) {
		scanf("%d", &(G->vexs[i]));
	}
	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	for (i = 0; i < G->arcnum; i++) {
		int v1, v2, w;
		int n, m;
		scanf("%d,%d,%d", &v1, &v2, &w);
		n = LocateVex(G, v1);
		m = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = w;
	}
}

void CreateGraph(MGraph* G)
{
	scanf("%d", &(G->Kind));
	switch (G->Kind)
	{
	case DG:
		CreateDG(G);
		break;
	case DN:
		CreateDN(G);
		break;
	case UDG:
		CreateUDG(G);
		break;
	case UDN:
		CreateUDN(G);
		break;
	default:
		break;
	}
}

void PrintGrapth(MGraph G)
{
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}