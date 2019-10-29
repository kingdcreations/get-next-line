/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:21:11 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 14:50:49 by tmarcon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void	output(int ret, char **nextl, char **line, char **buff)
{
	if (ret != 0)
	{
		free(*nextl);
		*nextl = ft_strdup(ft_strchr(*line, '\n'));
		*line = ft_substr(*line, 0, ft_strlen(*line) - ft_strlen(*nextl));
	}
	else
	{
		free(*nextl);
		*nextl = NULL;
	}
	free(*buff);
	*buff = NULL;
}

int		get_next_line(int fd, char **line)
{
	int			sz;
	int			ret;
	char		*tmp;
	char		*buff;
	static char	*nextl;

	ret = 1;
	tmp = NULL;
	if (!line || read(fd, tmp, 0) < 0
	|| !(buff = (char *)calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	*line = (nextl) ? ft_strdup(nextl + 1) : ft_strdup("");
	while (!(ft_strchr(*line, '\n')) && ret != 0)
		if ((sz = read(fd, buff, BUFFER_SIZE)) != 0)
		{
			buff[sz] = '\0';
			tmp = ft_strjoin(*line, buff);
			free(*line);
			*line = tmp;
		}
		else
			ret = 0;
	output(ret, &nextl, line, &buff);
	return (ret);
}
