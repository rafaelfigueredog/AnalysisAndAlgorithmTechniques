#include <bits/stdc++.h>

using namespace std;


int knapsack(vector<int> &val, vector<int> &wt, int n, int W) {
    vector<int> memo(W+1, 0); 
    for (int w = 0; w <= W; w++)
        for (int i = 0; i < n; i++)
            if ( wt[i] <= w )
                memo[w] = max(memo[w], val[i]+ memo[w-wt[i]]); 
    return memo[W]; 
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, W; 
    cin >> N >> W; 
    vector<int> C(N); 
    vector<int> V(N); 
    for (int i = 0; i < N; i++) 
        cin >> C[i] >> V[i]; 
    cout << knapsack(V, C, N, W) << endl; 
    return 0;
}