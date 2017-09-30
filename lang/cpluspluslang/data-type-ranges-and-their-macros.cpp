/*
 * Data Type                              Range                      Macro for min value           Macro for max value
 * char                                -128 to +127                        CHAR_MIN                      CHAR_MAX
 * short char                          -128 to +127                       SCHAR_MIN                     SCHAR_MAX
 * unsigned char                         0  to 255                             0                        UCHAR_MAX
 * 
 * short int                         -32768 to +32767                      SHRT_MIN                      SHRT_MAX
 * unsigned short int                    0  to  65535                          0                        USHRT_MAX 
 * int                          -2147483648 to +2147483647                  INT_MIN                       INT_MAX
 * unsigned int                          0  to  4294967295                     0                         UINT_MAX
 * long int            -9223372036854775808 to +9223372036854775807        LONG_MIN                      LONG_MAX
 * unsigned long int                     0  to  18446744073709551615           0                        ULONG_MAX 
 * long long int       -9223372036854775808 to +9223372036854775807       LLONG_MIN                     LLONG_MAX
 * unsigned long long int                0  to  18446744073709551615           0                       ULLONG_MAX
 * 
 * float                        1.17549e-38 to  3.40282e+38                 FLT_MIN                       FLT_MAX
 * float(negative)             -1.17549e-38 to -3.40282e+38                -FLT_MIN                      -FLT_MAX
 * double                      2.22507e-308 to  1.79769e+308                DBL_MIN                       DBL_MAX
 * double(negative)           -2.22507e-308 to -1.79769e+308               -DBL_MIN                      -DBL_MAX
 */
#include<iostream>
#include<limits.h> // for int,char macros
#include<float.h> // for float,double macros
using namespace std;
int main()
{
 
// Displaying ranges with the help of macros
cout << "char ranges from : " << CHAR_MIN << " to " << CHAR_MAX;
cout << "\n\nshort char ranges from : " << SCHAR_MIN << " to " << SCHAR_MAX;
cout << "\n\nunsigned char ranges from : " << 0 << " to " << UCHAR_MAX;
 
cout << "\n\n\nshort int ranges from : " << SHRT_MIN << " to " << SHRT_MAX;
cout << "\n\nunsigned short int ranges from : " << 0 << " to " << USHRT_MAX;
cout << "\n\nint ranges from : " << INT_MIN << " to " << INT_MAX;
cout << "\n\nunsigned int ranges from : " << 0 << " to " << UINT_MAX;
cout << "\n\nlong int ranges from : " << LONG_MIN << " to " << LONG_MAX;
cout << "\n\nunsigned long int ranges from : " << 0 << " to " << ULONG_MAX;
cout << "\n\nlong long int ranges from : " << LLONG_MIN << " to " << LLONG_MAX;
cout << "\n\nunsigned long long int ranges from : " << 0 << " to " << ULLONG_MAX;
 
cout << "\n\n\nfloat ranges from : " << FLT_MIN << " to " << FLT_MAX;
cout << "\n\nnegative float ranges from : " << -FLT_MIN << " to " << -FLT_MAX;
cout << "\n\ndouble ranges from : " << DBL_MIN << " to " << DBL_MAX;
cout << "\n\nnegative double ranges from : " << -DBL_MIN << " to " << +DBL_MAX;
 
return 0;
 
}
