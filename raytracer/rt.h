#ifndef RT_H
# define RT_H

int my_strlen(char *s);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, int n);

char *my_strtok(char *s, int *index);

int my_atoi(char *s);

int parse_camera(FILE *f);

int parse_input(char *path);

#endif /* !RT_H */
