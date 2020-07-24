class Solution {
public:
    string shortestPalindrome(string s)
    {
        string r = s, ss = s;
        reverse(r.begin(),r.end());
        ss += "#" + r;
        vector<int> next(ss.size()+1,0);
        getNext(ss,next);
        return r.substr(0,s.size()-next.back())+s;
    }

    void getNext(string &s,vector<int> &next)
    {
        next[0] = -1;
        int i = 0,p = -1;
        while(i<s.size())
        {
            if(p!=-1&&s[p]!=s[i])
                p = next[p];
            else
                next[++i] = ++p;
        }
        return;
    }
};
