// kruskal algorithm for finding minimum cost spanning tree

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
int t[2][6];        // array to store resultant spanning tree

// UNION FUNCTION
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

// FIND FUNCTION
int find(int u){
    int x=u;
    while(Set[x] > 0)
        x = Set[x];
    
    return x;
}

int main()
{
    int i=0;    // its index which will iterate over array "t"
    int j, k, e=9, n=7, min, u, v;

    // we want n-1 edges so this loop will iterate for n-1 times
    while(i<n-1){
        min = I;
        // STEP 1 : find out edge with minimum weight
        for(j=0 ; j<e ; j++)
        {
            if(included[j] == 0 && edges[2][j] < min){
                min = edges[2][j];
                k=j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        
        // now check whether the selected vertices are making cycle or not
        if(find(u) != find(v)){
            t[0][i] = u;
            t[1][i] = v;

            // now take union of these vertices
            Union(find(u), find(v)); 
            i++;
        }
        included[k] = 1;
    }

    // Now PRINTING our Result
    for(int p=0 ; p<n-1 ; p++){
        cout << "(" << t[0][p] << " , " << t[1][p] << ")" << endl;
    }

    return 0;
}