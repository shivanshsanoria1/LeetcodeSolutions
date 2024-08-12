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
    // T.C.=O((n+1)^2), S.C.=O((n+1)^2)
    // Union-Find
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        DisjointSet ds((n+1)*(n+1));

        // connect the vertices at North boundary
        for(int j=1; j<=n; j++)
            ds.unionBySize(j, j-1);
        
        // connect the vertices at South boundary
        for(int j=n*(n+1)+1; j<(n+1)*(n+1); j++)
            ds.unionBySize(j, j-1);

        // connect the vertices at West boundary
        for(int i=n+1; i<=n*(n+1); i += n+1)
            ds.unionBySize(i, i-(n+1));
        
        // connect the vertices at East boundary
        for(int i=2*(n+1)-1; i<(n+1)*(n+1); i += n+1)
            ds.unionBySize(i, i-(n+1));
        
        int regions = 1;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                int a = (n+1)*i + j;
                int b = a + 1;
                int c = a + (n+1);
                int d = b + (n+1);

                if(grid[i][j] == '/')
                {
                    if(!ds.unionBySize(b, c))
                        regions++;
                }
                else if(grid[i][j] == '\\')
                {
                    if(!ds.unionBySize(a, d))
                        regions++;
                }
            }

        return regions;
    }
};
/*
# for an empty grid of size n*n assume each intersection point to be a vertex of a graph
# for n = 3 the graph corresponding to the grid can represented as:
  0 - 1 - 2 - 3
  |   |   |   |
  4 - 5 - 6 - 7
  |   |   |   |
  8 - 9 - 10- 11
  |   |   |   |
  12- 13- 14- 15

# in general, for a grid of size n*n, the num of vertices in graph is (n+1)*(n+1)
# any general element grid[i][j] can be represented as a graph with 4 vertices
  a - b
  |   |
  c - d
# '/' will connect the vertices b and c while
  '\' will connect the vertices a and d as shown:
  a - b       a - b
  | / |       | \ |
  c - d       c - d

# in general, for an element grid[i][j], the vertices a,b,c,d of graph are:
  a = (n+1)*i + j
  b = a + 1
  c = a + (n+1)
  d = b + (n+1)

# initially all the vertices at the boundary will be connected
  thus for n=3, the connected vertices are:
  0 - 1 - 2 - 3
  |           |
  4   5   6   7
  |           |
  8   9   10  11
  |           |
  12- 13- 14- 15

  North boundary: 0,1,2,3
  South boundary: 12,13,14,15
  West boundary: 0,4,8,12
  East boundary: 3,7,11,15

# whenever a new edge is being added in between 2 vertices by '/' or '\'
  if those 2 vertices were present in the same component previously 
  then a new closed region a formed 
*/