class Solution {
vector<string> phoneNum={
    "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};
vector<string> answer;
string digitsInput;
int inputSize;
void dfs(int cur,string curWord)
{
    if(cur==inputSize)
    {
        answer.push_back(curWord);
        return;
    }

    // curWord+=phoneNum[digitsInput[cur]-'0'];
    for(int i=0;i<phoneNum[digitsInput[cur]-'0'].size();i++)
    {
        curWord+=phoneNum[digitsInput[cur]-'0'][i];
        dfs(cur+1,curWord);
        curWord.pop_back();
    }
   
    
}
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        inputSize=digits.size();
        digitsInput=digits;
        dfs(0,"");
        return answer;

    }
};
