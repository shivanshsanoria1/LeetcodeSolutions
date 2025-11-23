class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity > jug1Capacity + jug2Capacity) //targetCapacity cannot be greater than
            return false; //the sum of capacities of jug1 and jug2
        int v1=jug1Capacity, v2=jug2Capacity;
        vector<vector<bool>> vec(v1+1,vector<bool> (v2+1,false));
        queue<pair<int,int>> q;
        int i,j;
        vec[0][0]=true;
        q.push({0,0});
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            i=p.first;
            j=p.second;

            if(vec[i][j]==true && i+j == targetCapacity)
                return true;

            if(vec[0][j]==false)
            {
                q.push({0,j});
                vec[0][j]=true; //empty jug1 //mark (0,j) as visited
            }
            if(vec[v1][j]==false)
            {
                q.push({v1,j});
                vec[v1][j]=true; //fill jug1 //mark (v1,j) as visited
            }
            if(vec[i][0]==false)
            {
                q.push({i,0});
                vec[i][0]=true; //empty jug2 //mark (i,0) as visited
            }
            if(vec[i][v2]==false)
            {
                q.push({i,v2});
                vec[i][v2]=true; //fill jug2 //mark (i,v2) as visited
            }
            int a,b;
            
            //transfer from jug1 to jug2
            if(i+j > v2) //water left in jug1
            {
                b=v2; //jug2 is full
                a=i+j-v2;
            }
            else
            {
                b=i+j;
                a=0; //jug1 is empty
            }
            if(vec[a][b]==false)
            {
                q.push({a,b});
                vec[a][b]=true;
            }
            
            //transfer from jug2 to jug1
            if(i+j > v1) //water left in jug2
            {
                a=v1; //jug1 is full
                b=i+j-v1;
            }
            else
            {
                a=i+j;
                b=0; //jug2 is empty
            }
            if(vec[a][b]==false)
            {
                q.push({a,b});
                vec[a][b]=true;
            }
            
            q.pop();
        }
        return false;
    }
};