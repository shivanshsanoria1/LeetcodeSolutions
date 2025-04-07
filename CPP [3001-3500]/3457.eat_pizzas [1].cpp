class Solution {
public:
	// T.C.=O(n*log(n)), S.C.=O(1)
	// Greedy
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end(), greater<int>());
        int n = pizzas.size();
        long long int sum = 0;

        for(int oddDays = (n/4 + 1)/2, evenDays = (n/4)/2, i=0; oddDays > 0 || evenDays > 0; i++)
        {
            if(oddDays > 0)
            {
                sum += pizzas[i];
                oddDays--;
            }
            else // evenDays > 0
            {
                i++;
                sum += pizzas[i];
                evenDays--;
            }
        }

        return sum;
    }
};

/*
# process all the odd-numbered days before the even-numbered days
# on odd-numbered days, it is optimal to pair the smallest three and the largest one
# on even-numbered days, it is optimal to pair the smallest two and the largest two
# total days = n/4, 
  odd-numbered days = ceil(total days / 2)
  even-numbered days = floor(total days / 2)
*/