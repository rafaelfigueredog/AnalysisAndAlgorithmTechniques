#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

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
    int T, N, K, R; 
    std::cin >> T; 
    item itens[51] = {0};  
    while (T--) {
        std::cin >> N; 
        for (int i = 0; i < N; i++) 
            std::cin >> itens[i].v >> itens[i].w; 
        std::cin >> K >> R; 
        if ( knapsack(itens, N, K) >= R ) 
            printf("Missao completada com sucesso\n"); 
        else 
            printf("Falha na missao\n");
    }
}
