class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size=s1.size();
        int s2Size=s2.size();
        int s1Cnt[26]={};
        int s2Cnt[26]={};
        for(int i=0;i<s1Size;i++)
        {
            s1Cnt[s1[i]-'a']++;
            s2Cnt[s2[i]-'a']++;
        }
    
        int windowCnt=s2Size-s1Size+1;
        for(int i=0;i<windowCnt;i++)
        {
           bool isMatch=false; 
           int cnt=0;
           for(int j=0;j<26;j++)
           {
                if(s1Cnt[j]==s2Cnt[j])
                {
                    cnt+=s1Cnt[j];
                }
           }
           if(cnt==s1Size)
           {
            return true;
           }
             if (i + 1 < windowCnt) {
                s2Cnt[s2[i] - 'a']--;
                s2Cnt[s2[i + s1Size] - 'a']++;
            }
        }
        return false;
    }
};
