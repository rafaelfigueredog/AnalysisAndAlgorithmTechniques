#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>


int memo[102][102]; 

using namespace std; 

struct Item {
    int v = 0; 
    int w = 0; 
}; 

int max (int a, int b) {
    return a > b ? a : b;  
}

int knapsack(vector<Item> &itens,  int N, int W) {
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if ( itens[i-1].w > w )                         
                memo[i][w] =  memo[i-1][w]; 
            else 
                memo[i][w] = std::max(memo[i-1][w], memo[i-1][w-(itens[i-1].w)] + itens[i-1].v); 
        }
    }
    return memo[N][W]; 
}

void recover(vector<Item> &itens, vector<Item> &arr, int res, int n, int w) {
    if ( res == 0 || n == 0 ) return;
    if ( res == memo[n-1][w] ) 
        return recover(itens, arr, res, n-1, w); 
    arr.push_back(itens[n-1]); 
    res -= itens[n-1].v;
    w -= itens[n-1].w; 
    return recover(itens, arr, res, n-1, w); 
}


void solve(vector<Item> &itens, int n, int W) {
    int maxv, maxw = 0, pk = 0; 
    memset(memo, 0, sizeof(memo)); 
    maxv = knapsack(itens, n, W); 
    vector<Item> arr; 
    recover(itens, arr, maxv, n, W); 
    for (Item it : arr) maxw += it.w; 

    printf("%d brinquedos\n", maxv); 
    printf("Peso: %d kg\n", maxw); 
    printf("sobra(m) %d pacote(s)\n\n", (int)(n - arr.size()) ); 
}


int main () {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    const int W = 50; 
    int N; 
    int pac = 0; 
    std::cin >> N; 
    std::vector<Item> itens; 
    while (N--) {
        std::cin >> pac; 
        itens.resize(pac); 
        for (int i = 0; i < pac; i++) {
            cin >> itens[i].v >> itens[i].w; 
        }
        solve(itens, pac, W); 
    }
    return 0; 
}