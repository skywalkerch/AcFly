//
// Created by skywalkerch on 6/2/2023.
//

#ifndef ACFLY_ACFLY_GRAPH_H
#define ACFLY_ACFLY_GRAPH_H
#include <vector>
#include <stack>

// 定义图结点的结构体
typedef struct  MGraph{
    int *vex;
    int edge[100][100];
    int vexnum,arcnum;
}MGraph;

//-- adjacency matrix 用邻接矩阵存储的算法
int firstneighbor(const MGraph  G,int number){
for(int i=0;i<G.vexnum;i++){
    if(i==number){ continue;}
    if(G.edge[number][i]){
        return i;
    }
}
return -1;
}

int nextneighbor(const MGraph  G,int number,int w){
    for(int i=w+1;i<G.vexnum;i++){
        if(i==number){ continue;}
        if(G.edge[number][i]){
            return i;
        }
    }
    return -1;
}




void dfs_stack_ud(const MGraph G,int number,std::vector<int> &result){
    bool *visited=new bool[G.vexnum];
    for(int i=0;i<G.vexnum;i++){
        visited[i]=false;
    }
    std::stack<int> *s=new std::stack<int>;
    s->push(number);
    visited[number]=true;
    while(!s->empty()){
        int k=s->top();
        result.push_back(k);

        s->pop();
        for(int w= firstneighbor(G,k);w>=0;w= nextneighbor(G,k,w)){
            if(!visited[w]){
                s->push(w);
                visited[w]=true;
            }
        }
    }
}

#endif //ACFLY_ACFLY_GRAPH_H
