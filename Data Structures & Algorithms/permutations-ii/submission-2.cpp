class Solution {
bool visit[10];
int target;
vector<int> curArr;
vector<int> input;
vector<vector<int>> answer;
void dfs(int cur)
{
    if(cur==target)
    {
        answer.push_back(curArr);
        return ;
    }
    for(int i=0;i<target;i++)
    {
        if(!visit[i] &&!(i > 0 && input[i] == input[i - 1] && !visit[i - 1]))
        {
            
            visit[i]=true;
            curArr.push_back(input[i]);
            dfs(cur+1);
            visit[i]=false;
            curArr.pop_back();
        }
    }

}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        target=nums.size();
        input=nums;
        sort(input.begin(),input.end());
        dfs(0);
        return answer;
    }
};