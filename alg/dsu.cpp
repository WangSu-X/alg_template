/*** 
 * @Author: ssp
 * @Date: 2026-09-22 16:29:26
 * @LastEditTime: 2026-09-22 16:41:58
 */

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int f[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        f[i] = i;


    while (m--) {

        char op;
        int x, y;

        cin >> op >> x >> y;

        if (op == 'M') {

            x = find(x);
            y = find(y);

            f[x] = f[y];

        } else {

            x = find(x);
            y = find(y);

            cout << (x == y ? "Yes" : "No") << '\n';

        }

    }


    return 0;
}


/**
 *
 * 题目：
 *
 * 一共有 n 个数，编号是 1∼n，
 * 最开始每个数各自在一个集合中。
 *
 * 现在要进行 m 个操作，操作共有两种：
 *
 * 1. M a b
 *
 * 将编号为 a 和 b 的两个数所在的集合合并，
 * 如果两个数已经在同一个集合中，则忽略这个操作。
 *
 *
 * 2. Q a b
 *
 * 询问编号为 a 和 b 的两个数是否在同一个集合中。
 *
 *
 *
 * 输入格式：
 *
 * 第一行输入整数 n 和 m。
 *
 * 接下来 m 行，每行包含一个操作指令，
 * 指令为 M a b 或 Q a b 中的一种。
 *
 *
 *
 * 输出格式：
 *
 * 对于每个询问指令 Q a b，
 * 都要输出一个结果。
 *
 * 如果 a 和 b 在同一集合内，则输出 Yes，
 * 否则输出 No。
 *
 * 每个结果占一行。
 *
 *
 *
 * 数据范围：
 *
 * 1 <= n, m <= 10^5
 *
 *
 *
 * 输入样例：
 *
 * 4 5
 * M 1 2
 * M 3 4
 * Q 1 2
 * Q 1 3
 * Q 3 4
 *
 *
 *
 * 输出样例：
 *
 * Yes
 * No
 * Yes
 *
 */