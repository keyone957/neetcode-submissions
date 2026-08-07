/*
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cur;
        cur.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(cur[cur.size()-1]<nums[i])
            {
                cur.push_back(nums[i]);
            }
            else
            {
                int left=0;
                int right=cur.size()-1;
                while(left<right)
                {
                    int mid=(right+left)/2;
                    if(cur[mid]>=nums[i])
                    {
                        right=mid;
                    }
                    else
                    {
                        left=mid+1;
                    }
                }
                cur[left]=nums[i];
                
            }
        }
        return cur.size();
    }
};
