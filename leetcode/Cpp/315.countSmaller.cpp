class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> countSmaller(vector<int>& nums) {
        vector<pii> buf;
        vector<int> res(nums.size(),0);
        for(int i=0;i<nums.size();i++)
            buf.push_back({nums[i],i});
        megSort(buf,0,buf.size()-1,res);
        return res;
    }

    void megSort(vector<pii> &nums,int l, int r, vector<int> &res)
    {
        if(l>=r)
            return;
        int m = l + (r-l)/2;
        megSort(nums,l,m,res);
        megSort(nums,m+1,r,res);

        vector<pii> buf;
        int i=l,j=m+1;
        while(i<=m||j<=r)
        {
            if(j<=r&&(i>m||nums[i]>nums[j]))
                buf.push_back(nums[j++]);
            else
            {
                res[nums[i].second] += buf.size() - (i-l);
                buf.push_back(nums[i++]);
            }
        }
        for(i=0;i+l<=r;i++)
            nums[l+i]=buf[i];
    }
};
