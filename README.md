Access my public [**notebook**](https://www.notion.so/brnpapa/icpc-notebook-0355e05508e9470fb065801e277f0c6c), a Notion workspace where I do my notes while studying and coding general-purpose algorithms. The book I recommend for studying is "Competitive Programming 3: The new lower bound of programming contests" by Steven Halim.

<p align="center">Feel free to follow my progress on my main online judge profiles:</p>

<p align="center">
<a href="https://uhunt.onlinejudge.org/id/1094350"><img src="https://img.shields.io/static/v1?label=uva&message=78&color=yellow&style=flat-square"></a>
<a href="https://codeforces.com/profile/brnpapa"><img src="https://img.shields.io/static/v1?label=codeforces&message=60&color=yellow&style=flat-square"></a>
<a href="https://www.urionlinejudge.com.br/judge/pt/users/statistics/310281"><img src="https://img.shields.io/static/v1?label=uri&message=74&color=yellow&style=flat-square"></a>
<a href="https://www.spoj.com/users/brnpapa"><img src="https://img.shields.io/static/v1?label=spoj&message=32&color=yellow&style=flat-square"></a>
</p>
<br/>

<h1 align="center">Solutions categorized into themes</h1>

- [#techniques](#techniques)
- [#greedy](#greedy)
- [#ad-hoc](#ad-hoc)
- [#math](#math)
- [#searching](#searching)
- [#computational-geometry](#computational-geometry)
- [#dynamic-programming](#dynamic-programming)
- [#divide-&-conquer](#divide-&-conquer)
- [#brute-force](#brute-force)
- [#graphs](#graphs)


## graphs
- **specials**
	- **tree traversal**
		- 📗 [spoj/ONP](https://github.com/brnpapa/competitive-programming/blob/master/spoj/ONP.cpp): `transform the algebraic expression with brackets into reverse polish notation (RPN) ` 
- **shortest path**
	- **all-pairs**
		- 📗 [uri/2372](https://github.com/brnpapa/competitive-programming/blob/master/uri/2372.cpp) 
	- **single-source**
		- **weighted graph**
			- 📙 [uva/10806](https://github.com/brnpapa/competitive-programming/blob/master/uva/10806.cpp): `find the global shortest path from 0 to V-1 (round trip), without repeting edges` 
			- 📙 [uri/1123](https://github.com/brnpapa/competitive-programming/blob/master/uri/1123.cpp) 
			- 📕 [uva/11367](https://github.com/brnpapa/competitive-programming/blob/master/uva/11367.cpp) 
		- **unweighted graph**
			- 📙 [icpc/2014-01-uva-12797](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2014-01-uva-12797.cpp) 
- **minimum spanning tree (MST)**
	- 📗 [uva/10034](https://github.com/brnpapa/competitive-programming/blob/master/uva/10034.cpp) 
- **traversal**
	- 📙 [uva/11906](https://github.com/brnpapa/competitive-programming/blob/master/uva/11906.cpp) 
	- 📙 [code-jam/2020-1A-pascal-walk-TLE](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2020-1A-pascal-walk-TLE.cpp) 
	- 📗 [uva/11831](https://github.com/brnpapa/competitive-programming/blob/master/uva/11831.cpp) 
	- 📙 [uva/12442](https://github.com/brnpapa/competitive-programming/blob/master/uva/12442.cpp): `given a graph with all vertices with out-degree 1, find the vertice that reaches the most vertices` 
	- **flood fill**
		- 📗 [uva/11094](https://github.com/brnpapa/competitive-programming/blob/master/uva/11094.cpp) 
		- 📕 [uva/1103](https://github.com/brnpapa/competitive-programming/blob/master/uva/1103.cpp) 
	- **topological sorting**
		- 📗 [uva/11060](https://github.com/brnpapa/competitive-programming/blob/master/uva/11060.cpp) 
	- **bipartite checking**
		- 📗 [uva/10004](https://github.com/brnpapa/competitive-programming/blob/master/uva/10004.cpp) 
	- **strongly connected components (SCC)**
		- 📙 [uva/11504](https://github.com/brnpapa/competitive-programming/blob/master/uva/11504.cpp): `count the number of SCCs without incoming edge from a vertex of another SCC` 
	- **depth-first search (DFS)**
		- 📙 [icpc/2019-01-uri-2965](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2019-01-uri-2965.cpp) 
		- 📗 [codeforces/104-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/104-C.cpp): `check if the given undirected graph can be represented as a set of three or more rooted trees, whose roots are connected by a simple cycle` 
	- **bridges and articulation points**
		- 📗 [uva/796](https://github.com/brnpapa/competitive-programming/blob/master/uva/796.cpp) 

## brute force
- **recursive backtracking**
	- 📙 [uva/10503](https://github.com/brnpapa/competitive-programming/blob/master/uva/10503.cpp): `given domino pieces, check if it is possible to arrive at a target piece from an initial piece using N intermediate pieces (possibly rotating them)` 
	- 📗 [spoj/MKJUMPS](https://github.com/brnpapa/competitive-programming/blob/master/spoj/MKJUMPS.cpp): `given an unweighted implicit graph, count the longest possible path` 
	- 📗 [code-jam/2020-QR-indicium-TLE](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2020-QR-indicium-TLE.cpp): `generate M, where M[i][j] is any value in [1 .. N] (2 <= N <= 5), but without repeting a value in same line or column, and with the sum of the main diagonal equal to K` 
	- 📗 [uva/10344](https://github.com/brnpapa/competitive-programming/blob/master/uva/10344.cpp): `check if some arithmetic expression of 5 given numbers will result in 23` 
	- **n-queens**
		- 📙 [uva/11195](https://github.com/brnpapa/competitive-programming/blob/master/uva/11195.cpp) 
	- **sudoku**
		- 📗 [uva/989](https://github.com/brnpapa/competitive-programming/blob/master/uva/989.cpp) 
	- **pruned permutations**
		- 📗 [spoj/BTCK](https://github.com/brnpapa/competitive-programming/blob/master/spoj/BTCK.cpp) 
		- 📙 [uva/524](https://github.com/brnpapa/competitive-programming/blob/master/uva/524.cpp) 
- **iterative**
	- 📗 [uva/725](https://github.com/brnpapa/competitive-programming/blob/master/uva/725.cpp) 
	- 📙 [icpc/2014-01-uva-12792](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2014-01-uva-12792.cpp): `simulation` 
	- 📗 [uva/10360](https://github.com/brnpapa/competitive-programming/blob/master/uva/10360.cpp) 
	- 📗 [uva/628](https://github.com/brnpapa/competitive-programming/blob/master/uva/628.cpp) 
	- 📗 [icpc/2014-01-uva-12801](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2014-01-uva-12801.cpp) 
	- **all permutations**
		- 📗 [uva/750](https://github.com/brnpapa/competitive-programming/blob/master/uva/750.cpp) 
	- **all subsets**
		- 📗 [uva/12455](https://github.com/brnpapa/competitive-programming/blob/master/uva/12455.cpp) 

## divide & conquer
- 📙 [codeforces/768-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/768-B.cpp) 

## dynamic programming
- 📗 [uva/11450](https://github.com/brnpapa/competitive-programming/blob/master/uva/11450.cpp) 
- 📙 [uva/10721](https://github.com/brnpapa/competitive-programming/blob/master/uva/10721.cpp) 
- 📗 [uva/10337](https://github.com/brnpapa/competitive-programming/blob/master/uva/10337.cpp) 
- 📙 [codeforces/166-E](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/166-E.cpp) 
- 📗 [uva/10943](https://github.com/brnpapa/competitive-programming/blob/master/uva/10943.cpp) 
- 📗 [uva/10003](https://github.com/brnpapa/competitive-programming/blob/master/uva/10003.cpp) 
- 📙 [codeforces/1061-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1061-C.cpp) 
- 📙 [uva/10651](https://github.com/brnpapa/competitive-programming/blob/master/uva/10651.cpp) 
- **max 1D range sum**
	- 📙 [uva/787](https://github.com/brnpapa/competitive-programming/blob/master/uva/787.py): `max 1D range product query` 
	- **kadane**
		- 📗 [uva/12640](https://github.com/brnpapa/competitive-programming/blob/master/uva/12640.py): `find the max range sum considering the possibility of a sub-range of length 0` 
		- 📗 [uva/10684](https://github.com/brnpapa/competitive-programming/blob/master/uva/10684.cpp) 
		- 📗 [spoj/MAXSUMSU](https://github.com/brnpapa/competitive-programming/blob/master/spoj/MAXSUMSU.cpp) 
		- 📗 [codeforces/1285-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1285-B.cpp) 
- **digit**
	- 📙 [uri/1707](https://github.com/brnpapa/competitive-programming/blob/master/uri/1707.cpp): `given two numbers x and y, compute the sum of the decimal digits of the odd numbers in the range [min(x,y) .. max(x,y)]` 
	- 📗 [spoj/CPCRC1C](https://github.com/brnpapa/competitive-programming/blob/master/spoj/CPCRC1C.cpp) 
- **max 2D range sum**
	- 📗 [uva/108](https://github.com/brnpapa/competitive-programming/blob/master/uva/108.cpp) 
	- 📕 [uva/10755](https://github.com/brnpapa/competitive-programming/blob/master/uva/10755.cpp): `max 3D range sum` 
- **0-1 knapsack**
	- 📗 [uva/990](https://github.com/brnpapa/competitive-programming/blob/master/uva/990.cpp): `with recovering` 
	- 📙 [uri/1487](https://github.com/brnpapa/competitive-programming/blob/master/uri/1487.cpp) 
	- 📗 [uri/2498](https://github.com/brnpapa/competitive-programming/blob/master/uri/2498.cpp) 
	- 📗 [spoj/SCUBADIV](https://github.com/brnpapa/competitive-programming/blob/master/spoj/SCUBADIV.cpp) 
	- 📙 [uva/10261](https://github.com/brnpapa/competitive-programming/blob/master/uva/10261.cpp): `as if there were 2 knapsacks to fill at the same time; with recovering` 
	- 📗 [spoj/KNAPSACK](https://github.com/brnpapa/competitive-programming/blob/master/spoj/KNAPSACK.cpp) 
	- **subset sum**
		- 📙 [uva/10616](https://github.com/brnpapa/competitive-programming/blob/master/uva/10616.cpp): `given an array of size N, count how many subsets of size M have their sum divisible by D` 
		- 📙 [uva/11658](https://github.com/brnpapa/competitive-programming/blob/master/uva/11658.cpp): `find the smallest sum s of a subset of A, s >= S` 
		- 📗 [uri/1203](https://github.com/brnpapa/competitive-programming/blob/master/uri/1203.cpp): `check if any subset of A has a sum equal to K` 
		- 📗 [uva/624](https://github.com/brnpapa/competitive-programming/blob/master/uva/624.cpp): `print the subset of A with the max sum k, k <= K` 
		- **with repetition**
			- 📗 [uva/11137](https://github.com/brnpapa/competitive-programming/blob/master/uva/11137.cpp) 
			- 📗 [uva/357](https://github.com/brnpapa/competitive-programming/blob/master/uva/357.cpp) 
			- 📗 [uva/674](https://github.com/brnpapa/competitive-programming/blob/master/uva/674.cpp) 
- **longest increasing subsequence (LIS)**
	- 📙 [uri/1517](https://github.com/brnpapa/competitive-programming/blob/master/uri/1517.cpp) 
	- 📙 [uva/10131](https://github.com/brnpapa/competitive-programming/blob/master/uva/10131.cpp) 
	- 📙 [uva/11456](https://github.com/brnpapa/competitive-programming/blob/master/uva/11456.cpp) 
- **traveling salesman problem (TSP)**
	- 📗 [uva/10496](https://github.com/brnpapa/competitive-programming/blob/master/uva/10496.cpp) 
	- 📙 [uva/116](https://github.com/brnpapa/competitive-programming/blob/master/uva/116.cpp) 
- **longest common subsequence (LCS)**
	- 📗 [spoj/ADASEQEN](https://github.com/brnpapa/competitive-programming/blob/master/spoj/ADASEQEN.cpp) 
	- 📗 [spoj/IOIPALIN](https://github.com/brnpapa/competitive-programming/blob/master/spoj/IOIPALIN.cpp): `given a string, determine the minimal quantity of characters to be inserted into it in order to obtain a palindrome` 
- **coin change**
	- 📗 [codeforces/189-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/189-A.cpp) 
	- 📙 [uva/166](https://github.com/brnpapa/competitive-programming/blob/master/uva/166.cpp): `coin change with limited amount of coins + greedy coin change with unlimited amount of coins; I don't know why, but it works without memo` 
	- 📗 [uva/11407](https://github.com/brnpapa/competitive-programming/blob/master/uva/11407.cpp) 

## computational geometry
- 📗 [codeforces/659-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/659-D.cpp) 

## searching
- **binary search**
	- 📗 [spoj/PAIRS1](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PAIRS1.cpp): `given the A array, count the quantity of pairs i < j such that A[i]-A[j] == K` 
	- 📙 [codeforces/1284-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1284-B.cpp) 
	- 📙 [codeforces/91-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/91-B.cpp): `given the array a, compute the array d, where d[i] = j-(i+1) for the max j such that a[j] < a[i]` 
	- 📙 [codeforces/1324-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-D.cpp): `given the A and B arrays, count the quantity of pairs i < j such that A[i]+A[j] > B[i]+B[j]` 
	- **on answer**
		- 📙 [uva/12097](https://github.com/brnpapa/competitive-programming/blob/master/uva/12097.cpp) 
		- 📙 [spoj/AGGRCOW](https://github.com/brnpapa/competitive-programming/blob/master/spoj/AGGRCOW.cpp): `given an array A of size N (2 <= N <= 10^5), print the largest minimum distance between any two of C (C <= N) elements choosen any` 
		- 📙 [icpc/2019-01-uri-2973](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2019-01-uri-2973.cpp) 
		- 📙 [codeforces/1223-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1223-C.cpp) 
		- 📕 [codeforces/460-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/460-C.cpp) 
- **segment tree**
	- 📗 [codeforces/339-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/339-D.cpp) 
	- **lazy propagation**
		- 📙 [uri/2658](https://github.com/brnpapa/competitive-programming/blob/master/uri/2658.cpp) 
		- 📙 [uva/11402](https://github.com/brnpapa/competitive-programming/blob/master/uva/11402.cpp) 

## math
- **number theory**
	- 📙 [uri/2291](https://github.com/brnpapa/competitive-programming/blob/master/uri/2291.cpp): `print n-th divine number, the one that is equal to the sum of the sum of each divisor from 1 to n` 
	- **greatest common divisor (GCD)**
		- 📗 [codeforces/822-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/822-A.cpp) 
		- 📗 [codeforces/854-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/854-A.cpp): `given n, determine maximum possible proper (a < b) and irreducible fraction a/b such that a+b == n` 
	- **prime numbers**
		- 📗 [spoj/PRIONPRI](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PRIONPRI.cpp): `prime checking` 
		- **prime factorization**
			- 📗 [uva/10042](https://github.com/brnpapa/competitive-programming/blob/master/uva/10042.cpp) 
			- 📕 [uri/2661](https://github.com/brnpapa/competitive-programming/blob/master/uri/2661.cpp): `compute the number of divisors of n that can be written as the product of two or more distinct prime numbers (without repetition), 1 <= n <= 10^12` 
			- 📙 [uva/10139](https://github.com/brnpapa/competitive-programming/blob/master/uva/10139.cpp): `do n! is divisible by m?` 
		- **sieve of eratosthenes**
			- 📙 [codeforces/576-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/576-A.cpp) 
			- 📙 [uva/10539](https://github.com/brnpapa/competitive-programming/blob/master/uva/10539.cpp): `compute the quantity of non-prime numbers in [lo .. hi] which are divisible by only a single prime number, 0 < lo <= hi < 10^12` 
			- 📙 [spoj/PRIME1](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PRIME1.cpp): `print all primes p in [m .. n], 0 <= m <= n <= 10^9, n-m <= 10^5` 
			- 📗 [spoj/AMR11E](https://github.com/brnpapa/competitive-programming/blob/master/spoj/AMR11E.cpp): `print the n-th number that has at least 3 distinct prime factors` 
	- **module arithmetic**
		- 📗 [uva/10176](https://github.com/brnpapa/competitive-programming/blob/master/uva/10176.cpp): `is a given binary number of 100 digits divisible by 131071?` 
- **ad-hoc**
	- 📗 [uva/10346](https://github.com/brnpapa/competitive-programming/blob/master/uva/10346.cpp) 
	- 📗 [uva/10812](https://github.com/brnpapa/competitive-programming/blob/master/uva/10812.cpp) 
	- 📗 [uva/11875](https://github.com/brnpapa/competitive-programming/blob/master/uva/11875.cpp) 
	- 📗 [uva/11723](https://github.com/brnpapa/competitive-programming/blob/master/uva/11723.cpp) 
	- 📗 [codeforces/1042-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1042-A.cpp) 
	- 📗 [icpc/2014-01-uva-12791](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2014-01-uva-12791.cpp) 
	- **sequences**
		- 📙 [uva/264](https://github.com/brnpapa/competitive-programming/blob/master/uva/264.cpp) 
		- 📙 [uva/443](https://github.com/brnpapa/competitive-programming/blob/master/uva/443.cpp) 
		- 📕 [uva/10706](https://github.com/brnpapa/competitive-programming/blob/master/uva/10706.cpp) 
	- **finding pattern**
		- 📗 [codeforces/1221-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1221-C.cpp) 
		- 📕 [uva/11718](https://github.com/brnpapa/competitive-programming/blob/master/uva/11718.cpp) 
		- 📙 [codeforces/1092-D1](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1092-D1.cpp) 
		- 📗 [spoj/EIGHTS](https://github.com/brnpapa/competitive-programming/blob/master/spoj/EIGHTS.cpp) 
		- 📗 [codeforces/1324-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-A.cpp) 
		- 📙 [uva/10161](https://github.com/brnpapa/competitive-programming/blob/master/uva/10161.cpp) 
	- **arithmetic progression**
		- 📙 [uva/11254](https://github.com/brnpapa/competitive-programming/blob/master/uva/11254.cpp) 
- **combinatorics**
	- **fibonacci numbers**
		- 📙 [uva/10334](https://github.com/brnpapa/competitive-programming/blob/master/uva/10334.py) 
	- **binomial coefficient**
		- 📗 [codeforces/844-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/844-B.cpp) 
		- 📕 [icpc/2019-01-uri-2972](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2019-01-uri-2972.cpp): `calculate the sum of C(N, k)%2 for all k in [0 .. n], i.e., how many odd combinations of k heads between n coins there are` 
- **game theory**
	- **minimax**
		- 📙 [uva/12484](https://github.com/brnpapa/competitive-programming/blob/master/uva/12484.cpp): `alberto and wanderley take one of two cards at the edges of the cards sequence, alberto want maximize it` 
		- 📙 [uva/10111](https://github.com/brnpapa/competitive-programming/blob/master/uva/10111.cpp): `given a state of a tic tac toe board, check if X will win independent of the O movement` 
		- **optimized**
			- 📕 [uva/847](https://github.com/brnpapa/competitive-programming/blob/master/uva/847.cpp): `multiplication game` 

## ad-hoc
- 📗 [spoj/ADAQUEUE](https://github.com/brnpapa/competitive-programming/blob/master/spoj/ADAQUEUE.cpp) 
- 📗 [uri/2879](https://github.com/brnpapa/competitive-programming/blob/master/uri/2879.cpp) 
- 📗 [uri/2884](https://github.com/brnpapa/competitive-programming/blob/master/uri/2884.cpp) 
- 📗 [codeforces/151-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/151-A.cpp) 
- 📗 [code-jam/2020-1C-overexcited-fan](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2020-1C-overexcited-fan.cpp) 
- 📗 [codeforces/37-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/37-A.cpp) 
- 📗 [spoj/SBANK](https://github.com/brnpapa/competitive-programming/blob/master/spoj/SBANK.cpp) 
- 📕 [uri/1368](https://github.com/brnpapa/competitive-programming/blob/master/uri/1368.cpp) 
- 📗 [uri/2242](https://github.com/brnpapa/competitive-programming/blob/master/uri/2242.cpp) 
- 📗 [icpc/2019-02-uri-3024](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2019-02-uri-3024.cpp) 
- 📗 [codeforces/1220-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1220-A.cpp) 
- 📗 [icpc/2019-01-uri-2963](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2019-01-uri-2963.cpp) 
- 📗 [code-jam/2019-QR-foregone-solution](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2019-QR-foregone-solution.py) 
- 📗 [icpc/2014-01-uva-12798](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2014-01-uva-12798.cpp) 
- 📗 [uva/10141](https://github.com/brnpapa/competitive-programming/blob/master/uva/10141.cpp) 
- 📗 [codeforces/1285-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1285-A.cpp) 
- 📗 [spoj/EC_CONB](https://github.com/brnpapa/competitive-programming/blob/master/spoj/EC_CONB.cpp) 
- 📗 [uva/11799](https://github.com/brnpapa/competitive-programming/blob/master/uva/11799.cpp) 
- 📗 [icpc/2019-01-uri-2968](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2019-01-uri-2968.cpp) 
- 📗 [uva/12015](https://github.com/brnpapa/competitive-programming/blob/master/uva/12015.cpp) 
- **implementation**
	- 📗 [codeforces/110-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/110-A.cpp) 
	- 📙 [codeforces/519-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/519-C.cpp) 
	- 📗 [codeforces/81-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/81-A.cpp) 
	- 📗 [uri/1261](https://github.com/brnpapa/competitive-programming/blob/master/uri/1261.cpp) 
	- 📙 [icpc/2019-01-uri-2971](https://github.com/brnpapa/competitive-programming/blob/master/icpc/2019-01-uri-2971.cpp) 
	- 📙 [codeforces/1254-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1254-A.cpp) 
	- 📗 [uri/1763](https://github.com/brnpapa/competitive-programming/blob/master/uri/1763.cpp) 
	- 📗 [uri/1215](https://github.com/brnpapa/competitive-programming/blob/master/uri/1215.cpp) 
	- 📗 [uri/2593](https://github.com/brnpapa/competitive-programming/blob/master/uri/2593.cpp) 
	- 📙 [codeforces/1296-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1296-C.cpp) 
	- 📗 [codeforces/266-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/266-A.cpp) 
	- 📗 [spoj/GNY07D](https://github.com/brnpapa/competitive-programming/blob/master/spoj/GNY07D.cpp) 
	- 📗 [uri/1260](https://github.com/brnpapa/competitive-programming/blob/master/uri/1260.cpp) 
	- 📗 [codeforces/373-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/373-A.cpp) 
	- 📗 [codeforces/158-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/158-C.cpp) 
	- 📗 [codeforces/492-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/492-B.cpp) 
	- 📗 [codeforces/1284-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1284-A.cpp) 
	- 📗 [code-jam/2020-QR-vestigium](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2020-QR-vestigium.cpp) 
	- 📗 [uri/1975](https://github.com/brnpapa/competitive-programming/blob/master/uri/1975.cpp) 
	- 📗 [codeforces/811-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/811-B.cpp) 

## greedy
- 📗 [codeforces/1324-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-B.cpp): `given a sequence of integers, is there a subsequence palindrome of size 3?` 
- 📗 [codeforces/984-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/984-A.cpp) 
- 📗 [spoj/CADYDIST](https://github.com/brnpapa/competitive-programming/blob/master/spoj/CADYDIST.cpp) 
- 📗 [codeforces/1324-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-C.cpp) 
- 📗 [codeforces/1257-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1257-A.cpp) 
- 📗 [codeforces/275-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/275-C.cpp) 
- 📙 [codeforces/204-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/204-B.cpp): `given the two-sided values of N cards, what is the minimum number of turns in the cards so that at least half of them are the same front?; they are initially facing upwards` 
- 📗 [codeforces/1092-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1092-B.cpp) 
- 📗 [uva/10954](https://github.com/brnpapa/competitive-programming/blob/master/uva/10954.cpp): `add all` 
- 📗 [code-jam/2020-QR-parenting-partnering-returns](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2020-QR-parenting-partnering-returns.cpp) 
- 📗 [spoj/SNGINT](https://github.com/brnpapa/competitive-programming/blob/master/spoj/SNGINT.cpp): `given an integer n, find the smallest positive integer m > 0 such that the product of digits of m equals n` 
- 📗 [spoj/GERGOVIA](https://github.com/brnpapa/competitive-programming/blob/master/spoj/GERGOVIA.cpp) 
- 📗 [code-jam/2020-QR-nesting-depth](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2020-QR-nesting-depth.cpp) 
- 📗 [spoj/BUSYMAN](https://github.com/brnpapa/competitive-programming/blob/master/spoj/BUSYMAN.cpp): `compute the maximum number of activities (each with start and end times) that you can do without overlapping them (one at a time)` 
- 📙 [code-jam/2020-1A-pattern-matching](https://github.com/brnpapa/competitive-programming/blob/master/code-jam/2020-1A-pattern-matching.cpp) 
- 📙 [codeforces/1237-C2](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1237-C2.cpp) 
- 📗 [codeforces/545-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/545-D.cpp) 
- **interval covering**
	- 📙 [uva/10382](https://github.com/brnpapa/competitive-programming/blob/master/uva/10382.cpp): `uce the problem using pythagoras to one line` 
- **bipartite matching**
	- 📗 [uva/11292](https://github.com/brnpapa/competitive-programming/blob/master/uva/11292.cpp) 
- **loading balance**
	- 📗 [uva/11389](https://github.com/brnpapa/competitive-programming/blob/master/uva/11389.cpp) 
	- 📙 [uri/1055](https://github.com/brnpapa/competitive-programming/blob/master/uri/1055.cpp) 
- **restrict coin change**
	- 📗 [codeforces/1255-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1255-A.cpp) 
- **fast longest increasing subsequence (LIS)**
	- 📙 [uva/481](https://github.com/brnpapa/competitive-programming/blob/master/uva/481.cpp) 

## techniques
- **two pointers**
	- 📙 [codeforces/676-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/676-C.cpp) 
	- 📕 [codeforces/1041-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1041-D.cpp) 
	- 📗 [codeforces/6-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/6-C.cpp) 
	- 📙 [uva/967](https://github.com/brnpapa/competitive-programming/blob/master/uva/967.cpp): `pope` 
	- 📗 [codeforces/381-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/381-A.cpp) 
	- 📙 [codeforces/279-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/279-B.cpp) 
