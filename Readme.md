# LUHN algorithm implemented as an automaton.

This repository implements an automaton capable of
recognizing correct LUHN encoded sequences of characters.

LUHN algorithm consists of adding the odd numbered
positions (counting from the less signifiant digit to
the most) with the doubled even positions (the digits
of the result are added together, resulting in a mod 9
operation) and getting the remainder, mod 10 of the total.
If the result is 0, then the LUHN code is correct.
```
,---v---v---v---v---v---v---v---v---v---v---v---.
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | 3 |
`---^---^---^---^---^---^---^---^---^---^---^---'
  |   |   |   |   |   |   |   |   |   |   |   |
 *2   |  *2   |  *2   |  *2   |  *2   |  *2   |
  |   |   |   |   |   |   |   |   |   |   |   |
  0   |   4   |   8   |  12   |  16   |   0   |
  |   |   |   |   |   |   |   |   |   |   |   |
 %9   |  %9   |  %9   |  %9   |  %9   |  %9   |
  |   |   |   |   |   |   |   |   |   |   |   |
  0   1   4   3   8   5   3   7   7   9   0   3
  |   |   |   |   |   |   |   |   |   |   |   |
  `---+---+---+---+---+---+---+---+---+---+---+
                                              /
         0+1+4+3+8+5+3+7+7+9+0+3=50 <--------'
                                  |
                                %10
                                  |
                                  V
                                  0  OK
```
The `luhn_rl.c` positions the pointer at the end of
the string and goes backwards on the string of digits,
using the simpler table in `luhn_rl.c`.

The `luhn.c` scans the string from the left, but uses
a more elaborate automaton, as now both remainders
(the one for odd/even positions) have to be carried
while scanning, resulting in a 100 states automaton.

Anyway, using an `unsigned char` array for the _next state_
table, the table uses just 1000bytes of memory, making it
suitable for a fast implementation (no adding, multiplication,
division or remainder operations are done by the automaton)

To compile these programs, just
```
make
```
and you are done.  `luhn` & `luhn_r2l` take their arguments
from the command line, or if no arguments are given, from
the standard input (one per line of input)  Both programs output
the input string, followed by a `"OK"` or `"BAD"` result code.
