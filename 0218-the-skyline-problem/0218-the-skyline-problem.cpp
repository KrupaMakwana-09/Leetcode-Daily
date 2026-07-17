class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int,int> mp;
        set<int> st;

        for(auto &it: buildings){
            st.insert(it[0]);
            st.insert(it[1]);
        }

        int idx=0;
        for(auto x: st)
            mp[x]=idx++;

        int n=st.size();
        vector<vector<int>> start(n),end(n);

        for(auto &it: buildings){
            int l=mp[it[0]];
            int r=mp[it[1]];
            int h=it[2];

            start[l].push_back(h);
            end[r].push_back(h);
        }

        vector<int> orgVal(st.begin(),st.end());

        vector<vector<int>> ans;
        multiset<int> ms;
        int prev = 0;

        for(int i=0;i<n;i++){

            // Add all starting buildings
             for(auto h : start[i])
            ms.insert(h);

            // Remove all ending buildings
            for(auto h : end[i]){
            auto it = ms.find(h);
            if(it != ms.end())
            ms.erase(it);
        }

        int cur = ms.empty() ? 0 : *ms.rbegin();

        if(cur != prev){
        ans.push_back({orgVal[i], cur});
        prev = cur;
    }
}
        return ans;
    }
};