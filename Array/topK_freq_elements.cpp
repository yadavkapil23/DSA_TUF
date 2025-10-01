class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        int n = v.size();
        map<int,int> m;
        vector<int> result;

        for(int i=0 ; i<n ; i++){ //using map to calculate count.
            m[v[i]]++;
        }

        vector<pair<int,int>> freq; //converting count to pairs -> count , element
        for (auto &p : m) {
            freq.push_back({p.second, p.first});
        }

        //sorting by freq.
        sort(freq.begin(), freq.end(), greater<pair<int,int>>()); //to sort in descending order.
        //we couldnt use the f.end() to f.begin() ,bcz begin always comes before the end , so thats why we use greater 


        //top K
        for(int i = 0; i < k; i++) {
            result.push_back(freq[i].second);
        }
        
        return result;
    }
};