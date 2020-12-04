#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>

#define MAX 100001

typedef struct point {

    double x; 
    double y; 

} Point ; 

double min( double a, double b) {
    return a < b ? a : b; 
}

int abs(int v) {
    return v < 0 ? -v : v; 
}


/* int compx( const void *u, const void *v ) {
    Point *p1 = (Point *) u, *p2 = (Point *) v;  
    return (p1->x - p2->x);
}

int compy( const void *u, const void *v ) {
    Point *p1 = (Point *) u, *p2 = (Point *) v;  
    return (p1->y - p2->y);
} */

bool compy( Point u, Point v) {
    return u.y > v.y; 
}

bool compx( Point u, Point v) {
    return u.x > v.x; 
}

double distance(point u, point v) {
    return sqrt( (u.x - v.x)*(u.x - v.x) + (u.y - v.y)*(u.y - v.y)  );  
}

double bruteForceCPP(Point *cordenates, int left, int right) {
    double dist = MAX; // max distance allowed by the problem 
    for (int k = left; k < right; k++ ) {
        for (int x = k + 1; x < right; x++) {
            dist = min(dist, distance(cordenates[k], cordenates[x])); 
        }
    }
    return dist; 
}

double closestPairProblemDVC(Point *cordenates, int left, int right) {

    if ( right - left < 3) return bruteForceCPP(cordenates, left, right); 
    int middle = (left + right) / 2; 
    double D1 = closestPairProblemDVC(cordenates, left, middle); 
    double D2 = closestPairProblemDVC(cordenates, middle+1, right); 
    double D = min(D1, D2); 
    
    std::vector<Point> front; 

    for (int k = left; k <= right; k++) {
        if ( abs(cordenates[k].x - cordenates[middle].x) < D) {
            front.push_back(cordenates[k]); 
        }
    }

    /* qsort(front, fi, sizeof(Point),  compy); */
    std::sort(front.begin(), front.end(), compy);
    for (int k = 0; k < front.size(); k++) {
        for (int x = k+1; x < front.size(); x++) {
            if ( abs(front[x].y - front[k].y) > D) break; 
            D = min(D, distance(front[x], front[k]));  
        }
    }

    return D; 
}


double closestPairProblem(Point *cordenates, int n) {
    std::sort(cordenates, cordenates+n, compx);
    /*  qsort(cordenates, n, sizeof(Point),  compx); */
    return closestPairProblemDVC(cordenates, 0, n-1);   
}

int main () {
    int n; 
    Point p;
    Point cordenates[10002];
    while (1) {
        scanf("%d", &n); 
        if (n == 0) break; 
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &cordenates[i].x, &cordenates[i].y); 
        double solution = closestPairProblem(cordenates, n); 
        if ( solution < 10000 ) printf("%.4lf\n", solution); 
        else printf("INFINITY\n");  
    }
}