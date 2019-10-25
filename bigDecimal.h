#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H
#include <string>
 using namespace std;
class bigDecimal
{
    public:
        bigDecimal();
        bigDecimal(string decstr);
        bigDecimal(long int decint);
        bigDecimal operator+(bigDecimal b);
        bigDecimal operator-(bigDecimal b);
        void operator=(bigDecimal b);
        int size_();
          string number;
        friend ostream& operator<<(ostream& out,bigDecimal &b){
            out<<b.number;
            }

        virtual ~bigDecimal();

    protected:

    private:

};

#endif // BIGDECIMAL_H
