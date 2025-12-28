#include <iostream>
#include <string>
using namespace std;

void bin_to_hex(string num)
{
	string n=num,n2;
	string hexstr,quad;
	int len=n.length();
	if(len%4==0)
		n2=n;
	else if(len%4==1)  // make string length a multiple of 4 by adding 0's to the left
		n2="000"+n; 
	else if(len%4==2)
		n2="00"+n;
	else if(len%4==3)
		n2="0"+n;
	int len2=n2.length();
	for(int i=0;i<len2;i+=4)
		{
			
			if(quad=="0001")
				hexstr.append("1");
			else if(quad=="0010")
				hexstr.append("2");
			else if(quad=="0011")
				hexstr.append("3");
			else if(quad=="0100")
				hexstr.append("4");
			else if(quad=="0101")
				hexstr.append("5");
			else if(quad=="0110")
				hexstr.append("6");
			else if(quad=="0111")
				hexstr.append("7");
			else if(quad=="1000")
				hexstr.append("8");
			else if(quad=="1001")
				hexstr.append("9");
			else if(quad=="1010")
				hexstr.append("A");
			else if(quad=="1011")
				hexstr.append("B");
			else if(quad=="1100")
				hexstr.append("C");
			else if(quad=="1101")
				hexstr.append("D");
			else if(quad=="1110")
				hexstr.append("E");
			else if(quad=="1111")
				hexstr.append("F");
		}
	cout << quad;
}

int main()
{
	string num="110001110";
	bin_to_hex(num);
	return 0;
}