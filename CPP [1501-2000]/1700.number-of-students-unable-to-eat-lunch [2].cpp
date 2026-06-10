class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // num of students who like the sandwich 
        // of type '0' and '1' respecttively
        int zeros = 0, ones = 0;
        for(int student: students)
        {
            if(student == 0)
                zeros++;
            else
                ones++;
        }

        int n=sandwiches.size();
        for(int i=0; i<n; i++)
        {
            if(sandwiches[i] == 0)
                zeros--;
            else
                ones--;
            
            // no student in range [i, n-1] can be served
            if(zeros < 0 || ones < 0)
                return n-i;
        }

        // all students are served
        return 0;
    }
};