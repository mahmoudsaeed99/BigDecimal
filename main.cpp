#include <iostream>
#include "bigDecimal.h"
using namespace std;

int main()
{
    bigDecimal b1("45656676878");
    bigDecimal b2("999999999999999");
    bigDecimal b3=b2+b1;
    cout<<b3<<endl;


    return 0;
}
