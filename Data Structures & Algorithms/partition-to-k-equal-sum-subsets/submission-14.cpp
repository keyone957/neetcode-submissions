class Solution {
int arrSize=0;
int targetNum=0;
int targetCnt=0;
bool visit[17]={};
vector<int> inputArr;
//한 집합에서 도달해야 할 숫자
bool dfs(int cur,int curSum,int curIdx)
//부분집합이 k개 도달하면 끝?흠
{
    if(cur==targetCnt)
    {
        for(int i=0;i<arrSize;i++)
        {
            if(!visit[i])
            {
                return false;
            }
        }
        return true;
    }
    for(int i=curIdx;i<arrSize;i++)
    {
        if(!visit[i])
        {
            int temp=curSum+inputArr[i];
            if(temp<targetNum)
            {
                visit[i]=true;
                if(dfs(cur,temp,i+1)) return true;
                visit[i]=false;
            }
            else if(temp==targetNum)
            {
                visit[i]=true;
                if(dfs(cur+1,0,0)) return true;
                visit[i]=false;
            }
        }
    }
    return false;
}
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        arrSize=nums.size();
        targetCnt=k;
        inputArr=nums;
        int sum=0;
        for(int i=0;i<arrSize;i++)
        {
            sum+=nums[i];
        }
        targetNum=sum/k;        
        return dfs(0,0,0);
        
    }
};