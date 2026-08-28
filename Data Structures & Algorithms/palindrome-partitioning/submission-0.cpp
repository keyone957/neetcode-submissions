class Solution {
vector<vector<string>> answer;
vector<string> cur;
string input;
public :
    void func(int start)
    {
        if(start==input.size())
        {
            answer.push_back(cur);
            return;
        }
      
        for(int end=start;end<input.size();end++)
        {
            int left=start;
            int right=end;
            bool isPal=true;
            while(left<right)
            {
                if(input[left]==input[right])
                {
                    left++;
                    right--;
                }
                else
                {
                    isPal=false;
                    break;
                }
            }
            if(isPal)
            {
                cur.push_back(input.substr(start,end-start+1));
                func(end+1);
                cur.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        input=s;
        func(0);
        return answer;
    }
};
