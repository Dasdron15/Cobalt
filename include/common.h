#ifndef COMMON_H
#define COMMON_H

char *mult_char(char c, int count);
int int_len(int num);
char *get_filename(char *path);
int rgb_to_ncurses(int rgb);
int count_char(char *string, char ch);
char **split(char *str, char delim);

#endif
