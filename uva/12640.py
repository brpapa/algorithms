'''
   dynamic programming > max 1D range sum > kadane
   difficulty: easy
   date: 24/Mar/2020
   problem: find the max range sum considering the possibility of a sub-range of length 0
   by: @brnpapa
'''

while (1):
   try:
      line = input().split(' ')
   except EOFError:
      break

   ans = acc = 0

   for num in line:
      acc = max(0, acc + int(num))
      ans = max(ans, acc)

   print(ans)