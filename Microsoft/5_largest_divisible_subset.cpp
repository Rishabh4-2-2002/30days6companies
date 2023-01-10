class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i].push_back(nums[i]);
        }
        
        int maxs=0;
        int maxi=0;
        for(int i=1;i<n;i++)
        {
            int curr = nums[i];
                int max_iteri=0;
                int max_size=0;
                bool flag=false;
            for(int j=i-1;j>=0;j--)
            {
                if(curr%nums[j]==0)
                {
                    if(max_size<dp[j].size())
                    {
                        max_iteri=j;
                        max_size=dp[j].size();
                        flag = true;
                    }
                }
            }
            //now i have the max size regarding this 
            if(flag)
            {
                for(auto itr : dp[max_iteri])
                    {   
                        dp[i].push_back(itr);
                    }
                    
                    if(maxs<=dp[i].size())
                    {
                        maxi=i;
                        maxs=dp[i].size();
                    }
        }
            }
            
        return dp[maxi];
    }
};