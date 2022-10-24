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
'---v---v---v---v---v---v---v---v---v---v---v---`
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
