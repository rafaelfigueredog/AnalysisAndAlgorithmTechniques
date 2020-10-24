#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std; 

int SortSolution(std::vector<int> v, int k) {
    std::sort(v.begin(), v.end()); 
    return v[k]; 
}

int QuickSelection(vector<int> arr, int l, int r, int k) {
    int d = l-1; 
    int p = arr[r]; 
    for (int j = l; j < r; j++) {
        if (arr[j] <= p) {
            d++;
            std::swap(arr[j], arr[d]); 
        } 
    }
    d++; 
    std::swap(arr[r], arr[d]); 
    if (d == k) return p; 
    if ( k < d ) return QuickSelection(arr, l, d-1, k); 
    return QuickSelection(arr, d+1, r, k); 
}



int main () {

    srand (time(NULL));
    vector<int> arr; 

    int textsCases = 1000000; 
    int it = 1; 

    while (it <= textsCases) {
        int size = rand() % 100 + 1; 
        arr.resize(size); 
        for (int i = 0; i < size; i++) 
            arr[i] = rand() % 100; 
        
        int k = rand() % size; 
        int S1 = QuickSelection (arr, 0, size-1, k); 
        int S2 = SortSolution( arr, k );
        
        if ( S1 == S2 ) 
            printf("Test: %d\nQuickSelection: %d\tSortSolution: %d \n", it, S1, S2);  
        else {
            // caso ocorra algum erro
            printf("Wrong Answer:\nArray: ");
            for (auto v : arr) 
                std::cout << v << " "; 
            cout << endl; 
            printf("Test: %d\nQuickSelection: %d\tSortSolution: %d \n", it, S1, S2);
            break; 
        }
        it++; 
    }

    if ( it == textsCases + 1 )
        std::cout << "\n The test finished successfully! \n"; 

    return 0; 
}