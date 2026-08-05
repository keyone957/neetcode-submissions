class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());
        int numSize=nums.size();
        // int leftIdx=0;
        // int rightIdx=1;

        for(int leftIdx=0;leftIdx<numSize-3;leftIdx++)
        {
             if (leftIdx > 0 && nums[leftIdx] == nums[leftIdx - 1]) {
                continue;
            }
            for(int rightIdx=leftIdx+1;rightIdx<numSize-2;rightIdx++)
            {
                if (rightIdx > leftIdx + 1 &&
                nums[rightIdx] == nums[rightIdx - 1]) 
                {
                    continue;
                }
                 long long sum=nums[leftIdx]+nums[rightIdx];
            int tIdx=rightIdx+1;
            int fIdx=numSize-1;
            bool isTarget;
            while(tIdx<fIdx)
            {
                long long tempSum=sum+nums[tIdx]+nums[fIdx];
                if(tempSum<target)
                {
                    tIdx++;
                }
                else if(tempSum>target)
                {
                    fIdx--;
                }
                else
                {                        answer.push_back({nums[leftIdx],nums[rightIdx],nums[tIdx],nums[fIdx]});
                // tIdx++;
                // fIdx--;
                
                //     // break;
                  // 현재 정답에 사용한 값을 저장
                        int thirdValue = nums[tIdx];
                        int fourthValue = nums[fIdx];

                        // 같은 세 번째 값을 모두 건너뜀
                        while (tIdx < fIdx && nums[tIdx] == thirdValue) {
                            tIdx++;
                        }

                        // 같은 네 번째 값을 모두 건너뜀
                        while (tIdx < fIdx && nums[fIdx] == fourthValue) {
                            fIdx--;
                        }
                }
            }
   
            }
        }
        return answer;
    }
};