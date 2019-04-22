# Team BetterHash Implementation of DSA in C/C++
### Danny Kang, Manu Patil

## Goal
Our initial goal was to dig deeper into hash functions and try to come up with better hashing algorithm for data, more specifically, strings. However, we came to realize that there are deep cryptography related into those hashes so we decided to end with making testing program for different hash functions to look at collision rate and time to run each hashes. Now, we are moving to next step, which is learning about implementation of dynamically programmed recursion and also memoization to reduce time complexity of those implementations. The lower bound to achieve would be implementing algorithms such as fibonacci or solving some interestingly challenging problems about dynamic programming. We are also excited to have weekly study sessions to go over these concepts and solve those problems. 
 
## Learning Goals
**Understanding DSA better**: Our general learning goals were to learn more about data structures and algorithms in C. We initially intended to implement a couple different data structures. By implementing several different data structures and algorithms ( such as hash tables, graph data structures, recursion). We hoped to gain a deeper understanding of this content and we have succeeded so far. We hope to continue our progress for the second half of the project. <br>

**Understanding C better**: We hoped to gain more skills and knowledge in the language C itself while implementing above data structures and algorithms. So far, we feel more comfortable working with pointers and C specific syntaxes. <br>

**Increase problem solving technique/ability**: We decided that solving problems related to dynamic programming and recursion would significantly boost our problem approach/solving ability. There are tons of problems online that we could tackle and good things about this project is that we can work on those together to improve on our communication/solving skills.
 
 
## Progress
**Testing hash functions**: Danny<br>
I wrote test.c program that uses several hash functions to hash data of randomly generated strings and count the number of collisions to assess the efficiency of each hashing algorithm. We have found certain hashing technique to be far superior over others. Most of them were done by assigning int value to variable ‘hash’. The value of ‘hash’ is determined mostly by bit operations and some additions and multiplications. The worst hashing function that we found was using XOR bit operator within a while loop that iterates over integers.

**Visualization of test**: Manu<br>
The first visualization of the data was done using python. I mimicked the graph used for the cache example from a couple classes ago. With this visualization I was able to complete the speed testing API. One can see in the visualization how the different hash functions work over different sized sets of data. I am still working on a bit of refinement of this as i am not satisfied with the initial implementation of it. I am also trying to implement a couple more time consuming hash algorithms to better contrast the data. 

**Implementation of recursion/solving problems**: Danny<br>
After talking to our instructor, I got excited about implementing recursion and famous algorithms in C as much as time allows. Some initial ideas are Fibonacci and Tower of Hanoi. Starting from there, I would also apply concepts of memoization and dynamic programming to make the implementation more efficient in terms of time complexity. When these are done, I would be happy to move on to more challenging problems related to dynamic programming that could be implemented in C within reasonable amount of time and devotion. 

**Graph Data Structure**: Manu<br>
I have made some basic progress in implementing a graph data structure. The back end implementation is relatively straight-forward. I have decided to spend more of my time developing a visualization of the structure to better see how path finding algorithms work out with it. 


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

## Future Steps

Manu<br> 
I am working on refining the hash function testing library and also developing a graph data structure visualizer. This task will be completed when the graph data structure can visualize different path finding algorithms at work. I am currently exploring the GTK library and attempting to come up with an effective way to visualize a graph data structure. 
I am also attempting to create more clever ways visualize the effectiveness vs. efficiency of the hash functions.

Danny<br>
I will continue working on implementing algorithms and solving problems. <br>

**link to our trello board**: <br>
https://trello.com/b/bGoEATK4/betterhash
