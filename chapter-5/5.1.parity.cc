/* problem statement - how would you go about computing the parity of very 
 * large number of 64-bit non-negative integers?
 * 
 * questions:
 *      - what is parity? parity is 1 if the number of bits set to 1 is odd, otherwise 0
 *         
 * usage or the area from where the problem arose
 *      - to compute 1-bit parity errors in storage and communication
 *                 
 * what do we have
 *       - non-negative integers
 *       - each being 64-bits
 *       - very large number of integers in a sequence
 *
 * assumptions
 *
 * inputs to the method
 *      unsigned int get_parity(unsigned long long int * plli, int n)
 *
 * output of the method
 *      unsigned int - which denotes the parity (either 0 or 1)
 * 
 * test cases
 *
 *
 *
 *
 * */

#include <iostream>
#include <limits>
#include <assert.h>
using namespace std;

typedef unsigned long long int ULLI;

int get_parity(ULLI * plli, int n)
{
    cout << sizeof(ULLI) << endl;
    cout << "get_parity called with " << n << " numbers." << endl;
    return -1;
}

int tests()
{
    ULLI* parr = new ULLI[1];
    int res = 0;

    parr[0] = 0;
    res = get_parity(parr, 1);
    assert (res == 0);
    delete parr;

    parr = new ULLI[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    res = get_parity(parr, 16);
    assert (res == 0);

    ULLI arr [2] = {1, 3};
    res = get_parity(arr, 2);
    assert(res == 1);
}

int main()
{
    tests();
    return 0;
}

