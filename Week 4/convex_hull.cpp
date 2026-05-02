#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

long long crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

long long distSquared(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool compare(Point a, Point b) {
    long long o = crossProduct(p0, a, b);
    if (o == 0)
        return distSquared(p0, a) < distSquared(p0, b);
    return o > 0;
}

Point nextToTop(stack<Point> &S) {
    Point top = S.top();
    S.pop();
    Point res = S.top();
    S.push(top);
    return res;
}

vector<Point> grahamScan(vector<Point> &points) {
    int n = points.size();
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIndex].y ||
           (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x)) {
            minIndex = i;
        }
    }
    swap(points[0], points[minIndex]);
    p0 = points[0];
    sort(points.begin() + 1, points.end(), compare);
    vector<Point> filtered;
    filtered.push_back(points[0]);
    for (int i = 1; i < n; i++) {
        while (i < n-1 && crossProduct(p0, points[i], points[i+1]) == 0)
            i++;
        filtered.push_back(points[i]);
    }
    int m = filtered.size();
    if (m < 3) {
        cout << "Convex hull is empty\n";
        return {};
    }
    stack<Point> S;
    S.push(filtered[0]);
    S.push(filtered[1]);
    S.push(filtered[2]);
    for (int i = 3; i < m; i++) {
        while (crossProduct(nextToTop(S), S.top(), filtered[i]) <= 0) {
            S.pop();
        }
        S.push(filtered[i]);
    }
    vector<Point> hull;
    while (!S.empty()) {
        hull.push_back(S.top());
        S.pop();
    }
    reverse(hull.begin(), hull.end());
    return hull;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<Point> hull = grahamScan(points);
    cout << "Convex Hull:\n";
    for (auto p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
}