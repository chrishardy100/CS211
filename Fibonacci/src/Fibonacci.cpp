/*
* 
* This program produces the fibonacci sequence up to the iteration
* defined by size
* 
* @author Christopher Hardy
* 
* 
*/

#include <iostream>
using namespace std;

const int size = 47;  //size of sequence
int fib(int n){
    //static so memo is remembered every call
    static int memo[size]{ 0 };
    //base case
    if (n == 1 || n == 2)
        return 1;
    //cheack value has been computed
    if (memo[n] > 0)
        return memo[n];

    //recursive step
    return memo[n] = fib(n - 2) + fib(n - 1);
}

int main()
{
    for (int i = 1; i < size; ++i)
    {
        cout << i << "- " << fib(i) << endl;
    }
}
