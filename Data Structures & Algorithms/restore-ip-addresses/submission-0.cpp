class Solution {
vector<string> answer;
string cur;
string input;
void dfs(int start,int cnt)
{
    if(cnt==4)
    {
       if(start==input.size())
       {
        answer.push_back(cur);
       } 
        return;
    }
    for(int a=start;a<input.size();a++)
    {
         // 한 구간은 최대 3자리
    if(a - start + 1 > 3)
    {
        break;
    }

    // 0으로 시작하는 두 자리 이상 숫자는 불가능
    if(input[start] == '0' && a > start)
    {
        break;
    }

    string temp = input.substr(start, a - start + 1);
    int num = stoi(temp);

    // 255 초과면 불가능
    if(num > 255)
    {
        break;
    }

    int prevSize = cur.size();

    if(cnt > 0)
    {
        cur.push_back('.');
    }

    cur += temp;

    dfs(a + 1, cnt + 1);

    // 백트래킹
    cur.resize(prevSize);
    }

}
public:
    vector<string> restoreIpAddresses(string s) {
        input=s;
        dfs(0,0);
        return answer;
    }
};