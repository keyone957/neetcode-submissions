class Solution {
int arrSize;
vector<vector<int>> answer;
vector<int> input;
vector<int> cur;
void dfs(int start)
{
    answer.push_back(cur);
    for(int i=start;i<arrSize;i++)
    {
        if(i>start&&input[i]==input[i-1]) continue;
        
            cur.push_back(input[i]);
            dfs(i+1);
            cur.pop_back();
        
    }   
    
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        arrSize=nums.size();
        sort(nums.begin(),nums.end());
        input=nums;
        dfs(0);
        return answer;
    }
};
