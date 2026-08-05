class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        
        vector<vector<int>> graph(n);

        // Build graph
        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods
        vector<bool> suspicious(n, false);
        queue<int> q;

        suspicious[k] = true;
        q.push(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // Check if any non-suspicious method
        // calls a suspicious method
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                // Cannot safely remove suspicious methods
                vector<int> ans(n);

                iota(ans.begin(), ans.end(), 0);

                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};