#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

void show(int **arr, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            printf("%d%s", arr[i][j], (j != size-1? " " : "\n")); 
    printf("\n"); 
}

void backTracking(int** M, int** V, int n, int i, int j) {

    if (M[i][j] == 0) M[i][j] = 1; 
    else return; 

    if (V[i][j] == 0) V[i][j] = 1; 
    else return; 
    
    if ( i < n-1 && (M[i+1][j] != 1) ) backTracking(M, V, n, i+1, j  );
    if ( i > 0   && (M[i-1][j] != 1) ) backTracking(M, V, n, i-1, j  );
    if ( j < n-1 && (M[i][j+1] != 1) ) backTracking(M, V, n, i,   j+1); 
    if ( j > 0   && (M[i][j-1] != 1) ) backTracking(M, V, n, i,   j-1); 

    return; 
} 

std::string solve(int **M, int** V, int N) {
    backTracking(M, V, N, 0, 0); 
    // show(V, N); 
    return V[N-1][N-1] == 1? "COPS" : "ROBBERS";
}

int main () {

    int T;
    const int N = 5;  
    std::cin >> T; 
    std::list<std::string> solution; 

    // create a data matrix 
    int **M = new int*[N]; 
    for (int i = 0; i < N; i++)
        M[i] = new int[N]; 

    // create a visited matrix
    int **V = new int*[N]; 
    for (int i = 0; i < N; i++)
        V[i] = new int[N]; 

    std::string s;
    
    while (T--) { 
        // read input
        getline(std::cin, s); // get black line; 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> M[i][j];
                V[i][j] = 0; // initialize visited matrix; 
            }
        }
        solution.push_back(solve(M, V, N)); 
    }

    // write solution
    for(std::string str : solution)
        std::cout <<  str << std::endl; 

    return 0; 
}