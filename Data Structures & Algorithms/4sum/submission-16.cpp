class Solution {
private:
    vector<vector<int>> answer;
    vector<int> selected;

    void backtracking(
        const vector<int>& nums,
        long long target,
        int start
    ) {
        if (selected.size() == 4) {
            long long sum = 0;

            for (int i = 0; i < selected.size(); i++) {
                sum += selected[i];
            }

            if (sum == target) {
                answer.push_back(selected);
            }

            return;
        }

        int need = 4 - selected.size();

        for (int i = start; i <= nums.size() - need; i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            selected.push_back(nums[i]);
            backtracking(nums, target, i + 1);
            selected.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) 
        {
            return answer;
        }
        sort(nums.begin(), nums.end());

        backtracking(nums, target, 0);

        return answer;
    }
};