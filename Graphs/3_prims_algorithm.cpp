// Prims Algorithm to find Minimum Spanning Tree

#include<bits/stdc++.h>
using namespace std;

#define I INT_MAX

int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},
    {I, I, 10, I, 14, 18, I, I}
};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][6];


int main(){

// INITIAL STEPS
    int u, v, k, n=7, min = I;

    // Step1 : Finding Minimum Weighted edge
    for(int i=0 ; i<=n ; i++){
        for(int j=i ; j<=n ; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u=i;
                v=j;
            }
        }
    }

    // Step 2 : Update Arrays "t" and "near"
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    // Step 3 : update near array
    for(int i=1 ; i<=n ; i++){
        // if near[i] = 0 then, skip that element
        if(near[i] != 0){
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }


// REPEATING STEPS
    // Step 1 : find the edge with minimum weight from near array
    for(int i=1 ; i<n-1 ; i++){

        min = I;
        for(int j=1 ; j<=n ; j++){

            if(near[j]!=0){     // do not consider vertices which are already considered

                if(cost[j][near[j]] < min){
                    min = cost[j][near[j]];
                    k = j; 
                }
            }
        }
        
    // Step 2 : update arrays "t", and "near"
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;        // we update this vertex as zero because we do not want to include it again

    // Step 3 : Now Update near array
        for(int j=1 ; j<=n ; j++){
            if(near[j] != 0){
                if(cost[j][k] < cost[j][near[j]])
                    near[j] = k;
            }
        }

    } 

    // Now PRINTING our Result
    for(int i=0 ; i<n-1 ; i++){
        cout << "(" << t[0][i] << " , " << t[1][i] << ")" << endl;
    }


    return 0;
}