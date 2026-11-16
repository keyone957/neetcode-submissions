class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        int cnt[129]={};
        int sSize=s.length();
        int answer=0;
        int left=0;
        int right=0;
        
        for(int i=0;i<sSize;i++)
        {
            cnt[s[i]]++;

            while(cnt[s[right]]>1)
            {
                cnt[s[left]]--;
                left++;
            }
           
            answer=max(answer,right-left+1);
            right++;
        }

        
        return answer;

        
    }
};
