class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int V) { 
        parent.resize(V);
        size.resize(V, 1);

        // initially every node is a parent of itself
        for(int i=0; i<V; i++)
            parent[i] = i;
    }

    int findUltimateParent(int curr) { 
        if(curr == parent[curr])
            return curr;

        parent[curr] = findUltimateParent(parent[curr]);

        return parent[curr];
    }
    
    bool unionBySize(int a, int b) {
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();

        // elements in disjoint-set are just the indexes of string 's'
        DisjointSet ds = DisjointSet(n);

        // union each index pair
        for(vector<int>& pair: pairs)
            ds.unionBySize(pair[0], pair[1]);
        
        // ultimate-parent index -> {index}
        unordered_map<int, vector<int>> mp;
        // ultimate-parent identifies the component
        // to which an element belongs to
        for(int i=0; i<n; i++)
            mp[ds.findUltimateParent(i)].push_back(i);

        string ans = s;
        for(auto it: mp)
        {
            // string corresponding to each component
            string str = "";
            for(int idx: it.second)
                str += s[idx];
            
            // sort 'str' to make it lexicographically smallest
            sort(str.begin(), str.end());

            // fill the sorted 'str' into 'ans' at the 
            // indexes found in the curr component 
            int i = 0;
            for(int idx: it.second)
            {
                ans[idx] = str[i];
                i++;
            }
        }

        return ans;
    }
};