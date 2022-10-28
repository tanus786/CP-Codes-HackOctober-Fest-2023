#include <bits/stdc++.h>
using namespace std;

class DSU {
    int n;
    vector<int> par;
    vector<int> size, rank; // size[i] = no of nodes in the subtree of i

    public:
    DSU(int n) {
        this->n = n;

        par.resize(n);
        size.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            make_set(i);
        }
    }

    // makes a disjoint set with leader = x, containing only x
    void make_set(int x) {
        par[x] = x;
        size[x] = rank[x] = 1;
    }

    // finds the leader of the set containing x
    int find_set(int x) {
        if(x == par[x]) {
            return x;
        }

        return par[x] = find_set(par[x]); // path compression
    }

    // unifies two disjoint sets into one
    void union_sets(int x, int y) {
        // use anyone as you like
        // union_by_size(x, y);
        union_by_rank(x, y);
    }

    void union_by_random(int x, int y) {
        // leaders
        int lx = find_set(x);
        int ly = find_set(y);

        if(lx == ly) {
            return; // already in same set
        }

        par[ly] = lx; // or vice versa
    }

    // attach the subtree with smaller size/rank to the one with larger size/rank so resultant tree has minimum height (I guessed and examined too)
    void union_by_size(int x, int y) {
        // leaders
        int lx = find_set(x);
        int ly = find_set(y);

        if(lx == ly) {
            return; // already in same set
        }

        if(size[lx] < size[ly]) {
            swap(lx, ly); // we always want to attach ly to lx to reduce the lines of code, so swap
        } // now size[lx] >= size[ly] for sure

        par[ly] = lx;
        size[lx] += size[ly]; // size[ly] remains same because it has'nt been changed
    }

    // here rank = depth for impementation
    void union_by_rank(int x, int y) {
        // leaders
        int lx = find_set(x);
        int ly = find_set(y);

        if(lx == ly) {
            return; // already in same set
        }

        if(rank[lx] < rank[ly]) {
            swap(lx, ly); // we always want to attach ly to lx to reduce the lines of code, so swap
        } // now rank[lx]>=rank[ly] for sure

        par[ly] = lx;
        if(rank[lx] == rank[ly]) {
            rank[lx]++; // out of the two cases possible after swapping, rank[lx] increases by 1 only when rank[lx]=rank[ly], rank[ly] remains same because it has'nt been changed
        }
    }
};
