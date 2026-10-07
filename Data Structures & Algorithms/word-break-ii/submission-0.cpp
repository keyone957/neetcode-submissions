class Solution {
int inputSize;
string input;
vector<string> dictArr;
string curDic;
vector<string> answer;
void func(int cur)
{
    if(cur==inputSize)
    {
        answer.push_back(curDic);
        return;
    }
    for(int i=0;i<dictArr.size();i++)
    {
        if(input.compare(cur,dictArr[i].size(),dictArr[i])==0)
        {   
            
            bool addSpace = false;
            if (!curDic.empty())
            {
                curDic += " ";
                addSpace = true;
            }
            curDic+=dictArr[i];
            func(cur+dictArr[i].size());
            if(addSpace)
            {
                curDic.pop_back();
            }
            for(int j = 0; j < dictArr[i].size(); j++)
            {
                curDic.pop_back();
            }
            
        }
    }
}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        inputSize=s.size();
        dictArr=wordDict;
        input=s;
        func(0);
        return answer;
    }
};