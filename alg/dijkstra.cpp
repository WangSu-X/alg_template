/*** 
 * @Author: ssp
 * @Date: 2026-09-22 15:30:45
 * @LastEditTime: 2026-09-22 15:55:11
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int dist[N];
bool st[N];

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        g[x].push_back({y, d});
    }

    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, 1});

    while (pq.size()) {

        auto p = pq.top();
        pq.pop();

        int v = p.first;
        int x = p.second;

        if (st[x]) continue;

        st[x] = true;

        for (auto y : g[x]) {

            if (dist[y.first] > v + y.second) {

                dist[y.first] = v + y.second;

                pq.push({dist[y.first], y.first});
            }
        }
    }

    cout << (dist[n] == 0x3f3f3f3f ? -1 : dist[n]);

    return 0;
}


/**
 * 
 * 题目：
 * 
 * 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，
 * 所有边权均为非负值。
 * 
 * 请你求出 1 号点到 n 号点的最短距离，
 * 如果无法从 1 号点走到 n 号点，则输出 -1。
 * 
 * 
 * 输入格式：
 * 
 * 第一行包含整数 n 和 m。
 * 
 * 接下来 m 行，每行包含三个整数 x, y, z，
 * 表示存在一条从点 x 到点 y 的有向边，边长为 z。
 * 
 * 
 * 输出格式：
 * 
 * 输出一个整数，表示 1 号点到 n 号点的最短距离。
 * 
 * 如果路径不存在，则输出 -1。
 * 
 * 
 * 数据范围：
 * 
 * 1 <= n, m <= 1.5 * 10^5
 * 
 * 图中涉及边均不小于 0，且不超过 10000。
 * 
 * 数据保证：
 * 如果最短路径存在，则最短路长度不超过 10^9。
 * 
 * 
 * 输入样例：
 * 
 * 3 3
 * 1 2 2
 * 2 3 1
 * 1 3 4
 * 
 * 
 * 输出样例：
 * 
 * 3
 * 
 */