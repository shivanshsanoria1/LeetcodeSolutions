class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(auto it: students) //push students in queue
            q.push(it);
        for(int i=0; i<sandwiches.size(); i++)
        {
            bool flag=false;
            int rounds=0; //max (n-1) rounds for queue of size n, eg-, ABCD->BCDA->CDAB->DABC (3 rounds for queue of size 4)
            while(rounds < q.size() && sandwiches[i] != q.front()) //front student does not match with sandwiches[i]
            {
                int stu=q.front(); //pop the front student
                q.pop();
                q.push(stu); //push the popped student at the back
                rounds++; //increment rounds
            }
            if(sandwiches[i] == q.front()) //student found
            {
                q.pop();
                flag=true;
            }
            if(flag==false) //no student found
                break;
        }
        return q.size();
    }
};