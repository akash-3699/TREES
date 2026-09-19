class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
         int n = barcodes.size();

        unordered_map<int,int> freq;
        for(int bar : barcodes){
            freq[bar]++;
        }

        priority_queue<pair<int,int>> p;
         for (auto& [val, count] : freq) {
            p.push({count, val});
        }
        int index=0;
        vector<int> ans(barcodes.size(),-1);
        while(!p.empty()){
            auto [count, val] = p.top();
            p.pop();
            
            for (int i = 0; i < count; i++) {
                if (index >= n) {
                    index = 1; // switch to odd indices
                }
                ans[index] = val;
                index += 2;
            
            }
        }

        return ans;
    }
};