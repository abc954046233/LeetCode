#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<int> path;
    vector<vector<int>> answer;
    vector<bool> used;

    static void show_vector(const vector<int> &path) {
        for (auto v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    void dfs() {
        if (path.size() == nums.size()) {
            answer.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                path.emplace_back(nums[i]);
                used[i] = true;

                dfs();

                // 回溯
                path.pop_back();
                used[i] = false;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return answer;

        this->nums = nums;
        this->used.resize(nums.size());

        dfs();

        return answer;
    }
};