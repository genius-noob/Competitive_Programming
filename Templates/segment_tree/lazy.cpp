int merge(int a, int b) {
    return a + b;
}

void build(int idx, int start, int end) {
    if(start == end) {
        tree[idx] = a[start];
    }
    else {
        int mid = start + end >> 1;
        build(idx << 1, start, mid);
        build(idx << 1 | 1, mid + 1, end);
        tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
    }
}

void update(int idx, int start, int end, int ql, int qr, int value) {
    if(lazy[idx] != 0) {
        tree[idx] += (end - start + 1) * lazy[idx];             // change for min and max
        if(start != end) {
            lazy[idx << 1] += lazy[idx];
            lazy[idx << 1 | 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(start > qr || end < ql) return;
    if(start >= ql && end <= qr) {
        tree[idx] += (end - start + 1) * value;
        if(start != end) {
            lazy[idx << 1] += value;
            lazy[idx << 1 | 1] += value;
        }
        return;
    }
    int mid = start + end >> 1;
    update(idx << 1, start, mid, ql, qr, value);
    update(idx << 1 | 1, mid + 1, end, ql, qr, value);
    tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
}

int query(int idx, int start, int end, int ql, int qr) {
    if(lazy[idx] != 0) {
        tree[idx] += (end - start + 1) * lazy[idx];
        if(start != end) {
            lazy[idx << 1] += lazy[idx];
            lazy[idx << 1 | 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(start > qr || end < ql) return 0;
    if(start >= ql && end <= qr) {
        return tree[idx];
    }
    int mid = start + end >> 1;
    int left = query(idx << 1, start, mid, ql, qr);
    int right = query(idx << 1 | 1, mid + 1, end, ql, qr);
    return merge(left, right);
}
