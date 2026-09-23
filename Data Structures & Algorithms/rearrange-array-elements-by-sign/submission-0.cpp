class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int arrSize = nums.size();
        int left = 0;
        int right = 0;

        vector<int> answer;

        while (answer.size() < arrSize)
        {
            while (nums[left] < 0)
                left++;

            answer.push_back(nums[left]);
            left++;

            while (nums[right] > 0)
                right++;

            answer.push_back(nums[right]);
            right++;
        }

        return answer;
    }
};