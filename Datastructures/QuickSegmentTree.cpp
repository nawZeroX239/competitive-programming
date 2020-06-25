
class Quick_SegmentTree {
    vector<int> v, segment;
    int L, R;
    int search(int i, int j, int si, int sj, int k) {
        int mid = (i + j) / 2;
        if (si<mid+1 && sj>mid) {
            L = search(i, mid, si, mid, 2*k);
            R = search(mid + 1, j, mid+1, sj, 2 * k + 1);
            return (v[L] <= v[R] ? L : R);
        }else if (i < j && sj <= mid) {
           return search(i, mid, si, sj, 2 * k);
        } else if (i< j && si > mid){
            return search(mid + 1, j, si, sj, 2 * k + 1);
        }
        return segment[k];
    }

    int build(int i, int j, int k) {
        if (i < j) {
            L = build(i, (i + j) / 2, 2 * k);
            R = build((i + j) / 2 + 1, j, 2 * k + 1);
            return (segment[k] = v[L] <= v[R] ? L : R);
        }

        return segment[k] = i;
    }
public:
    Small_SegmentTree(vector<int> &arr) {
        v.assign(arr.begin(), arr.end());
        segment.assign(2*arr.size(), 0);
        build(0, arr.size()-1, 1);
    }

    int search(int i, int j) {
        return search(0, v.size()-1, i, j, 1);
    }

};