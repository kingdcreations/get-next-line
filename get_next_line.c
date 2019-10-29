/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:21:11 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 13:43:24 by tmarcon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void output(int sz, char **nextl, char **line, char **buff)
{
	if (sz != -1)
	{
		free(*nextl);
		*nextl = ft_strdup(strchr(*line, '\n'));
		*line = ft_substr(*line, 0, strlen(*line) - strlen(*nextl));
		free(*buff);
		*buff = NULL;
	}
	else
	{
		free(*nextl);
		*nextl = NULL;
	}
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	int			sz;
	char		*buff;
	char		*tmp;
	static char	*nextl;

	sz = 0;
	ret = 1;
	if (!(buff = (char *)calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	*line = (nextl) ? ft_strdup(nextl + 1) : ft_strdup("");
	while (!(strchr(*line, '\n')))
	{
		sz = read(fd, buff, BUFFER_SIZE);
		if (sz != 0)
		{
			buff[sz] = '\0';
			tmp = ft_strjoin(*line, buff);
			free(*line);
			*line = tmp;
		}
		else
		{
			free(buff);
			buff = NULL;
			sz = -1;
			ret = 0;
			break ;
		}
	}
	output(sz, &nextl, line, &buff);
	return (ret);
}
