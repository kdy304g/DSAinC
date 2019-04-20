#include <bits/stdc++.h> 
using namespace std; 
  
// Fibonacci Series using Recursion 
int fib(int n) 
{ 
  
    // Base case 
    if (n <= 1) 
        return n; 
  
    // recursive calls 
    return fib(n - 1) + fib(n - 2); 
} 
  
int main() 
{ 
    int n = 20; 
    printf("%d\n", fib(n)); 
    return 0; 
} 