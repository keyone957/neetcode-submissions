
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sSize=s.size();
        int tSize=t.size();
        int sP=0;
        int tP=0;
        bool answer=false;
        for(int i=0;i<tSize;i++)
        {
            if(s[sP]==t[i])
            {
                sP++;
            }
        }
        if(sP==sSize)
        {
            answer=true;
        }
        return answer;
    }
};