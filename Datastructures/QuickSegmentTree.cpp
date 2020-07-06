class QuickSegmentTree {
    vector<int> arr, st;
    int mid(int i, int j) { return (i + j) >> 1; }
    int left(int i) { return i << 1; }
    int right(int i) { return (i << 1) + 1; }
    void build(int L, int R, int k) {
        if (L == R) st[k] = arr[L];
        else {
            build(L, mid(L, R), left(k));
            build(mid(L, R) + 1, R, right(k));
            st[k] = min(st[left(k)], st[right(k)]);
        }
    }
public:
    QuickSegmentTree(vector<int>& _arr) {
        arr.assign(_arr.begin(), _arr.end());
        st.assign(4 * _arr.size(), 0);
        build(0, _arr.size() - 1, 1);
    }

    int search(int i, int j, int L, int R, int k) {
        if (i > R || j < L) return INT_MAX;
        if (L >= i && R <= j) return st[k];
        return min(search(i, j, L, mid(L, R), left(k)),
            search(i, j, mid(L, R) + 1, R, right(k)));
    }

    int search(int i, int j) {return search(i, j, 0, arr.size() - 1, 1);}
};
