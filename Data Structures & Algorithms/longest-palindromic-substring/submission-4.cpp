class Solution {
public:
    string longestPalindrome(string s) {
        int sSize=s.size();
        int answerLeft=0;
        int answerRight=0;
        int maxLength=1;
        bool isPal=true;
        for(int leftIdx=0;leftIdx<sSize;leftIdx++)
        {
            for(int rightIdx=leftIdx;rightIdx<sSize;rightIdx++)
            {
                int tempL=leftIdx;
                int tempR=rightIdx;
                isPal=true;
                while(tempL<tempR)
                {
                    if(s[tempL]!=s[tempR])
                    {
                        isPal=false;
                        break;
                    }
                    tempL++;
                    tempR--;
                }
                if(isPal&&maxLength<rightIdx-leftIdx+1)
                {
                    maxLength=rightIdx-leftIdx+1;
                    answerLeft=leftIdx;
                    answerRight = rightIdx;
                }
            }
        }
        return s.substr(answerLeft,answerRight-answerLeft+1);
    }
};