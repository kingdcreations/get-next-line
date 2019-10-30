/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:21:11 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 10:20:17 by tmarcon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int	output(int ret, char **nextl, char **line, char **buff)
{
	free(*nextl);
	if (ret != 0)
	{
		if (!(*nextl = ft_strdup(ft_strchr(*line, '\n'))) ||
		!(*line = ft_substr(*line, 0, ft_strlen(*line) - ft_strlen(*nextl))))
			return (0);
	}
	else
		*nextl = NULL;
	free(*buff);
	*buff = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			sz;
	int			ret;
	char		*buff;
	static char	*nextl;

	ret = 1;
	if (!line || read(fd, NULL, 0) < 0 ||
	!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!(*line = (nextl) ? ft_strdup(nextl + 1) : ft_strdup("")))
		return (-1);
	while (!(ft_strchr(*line, '\n')) && ret != 0)
		if ((sz = read(fd, buff, BUFFER_SIZE)) != 0)
		{
			buff[sz] = '\0';
			if (!(*line = ft_strjoin(*line, buff)))
				return (-1);
		}
		else
			ret = 0;
	if (!(output(ret, &nextl, line, &buff)))
		return (-1);
	return (ret);
}
