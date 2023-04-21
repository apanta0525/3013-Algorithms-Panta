
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


# Strassen’s Matrix Multiplication

### Table of Contents
  1. Problem Statement
  2. Strassen’s Submatrix
     * Pseudocode of Strassen’s multiplication
     * Complexity
     * C++ Implementation
  3. Applications

## 1. **Problem Statement**

Why Strassen’s matrix algorithm is better than normal matrix multiplication and How to multiply two matrices using Strassen’s matrix multiplication algorithm?

So the main idea is to use the divide and conquer technique in this algorithm – *divide matrix A & matrix B into 8 submatrices and then recursively compute the submatrices of C*
  
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
  
Using the Master Theorem with **T(n) = 8T(n/2) + O(n^2)** we still get a runtime of **O(n^3)**.

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
  ## 2. Strassen’s Submatrix
  
  ```ruby 
  p5+p4-p2+p6 = (a+d)*(e+h) + d*(g-e) - (a+b)*h + (b-d)*(g+h)
            = (ae+de+ah+dh) + (dg-de) - (ah+bh) + (bg-dg+bh-dh)
            = ae+bg
 p1+p2 = a*(f-h) + (a+b)*h
       = (af-ah) + (ah+bh)
       = af+bh
 p3+p4 = (c+d)*e + d*(g-e)
       = (ce+de) + (dg-de)
       = ce+dg 
 p1+p5-p3-p7 = a*(f-h) + (a+d)*(e+h) - (c+d)*e - (a-c)*(e+f)
             = (af-ah) + (ae+de+ah+dh) -(ce+de) - (ae-ce+af-cf)
             = cf+dh
  ```

The time complexity using the Master Theorem.

**T(n) = 7T(n/2) + O(n^2) = O(n^log(7))** runtime.

Approximately O(n^2.8074) which is better than O(n^3)

### Pseudocode of Strassen’s multiplication
``` 
 * Divide matrix A and matrix B in 4 sub-matrices of size N/2 x N/2 as shown in the above diagram.
 * Calculate the 7 matrix multiplications recursively.
 * Compute the submatrices of C.
 * Combine these submatricies into our new matrix C
````
### Complexity
``` 
  * Worst case time complexity: **Θ(n^2.8074)**
  * Best case time complexity: **Θ(1)**
  * Space complexity: **Θ(logn)**
```

### C++ Implementation
```ruby
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int nextpowerof2(int k){
    return pow(2, int(ceil(log2(k))));
}

void display(vector< vector<int>> &matrix, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j != 0){
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void Strassen_algorithmA(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    //base case
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int new_size = size / 2;
        vector<int> z(new_size);
        vector<vector<int>>
            a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
            b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
            c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
            p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
            p5(new_size, z), p6(new_size, z), p7(new_size, z),
            aResult(new_size, z), bResult(new_size, z);

int i, j;

//dividing the matrices into sub-matrices:
for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_size];
                a21[i][j] = A[i + new_size][j];
                a22[i][j] = A[i + new_size][j + new_size];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_size];
                b21[i][j] = B[i + new_size][j];
                b22[i][j] = B[i + new_size][j + new_size];
            }
}

// Calculating p1 to p7:

        add(a11, a22, aResult, new_size);     // a11 + a22
        add(b11, b22, bResult, new_size);    // b11 + b22
        Strassen_algorithmA(aResult, bResult, p1, new_size); 
        // p1 = (a11+a22) * (b11+b22)

        add(a21, a22, aResult, new_size); // a21 + a22
        Strassen_algorithmA(aResult, b11, p2, new_size);
        // p2 = (a21+a22) * (b11)

        sub(b12, b22, bResult, new_size);      // b12 - b22
        Strassen_algorithmA(a11, bResult, p3, new_size);
        // p3 = (a11) * (b12 - b22)

        sub(b21, b11, bResult, new_size);       // b21 - b11
        Strassen_algorithmA(a22, bResult, p4, new_size); 
        // p4 = (a22) * (b21 - b11)

        add(a11, a12, aResult, new_size);      // a11 + a12
        Strassen_algorithmA(aResult, b22, p5, new_size);
        // p5 = (a11+a12) * (b22)

        sub(a21, a11, aResult, new_size);      // a21 - a11
        add(b11, b12, bResult, new_size);               
        // b11 + b12
        Strassen_algorithmA(aResult, bResult, p6, new_size);
        // p6 = (a21-a11) * (b11+b12)

        sub(a12, a22, aResult, new_size);      // a12 - a22
        add(b21, b22, bResult, new_size);                
        // b21 + b22
        Strassen_algorithmA(aResult, bResult, p7, new_size);
        // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        add(p3, p5, c12, new_size); // c12 = p3 + p5
        add(p2, p4, c21, new_size); // c21 = p2 + p4

        add(p1, p4, aResult, new_size);       // p1 + p4
        add(aResult, p7, bResult, new_size);  // p1 + p4 + p7
        sub(bResult, p5, c11, new_size); // c11 = p1 + p4 - p5 + p7

        add(p1, p3, aResult, new_size);       // p1 + p3
        add(aResult, p6, bResult, new_size);  // p1 + p3 + p6
        sub(bResult, p2, c22, new_size); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + new_size] = c12[i][j];
                C[i + new_size][j] = c21[i][j];
                C[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}
void Strassen_algorithm(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b)
{  
/* Check to see if these matrices are already square and have dimensions of a power of 2. If not,
 * the matrices must be resized and padded with zeroes to meet this criteria. */
    int k = max({m, n, a, b});

    int s = nextpowerof2(k);

    vector<int> z(s);
    vector<vector<int>> Aa(s, z), Bb(s, z), Cc(s, z);

    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < a; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }
    Strassen_algorithmA(Aa, Bb, Cc, s);
    vector<int> temp1(b);
    vector<vector<int>> C(m, temp1);
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
    display(C, m, b);
}



int main() {
    // Your code goes here;
    vector<vector<int>> a = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> b = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
    Strassen_algorithm(a, b, 3, 3, 3, 3);
    return 0;
}

```

##Applications
Generally, Strassen’s Method is not preferred for practical applications for the following reasons.
  * The constants used in Strassen’s method are high and for a typical application Naive method works better.
  * For Sparse matrices, there are better methods especially designed for them.
  * The submatrices in recursion take extra space.
  * Because of the limited precision of computer arithmetic on noninteger values, larger errors accumulate in Strassen’s algorithm than in Naive Metho
