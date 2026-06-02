class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int ans = INT_MAX;
        for(int i=0;i<landStartTime.size();i++)
        {
            int l = landStartTime[i] + landDuration[i];
            for(int j=0;j<waterStartTime.size();j++)
            {
                int w = waterDuration[j];
                if(waterStartTime[j]>l) w += waterStartTime[j] - l;
                ans = min(ans,l+w);
            }
        }
        for(int i=0;i<waterStartTime.size();i++)
        {
            int w = waterStartTime[i] + waterDuration[i];
            for(int j=0;j<landStartTime.size();j++)
            {
                int l =  landDuration[j];
                if(landStartTime[j]>w) l += landStartTime[j] - w;
                ans = min(ans,l+w);
            }
        }
        return ans;
    }
//please upvote...
};