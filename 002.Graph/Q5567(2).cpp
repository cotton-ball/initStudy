//
//  Q5567(2).cpp
//  init
//
//  Created by Kong Nayeon  on 2022/03/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


#define MAX_VERTICES 10000
int visited[MAX_VERTICES];
typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


void init(GraphType* g){
    int r,c;
    g->n=0;
    for(r=0;r<MAX_VERTICES;r++)
        for(c=0;c<MAX_VERTICES;c++)
            g->adj_mat[r][c]=0;
}

//정점 삽입 연산
void insert_vertex(GraphType* g,int v){
    if(((g->n)+1)>MAX_VERTICES){
        //printf("그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType* g, int start,int end){
    if(start>=g->n||end>=g->n){
      //  printf("그래프: 정점 번호 오류");
        return ;
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

void dfs_mat(GraphType *g, int v) // 깊이 우선 탐색
{
     int u;
     visited[v] = 1;
     printf("%d -> ", v);
      
    for(u=0;u<g->n;u++)
        if(g->adj_mat[v][u]&&!visited[u])
            dfs_mat(g, u);

}


//인접 행렬 출력 함수
void print_adj_mat(GraphType* g){
    for(int i=0;i < g->n;i++){
        for(int j=0;j < g->n;j++)
            printf("%2d ",g->adj_mat[i][j]);
        printf("\n");
    
    }
}

int main(){
    GraphType *g1;
    g1=(GraphType*)malloc(sizeof(GraphType));
    init(g1);
    
    int friendNum, listNum, a, b;
    cin >> friendNum;
    
    for(int i=0;i<friendNum+1;i++)
        insert_vertex(g1, i);
    
    cin >> listNum;
    
    for(int i = 0; i < listNum; i++){
        cin >> a;
        cin >> b;
        insert_edge(g1,a,b);
    }
    

    
    print_adj_mat(g1);
    free(g1);

    return 0;
    
    
}

