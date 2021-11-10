#include<bits/stdc++.h>
using namespace std;

int n = 8;      // its number of vertices

int A[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0}
};

void bfs(int i){
    int visited[n+1] = {0};
    queue<int> q;

    
    cout << i << " ";   // visiting root node
    visited[i] = 1;     // mark i as visited
    q.push(i);      // push it into queue

    // REPEATING STEP
    while(!q.empty()){
        // take out element from queue
        int u = q.front();
        q.pop();

        // now explore that element
        for(int j=0 ; j<n ; j++){
            if(A[u][j] == 1 && visited[j] == 0){
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int main()
{
    bfs(1);
    return 0;
}