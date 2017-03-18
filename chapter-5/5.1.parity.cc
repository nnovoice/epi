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
 *      int get_parity(unsigned long long int * plli, int n)
 *
 * output of the method
 *      int - 0 or 1 which denotes the parity
 *          -1 if error
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
#include <unordered_map>
#include <iomanip>
using namespace std;

typedef unsigned long long int ULLI;
unordered_map<int, int> amap;
const int MAX = 256;
int parity_cache[MAX];

int get_num_bits_set(ULLI v) 
{
    int count = 0;
    ULLI a = 0;
    //cout << "num= " << v << endl;
    while (v) {
        a = v & ~(v - 1); // get the last bit that is on
        //cout << "a= " << a << endl;
        if (a > 0) ++count;
        v -= a;
    }
    //cout << "count= " << count << endl;
    return count;
}

int get_parity_bruteforce(ULLI * plli, int n)
{
    int count = 0;
    ULLI t = 0, a = 0;
    for (int i = 0; i < n; ++i) {
        count += get_num_bits_set(plli[i]);
        // cout << "count= " << count << endl;
    }
    
    if (count % 2 == 0)
        return 0;

    return 1;
}

int build_parity_cache()
{
    int count = 0;
    for (int i = 0; i < MAX; ++i) {
        count = get_num_bits_set(i);
        parity_cache[i] = count;
        //cout << "parity_cache[" << i << "]=" << count << endl;
    }
}

int get_parity_optimized(ULLI * plli, int n)
{
    int count = 0;
    ULLI t = 0;
    unsigned char *pc = 0;
    unsigned int m = 0;
    
    for (int i = 0; i < n; ++i) {
        t = plli[i];
        //cout << "num = ";
        //cout << std::hex << std::uppercase << t << endl;
        pc = (unsigned char *)&t;
        for (int j = 0; j < 8; ++j, pc++) {
            m = (unsigned int)*pc;
            count += parity_cache[m];
            //cout << "*pc=" << *pc << "int(*pc)= " << (unsigned int)*pc << " m= " << m << " parity_cache val= " << parity_cache[m] << endl;
        }
        //cout << "optimized parity: count= " << count << endl;
    }
    
    if (count % 2 == 0)
        return 0;

    return 1;
}

int get_parity(ULLI * plli, int n)
{
    //cout << sizeof(ULLI) << endl;
    //cout << "get_parity called with " << n << " numbers." << endl;
    int bruteforce_ret = get_parity_bruteforce(plli, n);
    int optimized_ret = get_parity_optimized(plli, n);
    //cout << "bruteforce_ret= " << bruteforce_ret << " optimzed_ret= " << optimized_ret << endl;
    assert (optimized_ret == bruteforce_ret);
    return optimized_ret;
}

int tests()
{
    ULLI* parr = new ULLI[1];
    int res = 0;

    parr[0] = 0;
    res = get_parity(parr, 1);
    assert (res == 0);
    delete parr;

    ULLI b[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    res = get_parity(b, sizeof(b)/sizeof(ULLI));
    assert (res == 0);

    ULLI arr [2] = {1, 3};
    res = get_parity(arr, sizeof(arr)/sizeof(ULLI));
    assert(res == 1);

    parr = new ULLI[5];
    parr[0] = 1;
    parr[1] = 0x1FFFFFFFFFFFFFFF;
    parr[2] = 0x0000000000000007;
    parr[3] = 0x0111111111111111;
    parr[4] = 0xFFFFFFFFFFFFFFF1;
    res = get_parity(parr, 5);
    assert (res == 1);
    delete parr;
}

int main()
{
    build_parity_cache();
    tests();
    return 0;
}

