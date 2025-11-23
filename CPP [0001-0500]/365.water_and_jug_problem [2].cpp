class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity > jug1Capacity + jug2Capacity) //targetCapacity cannot be greater than
            return false; //the sum of capacities of jug1 and jug2
        int v1=jug1Capacity, v2=jug2Capacity;
        map<pair<int,int>,bool> mp;
        queue<pair<int,int>> q;
        int i,j;
        mp[{0,0}]=true; //mark (0,0) as visited
        q.push({0,0});
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            i=p.first;
            j=p.second;
            
            if(i+j == targetCapacity) //(i,j) present in map and i+j==target
                return true;
            
            if(mp.find({0,j}) == mp.end()) //(0,j) not present in map
            {
                q.push({0,j});
                mp[{0,j}]=true; //empty jug1 //mark (0,j) as visited
            }
            if(mp.find({v1,j}) == mp.end())
            {
                q.push({v1,j});
                mp[{v1,j}]=true; //fill jug1 //mark (v1,j) as visited
            }
            if(mp.find({i,0}) == mp.end())
            {
                q.push({i,0});
                mp[{i,0}]=true; //empty jug2 //mark (i,0) as visited
            }
            if(mp.find({i,v2}) == mp.end())
            {
                q.push({i,v2});
                mp[{i,v2}]=true; //fill jug2 //mark (i,v2) as visited
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
            if(mp.find({a,b}) == mp.end()) //(a,b) not present in map
            {
                q.push({a,b});
                mp[{a,b}]=true; //mark (a,b) as visited
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
            if(mp.find({a,b}) == mp.end()) //(a,b) not present in map
            {
                q.push({a,b});
                mp[{a,b}]=true; //mark (a,b) as visited
            }
            
            q.pop();
        }
        return false;
    }
};