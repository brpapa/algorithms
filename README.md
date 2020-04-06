Access my public [**notebook**](https://www.notion.so/brnpapa/icpc-notebook-0355e05508e9470fb065801e277f0c6c), a Notion workspace where I do my notes while studying and coding general-purpose algorithms. The book I use and recommend for studying is "Competitive Programming 3: The new lower bound of programming contests" by Steven Halim.

<p align="center">Feel free to follow my progress on my online judge profiles:</p>

<p align="center">
<a href="https://uhunt.onlinejudge.org/id/1094350"><img src="https://img.shields.io/static/v1?label=uva&message=70&color=red&style=flat-square"></a>
<a href="https://codeforces.com/profile/brnpapa"><img src="https://img.shields.io/static/v1?label=codeforces&message=54&color=red&style=flat-square"></a>
<a href="https://www.urionlinejudge.com.br/judge/pt/users/statistics/310281"><img src="https://img.shields.io/static/v1?label=uri&message=70&color=red&style=flat-square"></a>
<a href="https://www.spoj.com/users/brnpapa"><img src="https://img.shields.io/static/v1?label=spoj&message=26&color=red&style=flat-square"></a>
</p>
<br/>

<h1 align="center">Solutions categorized into themes</h1>

- [#greedy](#greedy)
- [#dynamic-programming](#dynamic-programming)
- [#math](#math)
- [#searching](#searching)
- [#graphs](#graphs)
- [#brute-force](#brute-force)
- [#ad-hoc](#ad-hoc)


## ad-hoc
- **implementation**
	- 📙 [codeforces/1296-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1296-C.cpp)  → maps each position of the robot with the string index, and check if a new position has already been mapped before

## brute force
- **iterative**
	- **all subsets**
		- 📗 [uva/12455](https://github.com/brnpapa/competitive-programming/blob/master/uva/12455.cpp)  → use bitmasks
- **recursive backtracking**
	- 📗 [uva/10344](https://github.com/brnpapa/competitive-programming/blob/master/uva/10344.cpp): `check if some arithmetic expression of 5 given numbers will result in 23`  → check all combination of operators for each permutation of the given numbers
	- **n-queens**
		- 📙 [uva/11195](https://github.com/brnpapa/competitive-programming/blob/master/uva/11195.cpp)  → use bitmasks

## graphs
- **traversal**
	- 📗 [uva/11831](https://github.com/brnpapa/competitive-programming/blob/master/uva/11831.cpp)  → consider grid as an implicit graph and walk through it, or just rotate the robot, for each received instruction
	- 📙 [uva/11906](https://github.com/brnpapa/competitive-programming/blob/master/uva/11906.cpp)  → consider grid as an implicit graph and walk through it avoiding redundant positions (nr, nc)
	- **flood fill**
		- 📕 [uva/1103](https://github.com/brnpapa/competitive-programming/blob/master/uva/1103.cpp)  → consider each pixel as a vertex of an implicit graph, then identify each hieroglyph counting the number of white CCs within it
	- **depth-first search (DFS)**
		- 📗 [codeforces/104-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/104-C.cpp): `check if the given undirected graph can be represented as a set of three or more rooted trees, whose roots are connected by a simple cycle`  → check if the graph is connective and has only one cycle
- **shortest path**
	- **dijkstra**
		- 📕 [uva/11367](https://github.com/brnpapa/competitive-programming/blob/master/uva/11367.cpp)  → find the shortest path on space-state graph, where each vertex represent a city and a level of car fuel
- **specials**
	- **tree traversal**
		- 📗 [spoj/ONP](https://github.com/brnpapa/competitive-programming/blob/master/spoj/ONP.cpp): `transform the algebraic expression with brackets into reverse polish notation (RPN) `  → consider the given expression as the in-order traversal in a binary tree, then print post-order traversal recursively without building the tree

## searching
- **binary search**
	- 📙 [codeforces/1324-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-D.cpp): `given the A and B arrays, count the quantity of pairs i < j such that A[i]+A[j] > B[i]+B[j]`  → diff being the A-B array, count, for all i in [0 .. N-2], how many times -diff[i] < diff[j], for all j in [i+1 .. N-1]
	- 📙 [codeforces/91-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/91-B.cpp): `given the array a, compute the array d, where d[i] = j-(i+1) for the max j such that a[j] < a[i]`  → apply binary search on preprocessed array mn, filled from right to left
	- 📗 [spoj/PAIRS1](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PAIRS1.cpp): `given the A array, count the quantity of pairs i < j such that A[i]-A[j] == K`  → search on the sorted array A by the A[n]+K, for all n in [0 .. N-1]
- **segment tree**
	- **lazy propagation**
		- 📙 [uri/2658](https://github.com/brnpapa/competitive-programming/blob/master/uri/2658.cpp)  → build a segment tree for RSQ, but store an array of size 9 in tree[v], where tree[v][n] indicates the frequency that each note n appears in that interval
		- 📙 [uva/11402](https://github.com/brnpapa/competitive-programming/blob/master/uva/11402.cpp)  → build a segment tree for RSQ, but keep in lazy[v] the type of pending operation to be performed in that interval of A

## math
- **ad-hoc**
	- **finding pattern**
		- 📕 [uva/11718](https://github.com/brnpapa/competitive-programming/blob/master/uva/11718.cpp)  → compute K * N^(K-1) * sumA using fast power mod
		- 📙 [codeforces/1092-D1](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1092-D1.cpp)  → remove adjacent ones whose absolute difference is even (using a stack)
	- **sequences**
		- 📕 [uva/10706](https://github.com/brnpapa/competitive-programming/blob/master/uva/10706.cpp)  → pre-process the number sequence and f(k), so use binary search on f
		- 📙 [uva/264](https://github.com/brnpapa/competitive-programming/blob/master/uva/264.cpp)  → use binary search on preprocessed f(x)=f(x-1)+x-1
- **number theory**
	- **prime numbers**
		- **sieve of eratosthenes**
			- 📙 [spoj/PRIME1](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PRIME1.cpp): `print all primes p in [m .. n], 0 <= m <= n <= 10^9, n-m <= 10^5`  → sieve + prime checking
			- 📙 [uva/10539](https://github.com/brnpapa/competitive-programming/blob/master/uva/10539.cpp): `compute the quantity of non-prime numbers in [lo .. hi] which are divisible by only a single prime number, 0 < lo <= hi < 10^12`  → generate all powers of each prime number
			- 📗 [spoj/AMR11E](https://github.com/brnpapa/competitive-programming/blob/master/spoj/AMR11E.cpp): `print the n-th number that has at least 3 distinct prime factors`  → use modified sieve
		- **prime factorization**
			- 📕 [uri/2661](https://github.com/brnpapa/competitive-programming/blob/master/uri/2661.cpp): `compute the number of divisors of n that can be written as the product of two or more distinct prime numbers (without repetition), 1 <= n <= 10^12`  → note that the product of any combination of prime factors of a number will always be a divisor of that number
			- 📙 [uva/10139](https://github.com/brnpapa/competitive-programming/blob/master/uva/10139.cpp): `do n! is divisible by m?`  → check if the prime factors of m are contained in the prime factors of n!
- **game theory**
	- **minimax**
		- 📙 [uva/12484](https://github.com/brnpapa/competitive-programming/blob/master/uva/12484.cpp): `alberto and wanderley take one of two cards at the edges of the cards sequence, alberto want maximize it`  → fill memo table in row-major order
		- **optimized**
			- 📙 [uva/847](https://github.com/brnpapa/competitive-programming/blob/master/uva/847.cpp): `multiplication game`  → note that if Stan always multiply by 9 and Ollie by 2, it's still an optimal solution
- **combinatorics**
	- **fibonacci numbers**
		- 📙 [uva/10334](https://github.com/brnpapa/competitive-programming/blob/master/uva/10334.py)  → compute (n+2)-th fibonnaci number
	- **binomial coefficient**
		- 📕 [uri/2972](https://github.com/brnpapa/competitive-programming/blob/master/uri/2972.cpp): `calculate the sum of C(N, k)%2 for all k in [0 .. n], i.e., how many odd combinations of k heads between n coins there are`  → just compute 2^qtyBitsOn(n)

## dynamic programming
- 📙 [uva/10651](https://github.com/brnpapa/competitive-programming/blob/master/uva/10651.cpp)  → use bitmasks
- **longest common subsequence (LCS)**
	- 📗 [spoj/IOIPALIN](https://github.com/brnpapa/competitive-programming/blob/master/spoj/IOIPALIN.cpp): `given a string, determine the minimal quantity of characters to be inserted into it in order to obtain a palindrome`  → compute length of string minus lcs between string and reversed string
- **max 1D range sum**
	- 📙 [uva/787](https://github.com/brnpapa/competitive-programming/blob/master/uva/787.py): `max 1D range product query`  → compute for each sub-range without 0
- **0-1 knapsack**
	- **subset sum**
		- 📗 [uva/357](https://github.com/brnpapa/competitive-programming/blob/master/uva/357.cpp): `counting ways to represent S cents`  → subset sum with possible repetition
		- 📙 [uva/10616](https://github.com/brnpapa/competitive-programming/blob/master/uva/10616.cpp): `given an array of size N, count how many subsets of size M have their sum divisible by D`  → use module arithmetic
- **longest increasing subsequence (LIS)**
	- 📙 [uva/10131](https://github.com/brnpapa/competitive-programming/blob/master/uva/10131.cpp)  → sort elephants based on increasing kg, then apply LDS on iq
	- 📙 [uva/11456](https://github.com/brnpapa/competitive-programming/blob/master/uva/11456.cpp)  → find the max(lis[i]+lds[i]-1) for all i in [0 .. N-1], being i where the subsequence starts
- **max 2D range sum**
	- 📕 [uva/10755](https://github.com/brnpapa/competitive-programming/blob/master/uva/10755.cpp): `max 3D range sum`  → use max 2D range sum in two of the three dimensions and max 1D range sum (kadane) on the third dimension

## greedy
- 📗 [codeforces/1324-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-B.cpp): `given a sequence of integers, is there a subsequence palindrome of size 3?`  → check if there are two equal non-adjacent numbers using brute force
- 📗 [codeforces/1324-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-C.cpp)  → note that it's unnecessary jump to the left, so to minimize d, just jump between the nearest 'R' cells
