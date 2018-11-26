#include<stdio.h>
#include<stdlib.h>

#define M 20
typedef int DataType;
typedef struct node {
	int adjvex;
	struct  node *next;
}EdgeNode;
typedef struct vnode {
	DataType vertex;
	EdgeNode *FristEdge;
}VertexNode;
typedef struct {
	VertexNode adjlist[M];
	int n, e;
}LinkedGraph;

void creat(LinkedGraph *g,char filename[],int c)  //�ڽӱ�ָ����� ���ͼ����Ϣ�ļ���filename[] if ��c=0��ʱͼΪ����ͼ ���������Ϊ����ͼ 
{
	int i,j,k;
	EdgeNode *s;
	FILE *fp;
	fp= fopen(filename, "r");
	if (fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	fscanf(fp, "%d", &g->n);
	fscanf(fp, "%d", &g->e);
	for (i=0;i<g->n;i++)
	{
		fscanf(fp,"%d",&g->adjlist[i].vertex);
		g->adjlist[i].FristEdge=NULL;
	}
	for (k=0;k<g->e;k++)
	{
		fscanf(fp,"%d%d",&i,&j);
	    s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = g->adjlist[i].FristEdge;
		g->adjlist[i].FristEdge = s;
		if (c == 0)
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = i;
				s->next = g->adjlist[j].FristEdge;
				g->adjlist[j].FristEdge = s;
			}
	}
	fclose(fp);
}

int visited[M];

void dfs(LinkedGraph g, int i)  //�Ӷ���i��ʼ��ȱ���ͼ����ͨ���� 
{
	EdgeNode *p;
	printf("visit vertex: %d \n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].FristEdge;
	while (p)
	{
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}
void Dfstraverse(LinkedGraph g) //������ȱ���ͼ 
{
	int i;
	for (i = 0; i < g.n; i++)
		visited[i] = 0;
	for (i = 0; i < g.n; i++)
		if (!visited[i])
			dfs(g,i);
}

int visited1[M];

void bfs(LinkedGraph g,int i) //�Ӷ���i����������ȱ���ͼ����ͨ���� 
{
	int j;
	EdgeNode *p;
	int quene[M],front,rear;
	front=rear=0;
	printf("%d ",g.adjlist[i].vertex);
	visited1[i]=1;
	quene[rear++]=1;
	while (rear>front)
	{
		j=quene[front++];
		p=g.adjlist[j].FristEdge;
		while (p)
		{
			if(visited1[p->adjvex]==0)
			{
				printf("%d ",g.adjlist[p->adjvex].vertex);
				quene[rear++]=p->adjvex;
				visited1[p->adjvex]=1;
			}
			p=p->next;
		}
	 }
}
int BfsTraverse(LinkedGraph g)  //������ȱ���ͼ ��������ͨ������ 
{
	int i,count=0;
	for (i=0;i<g.n;i++)
		visited1[i]=0;
	for (i=0;i<g.n;i++)
	     if (!visited1[i])
	     {
	     	printf("\n");
	     	count++;
	     	bfs(g,i);
		 }
	return count;
}


int main()
{
	int c=0;
	int count1; 
	char name[9] = "text.txt";
	LinkedGraph *A;
	A=(LinkedGraph*)malloc(sizeof(LinkedGraph));
	creat(A,name,c);
    printf("��ȱ��������\n");
	Dfstraverse(*A);
	printf("\n");
	LinkedGraph *B;
	B=(LinkedGraph*)malloc(sizeof(LinkedGraph));
	creat(B,name,c);
	printf("��ȱ��������");
	count1=BfsTraverse(*B);
	printf("\n");
	printf("�����ͨ��֧����\n");
	printf("1");
	printf("\n");
	system("pause");
	return 0;
}
