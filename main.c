/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:18:48 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 10:48:10 by tmarcon     ###    #+. /#+    ###.fr     */
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

	res = 1;
	i = 1;
	line = NULL;
	fd = open("fewchar_perline.txt", O_RDONLY);

	while (res)
	{
		res = get_next_line(fd, &line);
		printf("(%d)(%d) %s\n", i++, res, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return(0);
}
