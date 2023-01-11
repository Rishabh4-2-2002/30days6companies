class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted;
        int ans=0;
        for(auto itr:nums)
        {
            sorted.push_back(itr);
        }
        sort(sorted.begin(),sorted.end());
        int n = nums.size();
        int low=0;
        int high =n;
        int flag = true;
        for( int i=0;i<n ;i++)
        {

            if(nums[i]!=sorted[i]){
                low = i;
                flag=false;
                break;
            }
            // else{
            //     while(nums[i]!=sorted[j] && j<n)
            //     {
            //         cout<<"entered"<<endl;
            //         ans++;
            //         j++;
            //     }
            //     if(j==n)    break;
            // }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]!=sorted[i]){
                high = i;
                flag=false;
                break;

            }
        }
        if(flag)    return 0;
        return high-low+1;
    }
};