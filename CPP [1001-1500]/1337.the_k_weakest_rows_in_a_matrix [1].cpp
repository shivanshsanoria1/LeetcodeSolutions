class Cmp{
private:
    typedef pair<int, int> PI;

public:
    bool operator()(PI &a, PI &b){
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    }
};

class Solution {
private:
    typedef pair<int, int> PI; // {freq of 1's in row, index of row}

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        int m=mat.size(), n=mat[0].size();
        priority_queue<PI, vector<PI>, Cmp> pq; // min-heap
        for(int i=0; i<m; i++)
        {
            int ones = 0;
            for(int j=0; j<n; j++)
                if(mat[i][j] == 1)
                    ones++;
            pq.push({ones, i});
        }
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};