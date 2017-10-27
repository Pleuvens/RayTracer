#include "rt.h"

int my_atoi(char *s)
{
  if (!s || !*s)
    return 0;
  int neg = 1;
  if (*s == '-')
  {
    neg = -1;
    ++s;
  }
  int res = 0;
  while (*s)
  {
    res = res * 10 + *s - '0';
    ++s;
  }
  return neg * res;
}

int my_strcontains(char *s, char *subs, size_t len, size_t slen)
{
  if (!s || !*s || !subs || slen > len)
    return 0;
  for (size_t i = 0; i < len; ++i)
    if (*s == *subs && my_strncmp(s + i, subs, slen))
      return 1;
  return 0;
}
