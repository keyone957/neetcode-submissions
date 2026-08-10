class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxNum=*max_element(piles.begin(),piles.end());
        // cout<<maxNum;
        int arrSize=piles.size();
        int answer=1e9;
        int left=1;
        int right=maxNum;

        while(left<=right)
        {
            int k=(left+right)/2;
            int minTime=0;
            for(int i=0;i<arrSize;i++)
            {
                int cur=piles[i]%k;
                if(cur==0)
                {
                    minTime+=piles[i]/k;
                }
                else
                {
                    minTime+=piles[i]/k+1;
                }
            }
            if(minTime<=h)
            {
                int minValue=min(answer,k);
                answer=minValue;
                right=k-1;
            }
            else
            {
                left=k+1;
            }
        }
        return answer;
    }
};
