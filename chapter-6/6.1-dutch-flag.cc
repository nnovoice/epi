/* write a function that takes an array A of length n and an index i into A,
 * and rearranges the array such that all elements less than A[i] appear
 * first, followed by elements equal to A[i], followed by elements greater
 * that A[i]. Algorithm should have O(1) space complexity and O(n) time
 * complexity.
 *
 * Questions:
 *  - don't know what to ask
 *
 * Assumptions:
 *
 * Inputs to the method:
 *      - array, length, one index
 * Outputs
 *      - array {e0<A[i]...ei==A[i]...ek>A[i]}
 *
 * Test cases:
 *      - random values
 *      - all sorted in descending order
 *      - all sorted in ascending order
  */

#include <iostream>
using namespace std;


void bruteforce_partition(int * a, int n, int k)
{
    // p means the pivot element
    int i = 0, j = n -1, p = a[k];
    
    //move elements > p to the right
    while (i < j) {
        for (; i < j; ++i) {
            if (a[i] > p) break;
        }
        for (; j > i; --j) {
            if (a[j] <= p) break;
        }
        if (i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            
            ++i;
            --j;
        }
    }
    
    //move elements < p to the left
    i = 0;
    
    // j will be the last element that is less than or equal to p
    for (j = 0; a[j] <= p; ++j)
        ;
    --j;
    
    while (i < j) {
        for (; i < j; ++i) {
            if (a[i] == p) break;
        }
        for (; j > i; --j) {
            if (a[j] < p) break;
        }
        if (i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            
            ++i;
            --j;
        }
    }
    
    return;
}

void print_array(int * a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << "\t";
    cout << endl;
}

int tests()
{
    int b0[16] = {11, 12, 2, 5, 4, 5, -1, 700, -8, 9, 101, 1, 5, 3, 4, 5};
    print_array(b0, sizeof(b0)/sizeof(int));
    bruteforce_partition(b0, sizeof(b0)/sizeof(int), 3);
    print_array(b0, sizeof(b0)/sizeof(int));
    cout << endl;
    
    int b1[16] = {11, 12, 0, 1, 6, 20, 6, 20, 3, -1, 100, 0, 6, 5, 10, 5};
    print_array(b1, sizeof(b1)/sizeof(int));
    bruteforce_partition(b1, sizeof(b1)/sizeof(int), 4);
    print_array(b1, sizeof(b1)/sizeof(int));
    cout << endl;
    
    int b2[16] = {-4, -3, -2, -1, 6, 7, 7, 8, 9, 10, 11, 12, 16, 25, 100, 105};
    print_array(b2, sizeof(b2)/sizeof(int));
    bruteforce_partition(b2, sizeof(b2)/sizeof(int), 4);
    print_array(b2, sizeof(b2)/sizeof(int));
    cout << endl;
    
    
    int b3[16] = {111, 102, 100, 91, 86, 70, 66, 50, 50, 49, 40, 40, 36, 35, 10, 5};
    print_array(b3, sizeof(b3)/sizeof(int));
    bruteforce_partition(b3, sizeof(b3)/sizeof(int), 4);
    print_array(b3, sizeof(b3)/sizeof(int));
    cout << endl;
    
    return 0; 
}

int main()
{
    tests();
    return 0;
}
