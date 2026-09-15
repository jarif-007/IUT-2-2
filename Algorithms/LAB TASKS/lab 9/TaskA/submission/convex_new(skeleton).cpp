#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
    int id;
};

bool comparePoints(const Point& a, const Point& b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool isValid(const Point& p, const Point& q, const Point& r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val>0) return true;
    else return false;
}

double getYIntersection(const Point& pA, const Point& pB, double x_mid) {
    double slope = (double)(pB.y - pA.y) / (pB.x - pA.x);
    return pA.y + slope * (x_mid - pA.x);
}

void findUpperTangent(int &uA, int &uB, const vector<Point>& A, const vector<Point>& B, double x_mid){
    int nB = B.size();
    int nA = A.size();
    bool changed = true;
    while (changed) {
        changed = false;
        double current_y = getYIntersection(A[uA], B[uB], x_mid);

        // Try rotating B Clockwise
        int nextB = (uB + 1) % nB;
        if (getYIntersection(A[uA], B[nextB], x_mid) > current_y) {
            uB = nextB;
            changed = true;
            continue;
        }

        // Try rotating A Counter-Clockwise
        int prevA = (uA - 1 + nA) % nA;
        if (getYIntersection(A[prevA], B[uB], x_mid) > current_y) {
            uA = prevA;
            changed = true;
            continue;
        }
    }
}

void findLowerTangent(int &lowA, int &lowB, const vector<Point>& A, const vector<Point>& B, double x_mid){
    /*implement this following the upper tangent function*/
}

vector<Point> combine(int uA,int uB,int lowA,int lowB,const vector<Point>& A, const vector<Point>& B){
    vector<Point> res;
    int nB = B.size();
    int nA = A.size();
    for (int i = uB; ; i = (i + 1) % nB){
        res.push_back(B[i]);
        if (i == lowB) break;
    }
    for (int i = lowA; ; i = (i + 1) % nA){
        res.push_back(A[i]);
        if (i == uA) break;
    }
    return res;
}


vector<Point> bruteForce(vector<Point>& pts) {
    int n = pts.size();

    vector<int> next_node(n, -1);
    int start_idx = 0;

    /*write code here:
    Iterate through all possible pairs of points (except the points paired with itself)
    to find whether a pair is valid or not.
    A pair is valid where all the points fall on the right side of the line
    This validity can be checked using "isValid(...)" function.
    "isValid()" functions returns true, if the current pair is valid
    You have to check all the pairs of the points and..
    for each valid pair, save the pair information into "next_node" vector 
    and save the current value of i as "start_idx"
    */
    

    vector<Point> h; //h containts the sequence of points which make the polygon
    int curr = start_idx;
    do {
        h.push_back(pts[curr]);
        curr = next_node[curr];
    } while (curr != start_idx && curr != -1 && h.size() < n);

    return h;
}

// Two-Finger Merge
vector<Point> mergeHulls(const vector<Point>& A, const vector<Point>& B) {
    int nA = A.size(), nB = B.size();
    int rA = max_element(A.begin(), A.end(), comparePoints) - A.begin();
    int lB = min_element(B.begin(), B.end(), comparePoints) - B.begin();

    // Define the vertical dividing line between the two hulls
    double x_mid = (A[rA].x + B[lB].x) / 2.0;

    //Find Upper Tangent (Maximize Y-intersection)
    int uA = rA, uB = lB;
    findUpperTangent(uA,uB,A,B,x_mid);

    //Find Lower Tangent (Minimize Y-intersection)
    int lowA = rA, lowB = lB;
    findLowerTangent(lowA,lowB,A,B,x_mid);

    //Cut & Paste Output Construction (Clockwise traversal)
    vector<Point> res;
    res = combine(uA,uB,lowA,lowB,A,B);
    return res;
}

vector<Point> divideAndConquer(vector<Point>& pts) {
    /*write the divide and conquer part here */
}

int main() {
    //read input and also assign the index of the points (starting from 1)

    //sort the points (you may use the funciton comparePoints(...)
    
    //call divide and conquer function and save the returned value

    //print the result satisfying the requirements
    return 0;
}
