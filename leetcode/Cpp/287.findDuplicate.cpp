class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l = 1,r = n,m,cnts,cntl;
        while(l<r)
        {
            m = l + (r-l)/2;
            cnts = cntl = 0;
            for(int &x:nums)
            {
                cnts+=x<m;
                cntl+=x>m;
            }
            if(cnts+cntl<n-1)
                return m;
            else if(cnts<m)
                l = m+1;
            else
                r = m;
            
        }
        return l;
    }
};
