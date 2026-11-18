class Solution {
public:
    int appendCharacters(string s, string t) {
        int sSize=s.length();
        int tSize=t.length();
        int sp=0;
        int tp=0;
        int answer=0;
        while(sp<sSize&&tp<tSize)
        {
            if(s[sp]==t[tp])
            {
                sp++;
                tp++;
            }
            else
            {
                sp++;
            }
            answer=tSize-tp;
        }
        return answer;   
    }
};