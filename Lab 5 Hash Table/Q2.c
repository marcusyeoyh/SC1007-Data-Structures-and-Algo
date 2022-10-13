#include <stdio.h>
#include <stdlib.h>

enum GraphType {ADJ_MATRIX, ADJ_LIST}; // Types of Graph Representation

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

union GraphForm{
    int **matrix;
    ListNode **list;
};

typedef struct _graph{
    int V;
    int E;
    enum GraphType type;
    union GraphForm adj;
}Graph;

void printGraphMatrix(Graph );
void adjM2adjL(Graph *);
void printGraphList(Graph );
void calDegreeV(Graph,int *);
void printDegreeV(int *,int );

int main()
{
    Graph g;
    int i,j;

    int* degreeV;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.adj.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.adj.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
        for(j=0;j<g.V;j++)
            g.adj.matrix[i][j] = 0;
    g.type = ADJ_MATRIX;

    degreeV = (int *) malloc(g.V*sizeof(int));
    for(i=0;i<g.V;i++)
        degreeV[i]=0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other: (enter a to stop)\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.adj.matrix[V1-1][V2-1] = 1;
            g.adj.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other: (enter a to stop)\n");
    }


    printGraphMatrix(g);
    
    adjM2adjL(&g);
    
    printGraphList(g);

    calDegreeV(g,degreeV);
    
    printDegreeV(degreeV,g.V);

    return 0;
}

void printGraphMatrix(Graph g)
{
    int i,j;
    printf("Print graph matrix \n");
    if(g.type == ADJ_LIST) {printf("Error"); return;}
    
    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.adj.matrix[i][j]);
        printf("\n");
    }
    printf("\n");

}

void adjM2adjL(Graph *g)
{
	
    ListNode** list = (ListNode**)malloc(sizeof(ListNode)*g->V);
    for(int i=0; i<g->V;i++){
        list[i]=NULL;
    }

    for(int i=0; i<g->V;i++){
        for (int j=0; j<g->V;j++){
            if(g->adj.matrix[i][j]==1){
                if (list[i]==NULL){
                    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
                    newNode->vertex=j+1;
                    newNode->next=NULL;
                    list[i]=newNode;
                }
                else{
                    ListNode *temp = list[i];
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
                    newNode->vertex=j+1;
                    newNode->next=NULL;
                    temp->next=newNode;
                    //printf("%d\t",g->adj.matrix[i][j]);
                }
            }
        }
    }

    g->type = ADJ_LIST; //change representation form
    g->adj.list=list;
}


void printGraphList(Graph g){
    int i;
    ListNode* temp;
    printf("Print graph list \n");
    if(g.type == ADJ_MATRIX) {printf("Error"); return;}

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.adj.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}

void calDegreeV(Graph g, int *degreeV)
{
    // Question 3
    // Write your code here
    int counter=0;
    for(int i = 0; i<g.V; i++){
        ListNode *temp=g.adj.list[i];
        while(temp!=NULL){
            counter++;
            temp=temp->next;
        }
        degreeV[i]=counter;
        counter=0;
    }
}

void printDegreeV(int *degreeV,int V)
{
    int i;
    for(i=0;i<V;i++)
        printf("%d: %d degree\n",i+1,degreeV[i]);
}
