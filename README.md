Note: this is a publish-only repository, so all pull requests will be ignored.

The **folders structure** is following:

- [`notebook`](./notebook): well-explained implementation of general-purpose algorithms.
- [`scripts`](./scripts): small scripts for automatizing some repetitive tasks.
- [`solutions`](./solutions): code of accepted problems, categorized by online judges.
- [`solutions/README.md`](./solutions/README.md): solutions index by themes, containing difficulty, name, description and hint of the problem.

<h1 align="center">Notebook index</h1>
<!-- https://www.geeksforgeeks.org/top-algorithms-and-data-structures-for-competitive-programming/ -->
<!-- https://cp-algorithms.com/ -->

## 🧱 data structures

- [segment tree](./notebook/data-structures/seg-tree.cpp)
- [lazy segment tree](./notebook/data-structures/seg-tree-lazy.cpp)
- [sparse table](./notebook/data-structures/sparse-table.cpp)
- [union-find disjoint sets (UFDS)](./notebook/data-structures/ufds.cpp)
<!-- - SQRT decomposition https://www.spoj.com/problems/RACETIME/en/ -->

<!-- ## 🥊 brute force -->

## 🔞 dynamic programming

- [coin change](./notebook/dynamic-programming/coin-change.cpp)
- [subset sum](./notebook/dynamic-programming/subset-sum.cpp)
- [0-1 knapsack](./notebook/dynamic-programming/0-1-knapsack.cpp)
- [longest increasing subsequence (LIS)](./notebook/dynamic-programming/lis.cpp)
- [longest common subsequence (LCS)](./notebook/dynamic-programming/lcs.cpp)
- [LCS reduced to LIS](./notebook/dynamic-programming/lcs-reduced-to-lis.cpp)
- [traveling salesman problem (TSP)](./notebook/dynamic-programming/tsp.cpp)
- [matrix chain multiplication (MCM)](./notebook/dynamic-programming/mcm.cpp)
- [rod cutting](./notebook/dynamic-programming/rod-cutting.cpp)
- [longest palindromic subsequence (LPS)](./notebook/dynamic-programming/lps.cpp)

## 🌍 graphs

- **traversal**
   - [depth-first search (DFS)](./notebook/graphs/dfs.cpp)
   - [breadth-first search (BFS)](./notebook/graphs/bfs.cpp)
   - [bridges and articulations points](./notebook/graphs/bridges-or-articulations.cpp)
   - **topological sorting**
      - [kahn](./notebook/graphs/topo-sort-kahn.cpp)
      - [naive](./notebook/graphs/topo-sort.cpp)
- **minimum spanning tree (MST)**
   - [kruskal](./notebook/graphs/mst-kruskal.cpp)
   - **variants**
      - [minimax path](./notebook/graphs/mst-minimax-path.cpp)
      <!--TODO - [2nd best mst](./notebook/graphs/mst-2nd-best.cpp) -->
- **network flow**
   - **max flow**
      - [edmonds karp](./notebook/graphs/edmonds-karp.cpp)
   - [min cost max flow](./notebook/graphs/mcmf.cpp)
- **shortest path**
   - **single-source**
      - [bellman ford](./notebook/graphs/sssp-bellman-ford.cpp)
      - [dijkstra](./notebook/graphs/sssp-dijkstra.cpp)
      <!-- - **all-pairs** -->
- **specials**
   - [**bipartite graph**](./notebook/graphs/bipartite.md)
      - [bipartite checking](./notebook/graphs/bipartite-checking.cpp)
      - [maximum cardinality bipartite matching](./notebook/graphs/mcbm.cpp)
   - [**directed acyclic graph**](./notebook/graphs/dag.md)
   - [**tree**](./notebook/graphs/tree.md)
      - [lowest common ancestor (LCA)](./notebook/graphs/lca-eulerian-tour.cpp)
      - [heavy-light decomposition (HLD)](./notebook/graphs/hld.cpp)

## ✏️ math

- **number theory**
   - [fast power](./notebook/math/fast-power.cpp)
<!-- - [**game theory**](./notebook/math/game-theory.md) -->
   <!-- - [minimax](./notebook/math/minimax.md) -->
   <!-- - [nim](./notebook/math/nim.md) -->
   <!-- - [grundy numbers]() -->
   <!-- - [sprague-grundy theorem]() -->
- [matrix power](./notebook/math/matrix-power.cpp)

<!-- ## strings -->

## 💭 miscellaneous

- [binary search](./notebook/miscellaneous/binary-search.md)
- [bitmasks](./notebook/miscellaneous/bitmasks.cpp)
- [two pointers](./notebook/miscellaneous/two-pointers.md)

# References

- HALIM, Steven. "Competitive Programming 3: The new lower bound of programming contests".
