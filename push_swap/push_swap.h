#ifndef __PUSH_SWAP__
#define __PUSH_SWAP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stack
{
    long num;
    long index;
    struct s_stack *next;
} t_stack;

t_stack *t_stack_new(int content, int i);
void t_stack_back(t_stack **a, t_stack *b);
char **ft_split(char *str, char delim);
void ft_error();
int ft_isdigit(char *str);
int ft_atoi2(char *str);
void check_dup(t_stack *a, int n);

#endif
