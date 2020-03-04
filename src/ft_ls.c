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

int main(int ac, char **argv) 
{
    DIR *dir;
    t_dirent *entry;

	if (ac == 1)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);
    if (!dir)
	{
        perror("diropen");
        exit(1);
    }        
	while ((entry = readdir(dir)) != NULL)
        ft_printf("%llu - %s [%d] %d\n",
            entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    // while ((entry = readdir(dir)) != NULL)
    //     printf("%llu - %s [%d] %d\n",
    //         entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    closedir(dir);
    return (0);
}
