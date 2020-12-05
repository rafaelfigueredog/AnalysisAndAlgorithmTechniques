#include <cstdio> 
#include <cstdlib> 

bool ans = false; 

void subSetSum(int arr[], int subarr[], int N, int subarrsize,  int sum, int index,  int const troco)  { 
	if ( troco == sum ) {
        ans = true; 
        return; 
    }
    if ( index < N && sum + subarr[index] <= troco )  { // poda na árvore
        for( int i = index; i < N; i++ ) { 
            subarr[subarrsize] = subarr[i]; 
            if( sum + arr[i] <= troco ) { 
                subSetSum(arr, subarr, N, subarrsize + 1, sum + arr[i], i + 1, troco); 
            } 
        } 
    }
} 

bool generateSubsets(int arr[], int n, int troco) { 
	int *subarr = (int *)malloc(n * sizeof(int)); 
    subSetSum(arr, subarr, n, 0, 0, 0, troco);  
	free(subarr);
    return ans;  
} 

int main()  { 
    int N, T; 
    scanf("%d %d", &N, &T); 
    int *arr = (int*) malloc(N*sizeof(int));  
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]); 
	printf("%c\n", ( generateSubsets(arr, N, T)? 'S' : 'N') ); 
	return 0; 
} 
