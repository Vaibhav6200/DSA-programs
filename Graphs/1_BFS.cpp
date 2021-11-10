#include<bits/stdc++.h>
using namespace std;

bool A[8][8] = {  //    1  2  3  4  5  6  7
                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                    {0, 0, 1, 1, 1, 0, 0, 0},  // 1
                    {0, 1, 0, 1, 0, 0, 0, 0},  // 2
                    {0, 1, 1, 0, 1, 1, 0, 0},  // 3
                    {0, 1, 0, 1, 0, 1, 0, 0},  // 4
                    {0, 0, 0, 1, 1, 0, 1, 1},  // 5
                    {0, 0, 0, 0, 0, 1, 0, 0},  // 6
                    {0, 0, 0, 0, 0, 1, 0, 0}   // 7
};

int n = 8;      // no of columns in our array
queue<int> q;
bool visited[8] = {0};

void BFS(int i){
    // Step 1 : Initial Step
    cout << i << " ";       // visit starting vertex
    visited[i] = 1;         // mark that vertex as visited
    q.push(i);              // push it in queue

    // Step 2 : Repeating Step
    while(!q.empty()){
        int u = q.front();          // take out a vertex from queue
        q.pop();
        for(int v=1; v<n ; v++){   // Exploring that vertex

            if(A[u][v] == 1 && visited[v] == 0){        
                // if A[u][v]==1 means there is a edge between u and v (and we need to visit them) 
                // also we check that vertex v is not visited (if it is then no need to visit it again)

                cout << v << " ";       // visiting that node
                visited[v] = 1;         // mark that node as visited
                q.push(v);              // push that node inside queue
            }
        }
    }
}

int main()
{
    BFS(1);
    return 0;
}