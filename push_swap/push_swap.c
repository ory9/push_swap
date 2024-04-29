#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a = NULL;
    char **tmp;
    int j;
    int i = 1;

    check_dup(stack_a, ft_atoi2(av[i]));
    if (ac > 2)
    {
        i = 1;
        while (av[i] != NULL)
        {
            t_stack_back(&stack_a, t_stack_new(atoi(av[i]), i));
            i++;
        }
    }
    else if (ac == 2 && !(av[1][0] == '"' && av[1][ac - 1] == '"'))
        exit(0);
    else if (ac == 2 && av[1][0] == '"' && av[1][ac - 1] == '"')
    {
        i = 1;
        tmp = ft_split(av[i], '\n');
        if (tmp == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        while (tmp[i] != NULL)
        {  
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
