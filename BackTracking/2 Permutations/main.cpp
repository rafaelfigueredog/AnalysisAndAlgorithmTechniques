#include <cstdio> 
#include <cstdlib> 
#include <algorithm>
#include <iostream>

void show(int *arr, int size) {
    for (int i = 0; i <= size; i++)
        printf("%d%c", arr[i], (i != size? ' ' : '\n')); 
}

void permutations(int *arr, int left, int right) {
    if (left == right) show(arr, right); 
    else {
        for (int i = left; i <= right; i++) {
            std::swap(arr[left], arr[i]); 
            permutations(arr, left+1, right); 
            std::swap(arr[left], arr[i]); 
        }
    }
}

int main()  { 
    int N; 
    std::cin >> N;
    int *arr = (int*) malloc(N*sizeof(int));  
    for (int i = 0; i < N; i++)
        std::cin >> arr[i]; 
	permutations(arr, 0, N-1); 
	return 0; 
} 
