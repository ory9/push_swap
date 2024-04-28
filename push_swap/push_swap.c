#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    long num;
    long index;
    struct s_stack *next;
} t_stack;

t_stack *t_stack_new(int content, int i);
void t_stack_back(t_stack **a, t_stack *b);
char **ft_split(char *str, char delim);
void ft_error(void);
int ft_isdigit(char *str);
int ft_atoi2(char *str);
void check_dup(t_stack *a, int n);

int main(int ac, char **av)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    char **tmp;
    int j;
    int i = 0;

    if (ac == 2)
    {
        i = 1;
        tmp = ft_split(av[i], '\n');
        if (tmp == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        while (tmp[i] != NULL)
        {  
            check_dup(stack_a, ft_atoi2(tmp[i]));
            t_stack_back(&stack_a, t_stack_new(ft_atoi2(tmp[i]), i));
            i++;
        }

        // Free memory allocated by ft_split
        j = 0;
        while (tmp[j] != NULL) 
        {
            free(tmp[j]);
            j++;
        }
        free(tmp);
    }
    else if (ac > 2)
    {
        i = 1;
        while (av[i] != NULL)
        {
            t_stack_back(&stack_a, t_stack_new(atoi(av[i]), i));
            i++;
        }
    }
    else
    {
        printf("error!\n");
        exit(1);
    }

    while (stack_a != NULL)
    {
        printf("%ld\n", stack_a->num);
        stack_a = stack_a->next;
    }
    return 0;
}

t_stack *t_stack_new(int content, int i)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->num = content;
    new_node->index = i;
    new_node->next = NULL;
    return new_node;
}

void t_stack_back(t_stack **a, t_stack *b)
{
    if (*a == NULL)
    {
        *a = b;
    }
    else
    {
        t_stack *temp = *a;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = b;
    }
}

char **ft_split(char *str, char delim)
{
    int token_num = 0;
    int token_start = 0;
    int token_end = 0;
    int token_index = 0;
    char **tokens;
    int i;

    while (str[token_end] != '\0')
    {
        if (str[token_end] == delim)
        {
            token_num++;
        }
        token_end++;
    }

    tokens = (char **)malloc((token_num + 1) * sizeof(char *));
    if (tokens == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    token_end = 0;
    while (str[token_end] != '\0')
    {
        if (str[token_end] == delim || str[token_end] == '\0')
        {
            int token_length = token_end - token_start;
            tokens[token_index] = (char *)malloc((token_length + 1) * sizeof(char));
            if (tokens[token_index] == NULL)
            {
                printf("Memory allocation failed!\n");
                return NULL;
            }
            i = 0;
            while (i++ < token_length)
            {
                tokens[token_index][i] = str[token_start + i];
            }
            tokens[token_index][token_length] = '\0';
            token_index++;
            token_start = token_end + 1;
        }
        token_end++;
    }

    tokens[token_index] = NULL;

    return tokens;
}

int ft_atoi2(char *str)
{
    int sign = 1;
    long long int i = 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == 34)
        str++;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str)
    {
        if (!ft_isdigit(str))
            ft_error();
        i = i * 10 + (*str - 48);
        str++;
    }
    if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
        ft_error();
    return (sign * i);
}

int ft_isdigit(char *str)
{
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return 0;
        str++;
    }
    return 1;
}

void ft_error(void)
{
    printf("error!\n");
    exit(1);
}


void check_dup(t_stack *a, int n)
{
    while (a != NULL)
    {
        if (a->num == n)
        {
            printf("%d is a duplicate!\n", n);
            exit(1);
        }
        a = a->next;
    }
}
