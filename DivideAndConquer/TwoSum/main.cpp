#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(const std::vector<int> &arr, int left, int right, int key ) {
    if (left < right) {
        int middle = (left + right) / 2; 
        if (key == arr[middle]) return true;
        if (key < arr[middle]) return binarySearch(arr, left, middle, key); 
        return binarySearch(arr, middle+1, right, key);
    }
    return false; 
}

int twosum(const std::vector<int> &array, int x) {
    int c; 
    for (int i = 0; i < array.size()-2; i++) {     
        c = x - array[i];   
        if (binarySearch(array, i+1, array.size()-1, c)) 
            return true; 
    }
    return false; 
}

int main () {
    // Esse algoritmo funciona para todo n >= 0
    int x = 1; 
    vector<int> arr = {0,1, 2, 3, 4, 5, 6, 6, 7, 9, 10}; 
    cout <<  (twosum(arr, x)? "Sim" : "Não") << endl; 
}
