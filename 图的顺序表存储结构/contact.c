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
	printf("����ͼ�Ķ������ͻ��ĸ�����\n");
	//����ͼ�Ķ������ͻ��ĸ���
	scanf("%d %d", &(G->vexnum), &(G->arcnum));
	
	printf("���붥�㱾������ݣ�");
	//���붥�㱾�������
	for (int i = 0; i < G->vexnum; ++i)
	{
		scanf("%d", &(G->vexs[i]));
	}

	//��ʼ������
	for (int i = 0; i < G->vexnum; ++i)
	{
		for (int j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}

	//�ڶ�ά��������ӻ�������
	for (int i = 0; i < G->arcnum; ++i)
	{
		int v1 = 0, v2 = 0;
		int n = 0, m = 0;
		//���뻡ͷ�ͻ�β
		scanf("%d %d", &v1, &v2);

		//ȷ������λ��
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
	printf("����ͼ�Ķ������ͻ��ĸ�����\n");
						//������		//����
	scanf("%d %d", &(G->vexnum), &(G->arcnum));

	printf("���붥�㱾������ݣ�");
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
		printf("�����뻡ͷ�ͻ�β:>");
		scanf("%d %d", &v1, &v2);

		n = LocateVex(G, v1);
		m = LocateVex(G, v2);

		if (n == -1 || m == -1)
		{
			printf("û���������.\n");
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
			printf("û���������.\n");
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