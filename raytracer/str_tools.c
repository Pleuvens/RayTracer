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
