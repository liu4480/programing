// Last Update:2017-07-03 13:00:15
/**
 * @file test.c
 * @brief 
 *
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2017-07-03
 */
#include <iostream>
using namespace std;

class a{
private:
    int b;
    char c;
    static int d;
public:
    a(int b, char c)
    {
        this->b = b;
        this->c = c;
        d = d + 1;
    }
    void print()
    {
        cout << "a.b=" << b
             << "a.c=" << c
             << "a.d=" <<d << endl;
    }
};
int a::d=0;
int main(){
    class a aa(0,'a');
    aa.print();
    return 0;
}
