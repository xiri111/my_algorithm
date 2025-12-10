#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string multiply(string num1, string num2) 
{
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    string res;
    int index=0;
    for(int i=0;i<num1.size();i++)
    {
        string curs;
        int carry=0;
        int cur=0;
        int val1=num1[i]-'0';
        for(int j=0;j<num2.size();j++)
        {   
            int val2=num2[j]-'0';
            cur = (val1 * val2 + carry)%10;
            carry = (val1* val2 + carry)/10;
            curs = curs + char(cur+'0');
            cur=0;
        }
        if(carry!=0)
        {
            curs=curs+char(carry+'0');
        }
        if(res.empty()) 
        {
            res=curs;
            index=1;
        }
        else
        {
            for(int k=0;k<index;i++)
            {
                curs='0'+curs;
            }
            index++;
            //curs和res两个字符串相加
            int car=0;
            int rn=res.size();
            int cn=curs.size();
            int m=0;
            for(m;m<rn;m++)
            {
                int sum = (res[m] - '0') + (curs[m] - '0') + car;
                res[m] = sum % 10 + '0';
                car = sum / 10;
            }
            if(m==(cn-1))
            {
                res=res+char((car+(curs[m]-'0'))%10);
                car=(car+(curs[m]-'0'))/10;
            }
            if(car!=0) 
                res=res+char(car+'0');
        }
    }    
    reverse(res.begin(),res.end());
    return res;   
}

int main()
{
    string num1,num2;
    cin>>num1>>num2;
    cout<<multiply(num1,num2)<<endl;
    return 0;   
}