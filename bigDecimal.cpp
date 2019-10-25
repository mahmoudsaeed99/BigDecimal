#include "bigDecimal.h"
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;
bigDecimal::bigDecimal()
{
    //ctor
}

bigDecimal::~bigDecimal()
{
    //dtor
}

bigDecimal::bigDecimal(string s)
{
    number=s;
}
bigDecimal::bigDecimal(long int n)
{

    stringstream ss;//convert between strings and other numerical types
    string s;
    ss << n;
    ss >> s;
    number=s;

}
bigDecimal bigDecimal::operator+(bigDecimal b)
{
        bigDecimal r=b;
        if(b.number[0]!='-'&&number[0]=='-'){
            bigDecimal m(number.substr(1));//copy all number's character[1 to end] in m
            bigDecimal a=(b-m);
            return a;
        }
        else if(b.number[0]=='-'&&number[0]!='-'){
                bigDecimal m(b.number.substr(1));
                bigDecimal n(number);
                bigDecimal a=(n-m);
                return a;

        }
        else if(b.number[0]=='-'&&number[0]=='-'){
            bigDecimal m(number.substr(1)),n(b.number.substr(1));
            bigDecimal a=(n+m);
            a.number='-'+a.number;
            return a;
        }
          string add = (b.number.length() > number.length()) ?  b.number : number;
        char carry = '0';
        int differenceInLength = abs( (int) (b.number.size() - number.size()) );//The abs() function takes a single argument and returns a value of type int,

        if(b.number.size() > number.size())
            number.insert(0, differenceInLength, '0'); // put zeros from left

        else// if(number1.size() < number2.size())
            b.number.insert(0, differenceInLength, '0');
         int x;
        for(int i=b.number.size()-1; i>=0; --i)
        {
            x=(carry-'0')+(b.number[i]-'0')+(number[i]-'0');
            cout<<carry-'0'<<" "<<x<<endl;
            add[i] = ((carry-'0')+(b.number[i]-'0')+(number[i]-'0')) + '0';

            if(i != 0)
            {
                if(add[i] > '9')
                {
                    add[i] -= 10;
                    carry = '1';
                }
                else
                    carry = '0';
            }
        }
        if(add[0] > '9')
        {
            add[0]-= 10;
            add.insert(0,1,'1');
        }
        return bigDecimal(add);

    }

void bigDecimal::operator = (bigDecimal b)
{
    b.number=number;
}
bigDecimal bigDecimal ::operator-(bigDecimal b)
{
        if(b.number[0]!='-'&&number[0]=='-'){
            bigDecimal m(number.substr(1));
            bigDecimal n(number);
            bigDecimal a=m+n;
            a.number='-'+a.number;
            return a;
        }
        else if(b.number[0]=='-'&&number[0]!='-'){
            bigDecimal n(b.number.substr(1));
            bigDecimal m(number);
            bigDecimal a=m+n;
            return a;
        }
        else if(b.number[0]=='-'&&number[0]=='-'){
            bigDecimal m(number.substr(1)),n(b.number.substr(1));
            bigDecimal a=n-m;
            return a;
        }
        string minus_ = (b.number.length() > number.length()) ?  b.number : number;
        char carry = '0';
        int differenceInLength = abs( (int) (b.number.size() - number.size()) );//The abs() function takes a single argument and returns a value of type int,

        if(b.number.size() > number.size()){
            number.insert(0, differenceInLength, '0');// put zeros from left
            int x;
        for(int i=b.number.size()-1; i>=0; i--)
        {
             x=(b.number[i]-'0')-(number[i]-'0')-(carry-'0');
            cout<<carry-'0'<<" "<<x<<endl;
            minus_[i] = ((b.number[i]-'0')-(number[i]-'0')-(carry-'0'))+'0' ;

            if(i != 0)
            {
                if(minus_[i] < '0')
                {
                    minus_[i] += 10;
                    carry = '1';
                }
                else
                    carry = '0';
            }
        }
        bigDecimal z(minus_);
        return z;
        }
        else// if(number1.size() < number2.size())
        {

            b.number.insert(0, differenceInLength, '0');

        int x;
        for(int i=b.number.size()-1; i>=0; i--)
        {
             x=(b.number[i]-'0')-(number[i]-'0')-(carry-'0');
            cout<<carry-'0'<<" "<<x<<endl;
            minus_[i] = ((number[i]-'0')-(b.number[i]-'0')-(carry-'0'))+'0' ;

            if(i != 0)
            {
                if(minus_[i] < '0')
                {
                    minus_[i] += 10;
                    carry = '1';
                }
                else
                    carry = '0';
            }
        }
        bigDecimal z(minus_);
        return z;
        }
}
