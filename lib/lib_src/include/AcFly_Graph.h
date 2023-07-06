//
// Created by skywalkerch on 6/2/2023.
//

#ifndef ACFLY_ACFLY_GRAPH_H
#define ACFLY_ACFLY_GRAPH_H

#include <vector>
#include <stack>
#include <queue>

// 定义图的结构体
typedef struct {
    int edge[100][100];//邻接矩阵
    int vexnum, arcnum;//结点数和边数
} MGraph;

//-- adjacency matrix 用邻接矩阵存储的算法
int firstneighbor(const MGraph G, int vexid) {
    for (int i = 0; i < G.vexnum; i++) {
        if (i == vexid) { continue; }
        if (G.edge[vexid][i]) {
            return i;
        }
    }
    return -1;
}

int nextneighbor(const MGraph G, int vexid, int w) {
    for (int i = w + 1; i < G.vexnum; i++) {
        if (i == vexid) { continue; }
        if (G.edge[vexid][i]) {
            return i;
        }
    }
    return -1;
}


//用栈实现的深度优先搜索
void dfs_stack_ud(const MGraph G, int vexid, std::vector<int> &result) {
    bool *visited = new bool[G.vexnum]();
    std::stack<int> *s = new std::stack<int>;
    s->push(vexid);
    visited[vexid] = true;
    while (!s->empty()) {
        int k = s->top();
        result.push_back(k);

        s->pop();
        for (int w = firstneighbor(G, k); w >= 0; w = nextneighbor(G, k, w)) {
            if (!visited[w]) {
                s->push(w);
                visited[w] = true;
            }
        }
    }
}


//用递归实现的深度优先搜索
int dfs(const MGraph G, int vexid, bool *visited, std::vector<int> &result) {
    if (vexid < 0) { return -1; }
    visited = visited;
    visited[vexid] = true;
    result.push_back(vexid);
    for (int neighbor = firstneighbor(G, vexid); neighbor >= 0; neighbor = nextneighbor(G, vexid, neighbor)) {
        if (visited[neighbor]) { continue; }
        else { dfs(G, neighbor, visited, result); }
    };
}

void dfs_recursion(const MGraph G, int vexid, std::vector<int> &result) {
    bool *visited = new bool[G.vexnum]();
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            dfs(G, i, visited, result);
        }
    }
}


void bfs_queue(const MGraph G, int vexid, bool *visited, std::vector<int> &result) {

    std::queue<int> q;
    visited[vexid] = true;
    q.push(vexid);
    while (!q.empty()) {
        vexid = q.front();
        for (int neighbor = firstneighbor(G, vexid); neighbor >= 0; neighbor = nextneighbor(G, vexid, neighbor)) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        };
        result.push_back(vexid);
        q.pop();
    }

}

void bfs(const MGraph G, int number, std::vector<int> &result) {
    bool *visited = new bool[G.vexnum]();
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            bfs_queue(G, i, visited, result);
        }
    }
}

#endif //ACFLY_ACFLY_GRAPH_H
