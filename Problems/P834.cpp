//
// Created by liyang on 2020/10/6.
//

#include <vector>
using namespace std;

class Solution {
public:
    // dp： dp[i]表示i到后代所有结点的距离和
    // sz： sz[i]表示以i为根的树一共有多少结点
    vector<int> ans, sz, dp;
    // 树的邻接表表示
    vector<vector<int>> graph;

    // 填入dp和sz
    // f表示u的父结点
    void dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        for (auto& v: graph[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    // dp更新为： dp[i]表示从i到其他结点的距离和
    void dfs2(int u, int f) {
        // 整个树的根到其他结点的距离就是原dp[u]
        ans[u] = dp[u];
        // 每个子节点v都做一次根，并更新ans
        for (auto& v: graph[u]) {
            // f之前已经做过根，或者说已经更新了ans，这里不用继续处理
            if (v == f) {
                continue;
            }
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];
            // 现在v是整个树的根

            dfs2(v, u);

            // 位置再换回来
            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

    // edges的元素为size为2的vector，edges[i][0]表示父结点标号，edges[i][1]表示孩子标号
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N, 0);
        sz.resize(N, 0);
        dp.resize(N, 0);
        graph.resize(N, {});
        // 根据edges初始化graph
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};