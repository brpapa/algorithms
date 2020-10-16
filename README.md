This is a publish-only repository, so all pull requests will be ignored.

The folders structure is following:

- [`notebook`](./notebook): well-explained implementation of general-purpose algorithms.
- [`scripts`](./scripts): small scripts for automatizing some repetitive tasks.
- [`solutions`](./solutions): code of accepted problems, categorized by online judges.
- [`solutions/README.md`](./solutions/README.md): solutions index by themes, with difficulty, name, description and hint of the problem.

<h1 align="center">Notebook index</h1>

## data structures

- [segment tree](./notebook/data-structures/seg-tree.cpp)
- [lazy segment tree](./notebook/data-structures/seg-tree-lazy.cpp)
- [sparse table](./notebook/data-structures/sparse-table.cpp)
- [union-find disjoint sets](./notebook/data-structures/ufds.cpp)

## dynamic programming

- [coin change](./notebook/dynamic-programming/coin-change.cpp)
- [subset sum](./notebook/dynamic-programming/subset-sum.cpp)
- [0-1 knapsack](./notebook/dynamic-programming/knapsack.cpp)
- [longest increasing subsequence](./notebook/dynamic-programming/lis.cpp)
- [traveling salesman problem](./notebook/dynamic-programming/tsp.cpp)

## graphs

- **traversal**
   - [breadth-first search](./notebook/graphs/bfs.cpp)
   - [depth-first search](./notebook/graphs/dfs.cpp)
   - [bridges or articulations points](./notebook/graphs/bridges-or-articulations.cpp)
   - **topological sorting**
      - [kahn](./notebook/graphs/topo-sort-kahn.cpp)
      - [naive](./notebook/graphs/topo-sort.cpp)
- **minimum spanning tree**
   - [kruskal](./notebook/graphs/mst-kruskal.cpp)
   - **variants**
      - [minimax path](./notebook/graphs/mst-minimax-path.cpp)
      <!--TODO - [2nd best mst](./notebook/graphs/mst-2nd-best.cpp) -->
- **network flow**
   - **max flow**
      - [edmonds karp](./notebook/graphs/edmonds-karp.cpp)
   - [min cost max flow](./notebook/graphs/min-cost-max-flow.cpp)
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
      <!-- - [] -->
   - [**tree**](./notebook/graphs/tree.md)
      - [lowest common ancestor](./notebook/graphs/lca-eulerian-tour.cpp)

## math

- **number theory**
   - [fast exponentiation](./notebook/math/fast-exponentiation.cpp)
- [matrix exponentiation](./notebook/math/matrix-exponentiation.cpp)

<!-- ## strings -->

## miscellaneous

- [binary search](./notebook/misc/binary-search.md)
- [bitmasks](./notebook/misc/bitmasks.cpp)

# Acknowledgements

- HALIM, Steven. "Competitive Programming 3: The new lower bound of programming contests".
