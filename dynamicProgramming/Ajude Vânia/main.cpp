#include <iostream>
#include <vector>

using namespace std; 

struct item {
    int w; int v; 
}; 

int max (int a, int b) {
    return a > b ? a : b;  
}

int knapsack(item *itens,  int N, int W) {
    std::vector<std::vector<int>> memory(N+1, std::vector<int>(W+1, 0)); 
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if ( itens[i-1].w > w )                         
                memory[i][w] =  memory[i-1][w]; 
            else 
                memory[i][w] = max(memory[i-1][w], memory[i-1][w-(itens[i-1].w)] + itens[i-1].v); 
        }
    }
    return memory[N][W]; 
}

int main () {
    int N, C; 
    item arr[1001]; 
    int t = 0; 
    while ( 1 ) {
        cin >> N >> C;
        if (!N && !C) break; 
        for (int i = 0; i < N; i++) 
            cin >> arr[i].w >> arr[i].v; 
        printf("Caso %d: %d\n", ++t, knapsack(arr, N, C));  
    }
    return 0; 
}