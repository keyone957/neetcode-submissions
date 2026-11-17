class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sSize=nums.size();
        bool answer=false;
        int cur=0;
        for(int i=0;i<sSize;i++)
        {
            if(i>cur) return false;
            cur=max(nums[i]+i,cur);
            if(cur>=sSize-1)
            {
                answer=true;
            }

        }

        return answer;
        
    }
};
