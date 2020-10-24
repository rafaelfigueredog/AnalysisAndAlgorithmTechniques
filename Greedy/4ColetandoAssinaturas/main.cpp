#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

struct Period {
    int ts; 
    int tf; 
    Period(int ts, int tf) : ts(ts), tf(tf) {}; 
}; 

bool operator<(const Period &a, const Period &b) {
    return a.tf < b.tf; 
}

void writeSolution(std::vector<int> solution) {
    cout << solution.size() << endl; 
    for (int i = 0; i < solution.size(); i++) {
        if (i != solution.size()-1) 
            cout << solution[i] << " "; 
        else 
            cout << solution[i] << endl;
    }
}

vector<int> solve(vector<Period> periods,  int n) {
    // sort
    std::sort(periods.begin(), periods.end()); 
    vector<int> ans; 
    int time = periods[0].tf; 
    ans.push_back(time); 
    for ( int i = 1; i < n; i++) {
        // se o time estiver fora do periodo atual        
        if ( time < periods[i].ts || time > periods[i].tf ) {
            time = periods[i].tf; 
            ans.push_back(time); 
        }
    }
    return ans; 
}


int main () {
    int ts, tf, n; 
    std::cin >> n; 
    std::vector<Period> periods; 
    for (int i = 0; i < n; i++)  {
        cin >> ts >> tf;
        periods.push_back(Period(ts, tf)); 
    }
    writeSolution( solve(periods, n) );  
    return 0; 
}