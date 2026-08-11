class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int arrSize=weights.size();
        int sum=0;
        int answer=1e9;
        for(int i=0;i<arrSize;i++)
        {
            sum+=weights[i];
        }
        int left=*max_element(weights.begin(),weights.end());
        int right=sum;
        int minW=1e9;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int curDay=1;
            int curSum=0;
            for(int i=0;i<arrSize;i++)
            {
                int tempSum=curSum+weights[i];
                if(tempSum<=mid)
                {
                    curSum+=weights[i];
                }
                else
                {
                    curDay++;
                    curSum=0;
                    curSum+=weights[i];
                }
            }
            if(curDay<=days)
            {
                answer=mid;
                right=mid-1;
            }
            else if(curDay>days)
            {
                left=mid+1;
            }
        }
return answer;
    }
};