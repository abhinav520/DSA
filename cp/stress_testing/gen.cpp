#include "bits/stdc++.h"
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

vector<int> gen_vec(int n, int lo = 0, int hi = 1e9) {
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = rand(lo, hi);
    }
    return a;
}

vector<pair<int, int>> gen_tree_edges(int n) {
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; ++i) {
        edges.emplace_back(rand(1, i - 1), i);
    }
    vector<int> perm(n + 1); // re-naming vertices
    for(int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    shuffle(perm.begin() + 1, perm.end(), rng);
    shuffle(edges.begin(), edges.end(), rng); // random order of edges
    for(auto& [a, b] : edges) {
        if(rand(0, 1) == 1) {
            swap(a, b); // random order of two vertices
        }
        a = perm[a];
        b = perm[b];
    }
    return edges;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cout << t << '\n';

    for (int i = 0; i < t; i++) {
        // random input size between 1 and 10
        int n = rand(1, 100000);
        cout << n << '\n';
        // n sized array having elements between 1 and 100
        vector<int> a = gen_vec(n, 1, 1e6);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}