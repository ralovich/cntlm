#pragma once

#include <string.h>
#include <ctype.h>

static int bcmp(const void * p1, const void * p2, size_t n)
{
    return memcmp( p1, p2, n);
}

static void   bcopy(const void * src, void * dst, size_t n)
{
    memmove( dst, src, n);  /* note different order of args - yuck */
}

static void   bzero(void * p, size_t n)
{
    memset( p, 0, n);
}

static char   *index(const char * s, int c)
{
    return strchr( s, c);
}

static char   *rindex(const char * s, int c)
{
    return strrchr( s, c);
}

static int    strcasecmp(const char* s1, const char* s2)
{
    for (;;) {
        int c1 = tolower( *((unsigned char*) s1++));
        int c2 = tolower( *((unsigned char*) s2++));

        if ((c1 != c2) || (c1 == '\0')) {
            return( c1 - c2);
        }
    }
}

static int    strncasecmp(const char* s1, const char* s2, size_t n)
{
    for (; n != 0; --n) {
        int c1 = tolower( *((unsigned char*) s1++));
        int c2 = tolower( *((unsigned char*) s2++));

        if ((c1 != c2) || (c1 == '\0')) {
            return( c1 - c2);
        }
    }

    return( 0);
}


static int    ffs(int v)
{
    unsigned int x = v;
    int c = 1;

    /* 
     * adapted from from 
     *      http://graphics.stanford.edu/~seander/bithacks.html#ZerosOnRightBinSearch
     *
     * a modified binary search algorithm to count 0 bits from 
     *  the right (lsb).  This algorithm should work regardless 
     *  of the size of ints on the platform.
     *
     */

    /* a couple special cases */
    if (x == 0) return 0;
    if (x & 1)  return 1;   /* probably pretty common */

    c = 1;
    while ((x & 0xffff) == 0) {
        x >>= 16;
        c +=  16;
    }
    if ((x & 0xff) == 0) {
        x >>= 8;
        c +=  8;
    }
    if ((x & 0x0f) == 0) {
        x >>= 4;
        c +=  4;
    }
    if ((x & 0x03) == 0) {
        x >>= 2;
        c +=  2;
    }

    c -= (x & 1);
    c += 1;     /* ffs() requires indexing bits from 1 */
                /*   ie., the lsb is bit 1, not bit 0  */
    return c;
}

#if defined(_WIN32) || defined(_WIN64)
/* We are on Windows */
# define strtok_r strtok_s
# define atoll _atoi64
#endif
