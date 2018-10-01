/**
310 Minimal height trees
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

        // n: number of nodes
        // edges: all edges

        // build adjacent list
        vector<vector<int>> adj_list(n);
        for (std::pair<int, int>& edge : edges) {
            adj_list[edge.first].push_back(edge.second);
            adj_list[edge.second].push_back(edge.first);
        }

        // DFS for all noeds
        std::vector<int> height(n);
        for (int node = 0; node < n; ++node) {
            height[node] = dfs(adj_list, node, -1);
        }

        // find minimal height
        int min_height = INT_MAX;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] < min_height)
                min_height = height[i];
        }

        std::vector<int> results;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] == min_height) {
                results.push_back(i);
            }
        }
        return results;
    }

    int dfs(vector<vector<int>>& adj_mat, int node, int parent) {

        int height = 0;
        int n = adj_mat.size();
        for (int i = 0; i < n; ++i) {
            if (i == node)
                continue;

            if (adj_mat[node][i] != 0) {

                if (i == parent) {
                    continue;
                }

                int curr_height = 0;
                if (adj_mat[i][node] > 1) {

                    curr_height = adj_mat[i][node];

                } else {

                    curr_height = dfs(adj_mat, i, node);
                    adj_mat[i][node] = curr_height;
                }
                if (curr_height > height) {
                    height = curr_height;
                }
            }
        }
        return height + 1;
    }
};