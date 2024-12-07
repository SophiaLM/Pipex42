#include "libft.h"

void	 ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*current;

	if (!*lst || !lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		del(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}
