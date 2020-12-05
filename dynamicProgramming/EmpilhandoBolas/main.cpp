#include <iostream>
#include <vector>
#include <algorithm>

using std::vector; 



int solve(vector<int> *arr, int n) {
    int max = 0; 
    vector<vector<int>> memo(n, vector<int>(n)); 
    memo[0][0] = arr[0][0];
    max = std::max(memo[0][0], max); 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) memo[i][j] = memo[i-1][j] + arr[i][j]; 
            else if (j == i) memo[i][j] = memo[i-1][j-1] + arr[i][j]; 
            else if (j == 1) memo[i][j] = arr[i-1][j-1] + memo[i-1][j] + arr[i][j];
            else if (j == i-1) memo[i][j] = arr[i-1][j] + memo[i-1][j-1] + arr[i][j]; 
            else {
                int k = i-1;
                memo[i][j] = memo[i-1][j] + arr[i][j]; 
                while (k != j) {
                    memo[i][j] += memo[k][j]; 
                    k--; 
                }
            }
            max = std::max(memo[i][j], max); 
        }
    }


    return max == 0? max : max + 1; 
}

int main () {
    int n; 
    vector<int> arr[1001]; 
    while (true) {
        std::cin >> n; 
        if (n == 0) break; 
        for (int i = 1; i <= n; i++) {
            arr[i-1].resize(i); 
            for (int j = 0; j < i; j++) {
                std::cin >> arr[i-1][j]; 
            } 
        }
        std::cout << solve(arr, n) << std::endl; 
    }
    return 0; 
} 