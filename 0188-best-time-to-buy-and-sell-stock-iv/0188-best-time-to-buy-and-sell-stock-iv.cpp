class Solution {
public:
    vector<vector<vector<int>>>dp;
    int limit;
    int rec(vector<int>& prices,int i,int cnt,int bought){
        if(i==prices.size() || cnt>=limit)
            return 0;
        if(dp[i][bought][cnt]!=-1)
            return dp[i][bought][cnt];
        int ans=0;
        if(bought==1 && cnt<limit){
            ans=max(rec(prices,i+1,cnt+1,0)+prices[i],rec(prices,i+1,cnt,1));
        }
        else
        {
            ans=max(rec(prices,i+1,cnt,1)-prices[i],rec(prices,i+1,cnt,0));
        }
        return dp[i][bought][cnt]=ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        limit=k;
        dp.assign(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
        return rec(prices,0,0,0);
    }
};