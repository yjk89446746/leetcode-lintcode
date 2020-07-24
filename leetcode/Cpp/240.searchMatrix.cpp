class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int x=mat.size();
        if(x<1)
            return 0;
        int y=mat[0].size(),l,r,m;
        if(y<1)
            return 0;
        for(int i=0;i<x;i++)
        {
            l=0,r=y;
            while(l<r)
            {
                m = l + (r-l)/2;
                if(mat[i][m]<tar)
                    l = m+1;
                else
                    r = m;
            }
            if(l<y&&mat[i][l]==tar)
                return 1;
        }
        return 0;
    }
};
