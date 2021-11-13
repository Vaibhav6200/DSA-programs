#include<bits/stdc++.h>
using namespace std;

# define I INT_MAX

int edges[3][9]{
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

int Set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int included[9] = {0};
int t[2][6];

void Union(int u, int v){
    if(Set[u] < Set[v]){
        Set[u] = Set[u] + Set[v];
        Set[v] = u;
    }
    else{
        Set[v] = Set[u] + Set[v];
        Set[u] = v;
    }
}

int find(int x){
    while(Set[x] > 0)
        x = Set[x];   

    return x;
}

int main()
{
    int i=0, j, k, u, v, e=9, n=7, min;

    while(i < n-1){
        // Step 1 : finding minimum vertex from set of edges
        min = I;

        for(j=0; j<e; j++){

            // Step 2 : check whether this edges is already included in our solution or not
            if(included[j] == 0){
                if(included[j] == 0 && edges[2][j] < min){
                    min = edges[2][j];
                    k = j;
                    u = edges[0][j];
                    v = edges[1][j];
                }
            }
        }

        // Step 3 : Checking for the cycles 
        if(find(u) != find(v)){
            t[0][i] = u;
            t[1][i] = v;
            i++;

        // Step 4 : Taking Union of Parents
            Union(find(u), find(v));
        }

        // Step 5: marking edges as included in our solution every time we run the while loop
        included[k] = 1;
    }

        // Now PRINTING our Result
    for(int p=0 ; p<n-1 ; p++){
        cout << "(" << t[0][p] << " , " << t[1][p] << ")" << endl;
    }

    return 0;
}