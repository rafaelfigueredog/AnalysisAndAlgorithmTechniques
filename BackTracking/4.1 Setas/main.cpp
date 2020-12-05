#include <iostream>
#include <algorithm>

void show(int **arr, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            printf("%d%s", arr[i][j], (j != size-1? " " : "\n")); 
}



int backTracking(char** M, int** V,  int n, int i, int j) {

    if ( i >= n || j >= n || i < 0 || j < 0) 
        return 0; 

    if ( V[i][j] != -1 ) return V[i][j]; 

    V[i][j] = 1; 

    if ( M[i][j] == '>' )
        V[i][j] = backTracking(M, V, n, i, j+1); 

    else if ( M[i][j] == '<' )
        V[i][j] = backTracking(M, V, n, i, j-1); 

    else if ( M[i][j] == 'A' )
        V[i][j] = backTracking(M, V, n, i-1, j); 

    else
        V[i][j] = backTracking(M, V, n, i+1, j);
    
    return V[i][j]; 
}

int solve(char **M, int** V,  int N) {
    int ans = 0; 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans = ans + backTracking(M, V, N, i, j);
    // show(V, N); 
    return ans; 
}

int main () {
    int N;
    std::cin >> N; 

    // create a data matrix 
    char **M = new char*[N]; 
    for (int i = 0; i < N; i++)
        M[i] = new char[N]; 

    // create a visited matrix
    int **V = new int*[N]; 
    for (int i = 0; i < N; i++)
        V[i] = new int[N]; 

    // initialize visited matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            V[i][j] = -1; 

    // read input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> M[i][j];
        }
    } 

    // write solution
    printf("%d\n", solve(M, V, N)); 

    return 0; 
}