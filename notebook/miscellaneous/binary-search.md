# built-in methods

```cpp
vector<int> A = {1, 1, 3, 3, 4, 5};

// primeiro l, tal que A[l] >= 3
int l = lower_bound(A.begin(), A.end(), 3) - A.begin();
cout << l << endl; // 2

// primeiro u, tal que A[u] > 3
int u = upper_bound(A.begin(), A.end(), 3) - A.begin();
cout << u << endl; // 4

// se o valor buscado fosse < 1, ambos retornariam 0
// se o valor buscado fosse > 5, ambos retornariam A.size()

cout << binary_search(A.begin(), A.end(), 3) << endl; // true
cout << binary_search(A.begin(), A.end(), 0) << endl; // false
```

# binary search on answer

Vai otimizando a resposta, aplicando busca binária no intervalo de todas as respostas possíveis.

Dado uma resposta possível `mid`, deve ser permitido invalidar metade do intervalo de respostas.

```cpp
int lo = 0, hi = 10000;
int ans = -1; // ans em [lo .. hi]

while (lo <= hi) {
	int mid = (lo + hi)/2;

   // se mid é uma resposta possível
	if (can(mid)) ans = mid, hi = mid-1; // diminui mid na próxima
	else          lo = mid+1;            // aumenta mid na próxima
}

// se ans == -1, não há solução
```

# binary search on bisection method

Estima x tal que f(x) = 0, particionando um intervalo inicial válido enquanto um erro não for satisfeito. 

Se f(a)*f(b) > 0, f(a) e f(b) têm sinais opostos, logo f cruza o eixo x em algum lugar entre a e b.