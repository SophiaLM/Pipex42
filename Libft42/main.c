#include "libft.h"
#include <stdlib.h>

void    print_list(t_list *lst)
{
	int	i = ft_lstsize(lst);
	int	j = 0;

        while (j < i)
        {
		j++;
                printf("%s\n", (char *)lst->content);
	       lst = lst->next;	
	}
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*node;
	int	i = 0;
	
	while(++i < ac)
	{
		node = ft_lstnew(av[i]);
		ft_lstadd_back(&lst, node);//si quiero sobreescribir le paso la clave, si quiero leer le paso solo el val
	}
	print_list(lst);
	return (0);
}
