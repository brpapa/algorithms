/* 
   Uso de uma variável numérica para representar um conjunto de itens.
   
   Let S (up to 64-bit integer) be a mask, and considering 0-based indexing in increasing bit significance (that is, from the right).
*/
#include <bits/stdc++.h>
using namespace std;

#define is_odd(n) (n & 1ll)        // equals n % 2 == 1
#define pow2(i) (1ll << (i))       // equals 2^i
#define mul_by_pow2(S, i) (S << i) // equals S*(2^i)
#define div_by_pow2(S, i) (S >> i) // equals S/(2^i)

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
all_seted(3) = 7 =  111


              S = 42 = 101010
       i = 2: 1 << 2 = 000100
                       ------ and // 1, se ambos os bits são 1
bit_is_on(42, 2) = 0 = 000000
*/
#define set_bit(S, i) (S |= (1ll << i))    // liga o i-ésimo bit de S
#define reset_bit(S, i) (S &= ~(1ll << i)) // desliga o i-ésimo bit de S
#define toggle_bit(S, i) (S ^= (1ll << i)) // inverte o i-ésimo bit de S
#define reset_low_bit(S) (S &= (S-1))      // desliga o bit menos significativo ligado de S

#define low_bit(S) (S & (-S))            // retorna uma mask com apenas o bit menos significativo ligado de S
#define all_seted(n) ((1ll << n) - 1)    // retorna um conjunto de tamanho n com todos os bits ligado
#define bit_is_on(S, i) (S & (1ll << i)) // retorna 1 se o i-ésimo bit de S está ligado, ou 0

#define bits_on(S) (__builtin_popcountll(S)) // número de bits ligados
#define bits_off_r(S) (__builtin_ctzll(S))   // número de 0 à direita, ex: bits_off_r(8) = 3
#define bits_off_l(S) (__builtin_clzll(S))   // número de 0 à esquerda, ex: bits_off_l(2) = 31

#define union(S, T) (S | T)
#define intersection(S, T) (S & T)
#define complement(S) (~S)

/* 
   C++ bitset suport bitmasks operations too
*/
int main() {
   bitset<8> set8;    // 00000000
   set8[1] = 1;       // 00000010
   set8[4] = set8[1]; // 00010010

   int bits_on = set8.count();
   int bits_off = set8.size() - bits_on;

   cout << set8.test(1) << endl; // true

   if (set8.any()) cout << "set8 has some bit set.\n";
   if (!set8.none()) cout << "set8 has some bit set\n";

   set8.set();     // 11111111
   set8.set(4, 0); // 11101111
   set8.set(4);    // 11111111
   set8.reset(2);  // 11111011
   set8.reset();   // 00000000
   set8.flip(2);   // 00000100
   set8.flip();    // 11111011

   // ------- bitmask operations ------

   bitset<4> bs1(9); // bs1 contains 1001
   bitset<4> bs2(3); // bs2 contains 0011

   cout << (bs1 == bs2) << endl; // false 0
   cout << (bs1 != bs2) << endl; // true  1

   cout << (bs1 ^= bs2) << endl; // 1010
   cout << (bs1 &= bs2) << endl; // 0010
   cout << (bs1 |= bs2) << endl; // 0011

   cout << (bs1 <<= 2) << endl; // 1100
   cout << (bs1 >>= 1) << endl; // 0110

   cout << (~bs2) << endl;      // 1100
}