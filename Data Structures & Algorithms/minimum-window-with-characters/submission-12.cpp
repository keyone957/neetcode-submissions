class Solution {
public:
    string minWindow(string s, string t) {
        int sSize=s.size();
        int tSize=t.size();
        int aCnt[128]={};
        int tCnt[128]={};
        int left=0;
        int right=0;
        string answer;
        int matched=0;
        int answerl=-1;
        int answerr=0;
        if(tSize==0) return answer;
        for(int i=0;i<tSize;i++)
        {
            tCnt[t[i]]++;
        }
        while(right<sSize)
        {
            aCnt[s[right]]++;
            if(aCnt[s[right]]<=tCnt[s[right]])
            {
                matched++;
            }
            while(matched==tSize)
            {
            
                if(answerl==-1||right-left<answerr-answerl)
                {
                    answerl=left;
                    answerr=right;
                    
                }   
                aCnt[s[left]]--;
                if(aCnt[s[left]] < tCnt[s[left]])
                {
                    matched--;
                }
                
                left++;
            }
            right++;
        }    
        if(answerl==-1) return "";
        return s.substr(answerl, answerr-answerl+1);
    }
};
