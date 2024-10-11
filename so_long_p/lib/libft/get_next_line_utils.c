/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:48 by stalash           #+#    #+#             */
/*   Updated: 2024/10/10 16:28:02 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_line(t_line *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		i = 0;
		while (list->content[i] && BUFFER_SIZE > i)
		{
			if (list->content[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

t_line	*ft_lstlast_of_gnl(t_line *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	copy_list(t_line *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->content[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_of_list(t_line *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	dealloc(t_line **list, t_line *clean_node, char *str)
{
	t_line	*last_node;
	t_line	*temp;

	if (list == NULL || *list == NULL)
		return ;
	last_node = *list;
	while (last_node != NULL)
	{
		temp = last_node;
		last_node = last_node->next;
		free(temp->content);
		free(temp);
	}
	*list = NULL;
	if (clean_node->content[0] != 0)
		*list = clean_node;
	else
	{
		free(str);
		free(clean_node);
	}
}
