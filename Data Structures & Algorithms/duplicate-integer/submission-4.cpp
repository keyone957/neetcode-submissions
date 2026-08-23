class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size()==0) return false;
         sort(nums.begin(),nums.end());
        bool answer=false;
        int i=0;
        while(i<nums.size()-1)
        {
            if(nums[i]==nums[i+1])
            {
                answer=true;
                break;
            }
            else
            {
                answer=false;
            }
            i++;
        }
        return answer;
    }
};