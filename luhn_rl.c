/* luhn.c -- simplified right to left luhn algorithm.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Sun Oct 23 06:39:15 AM EEST 2022
 * Copyright: (c) 2022 Luis Colorado.  All rights reserved.
 * License: BSD.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

const static char luhn_tab[][10] = {

    /* state 0, accepting state */
    { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 },
    { 11, 12, 13, 14, 15, 16, 17, 18, 19, 10 },
    { 12, 13, 14, 15, 16, 17, 18, 19, 10, 11 },
    { 13, 14, 15, 16, 17, 18, 19, 10, 11, 12 },
    { 14, 15, 16, 17, 18, 19, 10, 11, 12, 13 },
    { 15, 16, 17, 18, 19, 10, 11, 12, 13, 14 },
    { 16, 17, 18, 19, 10, 11, 12, 13, 14, 15 },
    { 17, 18, 19, 10, 11, 12, 13, 14, 15, 16 },
    { 18, 19, 10, 11, 12, 13, 14, 15, 16, 17 },
    { 19, 10, 11, 12, 13, 14, 15, 16, 17, 18 },

    /* state 10, accepting state */
    {  0,  2,  4,  6,  8,  1,  3,  5,  7,  9 },
    {  1,  3,  5,  7,  9,  2,  4,  6,  8,  0 },
    {  2,  4,  6,  8,  0,  3,  5,  7,  9,  1 },
    {  3,  5,  7,  9,  1,  4,  6,  8,  0,  2 },
    {  4,  6,  8,  0,  2,  5,  7,  9,  1,  3 },
    {  5,  7,  9,  1,  3,  6,  8,  0,  2,  4 },
    {  6,  8,  0,  2,  4,  7,  9,  1,  3,  5 },
    {  7,  9,  1,  3,  5,  8,  0,  2,  4,  6 },
    {  8,  0,  2,  4,  6,  9,  1,  3,  5,  7 },
    {  9,  1,  3,  5,  7,  0,  2,  4,  6,  8 },
};

const static int accepting = (1 << 0) | (1 << 10);

int luhn_ok(char *s, size_t s_len)
{
    s += s_len; /* point to the string end */
    char st = 0; /* automaton state, initially zero */
    while (s_len--) {
        if (isdigit(*--s)) {
            /* operate only on digits, skipping nondigits */
            st = luhn_tab[st][*s - '0'];
        }
    }
    return ((1 << st) & accepting) != 0;
} /* luhn_ok */

int main(int argc, char **argv)
{
    if (argc > 1) for (int i = 1; i < argc; i++) {
        printf("%s%s\n",
                argv[i],
                luhn_ok(argv[i], strlen(argv[i]))
                    ? "!"
                    : "?");
    } else {
        char buffer[1024];
        while (fgets(buffer, sizeof buffer, stdin)) {
            strtok(buffer, "\n");
            printf("%s%s\n",
                    buffer,
                    luhn_ok(buffer, strlen(buffer))
                        ? "!"
                        : "?");
        }
    }
} /* main */
