#include <iostream>
using namespace std;

void collatzConjecture(int n)
{
	if(n<=0)
	{
		cout << "number must be positive" << endl;
		return;
	}
	int c=0;
	while(n!=1)
	{
		c++;
		cout << n << " ";
		if(n%2==0) // even num.
			n=n/2;
		else // odd num.
			n=3*n+1;
	}
	cout << 1 << endl;
	cout << "steps- " << c << endl;
}

int main()
{
	int n=27;
	collatzConjecture(n);
	return 0;
}