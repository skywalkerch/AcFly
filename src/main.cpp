//
// Created by skywalkerch on 5/22/2023.
//


#include <iostream>
#include "AcFly_Graph.h"
#include <vector>

using namespace std;


//
// Created by skywalkerch on 5/29/2023.
//
int main() {

    MGraph G;

    G.arcnum = 6;
    G.vexnum = 5;
    int vex[5] = {0, 1, 2, 3, 4};
    G.vex = vex;

    G.edge[0][0]=0;G.edge[0][1]=1;G.edge[0][2]=0;G.edge[0][3]=1;G.edge[0][4]=0;
    G.edge[1][0]=1;G.edge[1][1]=0;G.edge[1][2]=1;G.edge[1][3]=0;G.edge[1][4]=1;
    G.edge[2][0]=0;G.edge[2][1]=1;G.edge[2][2]=0;G.edge[2][3]=0;G.edge[2][4]=1;
    G.edge[3][0]=1;G.edge[3][1]=0;G.edge[3][2]=1;G.edge[3][3]=0;G.edge[3][4]=0;
    G.edge[4][0]=0;G.edge[4][1]=1;G.edge[4][2]=1;G.edge[4][3]=0;G.edge[4][4]=0;
    vector<int> result;
    dfs_stack_ud(G, 0, result);
    for (auto a: result) {
        cout << a << endl;
    }


}