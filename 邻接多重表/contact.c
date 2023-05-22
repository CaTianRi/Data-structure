#include "AMLGraph.h"

int LocateVex(AMLGraph* G, VertexType v)
{
	for (int i = 0; i < G->vexnum; ++i)
	{
		if (G->adjmulist[i].data == v)
			return i;
	}
	printf("������Ϣ����\n");
	return -1;
}

Status InsertEdge(AMLGraph* G, VertexType V1, VertexType V2)
{
	int v1Add = LocateVex(G, V1);
	int v2Add = LocateVex(G, V2);
	if (v1Add < 0 || v2Add < 0)
	{
		printf("�������ݴ���\n");
		exit(-1);
	}

	EBox* node = (EBox*)malloc(sizeof(EBox));
	if (!node)
		exit(-2);

	node->mark = unvisited;
	node->ivex = v1Add;
	node->jvex = v2Add;
	node->ilink = G->adjmulist[v1Add].firstedge;
	G->adjmulist[v1Add].firstedge = node;
	node->jlink = G->adjmulist[v2Add].firstedge;
	G->adjmulist[v2Add].firstedge = node;
}

Status CreateDN(AMLGraph* G)
{
	printf("�����붥�����ͱ���:\n");
	scanf("%d %d", &(G->vexnum), &(G->edgenum));
	getchar();

	printf("�����붥������:\n");
	for (int i = 0; i < G->vexnum; ++i)
	{
		scanf("%c", &(G->adjmulist[i].data));
		getchar();
		G->adjmulist[i].firstedge = NULL;
	}

	printf("�����������\n");
	for (int i = 0; i < G->edgenum; ++i)
	{
		char v1 = 0, v2 = 0;
		scanf("%c %c", &v1, &v2);
		getchar();
		InsertEdge(G, v1, v2);
	}
}

Status DeleteEdge(AMLGraph* G, VertexType V1, VertexType V2)
{
	int v1 = LocateVex(G, V1);
	int v2 = LocateVex(G, V2);
	EBox* ipreNode = NULL, * icurNode = NULL;
	EBox* jpreNode = NULL, * jcurNode = NULL;
	//1.�ҵ�v1�����λ��
	icurNode = G->adjmulist[v1].firstedge;
	while (icurNode && !(((icurNode->ivex == v1) && (icurNode->jvex == v2)) || ((icurNode->ivex == v2) && (icurNode->jvex == v1))))
	{
		ipreNode = icurNode;
		if (icurNode->ivex == v1)
			icurNode = icurNode->ilink;
		else
			icurNode = icurNode->jlink;
	}
	if (!icurNode)
	{
		printf("����Ϣ����\n");
		exit(-3);
	}

	//2.�ҵ�v2����λ��
	jcurNode = G->adjmulist[v2].firstedge;
	while (jcurNode && !(((jcurNode->ivex == v1) && (jcurNode->jvex == v2)) || (jcurNode->ivex == v2) && (jcurNode->jvex == v1)))
	{
		jpreNode = jcurNode;
		if (jcurNode->ivex == v2)
			jcurNode = jcurNode->ilink;
		else
			jcurNode = jcurNode->jlink;
	}
	if (!jcurNode)
	{
		printf("����Ϣ����\n");
		exit(-3);
	}

	//3.������һ����
	if (!ipreNode)		//��һ���߾���Ŀ����������(v1)
	{
		if (icurNode->ivex == v1)
			G->adjmulist[v1].firstedge = icurNode->ilink;
		else
			G->adjmulist[v1].firstedge = icurNode->jlink;
	}
	else
	{
		if (ipreNode->ivex == v1)
		{
			if (icurNode->ivex == v1)
				ipreNode->ilink = icurNode->ilink;
			else
				ipreNode->ilink = icurNode->jlink;
		}
		else	//ipreNode->jvex == v1
		{
			if (icurNode->ivex == v1)
				ipreNode->jlink = icurNode->ilink;
			else
				ipreNode->jlink = icurNode->jlink;
		}
	}

	if (!jpreNode)
	{
		if (jcurNode->ivex == v2)
			G->adjmulist[v2].firstedge = jcurNode->ilink;
		else
			G->adjmulist[v2].firstedge = jcurNode->jlink;
	}
	else
	{
		if (jpreNode->ivex == v2)
		{
			if (jcurNode->ivex == v2)
				jpreNode->ilink = jcurNode->ilink;
			else
				jpreNode->ilink = jcurNode->jlink;
		}
		else
		{
			if (jcurNode->ivex == v2)
				jpreNode->jlink = jcurNode->ilink;
			else
				jpreNode->jlink = jcurNode->jlink;
		}
	}
	//���ٶ���icurNode/jcurNode
	free(icurNode);
	return 1;
}

void PrintEdges(AMLGraph* G)
{
	EBox* cur = NULL;
	InitMarks(G);
	for (int i = 0; i < G->vexnum; ++i)
	{
		cur = G->adjmulist[i].firstedge;
		while (cur && cur->mark == unvisited)
		{
			printf("%c-%c ", G->adjmulist[cur->ivex].data, G->adjmulist[cur->jvex].data);
			cur->mark = visited;
			if (cur->ivex == i)
				cur = cur->ilink;
			else
				cur = cur->jlink;
		}
	}
	printf("NULL\n");
}

void InitMarks(AMLGraph* G)
{
	EBox* cur = NULL;
	for (int i = 0; i < G->vexnum; ++i)
	{
		cur = G->adjmulist[i].firstedge;
		while (cur && cur->mark == visited)
		{
			cur->mark = unvisited;
			if (cur->ivex == i)
				cur = cur->ilink;
			else
				cur = cur->jlink;
		}
	}
}

Status DeleteDN(AMLGraph* G)
{
	EBox* cur = NULL, * prev = NULL;
	for (int i = 0; i < G->vexnum; ++i)
	{
		cur = G->adjmulist[i].firstedge;
		while (cur)
		{
			prev = cur;
			if (cur->ivex == i)
				cur = cur->ilink;
			else
				cur = cur->jlink;

			DeleteEdge(G, G->adjmulist[prev->ivex].data, G->adjmulist[prev->jvex].data);
		}
	}
}