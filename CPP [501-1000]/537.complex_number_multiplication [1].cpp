class Solution {
public:
    int real(string s) //returns real part (in int form) of string s
    {
        int i=0;
        string real="";
        while(s[i]!='+') //get the real part
        {
            real+=s[i];
            i++;
        }
        return stoi(real);
    }
    
    int img(string s) //returns img part (in int form) of string s
    {
        int i=0;
        string img="";
        while(s[i]!='+') //skip the real part
            i++;
        i++; //skip the '+' sign
        while(s[i]!='i') //get the img part
        {
            img+=s[i];
            i++;
        }
        return stoi(img);
    }
    
    string complexNumberMultiply(string num1, string num2) {
        int real1=real(num1), img1=img(num1);
        int real2=real(num2), img2=img(num2);
        int real=(real1*real2)-(img1*img2); //real part of ans
        int img=(real1*img2)+(img1*real2); //img part of ans
        return to_string(real)+'+'+to_string(img)+'i';
    }
};