#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

int max (int a, int b) {
    return a > b ? a : b;  
}

bool knapsackOptimalSpace(std::vector<int> &moedas, int n, int W)  { 
    std::vector<int> memory(W+1, 0); 
    for(int moeda : moedas)  
        for(int w = W; w >= moeda; w--) 
            memory[w] = max(memory[w] , moeda + memory[w-moeda]);
    return memory[W] == W; 
}

int main (void) {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    int v, n; 
    std::cin >> v >> n; 
    std::vector<int> moedas(n);   
    for (int i = 0; i < n; i++)
        std::cin >> moedas[i]; 
    std::cout << (knapsackOptimalSpace(moedas, n, v)? "S\n" : "N\n"); 
    return 0; 
}