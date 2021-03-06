struct node {
    int value, index;
};
vector<node> tree;
 
node merge(node &a, node &b) {
    return (a.value < b.value) ? a : b;
}
 
void build(int idx, int start, int end) {
    if(start == end) {
        // tree[idx].value = a[start]; tree[idx].index = start;
        tree[idx] = {a[start], start};
    }
    else {
        int mid = start + end >> 1;
        build(idx << 1, start, mid);
        build(idx << 1 | 1, mid+1, end);
        tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
    }
}

void update(int idx, int start, int end, int pos, int value) {
    if(start == end) {
        tree[idx] = {value, start};
        a[pos] = value;
    }
    else {
        int mid = start + end >> 1;
        if(pos <= mid) update(idx << 1, start, mid, pos, value);
        else update(idx << 1 | 1, mid+1, end, pos, value);
        tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
    }
}

void update(int pos, int value) {
    update(1, 0, n-1, pos, value);
}

node query(int idx, int start, int end, int ql, int qr) {
    if(start > qr || end < ql) return {inf, inf};
    if(start >= ql && end <= qr) return tree[idx];
 
    int mid = start + end >> 1;
    node left = query(idx << 1, start, mid, ql, qr);
    node right = query(idx << 1 | 1, mid+1, end, ql, qr);
    return merge(left, right);
}
 
node query(int ql, int qr) {
    return query(1, 0, n-1, ql, qr);
}

// tree.resize(n << 2);

