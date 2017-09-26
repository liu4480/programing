#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
 
using boost::multiprecision::cpp_dec_float_50;
using namespace boost::multiprecision;
using namespace std;
 
int128_t boost_product(long long A, long long B)
{
    int128_t ans = (int128_t) A * B;
    return ans;
}

cpp_int boost_factorial(int num)
{
    cpp_int fact = 1;
    for (int i=num; i>1; --i)    
        fact *= i;
    return fact;
}

template<typename T>
inline T area_of_a_circle(T r)
{  
   // pi represent predefined constant having value
   // 3.1415926535897932384...
   using boost::math::constants::pi;
   return pi<T>() * r * r;
}
 
int main()
{
    long long first = 98745636214564698;
    long long second=7459874565236544789;
    cout << "Product of "<< first << " * "
         << second << " = \n"
         << boost_product(first,second) ;
    return 0;
}
