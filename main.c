/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:18:48 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 14:55:40 by tmarcon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd;
	int res;
	int i;

	i = 1;
	line = NULL;
	fd = open("file.txt", O_RDONLY);
	while ((res = get_next_line(fd, &line)))
		printf("(%d)(%d) %s\n", i++, res, line);
	res = get_next_line(fd, &line);
	printf("(%d)(%d) %s\n", i, res, line);
	close(fd);
	return(0);
}
