/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:18:48 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 15:54:02 by tmarcon     ###    #+. /#+    ###.fr     */
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

	while (res > 0)
	{
		res = get_next_line(fd, &line);
		printf("(%d)(%d) %s\n", i++, res, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return(0);
}
//
// int main(void)
// {
// 	char *line;
// 	char *line2;
// 	int fd;
// 	int fd2;
// 	int res;
// 	int res2;
// 	int i;
//
// 	res = 1;
// 	res2 = 1;
// 	i = 1;
// 	line = NULL;
// 	line2 = NULL;
// 	fd = open(NULL, O_RDONLY);
// 	fd2 = open("file.txt", O_RDONLY);
//
// 	res = get_next_line(fd, &line);
// 	printf("(%d)(%d) %s\n", i++, res, line);
// 	free(line);
// 	res2 = get_next_line(fd2, &line2);
// 	printf("(%d)(%d) %s\n", i++, res2, line2);
// 	free(line2);
//
// 	close(fd);
// 	return(0);
// }
