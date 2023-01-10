class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int N = nums.size();
        int summ=0;
        int fp=0;
        for(int i=0;i<N;i++)
        {
            summ+=nums[i];
            fp+=nums[i]*i;
        }
        cout<<"fp"<< fp<<endl;
        int ans=fp;
        int fn=0;
        for(int i=1;i<N;i++)
        {
            fn = fp + summ - N*nums[N-i];
            ans = max(fn,ans);
            fp=fn;
            cout<<fp<<endl;
        }
        return ans;
    }
};