#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std; 

int ans = 0; 

int max(const int a, const int b) {
    return a > b? a : b; 
}

void show(int **arr, int size) {
    for (int i = 0; i <= size; i++)
        for (int j = 0; j <= size; j++)
            printf("%d%c", arr[i][j], (j != size? ' ' : '\n')); 
    printf("\n"); 
}

int process(int **arr, int size) {
    for (int i = 0; i <= size; i++) {
        int sum = 0; 
        for (int j = 0; j <= size; j++){
            if (arr[i][j] > 2) {
                sum += arr[i][j];
                if (j == size)
                    ans = max(ans, sum); 
            } else break; 
        }
    }
}

void permutations(int **arr, int left, int right, int j) {
    if (left == right) 
        process(arr, right); 
    else {
        for (int i = left; i <= right; i++) {
            std::swap(arr[j][left], arr[j][i]); 
            permutations(arr, left+1, right, j); 
            std::swap(arr[j][left], arr[j][i]); 
        }
    }
}


int solve(int** m, int n) {
    for (int job = 0; job < n; job++)
        permutations(m, 0, n-1, job); 
    return ans == 0? -1 : ans; 
} 

int main () {

    int n; 
    std::cin >> n; 
    
    // create a matriz; 
    int**m = new int*[n]; 
    for (int i = 0; i < n; i++)
        m[i] = new int[n]; 

    // read the input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> m[i][j];
        
    // solve the problem 
    cout << solve(m, n) << endl; 

    return 0; 
}