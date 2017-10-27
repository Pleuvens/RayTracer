#include <stdlib.h>

int my_strlen(char *s)
{
  int i = 0;
  for(; s[i] != '\0'; ++i)
    continue;
  return i;
}

int my_strlen_delim(char *s)
{
  int i = 0;
  for(; s[i] != '\0' && s[i] != '\n' && s[i] != ' '; ++i)
    continue;
  return i;
}

int my_strcmp(char *s1, char *s2)
{
  for (; *s1 != '\0' && *s2 != '\0'; ++s1, ++s2)
    if (*s1 != *s2)
      return 0;
  return *s1 == *s2;
}

int my_strncmp(char *s1, char *s2, int n)
{
  int i = 0;
  for (; i < n && s1[i] != '\0' && s2[i] != '\0'; ++i)
    if (s1[i] != s2[i])
      return 0;
  return 1;
}

char *my_strtok(char *s, int *index)
{
  int len = my_strlen_delim(s + *index); 
  char *token = calloc(len + 1, sizeof (char));
  if (!token)
    return NULL;
  for (int i = 0; i < len; ++i, *index += 1)
    token[i] = s[*index];
  *index += 1;
  return token;
}
