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
stack<int> st;
bool visited[8] = {0};

void DFS(int i){
    if(visited[i] == 0){
        cout << i << " ";
        visited[i] = 1;
        for(int j=1 ; j<n ; j++){
            if(A[i][j] == 1 && visited[j] == 0)
                DFS(j);
        }
    }
}

int main()
{
    DFS(4);
    return 0;
}