<!--
 * @Author: ssp
 * @Date: 2026-09-21 10:36:53
 * @LastEditTime: 2026-09-22 16:30:39
-->
# 算法模板
记录算法题常见模板

- segment tree

desc：每个node 代表一个区间，可以logn 维护查询区间属性（ min、max、sum...）核心操作为 build、update、query、pushup


- djkstra

desc: nlog 求s到每 个点的最短路径，核心是贪心，每次确定一个不可能再变短的点


- dsu

desc：并查集，支持维护集合间的操作，如合并两个集合，判断某两个数是否在同一个集合内