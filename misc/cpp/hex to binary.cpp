#include <iostream>
#include <string>
using namespace std;

void hex_to_bin(string num)
{
	string n=num,binstr;
	int l=n.length();
	for(int i=0;i<l;i++)
	{
		switch(n[i])
		{
			case '0':
            	binstr.append("0000");
           		break;
        	case '1':
            	binstr.append("0001");
            	break;
        	case '2':
            	binstr.append("0010");
            	break;
        	case '3':
            	binstr.append("0011");
           		break;
	        case '4':
	            binstr.append("0100");
	            break;
	        case '5':
	            binstr.append("0101");
	            break;
	        case '6':
	            binstr.append("0110");
	            break;
	        case '7':
	            binstr.append("0111");
	            break;
	        case '8':
	            binstr.append("1000");
	            break;
	        case '9':
	            binstr.append("1001");
	            break;
	        case 'A':
	        case 'a':
	            binstr.append("1010");
	            break;
	        case 'B':
	        case 'b':
	            binstr.append("1011");
	            break;
	        case 'C':
	        case 'c':
	            binstr.append("1100");
	            break;
	        case 'D':
	        case 'd':
	            binstr.append("1101");
	            break;
	        case 'E':
	        case 'e':
	            binstr.append("1110");
	            break;
	        case 'F':
	        case 'f':
	            binstr.append("1111");
	            break;
        	default:
            	cout << "\nInvalid hexadecimal digit " << n[i] << "\n";
		}
	}
	cout << binstr;
}

int main()
{
	string num="1AC5";
	hex_to_bin(num);
	return 0;
}