class DisjointSet
{
private:
    vector<int> parent, size;
    
public:
    DisjointSet(int V){
        parent.resize(V);
        size.resize(V, 1);
        for(int i=0; i<V; i++)
            parent[i] = i;
    }
    
    int findUltParent(int curr){ // find ultimate parent
        if(curr == parent[curr])
            return curr;
        parent[curr] = findUltParent(parent[curr]);
        return parent[curr];
    }
    
    bool unionBySize(int a, int b) 
    {
        int ultPar_a = findUltParent(a);
        int ultPar_b = findUltParent(b);
        if(ultPar_a == ultPar_b)
            return false;
        if(size[ultPar_a] <= size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else // size[ultPar_a] > size[ultPar_b]
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int> mp; // email -> vertex
        DisjointSet ds = DisjointSet(n); 
        for(int i=0; i<n; i++)
        {
            string name = accounts[i][0];
            for(int j=1; j<accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if(mp.find(email) == mp.end()) // email not found in map
                    mp[email] = i;
                else // email found in map
                    ds.unionBySize(mp[email], i);
            }
        }

        vector<vector<string>> ans(n, vector<string>(1, ""));
        for(auto it: mp)
        {
            string email = it.first;
            int vertex = ds.findUltParent(it.second);
            string name = accounts[vertex][0];
            ans[vertex][0] = name;
            ans[vertex].push_back(email);
        }

        vector<vector<string>> ans2;
        for(int i=0; i<n; i++)
        {
            if(ans[i].size() == 1) // no email
                continue;
            // sort the emails
            sort(ans[i].begin() + 1, ans[i].end());
            ans2.push_back(ans[i]);
        }
        return ans2;
    }
};