/*
   Motivation: get the sum of all divisors of n.

   Teorema:
      Sendo a, b, ..., c os fatores primos de n:
      n = a^i * b^j * ... * c^k  <==>  sum_div(n) = (a^(i+1)-1)/(a-1) * (b^(j+1)-1)/(b-1) * ... * (c^(k+1)-1)/(c-1),

   Exemplo:
      n = 60
      div(60) = {1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60}
      sum_div(60) = 168
*/
