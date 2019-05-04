# Team BetterHash Implementation of DSA in C/C++
### Danny Kang, Manu Patil

## Goal
We started broadly by stating that ‘we want to implement data structures and algorithms in c’. The danger in such a non-specific goal is that either you end up getting lost as to what to do next or making the direction of the project unclear by attempting to accomplish too much things at the same time. We tried best to avoid this by consulting our instructor and making use of our trello board to assign crystal clear tasks to all members of the team. What we have accomplished throughout this project is 1) implement hash table and its hash functions and write a test program that compares the efficiency of them, 2) visualizing the efficiency/speed of hash functions and 3) solving intermediate level dynamic programming challenges that are available on-line. 
 
## Implementation
**Fibonacci sequence**:
We solved this problem to set the context for dynamic programming using recursion. We used the integer array that stores value of fib(n-1)+fib(n-2) to optimize our fibonacci program. 

**Longest Common Subsequence**: 
This is a famous problem in programming. Using a recursive function that takes two string and their lengths and iterates as the length of string argument decreases depending on existence of common character solves this problem. Without memoization, however, the time complexity of this program is horrible since there would be too many function calls. We created a 2D array that stores the value of functions to prevent this program from making needless function calls. As we increased the length of the string input for this program and compared with the one without memoization, runtime was significantly different. 

**Find maximum length Snake Sequence**:
This problem is about finding the longest length sequence from one location to another when given a grid of numbers that are in form of a matrix.  The rule of the sequence is that adjacent numbers must satisfy the condition: the number on the right or the number below it is +1 or -1 its value. For example, if the current location is (x, y) in the grid, next location could be either right i.e. (x, y+1) if that number is ± 1 ordown i.e. (x+1, y) if that number is ± 1.
For example,
9, 6, 5, 2
8, 7, 6, 5
7, 3, 1, 6
1, 1, 1, 7
In above grid, the longest snake sequence is: (9, 8, 7, 6, 5, 6, 7). Of course, there could be more than one longest sequence. <br>
We approached this problem in a divide and conquer manner. We wrote a function that finds the longest sequence by storing the result of subproblems in a 2D array and another function that finds the specific longest path. We used 2D array that stores maximum lengths leading up to each point and variables that contain maximum length and position of snake’s tail to optimize this program. Our program finds and prints the longest sequence that conform to rules stated above.


**Testing and visualization of hash functions**: 
There is no update on testing and visualization of hash functions.
We first explored different ways to visualize the efficacy of hash functions. We limited our search to strings for our exploration. The first method was to simply tally the number of collisions. This proved to be useful for a quick understanding of how good an algorithm was at spreading out data. The output of this test is shown below
```
hash1 result: 7763
hash2 result: 30
hash3 result: 16
hash4 result: 2
hash5 result: 67
hash6 result: 9933
effectiveness ranked...
2
16
30
67
7763
9933
```

The second test was evaluating the speed of the hashing algorithms over different sizes of data. When we visualized this, we saw negligible differences between each type of hash. We suspect that the order at which these calculations are happening is too small for the differences to effect the hashing performance.

![](https://raw.githubusercontent.com/kdy304g/SoftSysBetterHash/master/src/Speed.png)

For, the third and fourth test we decided to focus in on collision detection and other ways to further dive into other types of collision detection as the speed test didn’t result in very interesting data. First we compared hash values with respect to length of word. This worked to seperate a few of the worse off hashes, but for the higher efficacy ones, this still wasn’t enough. For the fourth test, we dove deeper into the distribution of the collisions to see if they occured specifically across any segments. The results of these two tests are shown below. 
![](https://raw.githubusercontent.com/kdy304g/SoftSysBetterHash/master/src/Hash%201%20Length.png)

![](https://github.com/kdy304g/SoftSysBetterHash/blob/master/src/Hash%201%20Distribution.png)

![](https://raw.githubusercontent.com/kdy304g/SoftSysBetterHash/master/src/Hash%206%20Length.png)

![](https://raw.githubusercontent.com/kdy304g/SoftSysBetterHash/master/src/Hash%206%20Distribution.png)

An additional note about our API, is that it is set up to test any new hashing functions as well. They can simply be added to hash.c and hash.h and the rest of the tests need not be changed for these new functions to be evaluated as well. 


## Outcome
We as a team believe that we reached our goals pretty well. We succeeded in increasing our knowledge with respect to data structures and algorithms in C. While data structures or alorithms are not something purely limited to C by any nature, we found that given the opputunity to program them in C required a much cleaner understanding of how these features operate. Furthermore, having such a fast set of resources to explore, we were able to satisfy our curiosities with this subject. Overall, we learned quite a bit and are happy with how this project played out.

##Future Steps
The two largest flaws of this project were the time that was required to do the calculations and the visualization of the data. In a future iteration, the we could refine the algorithms to take less time potentially utilizing threads or other multiprocessing schemes. In terms of visualizing, the group spent about two weeks struggling with GTK in an attempt to visualize in C. This part of the project was put on hiatus when we decided that too much time was being devoted to this. In a future iteration, the team could develop a greater understanding of GTK and attempt to visualize the data effectively in C. 


## Resources
**Learning hash functions**:
- https://www.tutorialspoint.com/data_structures_algorithms/index.htm<br>
- https://en.wikipedia.org/wiki/Jenkins_hash_function<br>

**Visualizing result**:<br>
- https://www.gtk.org/<br>

**Recursion/dynamic programming with memoization**:<br>
- Think Python by Allen B. Downey<br>
- http://www.thelearningpoint.net/<br>

**Graph Data Structure**:<br>
- https://www.tutorialspoint.com/data_structures_algorithms/index.htm<br>

**link to our trello board**: <br>
https://trello.com/b/bGoEATK4/betterhash

