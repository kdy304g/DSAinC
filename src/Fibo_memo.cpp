#include <bits/stdc++.h> 
using namespace std; 
int term[1000]; 
// Fibonacci Series using memoized Recursion 
int fib(int n) 
{ 
    // base case 
    if (n <= 1) 
        return n; 
  
    // if fib(n) has already been computed 
    // we do not do further recursive calls 
    // and hence reduce the number of repeated 
    // work 
    if (term[n] != 0) 
        return term[n]; 
  
    else { 
  
        // store the computed value of fib(n) 
        // in an array term at index n to 
        // so that it does not needs to be 
        // precomputed again 
        term[n] = fib(n - 1) + fib(n - 2); 
  
        return term[n]; 
    } 
} 
  
int main() 
{ 
    int n = 20; 
    printf("%d\n", fib(n)); 
    return 0; 
} 