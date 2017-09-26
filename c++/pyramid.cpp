/*
 * print like the following
 *     *
 *     * *
 *     * * *
 *     * * * *
 *     * * * * *
 */
#include <iostream>
using namespace std;

void simple_pypart(int n)
{
    // outer loop to handle number of rows
    //  n in this case
    for (int i=0; i<n; i++)
    {
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for(int j=0; j<=i; j++ )
        {
            // printing stars
            cout << "* ";
        }
 
        // ending line after each row
        cout << endl;
    }
}

/*
 * print like following:
 *              *
 *            * *
 *          * * *
 *        * * * *
 *      * * * * *
 */
void simple_pypart_reverse180(int n)
{
    // number of spaces
    int k = 2*n - 2;
 
    // outer loop to handle number of rows
    //  n in this case
    for (int i=0; i<n; i++)
    {
 
        // inner loop to handle number spaces
        // values changing acc. to requirement
        for (int j=0; j<k; j++)
            cout <<" ";
 
        // decrementing k after each loop
        k = k - 2;
 
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for (int j=0; j<=i; j++ )
        {
            // printing stars
            cout << "* ";
        }
 
        // ending line after each row
        cout << endl;
    }
}
/*
 * print like following:
 *          *
 *         * *
 *        * * *
 *       * * * *
 *      * * * * *
 */
void triangle(int n)
{
    // number of spaces
    int k = n - 1;
 
    // outer loop to handle number of rows
    //  n in this case
    for (int i=0; i<n; i++)
    {
        // inner loop to handle number spaces
        // values changing acc. to requirement
        for (int j=0; j<k; j++)
            cout <<" ";
 
        // decrementing k after each loop
        k = k - 1;
 
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for (int j=0; j<=i; j++ )
        {
            // printing stars
            cout << "* ";
        }
 
        // ending line after each row
        cout << endl;
    }
}
 
/*
 * print like following:
 *     1
 *     2 2
 *     3 3 3
 *     4 4 4 4
 *     5 5 5 5 5
 */
void numpat(int n)
{
    // initializing starting number
    int num = 1;
 
    // outer loop to handle number of rows
    //  n in this case
    for (int i=0; i<n; i++)
    {
        // re assigning num
        num = 1;
 
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for (int j=0; j<=i; j++ )
        {
            // printing number
            cout << num << " ";
 
            // incrementing number at each column
            num = num + 1;
        }
 
        // ending line after each row
        cout << endl;
    }
}

/*
 * print like following:
 *     1
 *     2  3
 *     4  5  6
 *     7  8  9  10
 *     11 12 13 14 15
 */
void numpat_without_reassigning(int n)
{
    // initialising starting number
    int num = 1;
 
    // outer loop to handle number of rows
    //  n in this case
    for (int i=0; i<n; i++)
    {
        // without re assigning num
        // num = 1;
 
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for (int j=0; j<=i; j++ )
        {
            // printing number
            cout << num << " ";
 
            // incrementing number at each column
            num = num + 1;
        }
 
        // ending line after each row
        cout << endl;
    }
}

/*
 * print like following:
 *     a
 *     b b
 *     c c c
 *     d d d d
 *     e e e e e
 */
void alphapat(int n)
{
    // initializing value corresponding to 'A'
    // ASCII value
    int num = 97;
 
    // outer loop to handle number of rows
    //  n in this case
    for (int i=0; i<n; i++)
    {
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for (int j=0; j<=i; j++ )
        {
            // explicitly converting to char
            char ch = char(num);
 
            // printing char value
            cout << ch << " ";
        }
 
        // incrementing number
        num = num + 1;
 
        // ending line after each row
        cout << endl;
    }
}

/*
 * print like following:
 *     A
 *     B C
 *     D E F
 *     G H I J
 *     K L M N O
 */
void contalpha(int n)
{
    // initializing value corresponding to 'A'
    // ASCII value
    int num = 65;
 
    // outer loop to handle number of rows
    //  n in this case
    for (int i=0; i<n; i++)
    {
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for (int j=0; j<=i; j++ )
        {
            // explicitely converting to char
            char ch = char(num);
 
            // printing char value
            cout << ch << " ";
 
            // incrementing number at each column
            num = num + 1;
        }
 
        // ending line after each row
        cout << endl;
    }
}

// Driver Function
int main()
{
    int n = 6;
    simple_pypart(n);
    simple_pypart_reverse180(n);
    triangle(n);
    numpat(n);
    numpat_without_reassigning(n);
    alphapat(n);
    contalpha(n);
    return 0;
}
