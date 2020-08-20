/* let S be an 64-bit or 32-bit integer (mask), and considering 0-based indexing in increasing bit significance */

#define pow2(i) (1 << (i)) // = 2^i
#define mul_by_pow2(S, i) (S << i) // = S*(2^i)
#define div_by_pow2(S, i) (S >> i) // = S/(2^i)

#define set_bit(S, i) (S |= (1 << i)) // liga o i-ésimo bit de S
#define clear_bit(S, i) (S &= ~(1 << i)) // desliga o i-ésimo bit de S
#define toggle_bit(S, i) (S ^= (1 << i)) // inverte o i-ésimo bit de S
#define low_bit(S) (S & (-S)) // retorna o valor do bit menos significante ligado de S
#define set_all(n) ((1 << n) - 1) // retorna um conjunto de tamanho n com todos os bits ligado.
#define bit_is_on(S, i) (S & (1 << i)) // retorna 1, se o i-ésimo bit de S está ligado, caso contrário, 0

/*
       S = 34 = 100010
i = 3: 1 << 3 = 001000
                ------ or // 0, se ambos os bits são 0
       S = 42 = 101010        


          S = 42 = 101010
i = 1: ~(1 << 1) = 111101
                   ------ and // 1, se ambos os bits são 1
          S = 40 = 101000


       S = 40 = 101000
i = 3: 1 << 3 = 001000
                ------ xor // 1, se os bits são distintos entre si
       S = 32 = 100000


        S =  40 = 0...0101000
       -S = -40 = 1...1011000 // c-2
                  ----------- and // 1, se ambos os bits são 1
low_bit(40) = 8 = 0...0001000


 n = 3: 1 << 3 = 1000
					     1
                 ---- -
set_all(3) = 7 =  111


              S = 42 = 101010
       i = 2: 1 << 2 = 000100
                       ------ and // 1, se ambos os bits são 1
bit_is_on(42, 2) = 0 = 000000
*/
