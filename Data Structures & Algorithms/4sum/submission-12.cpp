class Solution {
private:
    vector<vector<int>> answer;
    vector<int> selected;

    void backtracking(
        const vector<int>& nums,
        long long target,
        int start
    ) {
        // 숫자 4개를 선택한 경우
        if (selected.size() == 4) {
            long long sum = 0;

            for (int value : selected) {
                sum += value;
            }

            if (sum == target) {
                answer.push_back(selected);
            }

            return;
        }

        // 남은 원소 수가 필요한 선택 개수보다 적으면 종료
        int need = 4 - static_cast<int>(selected.size());

        for (int i = start; i <= static_cast<int>(nums.size()) - need; i++) {
            // 같은 깊이에서 동일한 값 중복 선택 방지
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
        sort(nums.begin(), nums.end());

        backtracking(nums, static_cast<long long>(target), 0);

        return answer;
    }
};