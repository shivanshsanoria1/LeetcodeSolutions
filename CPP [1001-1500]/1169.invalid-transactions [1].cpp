class Solution {
private:
    static bool cmp(vector<string>& a, vector<string>& b){
        return stoi(a[1]) < stoi(b[1]);
    }

    vector<string> tokenize(string& transaction){
        vector<string> transAct;
        string data = "";
        transaction += ",";

        for(char ch: transaction)
        {
            if(ch == ',')
            {
                transAct.push_back(data);
                data = "";
            }
            else
                data += ch;
        }

        transaction.pop_back();

        return transAct;
    }

    vector<string> stringify(vector<vector<string>>& transActs, vector<bool>& isValid){
        vector<string> invalid;
        for(int i=0; i<transActs.size(); i++)
        {
            if(isValid[i])
                continue;
            
            string name = transActs[i][0];
            string time = transActs[i][1];
            string amount = transActs[i][2];
            string city = transActs[i][3];

            invalid.push_back(name + "," + time + "," + amount + "," + city);
        }

        return invalid;
    }

public:
    // T.C.=O(n*log(n) + n^2), S.C.=O(n)
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<vector<string>> transActs;
        for(string& transaction: transactions)
            transActs.push_back(tokenize(transaction));

        // sort in increasing order of amount
        sort(transActs.begin(), transActs.end(), cmp);

        int n=transActs.size();
        vector<bool> isValid(n, true);

        for(int i=0; i<n; i++)
        {
            if(!isValid[i])
                continue;
            
            // mark the transactions with amount > 1000 as invalid
            if(stoi(transActs[i][2]) > 1000)
            {
                isValid[i] = false;
                continue;
            }
            
            for(int j=i-1; j>=0; j--)
            {
                // time diff must be <= 60
                if(stoi(transActs[i][1]) - stoi(transActs[j][1]) > 60)
                    break;
                
                // same name and different city
                if(transActs[i][0] == transActs[j][0] && transActs[i][3] != transActs[j][3])
                {
                    isValid[i] = false;
                    break;
                }
            }

            if(!isValid[i])
                continue;

            for(int j=i+1; j<n; j++)
            {
                // time diff must be <= 60
                if(stoi(transActs[j][1]) - stoi(transActs[i][1]) > 60)
                    break;
                
                // same name and different city
                if(transActs[i][0] == transActs[j][0] && transActs[i][3] != transActs[j][3])
                {
                    isValid[i] = false;
                    break;
                }
            }
        }

        return stringify(transActs, isValid);
    }
};