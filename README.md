# Hi, visitor!

Access my public [**notebook**](https://www.notion.so/brnpapa/icpc-notebook-0355e05508e9470fb065801e277f0c6c), a Notion workspace where I do my notes while studying and coding general-purpose algorithms. The book I use and recommend for studying is "Competitive Programming 3: The new lower bound of programming contests" by Steven Halim.

<p align="center">Feel free to follow my progress on my online judge profiles:</p>

<p align="center">
<a href="https://uhunt.onlinejudge.org/id/1094350"><img src="https://img.shields.io/static/v1?label=uva&message=61&color=green&style=flat-square"></a>
<a href="https://codeforces.com/profile/brnpapa"><img src="https://img.shields.io/static/v1?label=codeforces&message=49&color=green&style=flat-square"></a>
<a href="https://www.urionlinejudge.com.br/judge/pt/users/statistics/310281"><img src="https://img.shields.io/static/v1?label=uri&message=65&color=green&style=flat-square"></a>
<a href="https://www.spoj.com/users/brnpapa"><img src="https://img.shields.io/static/v1?label=spoj&message=24&color=green&style=flat-square"></a>
</p>
<br/>

<h1 align="center">Solutions categorized into themes</h1>

- [#dynamic-programming](#dynamic-programming)
- [#searching](#searching)
- [#greedy](#greedy)
- [#techniques](#techniques)
- [#computational-geometry](#computational-geometry)
- [#ad-hoc](#ad-hoc)
- [#string-processing](#string-processing)
- [#math](#math)
- [#graphs](#graphs)
- [#brute-force](#brute-force)


## brute force
- **iterative**
	- 📗 [uva/725](https://github.com/brnpapa/competitive-programming/blob/master/uva/725.cpp) 
	- 📗 [uva/10360](https://github.com/brnpapa/competitive-programming/blob/master/uva/10360.cpp) 
	- **all subsets**
		- 📗 [uva/12455](https://github.com/brnpapa/competitive-programming/blob/master/uva/12455.cpp)  → use bitmasks
	- **all permutations**
		- 📗 [uva/750](https://github.com/brnpapa/competitive-programming/blob/master/uva/750.cpp) 
- **recursive backtracking**
	- 📓 [spoj/BTCK](https://github.com/brnpapa/competitive-programming/blob/master/spoj/BTCK.cpp) 
	- 📓 [spoj/SPIKES](https://github.com/brnpapa/competitive-programming/blob/master/spoj/SPIKES.cpp) 
	- 📓 [uri/1522](https://github.com/brnpapa/competitive-programming/blob/master/uri/1522.cpp) 
	- **n-queens**
		- 📙 [uva/11195](https://github.com/brnpapa/competitive-programming/blob/master/uva/11195.cpp)  → use bitmasks
	- **pruned permutations**
		- 📙 [uva/524](https://github.com/brnpapa/competitive-programming/blob/master/uva/524.cpp) 
- **recursive backtraking**
	- 📗 [uva/10344](https://github.com/brnpapa/competitive-programming/blob/master/uva/10344.cpp): `check if some arithmetic expression of 5 given numbers will result in 23 `  → check all combination of operators for each permutation of the given numbers 

## graphs
- 📓 [uri/1076](https://github.com/brnpapa/competitive-programming/blob/master/uri/1076.cpp) 
- **specials**
	- **tree traversal**
		- 📗 [spoj/ONP](https://github.com/brnpapa/competitive-programming/blob/master/spoj/ONP.cpp): `transform the algebraic expression with brackets into reverse polish notation (RPN) `  → consider the given expression as the in-order traversal in a binary tree, then print post-order traversal recursively without building the tree
- **shortest path**
	- **dijkstra**
		- 📓 [uri/1148](https://github.com/brnpapa/competitive-programming/blob/master/uri/1148.cpp) 
		- 📓 [uri/2566](https://github.com/brnpapa/competitive-programming/blob/master/uri/2566.cpp) 
		- 📙 [uri/1123](https://github.com/brnpapa/competitive-programming/blob/master/uri/1123.cpp) 
		- 📙 [uva/10806](https://github.com/brnpapa/competitive-programming/blob/master/uva/10806.cpp): `find the global shortest path from 0 to V-1 (round trip), without repeting edges` 
		- 📕 [uva/11367](https://github.com/brnpapa/competitive-programming/blob/master/uva/11367.cpp)  → find the shortest path on space-state graph, where each vertex represent a city and a level of car fuel
	- **floyd-warshall**
		- 📗 [uri/2372](https://github.com/brnpapa/competitive-programming/blob/master/uri/2372.cpp) 
- **minimum spanning tree (MST)**
	- 📗 [uva/10034](https://github.com/brnpapa/competitive-programming/blob/master/uva/10034.cpp) 
- **traversal**
	- 📙 [uva/11906](https://github.com/brnpapa/competitive-programming/blob/master/uva/11906.cpp)  → consider grid as an implicit graph and walk through it avoiding redundant positions (nr, nc)
	- 📙 [uva/12442](https://github.com/brnpapa/competitive-programming/blob/master/uva/12442.cpp): `given a graph with all vertices with out-degree 1, find the vertice that reaches the most vertices` 
	- 📗 [uva/11831](https://github.com/brnpapa/competitive-programming/blob/master/uva/11831.cpp)  → consider grid as an implicit graph and walk through it, or just rotate the robot, for each received instruction
	- **depth-first search (DFS)**
		- 📓 [uri/1322](https://github.com/brnpapa/competitive-programming/blob/master/uri/1322.cpp) 
		- 📓 [codeforces/902-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/902-B.cpp) 
		- 📙 [uri/2965](https://github.com/brnpapa/competitive-programming/blob/master/uri/2965.cpp) 
	- **strongly connected components (SCC)**
		- 📙 [uva/11504](https://github.com/brnpapa/competitive-programming/blob/master/uva/11504.cpp): `count the number of SCCs without incoming edge from a vertex of another SCC` 
	- **bipartite checking**
		- 📗 [uva/10004](https://github.com/brnpapa/competitive-programming/blob/master/uva/10004.cpp) 
	- **breadth-first search (BFS)**
		- 📓 [uri/2294](https://github.com/brnpapa/competitive-programming/blob/master/uri/2294.cpp) 
		- 📓 [uri/1799](https://github.com/brnpapa/competitive-programming/blob/master/uri/1799.cpp) 
	- **flood fill**
		- 📕 [uva/1103](https://github.com/brnpapa/competitive-programming/blob/master/uva/1103.cpp)  → consider each pixel as a vertex of an implicit graph, then identify each hieroglyph counting the number of white CCs within it
		- 📗 [uva/11094](https://github.com/brnpapa/competitive-programming/blob/master/uva/11094.cpp) 
	- **topological sorting**
		- 📗 [uva/11060](https://github.com/brnpapa/competitive-programming/blob/master/uva/11060.cpp) 
	- **bridges and articulation points**
		- 📗 [uva/796](https://github.com/brnpapa/competitive-programming/blob/master/uva/796.cpp) 
- **binary search tree (BST)**
	- 📓 [uri/1194](https://github.com/brnpapa/competitive-programming/blob/master/uri/1194.cpp) 
	- 📓 [uri/1215](https://github.com/brnpapa/competitive-programming/blob/master/uri/1215.cpp) 
	- 📓 [uri/1200](https://github.com/brnpapa/competitive-programming/blob/master/uri/1200.cpp) 
	- 📓 [uri/1195](https://github.com/brnpapa/competitive-programming/blob/master/uri/1195.cpp) 

## math
- **ad-hoc**
	- 📗 [uva/10812](https://github.com/brnpapa/competitive-programming/blob/master/uva/10812.cpp) 
	- 📗 [uva/10346](https://github.com/brnpapa/competitive-programming/blob/master/uva/10346.cpp) 
	- 📗 [uva/11875](https://github.com/brnpapa/competitive-programming/blob/master/uva/11875.cpp) 
	- 📗 [uva/11723](https://github.com/brnpapa/competitive-programming/blob/master/uva/11723.cpp) 
	- **arithmetic progression**
		- 📙 [uva/11254](https://github.com/brnpapa/competitive-programming/blob/master/uva/11254.cpp) 
	- **sequences**
		- 📙 [uva/443](https://github.com/brnpapa/competitive-programming/blob/master/uva/443.cpp) 
	- **finding pattern**
		- 📙 [uva/264](https://github.com/brnpapa/competitive-programming/blob/master/uva/264.cpp) 
		- 📙 [codeforces/1092-D1](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1092-D1.cpp)  → remove adjacent ones whose absolute difference is even (using a stack)
		- 📙 [uva/10161](https://github.com/brnpapa/competitive-programming/blob/master/uva/10161.cpp) 
		- 📗 [spoj/EIGHTS](https://github.com/brnpapa/competitive-programming/blob/master/spoj/EIGHTS.cpp) 
		- 📗 [codeforces/1324-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-A.cpp) 
		- 📕 [uva/11718](https://github.com/brnpapa/competitive-programming/blob/master/uva/11718.cpp)  → compute K * N^(K-1) * sumA using fast power mod
- **combinatorics**
	- **binomial coefficient**
		- 📕 [uri/2972](https://github.com/brnpapa/competitive-programming/blob/master/uri/2972.cpp): `calculate the sum of C(N, k)%2 for all k in [0 .. n], i.e., how many odd combinations of k heads between n coins there are`  → 2^qtyBitsOn(n)
		- 📗 [codeforces/844-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/844-B.cpp) 
		- 📓 [uri/1694](https://github.com/brnpapa/competitive-programming/blob/master/uri/1694.cpp) 
	- **fibonacci numbers**
		- 📙 [uva/10334](https://github.com/brnpapa/competitive-programming/blob/master/uva/10334.py)  → compute (n+2)-th fibonnaci number
- **number theory**
	- 📙 [uri/2291](https://github.com/brnpapa/competitive-programming/blob/master/uri/2291.cpp): `print n-th divine number, the one that is equal to the sum of the sum of each divisor from 1 to n` 
	- 📓 [codeforces/624-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/624-A.cpp) 
	- 📓 [spoj/AE00](https://github.com/brnpapa/competitive-programming/blob/master/spoj/AE00.cpp) 
	- 📓 [uri/1323](https://github.com/brnpapa/competitive-programming/blob/master/uri/1323.cpp) 
	- **greatest common divisor (GCD)**
		- 📓 [uri/1028](https://github.com/brnpapa/competitive-programming/blob/master/uri/1028.cpp) 
		- 📗 [codeforces/822-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/822-A.cpp) 
		- 📗 [codeforces/854-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/854-A.cpp): `given n, determine maximum possible proper (a < b) and irreducible fraction a/b such that a+b == n` 
	- **prime numbers**
		- 📗 [spoj/PRIONPRI](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PRIONPRI.cpp): `prime checking` 
		- **factorization**
			- 📕 [uri/2661](https://github.com/brnpapa/competitive-programming/blob/master/uri/2661.cpp): `compute the number of divisors of n that can be written as the product of two or more distinct prime numbers (without repetition), 1 <= n <= 10^12`  → note that the product of any combination of prime factors of a number will always be a divisor of that number
			- 📗 [uva/10042](https://github.com/brnpapa/competitive-programming/blob/master/uva/10042.cpp) 
		- **sieve of eratosthenes**
			- 📓 [codeforces/17-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/17-A.cpp) 
			- 📙 [uva/10539](https://github.com/brnpapa/competitive-programming/blob/master/uva/10539.cpp): `compute the quantity of non-prime numbers in [lo .. hi] which are divisible by only a single prime number, 0 < lo <= hi < 10^12`  → generate all powers of the primes
			- 📗 [spoj/AMR11E](https://github.com/brnpapa/competitive-programming/blob/master/spoj/AMR11E.cpp): `print the n-th number that has at least 3 distinct prime factors` 
			- 📙 [spoj/PRIME1](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PRIME1.cpp): `print all primes p in [m .. n], 0 <= m <= n <= 10^9, n-m <= 10^5`  → sieve + prime checking
			- 📙 [codeforces/576-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/576-A.cpp) 

## string processing
- 📓 [spoj/TESSER](https://github.com/brnpapa/competitive-programming/blob/master/spoj/TESSER.cpp) 
- **palindrome**
	- 📓 [spoj/AMR12D](https://github.com/brnpapa/competitive-programming/blob/master/spoj/AMR12D.cpp) 
- **knuth-morris-pratt (KMP)**
	- 📓 [uri/1127](https://github.com/brnpapa/competitive-programming/blob/master/uri/1127.cpp) 

## ad-hoc
- 📓 [uri/2663](https://github.com/brnpapa/competitive-programming/blob/master/uri/2663.cpp) 
- 📓 [uva/10954](https://github.com/brnpapa/competitive-programming/blob/master/uva/10954.cpp) 
- 📓 [uri/1069](https://github.com/brnpapa/competitive-programming/blob/master/uri/1069.cpp) 
- 📗 [uva/12015](https://github.com/brnpapa/competitive-programming/blob/master/uva/12015.cpp) 
- 📗 [codeforces/1220-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1220-A.cpp) 
- 📓 [uri/1253](https://github.com/brnpapa/competitive-programming/blob/master/uri/1253.cpp) 
- 📓 [uri/1548](https://github.com/brnpapa/competitive-programming/blob/master/uri/1548.cpp) 
- 📓 [uri/1438](https://github.com/brnpapa/competitive-programming/blob/master/uri/1438.cpp) 
- 📓 [uri/2880](https://github.com/brnpapa/competitive-programming/blob/master/uri/2880.cpp) 
- 📓 [codeforces/1033-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1033-A.cpp) 
- 📓 [uri/2246](https://github.com/brnpapa/competitive-programming/blob/master/uri/2246.cpp) 
- 📓 [codeforces/686-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/686-A.cpp) 
- 📓 [uri/1077](https://github.com/brnpapa/competitive-programming/blob/master/uri/1077.cpp) 
- 📓 [spoj/MBINGO](https://github.com/brnpapa/competitive-programming/blob/master/spoj/MBINGO.cpp) 
- 📗 [spoj/ADAQUEUE](https://github.com/brnpapa/competitive-programming/blob/master/spoj/ADAQUEUE.cpp) 
- 📗 [uri/2879](https://github.com/brnpapa/competitive-programming/blob/master/uri/2879.cpp) 
- 📓 [uri/1342](https://github.com/brnpapa/competitive-programming/blob/master/uri/1342.cpp) 
- 📗 [uri/2968](https://github.com/brnpapa/competitive-programming/blob/master/uri/2968.cpp) 
- 📗 [uva/10141](https://github.com/brnpapa/competitive-programming/blob/master/uva/10141.cpp) 
- 📗 [uri/3024](https://github.com/brnpapa/competitive-programming/blob/master/uri/3024.cpp) 
- 📓 [uri/1063](https://github.com/brnpapa/competitive-programming/blob/master/uri/1063.cpp) 
- 📓 [uri/1766](https://github.com/brnpapa/competitive-programming/blob/master/uri/1766.cpp) 
- 📓 [spoj/STACKEZ](https://github.com/brnpapa/competitive-programming/blob/master/spoj/STACKEZ.cpp) 
- 📓 [uri/1217](https://github.com/brnpapa/competitive-programming/blob/master/uri/1217.cpp) 
- 📓 [uri/1026](https://github.com/brnpapa/competitive-programming/blob/master/uri/1026.cpp) 
- 📓 [uri/1300](https://github.com/brnpapa/competitive-programming/blob/master/uri/1300.cpp) 
- 📓 [uri/1318](https://github.com/brnpapa/competitive-programming/blob/master/uri/1318.cpp) 
- 📗 [uri/2242](https://github.com/brnpapa/competitive-programming/blob/master/uri/2242.cpp) 
- 📗 [codeforces/37-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/37-A.cpp) 
- 📗 [codeforces/1285-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1285-A.cpp) 
- 📓 [uri/2345](https://github.com/brnpapa/competitive-programming/blob/master/uri/2345.cpp) 
- 📗 [uri/2884](https://github.com/brnpapa/competitive-programming/blob/master/uri/2884.cpp) 
- 📗 [uri/2963](https://github.com/brnpapa/competitive-programming/blob/master/uri/2963.cpp) 
- 📓 [uri/1715](https://github.com/brnpapa/competitive-programming/blob/master/uri/1715.cpp) 
- 📓 [uri/1901](https://github.com/brnpapa/competitive-programming/blob/master/uri/1901.cpp) 
- 📓 [uri/2065](https://github.com/brnpapa/competitive-programming/blob/master/uri/2065.cpp) 
- 📓 [uri/2465](https://github.com/brnpapa/competitive-programming/blob/master/uri/2465.cpp) 
- 📗 [spoj/EC_CONB](https://github.com/brnpapa/competitive-programming/blob/master/spoj/EC_CONB.cpp) 
- 📗 [spoj/SBANK](https://github.com/brnpapa/competitive-programming/blob/master/spoj/SBANK.cpp) 
- 📓 [uri/1271](https://github.com/brnpapa/competitive-programming/blob/master/uri/1271.cpp) 
- 📓 [uri/1091](https://github.com/brnpapa/competitive-programming/blob/master/uri/1091.cpp) 
- 📓 [uri/1285](https://github.com/brnpapa/competitive-programming/blob/master/uri/1285.cpp) 
- 📓 [uri/1340](https://github.com/brnpapa/competitive-programming/blob/master/uri/1340.cpp) 
- 📕 [uri/1368](https://github.com/brnpapa/competitive-programming/blob/master/uri/1368.cpp) 
- 📗 [uva/11799](https://github.com/brnpapa/competitive-programming/blob/master/uva/11799.cpp) 
- 📓 [uri/1068](https://github.com/brnpapa/competitive-programming/blob/master/uri/1068.cpp) 
- 📓 [uri/1110](https://github.com/brnpapa/competitive-programming/blob/master/uri/1110.cpp) 
- 📗 [codeforces/151-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/151-A.cpp) 
- **simulation**
	- 📙 [uri/2971](https://github.com/brnpapa/competitive-programming/blob/master/uri/2971.cpp) 
- **implementation**
	- 📗 [codeforces/110-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/110-A.cpp) 
	- 📗 [codeforces/266-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/266-A.cpp) 
	- 📗 [codeforces/158-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/158-C.cpp) 
	- 📗 [codeforces/1284-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1284-A.cpp) 
	- 📙 [codeforces/1254-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1254-A.cpp) 
	- 📗 [spoj/GNY07D](https://github.com/brnpapa/competitive-programming/blob/master/spoj/GNY07D.cpp) 
	- 📗 [codeforces/811-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/811-B.cpp) 
	- 📙 [codeforces/1296-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1296-C.cpp)  → maps each position of the robot with the string index, and check if a new position has already been mapped before
	- 📗 [codeforces/81-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/81-A.cpp) 
	- 📗 [codeforces/492-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/492-B.cpp) 
	- 📗 [codeforces/373-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/373-A.cpp) 
	- 📙 [codeforces/519-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/519-C.cpp) 

## computational geometry
- 📓 [uva/10310](https://github.com/brnpapa/competitive-programming/blob/master/uva/10310.cpp) 
- 📓 [codeforces/157-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/157-B.cpp) 
- 📗 [codeforces/659-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/659-D.cpp) 

## techniques
- **two pointers**
	- 📕 [codeforces/1041-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1041-D.cpp) 
	- 📙 [codeforces/676-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/676-C.cpp) 
	- 📙 [codeforces/279-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/279-B.cpp) 
	- 📗 [codeforces/6-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/6-C.cpp) 
	- 📗 [codeforces/381-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/381-A.cpp) 

## greedy
- 📓 [spoj/STPAR](https://github.com/brnpapa/competitive-programming/blob/master/spoj/STPAR.cpp) 
- 📗 [codeforces/1324-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-B.cpp): `given a sequence of integers, is there a subsequence palindrome of size 3?`  → check if there are two equal non-adjacent numbers using brute force
- 📗 [spoj/CADYDIST](https://github.com/brnpapa/competitive-programming/blob/master/spoj/CADYDIST.cpp) 
- 📗 [codeforces/275-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/275-C.cpp) 
- 📗 [codeforces/984-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/984-A.cpp) 
- 📓 [spoj/BUSYMAN](https://github.com/brnpapa/competitive-programming/blob/master/spoj/BUSYMAN.cpp) 
- 📗 [codeforces/1092-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1092-B.cpp) 
- 📓 [uri/1086](https://github.com/brnpapa/competitive-programming/blob/master/uri/1086.cpp) 
- 📓 [spoj/PL](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PL.cpp) 
- 📗 [codeforces/545-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/545-D.cpp) 
- 📗 [codeforces/1324-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-C.cpp)  → note that it's unnecessary jump to the left, so to minimize d, just jump between the nearest 'R' cells
- **maximum subsequence**
	- 📓 [codeforces/313-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/313-B.cpp) 
	- 📓 [codeforces/702-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/702-A.cpp) 
- **loading balance**
	- 📗 [uva/11389](https://github.com/brnpapa/competitive-programming/blob/master/uva/11389.cpp) 
	- 📙 [uri/1055](https://github.com/brnpapa/competitive-programming/blob/master/uri/1055.cpp) 
- **interval covering**
	- 📙 [uva/10382](https://github.com/brnpapa/competitive-programming/blob/master/uva/10382.cpp)  → reduce the problem using pythagoras to one line
- **fast longest increasing subsequence (LIS)**
	- 📙 [uva/481](https://github.com/brnpapa/competitive-programming/blob/master/uva/481.cpp) 
- **bipartite matching**
	- 📗 [uva/11292](https://github.com/brnpapa/competitive-programming/blob/master/uva/11292.cpp) 
- **coin change (CC)**
	- 📓 [codeforces/996-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/996-A.cpp) 
	- 📗 [codeforces/1255-A](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1255-A.cpp) 
	- **counting ways**
		- 📗 [uva/11137](https://github.com/brnpapa/competitive-programming/blob/master/uva/11137.cpp) 
		- 📗 [uva/674](https://github.com/brnpapa/competitive-programming/blob/master/uva/674.cpp) 

## searching
- **binary search**
	- 📓 [uri/2448](https://github.com/brnpapa/competitive-programming/blob/master/uri/2448.cpp) 
	- 📙 [codeforces/1324-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1324-D.cpp): `given the A and B arrays, count the quantity of pairs i < j such that A[i]+A[j] > B[i]+B[j]`  → diff being the A-B array, count, for all i in [0 .. N-2], how many times -diff[i] < diff[j], for all j in [i+1 .. N-1]
	- 📙 [codeforces/1284-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1284-B.cpp) 
	- 📗 [spoj/PAIRS1](https://github.com/brnpapa/competitive-programming/blob/master/spoj/PAIRS1.cpp): `given the A array, count the quantity of pairs i < j such that A[i]-A[j] == K`  → search on the sorted array A by the A[n]+K, for all n in [0 .. N-1]
	- **on answer**
		- 📙 [uva/12097](https://github.com/brnpapa/competitive-programming/blob/master/uva/12097.cpp) 
		- 📕 [codeforces/460-C](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/460-C.cpp) 
		- 📙 [uri/2973](https://github.com/brnpapa/competitive-programming/blob/master/uri/2973.cpp) 
- **segment tree**
	- 📗 [codeforces/339-D](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/339-D.cpp) 
	- **lazy propagation**
		- 📙 [uri/2658](https://github.com/brnpapa/competitive-programming/blob/master/uri/2658.cpp)  → build a segment tree for RSQ, but store an array of size 9 in tree[v], where tree[v][n] indicates the frequency that each note n appears in that interval
		- 📙 [uva/11402](https://github.com/brnpapa/competitive-programming/blob/master/uva/11402.cpp)  → build a segment tree for RSQ, but keep in lazy[v] the type of pending operation to be performed in that interval of A

## dynamic programming
- 📗 [uva/10003](https://github.com/brnpapa/competitive-programming/blob/master/uva/10003.cpp) 
- 📗 [uva/10337](https://github.com/brnpapa/competitive-programming/blob/master/uva/10337.cpp) 
- 📙 [uva/10721](https://github.com/brnpapa/competitive-programming/blob/master/uva/10721.cpp) 
- 📗 [uva/10943](https://github.com/brnpapa/competitive-programming/blob/master/uva/10943.cpp) 
- 📙 [codeforces/166-E](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/166-E.cpp) 
- 📗 [uva/11450](https://github.com/brnpapa/competitive-programming/blob/master/uva/11450.cpp) 
- 📙 [uva/10651](https://github.com/brnpapa/competitive-programming/blob/master/uva/10651.cpp)  → use bitmasks
- **traveling salesman problem (TSP)**
	- 📙 [uva/116](https://github.com/brnpapa/competitive-programming/blob/master/uva/116.cpp) 
	- 📗 [uva/10496](https://github.com/brnpapa/competitive-programming/blob/master/uva/10496.cpp) 
- **digits**
	- 📓 [uri/1707](https://github.com/brnpapa/competitive-programming/blob/master/uri/1707.cpp) 
- **longest increasing subsequence (LIS)**
	- 📙 [uva/10131](https://github.com/brnpapa/competitive-programming/blob/master/uva/10131.cpp)  → sort elephants based on increasing kg, then apply LDS on iq
	- 📙 [uri/1517](https://github.com/brnpapa/competitive-programming/blob/master/uri/1517.cpp) 
	- 📙 [uva/11456](https://github.com/brnpapa/competitive-programming/blob/master/uva/11456.cpp)  → find the max(lis[i]+lds[i]-1) for all i in [0 .. N-1], being i where the subsequence starts
- **max 2D range sum**
	- 📗 [uva/108](https://github.com/brnpapa/competitive-programming/blob/master/uva/108.cpp) 
	- 📕 [uva/10755](https://github.com/brnpapa/competitive-programming/blob/master/uva/10755.cpp): `max 3D range sum`  → use max 2D range sum in two of the three dimensions and max 1D range sum (kadane) on the third dimension
- **edit distance**
	- 📓 [spoj/EDIST](https://github.com/brnpapa/competitive-programming/blob/master/spoj/EDIST.cpp) 
- **minimax**
	- 📓 [uva/12484](https://github.com/brnpapa/competitive-programming/blob/master/uva/12484.cpp) 
- **0-1 knapsack**
	- 📗 [spoj/KNAPSACK](https://github.com/brnpapa/competitive-programming/blob/master/spoj/KNAPSACK.cpp) 
	- 📙 [uri/1487](https://github.com/brnpapa/competitive-programming/blob/master/uri/1487.cpp) 
	- 📗 [uri/2498](https://github.com/brnpapa/competitive-programming/blob/master/uri/2498.cpp) 
	- **subset sum**
		- 📗 [uri/1203](https://github.com/brnpapa/competitive-programming/blob/master/uri/1203.cpp): `check if any subset of A has a sum equal to K` 
		- 📙 [uva/10616](https://github.com/brnpapa/competitive-programming/blob/master/uva/10616.cpp) 
- **longest common subsequence (LCS)**
	- 📓 [uva/10405](https://github.com/brnpapa/competitive-programming/blob/master/uva/10405.cpp) 
- **max 1D range sum**
	- 📙 [uva/787](https://github.com/brnpapa/competitive-programming/blob/master/uva/787.py): `max 1D range product query`  → compute for each sub-range without 0
	- **kadane**
		- 📗 [spoj/MAXSUMSU](https://github.com/brnpapa/competitive-programming/blob/master/spoj/MAXSUMSU.cpp) 
		- 📗 [codeforces/1285-B](https://github.com/brnpapa/competitive-programming/blob/master/codeforces/1285-B.cpp) 
		- 📗 [uva/10684](https://github.com/brnpapa/competitive-programming/blob/master/uva/10684.cpp) 
