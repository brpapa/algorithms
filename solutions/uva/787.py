'''
   dynamic programming > max 1D range sum
   difficulty: medium
   date: 20/Feb/2020
   problem: max 1D range product query
   hint: compute for each sub-range without 0
   by: @brnpapa
'''
import math

a = [0]*110
accProd = [0]*110

# [l .. r-1]
def rpq(l, r):
   accProd[l] = a[l]
   for i in range(l+1, r):
      accProd[i] = a[i] * accProd[i-1]
      
   ans = -math.inf
   for i in range(l, r):
      for j in range(i, r):
         ans = max(ans, accProd[j]//(accProd[i-1] if i > l else 1))
   
   return ans

while (1):
   try:
      line = input().split(' ')
   except EOFError:
      break

   ans = -math.inf
   l = 0
   for r in range(0, len(line)):
      a[r] = int(line[r])
      if (a[r] == -999999):
         ans = max(ans, rpq(l, r))
         break
      elif (a[r] == 0):
         ans = max(ans, 0, rpq(l, r))
         l = r+1
   
   print(int(ans))
