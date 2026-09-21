/*** 
 * @Author: ssp
 * @Date: 2026-09-21 10:38:01
 * @LastEditTime: 2026-09-21 11:22:31
 */
// 题目：https://www.cnblogs.com/Kv-Stalin/p/9074274.html
#include <iostream>

using namespace std;
const int N = 2e5 + 10;
struct {
    int mx;
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = {0};
    if (l == r) return ;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void pushup(int u) {
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void update(int u, int l, int r, int pos, int x) {
    if (l == pos && r == pos) {
        tr[u].mx = x;
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(u << 1, l, mid, pos, x);
    else update(u << 1 | 1, mid + 1, r, pos, x);
    pushup(u);
}

int query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tr[u].mx;
    int mid = l + r >> 1;
    int res = 0;
    if (ql <= mid) res = max(res, query(u << 1, l, mid, ql, qr));
    if (qr > mid) res = max(res, query(u << 1 | 1, mid + 1, r, ql, qr));
    return res;
}


int main() {
    int n, d; cin >> n >> d;
    build(1, 1, n);
    int pre = 0;
    int idx = 0;
    for (int i = 0; i < n; i ++) {
        char op; cin >> op;
        if (op == 'A') {
            int ax; cin >> ax;
            idx ++;
            update(1, 1, n, idx, ((long long)ax + pre) % d);
        } else {
            int rlen; cin >> rlen;
            pre = query(1, 1, n, idx - rlen + 1, idx);
            cout << pre << endl;
        }
    }
}