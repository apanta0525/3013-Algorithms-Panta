
## A04 - Commenting Code
### Aashish Panta 
### Description:

This program implements a class that allows an Array to be used just like an Queue.

### Files

|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   | [main.cpp](https://github.com/apanta0525/3013-Algorithms-Panta/blob/main/Assignments/A04/main.cpp) | Main driver of my Queue program . |
| 2 | [Banner.txt](https://github.com/apanta0525/3013-Algorithms-Panta/blob/main/Assignments/A04/Banner.txt) | Banner File |

### Instructions

- This program does not require any non standard libraries

### Example Command

- None for now.


## Strassen’s Matrix Multiplication

### Table of Contents
  1. Problem Statement
  2. Strassen’s Submatrix
  3. Pseudocode of Strassen’s multiplication
  4. Complexity
  5. C++ Implementation
  6. Applications

### 1. Problem Statement

Why Strassen’s matrix algorithm is better than normal matrix multiplication and How to multiply two matrices using Strassen’s matrix multiplication algorithm?

So the main idea is to use the divide and conquer technique in this algorithm – divide matrix A & matrix B into 8 submatrices and then recursively compute the submatrices of C.
  
```ruby
  Consider the following matrices A and B:

A = |a b|,  B = |e f| and we know A*B = matrix C = |ae+bg af+bh| 
    |c d|       |g h|                              |ce+dg cf+dh|

There will be 8 recursive calls:

a * e
b * g
a * f
b * h
c * e
d * g
c * f
d * h
  
```
The above strategy is the basic O(N^3) strategy.
  
Using the Master Theorem with T(n) = 8T(n/2) + O(n^2) we still get a runtime of O(n^3).

But Strassen came up with a solution where we don’t need 8 recursive calls but can be done in only 7 calls and some extra addition and subtraction operations.

Strassen’s 7 calls are as follows:

 ```ruby
a * (f - h)
(a + b) * h
(c + d) * e
d * (g - e)
(a + d) * (e + h)
(b - d) * (g + h)
(a - c) * (e + f)
  
```
  
Our new matrix C’s new quadrants
  ```ruby
  matrix C = |p5+p4-p2+p6    p1+p2   |
             |   p3+p4    p1+p5-p3-p7| 
  ```
  
