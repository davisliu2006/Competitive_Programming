#include <bits/stdc++.h>

using namespace std;

int avg(int x, int y) {return (x+y)/2;}

template <class type>
struct segtree {
    int size;
    vector<type> tree;
    function<type(type,type)> func;
    
    segtree(const vector<type>& arr, function<type(const type&, const type&)> f) {
        size = arr.size();
        func = f;
        int width = 1<<int(ceil(log2(size)));
        tree = vector<type>(width*2-1);
        build(arr, 0, 0, size-1);
    }

    static inline int lnode(int x) {return x*2+1;}
    static inline int rnode(int x) {return x*2+2;}
    static inline int root(int x) {return (x-1)/2;}

    void build(const vector<type>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            build(arr, lnode(node), l, (l+r)/2);
            build(arr, rnode(node), (l+r)/2+1, r);
            tree[node] = func(tree[lnode(node)], tree[rnode(node)]);
        }
    }
    void update(int indx, const type& val) {
        int l = 0;
        int r = size-1;
        int node = 0;
        while (l != r) {
            if (indx <= (l+r)/2) {
                r = (l+r)/2;
                node = lnode(node);
            } else {
                l = (l+r)/2+1;
                node = rnode(node);
            }
        }
        assert(l == indx);
        tree[node] = val;
        while (node != 0) {
            node = root(node);
            tree[node] = func(tree[lnode(node)], tree[rnode(node)]);
        }
    }
    type query(int l, int r, int node = 0, int nl = 0, int nr = 0) {
        if (node == 0) {nr = size-1;}
        if (nl == l and nr == r) {
            return tree[node];
        } else {
            int r1 = min(r,(nl+nr)/2);
            int l2 = max(l,(nl+nr)/2+1);
            if (l <= r1 && l2 <= r) {
                return func(
                    query(l, r1, lnode(node), nl, (nl+nr)/2),
                    query(l2, r, rnode(node), (nl+nr)/2+1, nr)
                );
            } else if (l <= r1) {
                return query(l, r1, lnode(node), nl, (nl+nr)/2);
            } else {
                assert(l2 <= r);
                return query(l2, r, rnode(node), (nl+nr)/2+1, nr);
            }
        }
    }
};

struct sum_data {
    long sum;
    long max_sum;
    long max_lsum;
    long max_rsum;

    sum_data(int x = INT_MIN) {
        sum = x; max_sum = x;
        max_lsum = x; max_rsum = x;
    }
};
sum_data merge_sum(const sum_data& l, const sum_data& r) {
    sum_data val;
    val.sum = l.sum+r.sum;
    val.max_lsum = max(l.max_lsum, l.sum+r.max_lsum);
    val.max_rsum = max(r.max_rsum, r.sum+l.max_rsum);
    val.max_sum = max({l.max_sum, r.max_sum, l.max_rsum+r.max_lsum});
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n, q;
    cin >> n >> q;
    vector<sum_data> arr(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = sum_data(x);
    }

    segtree<sum_data> stree(arr, merge_sum);
    while (q--) {
        char c;
        cin >> c;
        if (c == 'S') {
            int i, v;
            cin >> i >> v;
            stree.update(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << stree.query(l, r).max_sum << '\n';
        }
    }

    return 0;
}
