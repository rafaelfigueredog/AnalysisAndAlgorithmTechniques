#include <iostream>
#include <vector>

#define MAX 100001

int min(int a, int b) {
    return a < b ? a : b; 
}

char solve(int amount, std::vector<int> &money) {
    std::vector<int> cache(amount+1, 0); cache[0] = 0; 
    for (int c = 0; c <= amount; c++) {
        for (int v = money[c]; v <= money.size(); v++) {
            cache[v] += cache[v-money[c]]; 
        }
    }
    return cache[amount]; 
}

int main (void) {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    int v, n; 
    std::cin >> v >> n; 
    std::vector<int> arr(n); 
    for (int i = 0; i < n; i++)
        std::cin >> arr[i]; 
    std::cout << solve(v, arr) << std::endl; 
    return 0; 
}