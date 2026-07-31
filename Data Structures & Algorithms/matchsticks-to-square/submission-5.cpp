/*
성냥 하나를 4개의 변 중 하나에 하나씩 배치해 보는 방식?
전체 성냥 / 4 = 정사각형을 만들기 위해 목표하는 한변의 길이
side[4]에 이제 모든 변이 다 targetSide면 true
*/
class Solution {
int side[4]={};
vector<int> inputArr;
int targetSide;
int arrSize;
bool dfs(int cur)
{
    if(cur==arrSize)
    {
        for(int i=0;i<4;i++)
        {
            if(side[i]!=targetSide)
            {
                return false;
            }
        }
        return true;
    }
    for(int i=0;i<4;i++)
    {
        int curSum=side[i]+inputArr[cur];
        if(curSum<=targetSide)
        {
            side[i]+=inputArr[cur];
            if(dfs(cur+1)) return true;
            side[i]-=inputArr[cur];
        }
    }
    return false;
}
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int i=0;i<matchsticks.size();i++)
        {
            sum+=matchsticks[i];
        }
        if(sum%4!=0) return false;
        inputArr=matchsticks;
        arrSize=matchsticks.size();
        targetSide=sum/4;
        return dfs(0);
    }
};