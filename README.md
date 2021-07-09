<p align="center">"Think twice, code once"</p>

# Overview

I use this repository as a study playground for programming contests, which contains my personal notes and implementations. Note that this is a publish-only repository, so all pull requests will be ignored.

The **folders structure** is following:

- [`notebook`](./notebook): well-explained implementation of general-purpose algorithms.
- [`scripts`](./scripts): small scripts for automatizing some repetitive tasks.
- [`solutions`](./solutions): code of accepted problems, categorized by online judges.
   - [`README.md`](./solutions/README.md): solutions index by themes, containing difficulty, name, description and hint of the problem.

# Notebook index

## 🧱 data structures

- [segment tree](./notebook/data-structures/seg-tree.cpp)
- [lazy segment tree](./notebook/data-structures/seg-tree-lazy.cpp)
- [sparse table](./notebook/data-structures/sparse-table.cpp)
- [union-find disjoint sets (UFDS)](./notebook/data-structures/ufds.cpp)
<!-- - SQRT decomposition https://www.spoj.com/problems/RACETIME/en/ -->
<!-- - Wavelet tree https://github.com/andrefakhoury/competitive-programming/blob/master/lib/DataStructures/WaveletTree.hpp -->

## 🥊 brute force

- []()

## 🔞 dynamic programming

- [coin change](./notebook/dynamic-programming/coin-change.cpp)
- [subset sum](./notebook/dynamic-programming/subset-sum.cpp)
- [0-1 knapsack](./notebook/dynamic-programming/0-1-knapsack.cpp)
- [edit distance](./notebook/dynamic-programming/edit-distance.cpp)
- [longest increasing subsequence (LIS)](./notebook/dynamic-programming/lis.cpp)
- [longest common subsequence (LCS)](./notebook/dynamic-programming/lcs.cpp)
   - [LCS reduced to LIS](./notebook/dynamic-programming/lcs-reduced-to-lis.cpp)
- [longest palindromic subsequence (LPS)](./notebook/dynamic-programming/lps.cpp)
- [traveling salesman problem (TSP)](./notebook/dynamic-programming/tsp.cpp)
- [matrix chain multiplication (MCM)](./notebook/dynamic-programming/mcm.cpp)
- [rod cutting](./notebook/dynamic-programming/rod-cutting.cpp)

## 🌍 graphs

- [data structures representation](./notebook/graphs/ds-representation.md)
- **traversal**
   - [depth-first search (DFS)](./notebook/graphs/dfs.cpp)
   - [breadth-first search (BFS)](./notebook/graphs/bfs.cpp)
   - [flood fill](./notebook/graphs/flood-fill.cpp)
   - [edge classification](./notebook/graphs/edge-classification.cpp)
   - [bridges and articulations points](./notebook/graphs/bridges-and-articulations.cpp)
   - [strongly connected components (SCC)](./notebook/graphs/scc.cpp)
   - **topological sorting**
      - [kahn](./notebook/graphs/topo-sort-kahn.cpp)
      - [naive](./notebook/graphs/topo-sort.cpp)
- **minimum spanning tree (MST)**
   - [kruskal](./notebook/graphs/mst-kruskal.cpp)
   - **variants**
      - [minimax path](./notebook/graphs/mst-minimax-path.cpp)
      <!--TODO - [2nd best MST](./notebook/graphs/mst-2nd-best.cpp) -->
- **network flow**
   - [max flow w/ edmonds karp](./notebook/graphs/edmonds-karp.cpp)
   - [min cost max flow](./notebook/graphs/mcmf.cpp)
- **shortest path**
   - **single-source**
      - [bellman ford](./notebook/graphs/bellman-ford.cpp)
      - [dijkstra](./notebook/graphs/dijkstra.cpp)
      <!-- - **all-pairs** -->
- **specials**
   - [**bipartite graph**](./notebook/graphs/bipartite.md)
      - [bipartite checking](./notebook/graphs/bipartite-checking.cpp)
      - [maximum cardinality bipartite matching](./notebook/graphs/mcbm.cpp)
   - [**directed acyclic graph**](./notebook/graphs/dag.md)
   - [**tree**](./notebook/graphs/tree.md)
      - [heavy-light decomposition (HLD)](./notebook/graphs/hld.cpp)
      - **lowest common ancestor (LCA)**
         - [binary lifting](./notebook/graphs/lca-binary-lifting.cpp)
         - [eulerian tour](./notebook/graphs/lca-eulerian-tour.cpp)

## ✏️ math

- **number theory**
   - [fast exponentiation](./notebook/math/fast-power.cpp)
   - **prime numbers**
      - [prime checking](./notebook/math/prime-checking.cpp)
      - [sieve of eratosthenes](./notebook/math/sieve.cpp)
      - [modified sieve](./notebook/math/modified-sieve.cpp)
      - [optimized prime checking](./notebook/math/optimized-prime-checking.cpp)
      - [prime factors of n](./notebook/math/prime-factors.cpp)
      - [prime factors of n!](./notebook/math/factorial-prime-factors.cpp)
      - [number of divisors of n](./notebook/math/num-div.cpp)
      - [sum of divisors of n](./notebook/math/sum-div.cpp)
- **matrix exponentiation**
   - [linear recurrences](./notebook/math/linear-recurrence.cpp)
      - [utility in graph](./notebook/math/linear-recurrence-graph.cpp)
      - [utility in counting](./notebook/math/linear-recurrence-counting.cpp)
<!-- - [**game theory**](./notebook/math/game-theory.md) -->
   <!-- - [minimax](./notebook/math/minimax.md) -->
   <!-- - [nim](./notebook/math/nim.md) -->
   <!-- - [grundy numbers]() -->
   <!-- - [sprague-grundy theorem]() -->

<!-- ## strings -->

## 💭 miscellaneous

- [binary search](./notebook/miscellaneous/binary-search.md)
- [bitmasks](./notebook/miscellaneous/bitmasks.cpp)
- [two pointers](./notebook/miscellaneous/two-pointers.md)

# References

- HALIM, Steven. "Competitive Programming 3: The new lower bound of programming contests".
