Feel free to follow my progress on my main online judge profiles:

<p align="center">
<a href="https: //uhunt.onlinejudge.org/id/1094350"><img src="https://img.shields.io/static/v1?label=uva&message=108&color=green&style=flat-square"></a>
<a href="https: //codeforces.com/profile/brnpapa"><img src="https://img.shields.io/static/v1?label=codeforces&message=79&color=green&style=flat-square"></a>
<a href="https: //www.urionlinejudge.com.br/judge/pt/users/statistics/310281"><img src="https://img.shields.io/static/v1?label=uri&message=69&color=green&style=flat-square"></a>
<a href="https: //www.spoj.com/users/brnpapa"><img src="https://img.shields.io/static/v1?label=spoj&message=42&color=green&style=flat-square"></a>
</p>
<br/>

<h1 align="center">Solutions index</h1>

· [#brute-force](#brute-force) · [#ad-hoc](#ad-hoc) · [#divide-&-conquer](#divide-&-conquer) · [#greedy](#greedy) · [#geometry](#geometry) · [#dynamic-programming](#dynamic-programming) · [#math](#math) · [#data-structures](#data-structures) · [#graphs](#graphs) · [#miscellaneous](#miscellaneous) · [#strings](#strings) ·

## strings
- **suffix array**
	- 😳 [spoj/SARRAY](./spoj/SARRAY.cpp): `just build a suffix array in O(N * log N)` 

## miscellaneous
- **two pointers**
	- 😳 [uva/967](./uva/967.cpp): `pope` 
	- 🙂 [codeforces/6-C](./codeforces/6-C.cpp) 
	- 🙂 [codeforces/381-A](./codeforces/381-A.cpp) 
	- 🥵 [codeforces/1041-D](./codeforces/1041-D.cpp) 
	- 😳 [codeforces/279-B](./codeforces/279-B.cpp) 
	- 😳 [codeforces/676-C](./codeforces/676-C.cpp) 
- **bitmask**
	- 🙂 [codeforces/484-A](./codeforces/484-A.cpp) 
- **binary search**
	- 🙂 [spoj/PAIRS1](./spoj/PAIRS1.cpp): `given the A array, count the quantity of pairs i < j such that A[i]-A[j] == K`  → search on the sorted array A by the A[n]+K, for all n in [0 .. N-1]
	- 😳 [codeforces/91-B](./codeforces/91-B.cpp): `given the array a, compute the array d, where d[i] = j-(i+1) for the max j such that a[j] < a[i]`  → apply binary search on preprocessed array mn, filled from right to left
	- 😳 [codeforces/1284-B](./codeforces/1284-B.cpp) 
	- 😳 [codeforces/1324-D](./codeforces/1324-D.cpp): `given the A and B arrays, count the quantity of pairs i < j such that A[i]+A[j] > B[i]+B[j]`  → diff being the A-B array, count, for all i in [0 .. N-2], how many times -diff[i] < diff[j], for all j in [i+1 .. N-1]
	- **on answer**
		- 😳 [uva/12097](./uva/12097.cpp) 
		- 😳 [codeforces/1223-C](./codeforces/1223-C.cpp) 
		- 😳 [spoj/AGGRCOW](./spoj/AGGRCOW.cpp): `given an array A of size N (2 <= N <= 10^5), print the largest minimum distance between any two of C (C <= N) elements choosen any` 
		- 🥵 [codeforces/460-C](./codeforces/460-C.cpp) 
		- 😳 [uri/2973](./uri/2973.cpp) 

## graphs
- **minimum spanning tree (MST)**
	- 🙂 [uva/10034](./uva/10034.cpp) 
	- 🙂 [uva/11710](./uva/11710.cpp) 
	- 🙂 [spoj/MST](./spoj/MST.cpp) 
	- 🙂 [uva/1174](./uva/1174.cpp) 
	- **minimum spanning subgraph**
		- 😳 [uva/10397](./uva/10397.cpp): `given an implicit complete graph and some edges, compute the cost of the minimum spanning subgraph` 
	- **minimax path**
		- 😳 [uva/10099](./uva/10099.cpp): `maximin path; find the minimum cost of the maximum path from s to t`  → apply kruskal to get the maximum spanning tree, but stop it when s and t connect
		- 🙂 [uva/10048](./uva/10048.cpp) 
- **shortest path**
	- **single-source**
		- **unweighted graph**
			- 😳 [uva/12797](./uva/12797.cpp)  → apply a BFS for each subset of letters possible (only 2^10) using bitmask
		- **negative-weighted and cycle graph**
			- 😳 [at-coder/ABC137-E](./at-coder/ABC137-E.cpp): `longest distance from 0 to V-1, checking for positive cycle that are part of that path (0 to V-1)` 
		- **weighted graph**
			- 🥵 [uva/11367](./uva/11367.cpp)  → find the shortest path on state-space graph, where each vertex represent a city and a level of car fuel
			- 😳 [uva/11833](./uva/11833.cpp)  → build the graph already with the given constraints
			- 😳 [uva/12144](./uva/12144.cpp): `almost shortest path` 
			- 🥵 [live-archive/3652](./live-archive/3652.cpp): `dijkstra on a given implicit graph as a 2D grid` 
			- 😳 [uva/10806](./uva/10806.cpp): `find the global shortest path from 0 to V-1 (round trip), without repeting edges` 
	- **all-pairs**
		- 🙂 [uri/2372](./uri/2372.cpp) 
- **traversal**
	- 🙂 [uva/11831](./uva/11831.cpp)  → consider grid as an implicit graph and walk through it, or just rotate the robot, for each received instruction
	- 😳 [uva/11906](./uva/11906.cpp)  → consider grid as an implicit graph and walk through it avoiding redundant positions (nr, nc)
	- 😳 [code-jam/2020-1A-pascal-walk-TLE](./code-jam/2020-1A-pascal-walk-TLE.cpp) 
	- **edge classification**
		- 🙂 [codeforces/104-C](./codeforces/104-C.cpp): `check if the given undirected graph can be represented as a set of three or more rooted trees, whose roots are connected by a simple cycle`  → check if the graph is connective and has only one cycle
		- 🙂 [codeforces/510-B](./codeforces/510-B.cpp): `check if a given implicit undirected graph has a cycle of length >= 4` 
	- **flood fill**
		- 🥵 [uva/1103](./uva/1103.cpp)  → consider each pixel as a vertex of an implicit graph, then identify each hieroglyph counting the number of white CCs within it
		- 🙂 [uva/11094](./uva/11094.cpp) 
	- **strongly connected components (SCC)**
		- 😳 [uva/11504](./uva/11504.cpp)  → count the number of SCCs without incoming edge from a vertex of another SCC
	- **depth-first search (DFS)**
		- 😳 [uri/2965](./uri/2965.cpp) 
	- **topological sorting**
		- 🙂 [uva/11060](./uva/11060.cpp) 
	- **bridges or articulation points**
		- 🥵 [codeforces/178-B3](./codeforces/178-B3.cpp): `given an undirected graph, count how many bridge edges exists between 2 query vertices`  → group the vertices connected by non-bridge edge during dfs; generate a tree considering each group as a vertice, and using only the bridge edges; find the distance between 2 query vertices of that tree with LCA in O(1)
		- 🥵 [uva/12363](./uva/12363.cpp): `given an undirected graph, check if there is a unique path between 2 query vertices`  → there is a unique path between s and t if the path between them is formed only by bridge edges; for optimize, keep sets for the vertices that are on the same connected component in the pruned graph (with only bridge edges)
		- 🙂 [uva/796](./uva/796.cpp) 
- **maximum flow**
	- 😳 [uva/10779](./uva/10779.cpp)  → each friend receives 1 flow unit of a sticker and offers a flow of other sticker; Bob also offers, but he receives 1 flow unit of each sticker; maximized it
	- 🙂 [uva/820](./uva/820.cpp) 
	- **minimum cost**
		- 🙂 [uva/10594](./uva/10594.cpp) 
- **specials**
	- 😳 [uva/12442](./uva/12442.cpp): `given a graph with all vertices with out-degree 1, find the vertice that reaches the most vertices` 
	- **directed acyclic graph (DAG)**
		- 🙂 [uva/988](./uva/988.cpp): `counting paths from 0 to V-1` 
	- **tree**
		- 🙂 [spoj/LABYR1](./spoj/LABYR1.cpp): `compute the diameter of a given implicit tree` 
		- 😳 [spoj/ONP](./spoj/ONP.cpp): `infix to postfix conversion`  → see that the given expression is the in-order traversal in a binary tree, then print post-order traversal recursively without building the tree
		- 🙂 [codeforces/115-A](./codeforces/115-A.cpp): `given a forest, find the length of the longest path` 
		- **lowest common ancestor (LCA)**
			- 😳 [uva/12238](./uva/12238.cpp): `given a weighted tree, find the distance between 2 query vertices` 
			- 🙂 [timus/1471](./timus/1471.cpp): `given a weighted tree, find the distance between 2 query vertices` 
	- **bipartite**
		- **bipartite checking**
			- 🙂 [spoj/BUGLIFE](./spoj/BUGLIFE.cpp)  → check all connect components
			- 🙂 [uva/10004](./uva/10004.cpp) 
		- **max cardinality bipartite matching**
			- 😳 [uva/10080](./uva/10080.cpp): `max number of preys that can hide safely from an predator attack`  → consider a bipartite graph with edges that connect a gopher (prey) to an reachable hole
			- 😳 [uva/11262](./uva/11262.cpp)  → binary search on answer + MCBM

## data structures
- **sparse table**
	- 🙂 [spoj/THRBL](./spoj/THRBL.cpp): `range max query` 
- **segment tree**
	- 🙂 [live-archive/6139](./live-archive/6139.cpp): `range product query` 
	- 🙂 [codeforces/339-D](./codeforces/339-D.cpp) 
	- **lazy propagation**
		- 😳 [uri/2658](./uri/2658.cpp)  → build a segment tree for RSQ, but store an array of size 9 in tree[v], where tree[v][n] indicates the frequency that the note n appears in that interval
		- 😳 [uva/11402](./uva/11402.cpp)  → build a segment tree for RSQ, but keep in lazy[v] the type of pending operation to be performed in that interval of A
- **union-find disjoint sets (UFDS)**
	- 🙂 [uva/11966](./uva/11966.cpp) 
	- 🙂 [codeforces/445-B](./codeforces/445-B.cpp)  → 2 ^ (sum of (size of set - 1), for each disjoint set)
	- 🙂 [uva/10608](./uva/10608.cpp) 
	- 🙂 [codeforces/1249-B2](./codeforces/1249-B2.cpp) 
	- 😳 [codeforces/25-D](./codeforces/25-D.cpp) 

## math
- **game theory**
	- **minimax**
		- 😳 [uva/12484](./uva/12484.cpp): `alberto and wanderley take one of two cards at the edges of the cards sequence, alberto want maximize it`  → fill memo table in row-major order
		- 😳 [uva/10111](./uva/10111.cpp): `given a state of a tic tac toe board, check if X will win independent of the O movement`  → minimax + memo + backtracking
		- **optimized**
			- 🥵 [uva/847](./uva/847.cpp): `multiplication game`  → note that if Stan always multiply by 9 and Ollie by 2, it's still an optimal solution
- **number theory**
	- 😳 [uri/2291](./uri/2291.cpp): `print n-th divine number, the one that is equal to the sum of the sum of each divisor from 1 to n`  → think like sieve
	- 😳 [uva/547](./uva/547.cpp): `find the longest DDF sequence`  → pre-process a array f, where f[i] is the sum of digits of all positive factors of i; think like sieve
	- **greatest common divisor (GCD)**
		- 😳 [codeforces/75-C](./codeforces/75-C.cpp): `find the gcd(a, b) that is in a query range [lo .. hi]`  → note that all divisors of gcd(a, b) are also divisors of a and b
		- 🙂 [codeforces/854-A](./codeforces/854-A.cpp): `given n, determine maximum possible proper (a < b) and irreducible fraction a/b such that a+b == n` 
		- 🙂 [codeforces/822-A](./codeforces/822-A.cpp) 
	- **module arithmetic**
		- 🙂 [uva/10176](./uva/10176.cpp): `is a given binary number of 100 digits divisible by 131071?` 
		- 🙂 [uva/374](./uva/374.cpp): `compute (a^n) % m, where a <= 2^31 and n <= 2^31`  → use fast power with mod
	- **prime numbers**
		- 🙂 [spoj/PRIONPRI](./spoj/PRIONPRI.cpp): `prime checking` 
		- **prime factorization**
			- 🙂 [uva/10042](./uva/10042.cpp) 
			- 😳 [uva/10139](./uva/10139.cpp): `do n! is divisible by m?`  → check if the prime factors of m are contained in the prime factors of n!
			- 🥵 [uri/2661](./uri/2661.cpp): `compute the number of divisors of n that can be written as the product of two or more distinct prime numbers (without repetition), 1 <= n <= 10^12`  → note that the product of any combination of prime factors of a number will always be a divisor of that number
		- **sieve of eratosthenes**
			- 😳 [codeforces/576-A](./codeforces/576-A.cpp) 
			- 🙂 [spoj/AMR11E](./spoj/AMR11E.cpp): `print the n-th number that has at least 3 distinct prime factors`  → use modified sieve
			- 🙂 [codeforces/230-B](./codeforces/230-B.cpp): `check if a large n has exactily three distinct positive divisors`  → check if sqrt(n) is prime
			- 😳 [uva/10539](./uva/10539.cpp): `compute the quantity of non-prime numbers in [lo .. hi] which are divisible by only a single prime number, 0 < lo <= hi < 10^12`  → generate all powers of each prime number
			- 😳 [spoj/PRIME1](./spoj/PRIME1.cpp): `print all primes p in [m .. n], 0 <= m <= n <= 10^9, n-m <= 10^5`  → sieve + prime checking
- **matrix exponentiation**
	- 🙂 [uva/10229](./uva/10229.cpp)  → transform the fibonacci recurrence into a matrix exponentiation
- **ad-hoc**
	- 🙂 [uva/10812](./uva/10812.cpp) 
	- 🙂 [codeforces/16-C](./codeforces/16-C.cpp) 
	- 🙂 [uva/10346](./uva/10346.cpp) 
	- 🙂 [uva/12791](./uva/12791.cpp) 
	- 🙂 [codeforces/1042-A](./codeforces/1042-A.cpp) 
	- 🙂 [uva/11875](./uva/11875.cpp) 
	- 🙂 [uva/10110](./uva/10110.cpp): `check if the number of divisors of n is odd`  → check if n is a perfect square
	- 🙂 [uva/11723](./uva/11723.cpp) 
	- 😳 [codeforces/573-A](./codeforces/573-A.cpp) 
	- **finding pattern**
		- 🙂 [codeforces/1221-C](./codeforces/1221-C.cpp) 
		- 😳 [uva/10161](./uva/10161.cpp) 
		- 🙂 [codeforces/1324-A](./codeforces/1324-A.cpp) 
		- 😳 [codeforces/1092-D1](./codeforces/1092-D1.cpp)  → remove adjacent ones whose absolute difference is even (using a stack)
		- 🙂 [spoj/EIGHTS](./spoj/EIGHTS.cpp) 
		- 🥵 [uva/11718](./uva/11718.cpp)  → compute K * N^(K-1) * sumA using fast power mod
	- **sequences**
		- 😳 [uva/443](./uva/443.cpp) 
		- 🥵 [uva/10706](./uva/10706.cpp)  → pre-process the number sequence and f(k), so use binary search on f
		- 😳 [uva/264](./uva/264.cpp)  → use binary search on preprocessed f(x)=f(x-1)+x-1
	- **arithmetic progression**
		- 😳 [uva/11254](./uva/11254.cpp) 
- **combinatorics**
	- 🙂 [codeforces/131-B](./codeforces/131-B.cpp) 
	- 🙂 [codeforces/459-B](./codeforces/459-B.cpp): `find the max difference between numbers of a given array and the number of ways to get it` 
	- **combinations**
		- **binomial coefficient**
			- 🙂 [codeforces/844-B](./codeforces/844-B.cpp) 
			- 🥵 [uri/2972](./uri/2972.cpp): `calculate the sum of C(N, k)%2 for all k in [0 .. n], i.e., how many odd combinations of k heads between n coins there are`  → just compute 2^qtyBitsOn(n)
		- **multi-combinations**
			- 😳 [codeforces/630-G](./codeforces/630-G.cpp)  → C(n+5-1,5) * C(n+3-1,3)

## dynamic programming
- 😳 [codeforces/1061-C](./codeforces/1061-C.cpp)  → use space saving + all divisors in O(sqrt(n)) to optimize
- 🙂 [uva/11000](./uva/11000.cpp) 
- 😳 [uva/10651](./uva/10651.cpp)  → use bitmask
- 🙂 [uva/10943](./uva/10943.cpp) 
- 🙂 [uva/10911](./uva/10911.cpp)  → use bitmasks
- 😳 [codeforces/166-E](./codeforces/166-E.cpp) 
- 🙂 [spoj/RPLB](./spoj/RPLB.cpp) 
- 😳 [uva/10721](./uva/10721.cpp) 
- 🙂 [uva/10003](./uva/10003.cpp) 
- 🙂 [spoj/LINEUP](./spoj/LINEUP.cpp)  → use bitmask
- 🙂 [uva/10337](./uva/10337.cpp) 
- 🙂 [spoj/TRT](./spoj/TRT.cpp)  → don't memoize the current day
- 🙂 [uva/11450](./uva/11450.cpp) 
- **longest increasing subsequence (LIS)**
	- 😳 [uri/1517](./uri/1517.cpp) 
	- 😳 [uva/10131](./uva/10131.cpp)  → sort elephants based on increasing kg, then apply LDS on iq
	- 😳 [uva/11456](./uva/11456.cpp)  → find the max(lis[i]+lds[i]-1) for all i in [0 .. N-1], being i where the subsequence starts
	- 🥵 [uva/481](./uva/481.cpp) 
- **coin change**
	- 🙂 [uva/11407](./uva/11407.cpp)  → consider the coins as the perfect squares
	- 😳 [uva/166](./uva/166.cpp): `coin change with limited amount of coins + greedy coin change with unlimited amount of coins; I don't know why, but it works without memo` 
	- 🙂 [codeforces/189-A](./codeforces/189-A.cpp) 
- **0-1 knapsack**
	- 🙂 [spoj/SCUBADIV](./spoj/SCUBADIV.cpp) 
	- 🙂 [spoj/KNAPSACK](./spoj/KNAPSACK.cpp) 
	- 😳 [spoj/FISHER](./spoj/FISHER.cpp): `get the (min) total value and total weight of the optimal knapsack` 
	- 🙂 [uri/2498](./uri/2498.cpp) 
	- 😳 [uri/1487](./uri/1487.cpp) 
	- 😳 [uva/10261](./uva/10261.cpp): `as if there were 2 knapsacks to fill at the same time; with recovering` 
	- 🙂 [uva/990](./uva/990.cpp): `with recovering` 
- **max 2D range sum**
	- 🥵 [uva/10755](./uva/10755.cpp): `max 3D range sum`  → use max 2D range sum in two of the three dimensions and max 1D range sum (kadane) on the third dimension
	- 🙂 [uva/108](./uva/108.cpp) 
- **digit**
	- 😳 [uri/1707](./uri/1707.cpp): `given two numbers x and y, compute the sum of the decimal digits of the odd numbers in the range [min(x,y) .. max(x,y)]` 
	- 🙂 [spoj/CPCRC1C](./spoj/CPCRC1C.cpp) 
- **max 1D range sum**
	- **kadane**
		- 🙂 [uva/10684](./uva/10684.cpp) 
		- 🙂 [spoj/MAXSUMSU](./spoj/MAXSUMSU.cpp) 
		- 🙂 [codeforces/1285-B](./codeforces/1285-B.cpp) 
- **subset sum**
	- 😳 [uva/10616](./uva/10616.cpp): `given an array of size N, count how many subsets of size M have their sum divisible by D`  → use module arithmetic
	- 🙂 [uri/1203](./uri/1203.cpp): `check if any subset of A has a sum equal to K` 
	- 😳 [uri/2089](./uri/2089.cpp)  → optimize memory
	- 🙂 [uva/624](./uva/624.cpp): `print the subset of A with the max sum k, k <= K` 
	- 😳 [uva/11658](./uva/11658.cpp): `find the smallest sum s of a subset of A, s >= S`  → scan as %d.%d
	- **with repetition**
		- 🙂 [uva/674](./uva/674.cpp) 
		- 🙂 [uva/11137](./uva/11137.cpp) 
		- 🙂 [uva/357](./uva/357.cpp) 
- **traveling salesman problem (TSP)**
	- 🙂 [uva/10496](./uva/10496.cpp) 
	- 😳 [uva/116](./uva/116.cpp) 
- **longest common subsequence (LCS)**
	- 🙂 [spoj/IOIPALIN](./spoj/IOIPALIN.cpp): `given a string, determine the minimal quantity of characters to be inserted into it in order to obtain a palindrome`  → compute length of string minus lcs between string and reversed string
	- 🙂 [spoj/ADASEQEN](./spoj/ADASEQEN.cpp) 
- **LCS reduced to LIS**
	- 😳 [uva/10635](./uva/10635.cpp) 

## geometry
- 🙂 [uva/11152](./uva/11152.cpp) 
- 🙂 [spoj/GOALFR](./spoj/GOALFR.cpp) 
- 🙂 [codeforces/499-C](./codeforces/499-C.cpp)  → count how many lines the 2 points cross
- 🙂 [codeforces/1047-B](./codeforces/1047-B.cpp) 
- 🙂 [codeforces/659-D](./codeforces/659-D.cpp) 

## greedy
- 🙂 [uva/10954](./uva/10954.cpp): `add all` 
- 🙂 [codeforces/1092-B](./codeforces/1092-B.cpp) 
- 🙂 [code-jam/2020-QR-nesting-depth](./code-jam/2020-QR-nesting-depth.cpp) 
- 😳 [codeforces/204-B](./codeforces/204-B.cpp): `given the two-sided values of N cards, what is the minimum number of turns in the cards so that at least half of them are the same front?; they are initially facing upwards` 
- 🙂 [uva/11491](./uva/11491.cpp): `remove D digits from the given number, in a such way that the remain number is maximum` 
- 😳 [uva/11240](./uva/11240.cpp): `length of the longest inc/dec (alternating) subsequence` 
- 🙂 [codeforces/275-C](./codeforces/275-C.cpp) 
- 🙂 [spoj/GERGOVIA](./spoj/GERGOVIA.cpp) 
- 😳 [code-jam/2020-1A-pattern-matching](./code-jam/2020-1A-pattern-matching.cpp) 
- 🙂 [spoj/SNGINT](./spoj/SNGINT.cpp): `given an integer n, find the smallest positive integer m > 0 such that the product of digits of m equals n` 
- 🙂 [spoj/CADYDIST](./spoj/CADYDIST.cpp) 
- 😳 [codeforces/1237-C2](./codeforces/1237-C2.cpp)  → sort the points, remove pairs with equal x and y first, then pairs with equal x and finally the rest
- 🙂 [codeforces/1257-A](./codeforces/1257-A.cpp) 
- 🙂 [codeforces/1324-C](./codeforces/1324-C.cpp)  → note that it's unnecessary jump to the left, so to minimize d, just jump between the nearest 'R' cells
- 🙂 [code-jam/2020-QR-parenting-partnering-returns](./code-jam/2020-QR-parenting-partnering-returns.cpp) 
- 🙂 [spoj/BUSYMAN](./spoj/BUSYMAN.cpp): `compute the maximum number of activities (each with start and end times) that you can do without overlapping them (one at a time)`  → sort the activites by increasing end time
- 🙂 [codeforces/1324-B](./codeforces/1324-B.cpp): `given a sequence of integers, is there a subsequence palindrome of size 3?`  → check if there are two equal non-adjacent numbers using brute force
- 🙂 [codeforces/545-D](./codeforces/545-D.cpp) 
- 🙂 [codeforces/984-A](./codeforces/984-A.cpp) 
- 🙂 [codeforces/1360-C](./codeforces/1360-C.cpp) 
- **bipartite matching**
	- 🙂 [uva/11292](./uva/11292.cpp) 
- **restrict coin change**
	- 🙂 [codeforces/1255-A](./codeforces/1255-A.cpp) 
- **interval covering**
	- 😳 [uva/10382](./uva/10382.cpp)  → reduce the problem using pythagoras to one line
- **loading balance**
	- 🙂 [uva/11389](./uva/11389.cpp) 
	- 😳 [uri/1055](./uri/1055.cpp) 

## divide & conquer
- 😳 [codeforces/768-B](./codeforces/768-B.cpp)  → knowing the size of the final array with a little math, use the same idea to query a range in a segment tree

## ad-hoc
- 🙂 [spoj/ADAQUEUE](./spoj/ADAQUEUE.cpp) 
- 🙂 [codeforces/1220-A](./codeforces/1220-A.cpp) 
- 🙂 [uri/2963](./uri/2963.cpp) 
- 🙂 [uri/2968](./uri/2968.cpp) 
- 🙂 [spoj/SBANK](./spoj/SBANK.cpp) 
- 🙂 [uri/3024](./uri/3024.cpp) 
- 🙂 [codeforces/1285-A](./codeforces/1285-A.cpp) 
- 🙂 [spoj/EC_CONB](./spoj/EC_CONB.cpp) 
- 🙂 [uva/10141](./uva/10141.cpp) 
- 🙂 [uva/12015](./uva/12015.cpp) 
- 🙂 [codeforces/37-A](./codeforces/37-A.cpp) 
- 🙂 [code-jam/2020-1C-overexcited-fan](./code-jam/2020-1C-overexcited-fan.cpp) 
- 🙂 [uva/12798](./uva/12798.cpp) 
- 🥵 [uri/1368](./uri/1368.cpp) 
- 🙂 [codeforces/151-A](./codeforces/151-A.cpp) 
- 🙂 [uri/2884](./uri/2884.cpp) 
- 🙂 [uri/2879](./uri/2879.cpp) 
- 🙂 [uva/11799](./uva/11799.cpp) 
- 🙂 [uri/2242](./uri/2242.cpp) 
- **implementation**
	- 🙂 [codeforces/811-B](./codeforces/811-B.cpp) 
	- 🙂 [spoj/GNY07D](./spoj/GNY07D.cpp) 
	- 😳 [uri/2971](./uri/2971.cpp) 
	- 🙂 [uva/105](./uva/105.cpp): `skyline` 
	- 🙂 [codeforces/373-A](./codeforces/373-A.cpp) 
	- 🙂 [code-jam/2020-QR-vestigium](./code-jam/2020-QR-vestigium.cpp) 
	- 🙂 [codeforces/1284-A](./codeforces/1284-A.cpp) 
	- 😳 [codeforces/1296-C](./codeforces/1296-C.cpp)  → maps each position of the robot with the string index, and check if a new position has already been mapped before
	- 🙂 [codeforces/492-B](./codeforces/492-B.cpp) 
	- 🙂 [uri/2593](./uri/2593.cpp) 
	- 🙂 [codeforces/110-A](./codeforces/110-A.cpp) 
	- 😳 [codeforces/1254-A](./codeforces/1254-A.cpp) 
	- 😳 [codeforces/519-C](./codeforces/519-C.cpp) 
	- 🙂 [uri/1975](./uri/1975.cpp) 
	- 🙂 [uri/1215](./uri/1215.cpp) 
	- 🙂 [codeforces/266-A](./codeforces/266-A.cpp) 
	- 🙂 [codeforces/81-A](./codeforces/81-A.cpp) 
	- 🙂 [uri/1261](./uri/1261.cpp) 
	- 🙂 [uri/1260](./uri/1260.cpp) 
	- 🙂 [uri/1763](./uri/1763.cpp) 
	- 🙂 [codeforces/158-C](./codeforces/158-C.cpp) 

## brute force
- **recursive backtracking**
	- 🙂 [uva/10344](./uva/10344.cpp): `check if some arithmetic expression of 5 given numbers will result in 23`  → check all combination of operators for each permutation of the given numbers
	- 🙂 [code-jam/2020-QR-indicium-TLE](./code-jam/2020-QR-indicium-TLE.cpp): `generate M, where M[i][j] is any value in [1 .. N] (2 <= N <= 5), but without repeting a value in same line or column, and with the sum of the main diagonal equal to K` 
	- 😳 [uva/10503](./uva/10503.cpp): `given domino pieces, check if it is possible to arrive at a target piece from an initial piece using N intermediate pieces (possibly rotating them)`  → DFS + backtracking
	- 🙂 [spoj/MKJUMPS](./spoj/MKJUMPS.cpp): `given an unweighted implicit graph, count the longest possible path`  → DFS + backtracking
	- 🙂 [live-archive/2883](./live-archive/2883.cpp): `chess with a single horse against up to 8 pawns; print the length of the minimum sequence of horse moves if it wins` 
	- **n-queens**
		- 😳 [uva/11195](./uva/11195.cpp)  → use bitmask
	- **pruned permutations**
		- 😳 [uva/524](./uva/524.cpp) 
		- 🙂 [spoj/BTCK](./spoj/BTCK.cpp) 
	- **sudoku**
		- 🙂 [uva/989](./uva/989.cpp) 
- **iterative**
	- 😳 [uva/12792](./uva/12792.cpp): `simulation`  → note that if you 'watch' a unique card, the full deck will become sorted as soon as this card reaches its original position
	- 🙂 [uva/12801](./uva/12801.cpp) 
	- 🙂 [codeforces/633-A](./codeforces/633-A.cpp): `check if a diophantine equation has positive solution` 
	- 🙂 [uva/628](./uva/628.cpp) 
	- 🙂 [uva/10360](./uva/10360.cpp) 
	- 🙂 [uva/725](./uva/725.cpp) 
	- **all subsets**
		- 🙂 [codeforces/550-B](./codeforces/550-B.cpp)  → use bitmask
		- 🙂 [uva/12455](./uva/12455.cpp)  → use bitmask
	- **all permutations**
		- 🙂 [uva/750](./uva/750.cpp) 