class Solution {
public:
    // T.C.=O(??), S.C.=O(n)
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        // push students in queue
        for(int student: students) 
            q.push(student);
            
        for(int sandwich: sandwiches)
        {
            // max (n-1) rounds for queue of size n, eg-, 
            // ABCD -> BCDA -> CDAB -> DABC (3 rounds for queue of size 4)
            int rounds = 0; 
            // front student does not like the ith sandwich
            while(rounds < q.size() && sandwich != q.front()) 
            {
                int currStudent = q.front(); 
                q.pop();
                // push the curr student at the back of queue
                q.push(currStudent); 
                rounds++;
            }

            // student found
            if(sandwich == q.front()) 
                q.pop();
            // no student found
            else
                break;
        }

        return q.size();
    }
};