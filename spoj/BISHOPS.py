'''
   math > ad-hoc
   difficulty: easy
   date: 09/Jun/2020
   problem: how many bishops can be placed on a n x n chessboard without threatening each other?
   by: @brnpapa
'''

while (1):
   try:
      n = int(input())
      ans = n + (n-2 if n > 2 else 0)
      print(ans)
   except EOFError:
      break
