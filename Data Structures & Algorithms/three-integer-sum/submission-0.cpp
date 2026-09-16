class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        int arrSize=nums.size();
        for(int i=0;i<arrSize-2;i++)
        {
            int left=i+1;
            int right=arrSize-1;
            if(i>0&&nums[i]==nums[i-1]) continue;

            while(left<right)
            {
                int sum=nums[left]+nums[right]+nums[i];
                vector<int> temp;
                if(sum<0)
                {
                    left++;
                }
                else if(sum>0)
                {
                    right--;
                }
                else if(sum==0)
                {
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    temp.push_back(nums[i]);
                    answer.push_back(temp);
                    left++;
                    right--;
                    while(left<right&&nums[left]==nums[left-1])
                    {
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right+1])
                    {
                        right--;
                    }
                }
            }

        }

        return answer;
    }
};
