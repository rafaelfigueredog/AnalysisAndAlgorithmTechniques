#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

#define N 8

void show(int **arr, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            printf("%d%s", arr[i][j], (j != size-1? " " : "\n"));
    printf("\n");
}

void saveSolution(int **table, int size, vector<vector<int>> &solution) {
    vector<int> ans;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (table[j][i] == 1)
                ans.push_back(j+1);
        }
    }
    solution.push_back(ans);
    ans.clear(); 
}

bool isSafe(int **table, int row, int col) {
	int i, j;

	for (i = 0; i < col; i++)
		if (table[row][i])
			return false;

	for (i=row, j=col; i>=0 && j>=0; i--, j--)
		if (table[i][j])
			return false;

	for (i=row, j=col; j>=0 && i<N; i++, j--)
		if (table[i][j])
			return false;

	return true;
}

bool backTracking(int **table, int col, vector<vector<int>> &solution, list<int> &colums) {
	if (colums.empty()) {
	    // show(table, N);
        saveSolution(table, N, solution);
		return true;
	}
	bool res = false;
	for (int i = 0; i < N; i++) {
		if ( isSafe(table, i, col) ) {
			table[i][col] = 1;
            int next = colums.front();
            colums.pop_front();  
			res = backTracking(table, next, solution, colums) || res;
			table[i][col] = 0;
		}
	}
	return res;
}

void outputSolution(vector<vector<int>> &solution) {
    printf("SOLN\t   COLUMN\n");
    printf(" #\t");
    for (int c = 1; c <= N; c++)
        printf("%d%c", c, (c != N? ' ' : '\n'));
    printf("\n");

    for (int i = 0; i < solution.size(); i++) {
        printf(" %d\t", i+1);
        for (int j = 0; j < N; j++)
            printf("%d%c", solution[i][j], (j != N-1? ' ' : '\n'));
    }
    printf("\n");

    return;
}

void solve(int **table, int R, int C, vector<vector<int>> &solution) {

    // init table;
    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            table[i][j] = 0;
    table[R-1][C-1] = 1;

    list<int> colums;
    for (int c = 0; c < N; c++)
        if (c != C-1) colums.push_back(c); 
    
    int begin = colums.front();
    colums.pop_front();  

    backTracking(table, begin, solution, colums);
    return; 
}

int main () {

    int T;
    int R, C;
    std::string line;

    int** table = new int*[N];
    for (int i = 0; i < N; i++)
        table[i] = new int[N];

    std::cin >> T;
    vector<vector<int>> solution;
    while (T--) {
        getline(std::cin, line);
        std::cin >> R >> C;
        solve(table, R, C, solution);
        outputSolution(solution);
        solution.clear(); 
    }

    

    return 0;
}