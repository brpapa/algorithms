# Two pointers

Para responder perguntas do tipo **"em qual intervalo"**.

## Exemplo 1

**Motivação**: encontre o tamanho da **maior subsequência contígua** de um array com soma <= **K**.

-  Dado:

   ```cpp
   vector<int> A(N);
   int K; // condição de cada segmento
   ```

-  Algoritmo: O(2\*N) = **O(N)**

   ```cpp
   int l, r = 0; // ponteiros de A
   int k = 0;    // referente ao segmento atual de A

   int max_len = 0;
   for (l = 0; l < N; l++) {
   	if (l > 0) k -= A[l-1];

   	// k: soma em A[l..r-1]
   	while (k+A[r] <= K && r < N)
   		k += A[r], r++;

   	max_len = max(max_len, r-l);
   }

   return max_len;
   ```

-  Algoritmo alternativo pré-processando a **soma de prefixos**: O(N+1 + 2\*(N+1)) = **O(N)**

   ```cpp
   vector<int> sum(N+1); // sum[i]: soma em [0..i-1] de a
   sum[0] = 0;
   for (int i = 1; i < N+1; i++)
   	sum[i] = a[i-1] + sum[i-1];
   ```

   ```cpp
   // não preciso me preocupar com k

   int l, r = 0; // pointers de sum
   int max_len = 0;
   for (l = 0; l < N+1; l++) {
   	// sum[r]-sum[l]: soma em [l..r-1] de a

   	while (sum[r+1] - sum[l] <= K && r+1 < N+1)
   		r++;

   	max_len = max(max_len, r-l);
   }
   return max_len;
   ```

## Exemplo 2

**Motivação**: em um array **ordenado**, verifique se `a[l] + a[r] == K`, para algum 0 <= l <> r < N.

-  Dado:

   ```cpp
   vector<int> arr(N);
   int K;
   ```

-  Algoritmo:

   ```cpp
   int l = 0, r = N-1;

   while (l < r) {
   	int sum = arr[l]+arr[k];

   	if (sum == K)
   		return true;

   	if (sum < K) l++;
   	else r--;
   }
   return false;
   ```
