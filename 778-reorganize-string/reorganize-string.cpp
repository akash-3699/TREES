class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char,int> freq;

        for(auto &a :s){
            freq[a]++;
        }
        int maxFreq = 0;
        for (auto& [ch, count] : freq) {
            maxFreq = max(maxFreq, count);
        }
        if (maxFreq > (n + 1) / 2) {
            return ""; // impossible
        }

        priority_queue<pair<int,char>> p;

        for(auto &[ch,count]: freq){
            p.push({count,ch});
        }

        string ans="";

        string result;
        result.reserve(n);
        
        while (p.size() >= 2) {
            auto [count1, ch1] = p.top(); p.pop();
            auto [count2, ch2] = p.top(); p.pop();
            
            result += ch1;
            result += ch2;
            
            if (--count1 > 0) p.push({count1, ch1});
            if (--count2 > 0) p.push({count2, ch2});
        }
        
        // At most one character can remain
        if (!p.empty()) {
            auto [count, ch] = p.top();
            if (count > 1) return ""; // safety check, shouldn't trigger if maxFreq check passed
            result += ch;
        }
        
        return result;
    }
};