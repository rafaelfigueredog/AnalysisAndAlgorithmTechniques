#include <cstdio>
#include <climits> 

int max (int a, int b ) {
    return a > b? a : b; 
}

int subArraySumMid(int *arr, int left, int mid, int right ) {

    int sum; 
    int sumLeft = INT_MIN; 
    int sumRight = INT_MIN; 
    
    sum = 0; 
    for (int i = mid; i >= left; i--) {
        sum += arr[i]; 
        sumLeft = max(sumLeft, sum); 
    }
    sum = 0; 
    for (int i = mid+1; i <= right; i++ ) {
        sum += arr[i]; 
        sumRight = max(sumRight, sum); 
    }

    return max( sumLeft + sumRight, max(sumLeft, sumRight) ); 

}


int subArraySum(int *arr, int left, int right) {
    if (left == right) return arr[right];
    int mid = (left + right)/2; 
    int maxSubArrays = max( subArraySum(arr, left, mid), subArraySum(arr, mid+1, right) );  
    return max ( maxSubArrays, subArraySumMid(arr, left, mid, right) ); 
}


int maxSubArraySum(int *arr, int n) {
    return subArraySum(arr, 0, n-1); 
}



int main () {
    int n;
    int arr[100001] = {}; 
    while (true) {
        scanf("%d", &n);  
        if (n == 0) break; 
        for (int i = 0; i < n; i++ )
            scanf("%d", &arr[i]); 
        int streak = maxSubArraySum(arr, n); 
        if (streak > 0) printf("The maximum winning streak is %d.\n", streak); 
        else printf("Losing streak.\n"); 
    }
}