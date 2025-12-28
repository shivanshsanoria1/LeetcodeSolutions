/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    int n=grades.size();
    vector<int> res(n);
    for(int i=0; i<n; i++)
    {
        if(grades[i]<=37 || grades[i]%5<=2)
            res[i]=grades[i];
        else if(grades[i]%5==3)
            res[i]=grades[i]+2;
        else if(grades[i]%5==4)
            res[i]=grades[i]+1;
    }
    return res;
}