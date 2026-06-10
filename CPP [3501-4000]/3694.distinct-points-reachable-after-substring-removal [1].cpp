class Solution {
private:
    // converts direction to the change in coordinates it brings
    pair<int, int> dirToCoord(char dir){
        if(dir == 'U')
            return {0, 1};
        else if(dir == 'D')
            return {0, -1};
        else if(dir == 'L')
            return {-1, 0};
        
        // dir == 'R'
        return {1, 0};
    }

public:
    // T.C.=O(n), S.C.=O(n)
    // Prefix sum + Sliding-window (fixed-length)
    int distinctPoints(string s, int k) {
        int n = s.length();
        vector<pair<int, int>> prefixSum(n, {0, 0});
        prefixSum[0] = dirToCoord(s[0]);

        for(int i=1; i<n; i++){
            auto [dx, dy] = dirToCoord(s[i]);

            prefixSum[i].first = prefixSum[i-1].first + dx;
            prefixSum[i].second = prefixSum[i-1].second + dy;
        }

        unordered_set<string> coords;
        // the subarray (of size k) in range [l, r] 
        // is to be removed at each step,
        // so, r-l+1 = k
        for(int l=0, r=k-1; r<n; l++, r++){
            // from the sum of [0, n-1]
            auto [finalX, finalY] = prefixSum[n-1];
            // subtract the sum of [0, r] and
            auto [subX, subY] = prefixSum[r];
            // add the sum of [0, r-k]
            auto [addX, addY] = l-1 >= 0 ? prefixSum[l-1] : make_pair(0, 0);

            int x = finalX - subX + addX;
            int y = finalY - subY + addY;

            string hash = to_string(x) + "#" + to_string(y);
            coords.insert(hash);
        }

        return coords.size();
    }
};