#include <iostream>
#include <vector>

using namespace std;

int minStops(int d, int m, int n, vector<int> &stops) {

    if ( m >= d ) return 0; 
    if ( stops.size() == 0 ) return -1; 
    
    int i = 0;
    int ans = 0;
    int kickoff = 0;
    int last = 0;

    // just to follow the code;
    int tank = m;

    while(true) {

        while ( (i < n-1) && (stops[i + 1] - stops[kickoff]) <= tank )
            i++;

        // segunda condição do while atendida
        if ( kickoff == 0 ) {
            tank -= stops[i-1] - 0;
        } else {
            tank = stops[i-1] - stops[last];
        }

        if ( i != n-1 && i == kickoff )
            return -1;

        // parada obrigatória;
        if (i < n) {
            kickoff = i;
            last = i - 1;
            ans++;
            tank = m;
        }

        // Caso especial: Ultima parada possível
        if ( i == n-1 ) {

            if ( d - stops[last] <= tank) 
                return ans; 

            if ( d - stops[i] <= tank) 
                return ans + 1; 

            return -1;
        }
    }
}


int main () {
    int d, m, n;
    cin >> d;
    cin >> m;
    cin >> n;
    vector<int> stops(n);
    for (int i = 0; i < n ; i++)
        cin >> stops[i];
    cout << minStops(d, m, n, stops) << endl;
    return 0;
}