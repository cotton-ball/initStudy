//
//  Q5567.cpp
//  init
//
//  Created by Kong Nayeon  on 2022/03/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


#define MAX_VERTICES 10000
int visited[MAX_VERTICES] = {0};
int visitNum=0;
typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;


typedef struct GraphType{
    int n;
    struct GraphNode* adj_list[10000];
}GraphType;


void init(GraphType* g){
    int v;
    g->n = 0;
    for(v=0;v<MAX_VERTICES;v++)
        g->adj_list[v]=NULL;
}


//정점 삽입 연산
void insert_vertex(GraphType* g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        return;
    }
    g->n++;
}

//간선 삽입 연산, v를 u의 인접 리스트에 삽입한다
void insert_edge(GraphType* g,int u, int v){
    GraphNode* node;
    if(u>=g->n||v>=g->n){
        return;
    }
    node=(GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=g->adj_list[u];
    g->adj_list[u]=node;
    
    
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node -> vertex = u;
    node -> link = g->adj_list[v];
    g-> adj_list[v] = node;
}


int findFriends(GraphType *g){
    
    GraphNode *w,*h,*node;
    int i=0;
   // node = g->adj_list[1];
    for(w=g->adj_list[1];w;w=w->link){
        node=(GraphNode*)malloc(sizeof(GraphNode));
        node->vertex=w->vertex;
        node->link=w->link;
        node = node->link;
        visitNum++;
    }
    
    
    
    return visitNum;
}

void dfs_list(GraphType *g, int v) // 깊이 우선 탐색(인접리스트)
{
GraphNode *w,*check;
visited[v] = true;           // 정점 v의 방문 표시
printf("%d-->", v);           // 방문한 정점 출력

    for(w=g->adj_list[v];w;w=w->link){
        for(check = g->adj_list[1]; check; check= check->link){
            if(!visited[w->vertex]){
                if( (visited [w->vertex] == check -> vertex))
                    dfs_list(g, w->vertex);
                }
        }
    }
    

}



void print_adj_list(GraphType* g){
    for(int i=0;i<g->n;i++){
        GraphNode* p=g->adj_list[i];
        printf("정접 %d의 인접 리스트 ",i);
        while(p!=NULL){
            printf("-> %d ",p->vertex);
            p=p->link;
        }
        printf("\n");
    }
}



int main(){
    
    GraphType *g;
    g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    
    
    
    print_adj_list(g);

    dfs_list(g, 1);
    free(g);
    
    return 0;
    
}
