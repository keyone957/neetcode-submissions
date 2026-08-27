class Solution {
int targetCnt;
int targetPair;
vector<string> answer;
string cur;
public: 
    void func(int curCnt,int open, int close)
    {
        if(curCnt==targetCnt)
        {
            answer.push_back(cur);
            return;
        }
         if(open < targetPair)
        {
            cur.push_back('(');
            func(curCnt + 1, open + 1, close);
            cur.pop_back();
        }

        // ')' 추가 가능
        if(close < open)
        {
            cur.push_back(')');
            func(curCnt + 1, open, close + 1);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        targetCnt=n*2;
        targetPair=n;
        func(0, 0, 0);
        return answer;
    }
};
