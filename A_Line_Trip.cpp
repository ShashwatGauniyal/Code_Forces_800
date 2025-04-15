#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int solve(vector<int>& stations, int x, int n) {
    
    // Add 0 and x to the list of points for easier processing
    vector<int> points;
    points.push_back(0);
    for (int i = 0; i < n; i++) {
        points.push_back(stations[i]);
    }
    points.push_back(x);
    
    // Find the maximum gap between adjacent refueling points
    int max_gap = 0;
    for (int i = 1; i < points.size(); i++) {
        max_gap = max(max_gap, points[i] - points[i-1]);
    }
    
    // The critical section is from the last gas station to x and then back to that station
    // We need enough fuel to go: last station -> x -> last station
    int critical_section = 2 * (x - stations[n-1]);
    
    return max(max_gap, critical_section);
}

int main() {
    fast_io();
    int tc;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
        int n, x;
        cin >> n >> x;
        
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        
        cout << solve(stations, x, n) << endl;
    }
    
    return 0;
}