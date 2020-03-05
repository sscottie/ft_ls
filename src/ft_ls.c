/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:48:15 by sscottie          #+#    #+#             */
/*   Updated: 2020/03/04 19:43:35 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// int	*ls_fill_flags(int ac, char **av)
// {
// 	int i = 1;
// 	int *t;
// 	int j;

// 	i = 1;
// 	t = fill_tab(t);
// 	while (i < ac)
// 	{
// 		j = 1;
// 		if(av[i][0] == '-')
// 		{
// 			while(av[i][j] && av[i][j] >= 'a'  && av[i][j] <= 'z')
// 			{
// 				t['z' - av[i][j] + 6] = 1;
// 				j++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (t);
// }

// void	fill_rights(const char* name, t_stat *staty)
// {

// }

int main(int ac, char **av) 
{
    DIR			*dir;
    t_dirent	*entry;
	t_stat		*staty = NULL;

	if (ac == 1)
		dir = opendir(".");
	else
		dir = opendir(av[1]);
    if (!dir)
	{
        perror("diropen");
        exit(1);
    }        
	while ((entry = readdir(dir)) != NULL)
    {
		if (stat(entry->d_name, staty))
		{
			perror("fileread");
			exit(1);
		}
		// if (entry->d_name[0] != '.')
	    // 	ft_printf("%llu - %s [%d] %d\n",
        //     entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
		if (entry->d_name[0] != '.')
	    	ft_printf("%s\n",
            entry->d_name);
	}

	// while ((entry = readdir(dir)) != NULL)
    //     printf("%llu - %s [%d] %d\n",
    //         entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    closedir(dir);
    return (0);
}
