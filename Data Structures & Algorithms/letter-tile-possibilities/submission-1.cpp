class Solution {
int answer=0;
int sSize;
string inputS;
bool check[8]={};
void dfs(int cnt)
{
    if(cnt==sSize)
    {

        return;
    }
    for(int i=0;i<sSize;i++)
    {
        if(i>0&&inputS[i-1]==inputS[i]&&!check[i-1])
        {
            continue;
        }
        if(!check[i])
        {
            check[i]=true;
            answer++;
            dfs(cnt+1);
            check[i]=false;
        }

    }
}
public:
    int numTilePossibilities(string tiles) {
        sSize=tiles.size();
        inputS=tiles;
        sort(inputS.begin(),inputS.end());
        dfs(0);
        return answer;
    }
};
