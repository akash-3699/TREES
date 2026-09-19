class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        int dist =0;
        for(auto &nums: points){
            dist = nums[0]*nums[0]+nums[1]*nums[1];
            p.push({dist,{nums[0],nums[1]}});
        }

        vector<vector<int>> ans;
        
        while(k--){
            ans.push_back({p.top().second.first, p.top().second.second});
            
            p.pop();
        }

        return ans;

        
        
    }
};