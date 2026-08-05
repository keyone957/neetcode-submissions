class Solution {
private:
    vector<vector<int>> answer;
    vector<int> selected;
    int targetNum;
    void dfs(const vector<int>& nums,int start)
    {
        if (selected.size() == 4) 
        {
            long long sum = 0;

            for (int i = 0; i < selected.size(); i++)
            {
                sum += selected[i];
            }

            if (sum == targetNum) 
            {
                answer.push_back(selected);
            }

            return;
        }

        int need = 4 - selected.size();

        for (int i = start; i <= nums.size() - need; i++) 
        {
            if (i > start && nums[i] == nums[i - 1]) 
            {
                continue;
            }
            selected.push_back(nums[i]);
            dfs(nums, i + 1);
            selected.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) 
        {
            return answer;
        }
        targetNum=target;
        sort(nums.begin(), nums.end());

        dfs(nums, 0);

        return answer;
    }
};