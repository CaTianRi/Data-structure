#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define  MAX_VERTEX_NUM 20//��󶥵����
#define  VertexType char//ͼ�ж��������

typedef struct ArcNode {
    int adjvex;//�洢��������һ�˶����������е��±�
    struct ArcNode* nextarc;//ָ����һ�����
}ArcNode;

typedef struct VNode {
    VertexType data;                    //�����������
    ArcNode* firstarc;                  //ָ����һ�����
}VNode, AdjList[MAX_VERTEX_NUM];        //�洢��������Ԫ��������

typedef struct {
    AdjList vertices;       //�洢ͼ���ڽӱ�
    int vexnum, arcnum;     //ͼ�ж������Լ�����
}ALGraph;

void CreateGraph(ALGraph* graph) 
{
    int ret = 0;
    char VA, VB;
    printf("�����붥�����ͻ���:\n");
    scanf("%d %d", &(graph->vexnum), &(graph->arcnum));
    getchar();
    printf("�����붥������:\n");
    for (int i = 0; i < graph->vexnum; ++i)
    {
        scanf("%c", &(graph->vertices[i].data));
        getchar();
        graph->vertices[i].firstarc = NULL;
    }
    
    for (int i = 0; i < graph->arcnum; ++i)
    {
        ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
        if (!node)
            exit(-1);

        printf("�����뻡(a b)\n");
        scanf("%c %c", &VA, &VB);
        getchar();
        for (int j = 0; j < graph->vexnum; ++j)
        {
            ret = 0;
            if (VB == graph->vertices[j].data)
            {
                ret = 1;
                node->adjvex = j;
                break;
            }
        }
        if (!ret)
        {
            printf("���������\n");
            exit(-2);
        }

        for (int j = 0; j < graph->vexnum; ++j)
        {
            ret = 0;
            if (VA == graph->vertices[j].data)
            {
                ret = 1;
                node->nextarc = graph->vertices[j].firstarc;
                graph->vertices[j].firstarc = node;
                break;
            }
        }
        if (!ret)
        {
            printf("���������\n");
            exit(-2);
        }
    }
    printf("\n");
}

int InDegree(ALGraph* graph, char tg)   //���㶥�����
{
    int index = -1, count = 0;
    for (int i = 0; i < graph->vexnum; ++i)
    {
        if (tg == graph->vertices[i].data)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("û���ҵ��ö���\n");
        return -1;
    }
   
    for (int i = 0; i < graph->vexnum; ++i)
    {
        ArcNode* node = graph->vertices[i].firstarc;
        while (node)
        {
            if (node->adjvex == index)
                count++;

            node = node->nextarc;
        }
    }
    return count;
}

int OutDegree(ALGraph* graph, char g)
{
    int index = -1, count = 0;
    for (int i = 0; i < graph->vexnum; ++i)
    {
        if (graph->vertices[i].data == g)
        {
            ArcNode* node = graph->vertices[i].firstarc;
            while (node)
            {
                count++;
                node = node->nextarc;
            }
            return count;
        }
    }
    return -1;
}

void print_graph(ALGraph * graph)
{
    for (int i = 0; i < graph->vexnum; ++i)
    {
        printf("%c ", graph->vertices[i].data);
        ArcNode* node = graph->vertices[i].firstarc;
        while (node)
        {
            printf("%c->", graph->vertices[node->adjvex].data);
            node = node->nextarc;
        }
        printf("NULL\n");
    }
}


int main(void) {
    ALGraph graph;
    char tm = 0;
    CreateGraph(&graph);
    print_graph(&graph);
    printf("������Ҫ���ҵĶ���(���)\n");
    scanf("%c", &tm);
    getchar();
    int index = InDegree(&graph, tm);
    printf("%d\n", index);
    printf("������Ҫ���ҵĶ���(����)\n");
    scanf("%c", &tm);
    getchar();
    index = OutDegree(&graph, tm);
    printf("%d\n", index);
    return 0;
}