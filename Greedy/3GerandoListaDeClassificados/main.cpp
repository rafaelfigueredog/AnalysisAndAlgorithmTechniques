#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <list>

using namespace std; 

struct Aplicant {
    int score;
    string name; 
    int a, b, c; 
    Aplicant(string name_, int score_, int a_, int b_, int c_):
        score(score_), 
        name(name_),
        a(a_), b(b_), c(c_)
    {}; 
}; 

bool operator<( const Aplicant &A, const Aplicant &B ) {
    return A.score < B.score; 
}

vector<list<string>> solve(priority_queue<Aplicant> ranking, const int n, const int v) {
    vector<list<string>> coursesRank(n); 
    while ( !ranking.empty() ) {
        Aplicant A = ranking.top(); 
        // cout << A.name << " " <<  A.score << " " << A.a << A.b << A.c << endl; 
        ranking.pop();

        if ( coursesRank[A.a-1].size() < v ) 
             coursesRank[A.a-1].push_back(A.name); 

        else if (coursesRank[A.b-1].size() < v )
            coursesRank[A.b-1].push_back(A.name); 

        else if ( coursesRank[A.c-1].size() < v )
            coursesRank[A.c-1].push_back(A.name);

    }
    return coursesRank; 
}

void write(vector<list<string>> rank) {
    for (int i = 0; i < rank.size(); i++) {
        cout << i+1;  
        if (!rank[i].empty()) {
            for (string name : rank[i] ) 
                cout << " " << name;  
            cout << endl;
        }
        else {
            cout << " sem classificados" << endl; 
        }
    }
}

int main () {
    int n, k, v;  
    int score, a, b, c; 
    string name; 
    priority_queue<Aplicant> ranking; 
    cin >> n >> v >> k; 
    for (int i = 0; i < k; i++) {
        cin >> name >> score >> a >> b >> c;  
        ranking.push( Aplicant(name, score, a, b, c) ); 
    }
    write( solve(ranking, n, v) );
    return 0; 
}