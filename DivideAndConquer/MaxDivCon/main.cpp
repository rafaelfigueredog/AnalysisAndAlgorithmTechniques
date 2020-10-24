#include <vector>
#include <cstdio>

using namespace std; 

int max(int u, int v) { 
    return u > v? u: v; 
}

int getMaxDVC(const vector<int> &array, int left, int right) {
    if (left == right) return array[left]; 
    if (left + 1 == right) return max(array[left], array[right]); 
    if (left < right) {
        int middle = (left + right) / 2; 
        return max( getMaxDVC(array, left, middle),
                    getMaxDVC(array, middle+1, right) );
    }
}

// Helper Function; 
int getMax(vector<int> &array) {
    if (array.size() == 0) return 0; 
    return getMaxDVC(array, 0, array.size()-1); 
}

int main () {
    vector<int> array = {1, 2, 3, 10, 5, 30};
    printf("Max: %d \n", getMax(array));
}