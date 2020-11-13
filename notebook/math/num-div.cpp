/*
   Motivation: get the number of divisors of n.

   Teorema:
      Sendo a, b, ..., c os fatores primos de n:
      n = a^i * b^j * ... * c^k  <==>  num_div(n) = (i+1) * (j+1) * ... * (k+1)

   Exemplo:
      n = 60 = 2^2 * 3^1 * 5^1
      div(60) = {1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60}
      num_div(60) = (2+1)*(1+1)*(1+1) = 12
*/
