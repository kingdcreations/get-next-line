/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:21:11 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 12:09:10 by tmarcon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int ret;
	int sz;
	char *buf;
	char *tmp;
	static char *nextl;

	sz = 0;
	ret = 1;
	if(!(buf = (char *)calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	if (*line)
		free(*line);
	*line = (nextl) ? ft_strdup(nextl + 1) : ft_strdup("");
	while (!(strchr(*line, '\n')))
	{
		sz = read(fd, buf, BUFFER_SIZE);
		if (sz != 0)
		{
			buf[sz] = '\0';
			tmp = ft_strjoin(*line, buf);
			free(*line);
			*line = tmp;
		}
		else
		{
			free(buf);
			buf = NULL;
			sz = -1;
			ret = 0;
			break;
		}
	}
	if (sz != -1)
	{
		free(nextl);
		nextl = ft_strdup(strchr(*line, '\n'));
		*line = ft_substr(*line, 0, strlen(*line) - strlen(nextl));
		free(buf);
		buf = NULL;
	}
	else
	{
		free(nextl);
		nextl = NULL;
	}
	return(ret);
}
