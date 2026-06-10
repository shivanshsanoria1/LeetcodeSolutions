class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

public:
    // Constructor
    DisjointSet(int n){
        this->parent.resize(n);
        // initially, every node is a parent of itself
        for(int i=0; i<n; i++)
            this->parent[i] = i;

        // initially, size of each component
        // with ultimate-parent i is 1
        this->size.resize(n, 1);
    }

    int findUltimateParent(int curr){
        if(parent[curr] == curr)
            return curr;

        parent[curr] = findUltimateParent(parent[curr]);

        return parent[curr];
    }

    // returns false if 'a' and 'b' are in the same component
    bool unionBySize(int a, int b){
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

        if(ultPar_a == ultPar_b)
            return false;

        if(size[ultPar_a] < size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else // size[ultPar_a] >= size[ultPar_b]
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }

        return true;
    }

    // returns true if 'a' and 'b' are in same component
    bool areConnected(int a, int b){
        return findUltimateParent(a) == findUltimateParent(b);
    }

    // num of components is given by
    // num of distinct ultimate-parents
    int componentCount(){
        int n = parent.size();
        unordered_set<int> ultPars;

        for(int i=0; i<n; i++)
            ultPars.insert(findUltimateParent(i));

        return ultPars.size();
    }
};

class Solution {
public:
    // T.C.=O(n^2), S.C.=O(2*n^2)
    // Union-Find
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        DisjointSet ds(2*n*n);
        // north, west
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}};

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                int curr_id_left = 2*n*i + 2*j;
                int curr_id_right = 2*n*i + 2*j+1;

                if(grid[i][j] == ' ')
                    ds.unionBySize(curr_id_left, curr_id_right);

                for(auto [dx, dy]: dirs)
                {
                    int x = i + dx;
                    int y = j + dy;

                    if(x < 0 || x >= n || y < 0 || y >= n)
                        continue;

                    int nei_id_left = 2*n*x + 2*y;
                    int nei_id_right = 2*n*x + 2*y+1;

                    if(dx == -1 && dy == 0) // north
                    {
                        if(grid[i][j] == '\\')
                            ds.unionBySize(curr_id_right, grid[x][y] == '\\' ? nei_id_left : nei_id_right);
                        else // grid[i][j] == '/' or ' '
                            ds.unionBySize(curr_id_left, grid[x][y] == '/' ? nei_id_right : nei_id_left);
                    }
                    else // dx == 0 && dy == -1 // west
                        ds.unionBySize(curr_id_left, nei_id_right);
                }

            }

        return ds.componentCount();
    }
};
/*
# given a grid of size n*n where each element can be '/', '\', ' '
# assume each element grid[i][j] to be made up of 2 parts 'left' and 'right'
# if grid[i][j] == ' ' then both the parts 'left' and 'right' are connected
  else the parts 'left' and 'right' are not connected
# each part is uniquely identified by an id in range [0, m*n-1]
# id of 'left' and 'right' parts of the element grid[i][j] are 
  (2*n*i + 2*j) and (2*n*i + 2*j+1)
# for each element grid[i][j] check its north and west neighbours 
  and union the correct parts of both accordingly
*/