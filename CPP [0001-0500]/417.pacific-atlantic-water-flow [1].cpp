class Solution { //idea: find the coordinates which are reachable from oceans and then find their intersection
public:
    void dfs(vector<vector<int>>& heights, int m, int n, int x, int y, int prev_height, set<pair<int,int>>& visited)
    {
        if(x<0 || x>=m || y<0 || y>=n) //index out of bounds
            return;
        if(heights[x][y] < prev_height) //curr height < prev height
            return;
        if(visited.find({x,y}) != visited.end()) //curr element is in visited set
            return;
        visited.insert({x,y}); //add curr element in visited set
        dfs(heights,m,n,x-1,y,heights[x][y],visited); //up
        dfs(heights,m,n,x+1,y,heights[x][y],visited); //down
        dfs(heights,m,n,x,y-1,heights[x][y],visited); //left
        dfs(heights,m,n,x,y+1,heights[x][y],visited); //right
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m=heights.size(), n=heights[0].size();
        set<pair<int,int>> pac_visited; //stores coordinates (x,y) which are reachable from pacific ocean
        set<pair<int,int>> atl_visited; //stores coordinates (x,y) which are reachable from atlantic ocean
        for(int j=0; j<n; j++)
        {
            dfs(heights,m,n,0,j,heights[0][j],pac_visited); //0th row, pacific ocean edge
            dfs(heights,m,n,m-1,j,heights[m-1][j],atl_visited); //last row, atlantic ocean edge
        }
        for(int i=0; i<m; i++)
        {
            dfs(heights,m,n,i,0,heights[i][0],pac_visited); //0th col, pacific ocean edge
            dfs(heights,m,n,i,n-1,heights[i][n-1],atl_visited); //last col, atlantic ocean edge
        }
        for(int i=0; i<m; i++) //find intersection of coordinates which are present in pacific and atlantic ocean sets
            for(int j=0; j<n; j++)
                if(pac_visited.find({i,j}) != pac_visited.end() && atl_visited.find({i,j}) != atl_visited.end())
                    ans.push_back({i,j});
        return ans;
    }
};