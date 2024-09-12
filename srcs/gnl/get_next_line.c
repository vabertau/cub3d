/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:18:53 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/08 18:24:42 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_from_bb(char *big_buff)
{
	int		ret_index;
	char	*ret;

	ret_index = ret_found(big_buff);
	if (ret_index == -1)
		ret = ft_strdup(big_buff);
	else
		ret = ft_substr(big_buff, 0, ret_index);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char	*ft_strfreejoin_len(char *s1, char *s2, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_strdup(s1);
	free(s1);
	if (!tmp || !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(tmp) + len + 1));
	if (!ret)
		return (NULL);
	while (tmp[i])
	{
		ret[i] = tmp[i];
		i++;
	}
	while (j < len)
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (free(tmp), ret);
}

char	*get_read(int fd, char *backup, char *big_buff, int *endfile)
{
	char	*buff;
	int		endread;

	endread = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	big_buff = ft_strdup(backup);
	if (!big_buff)
		return (NULL);
	while (ret_found(big_buff) == -1 && endread > 0)
	{
		endread = read(fd, buff, BUFFER_SIZE);
		if (endread == -1)
			return (free(big_buff), free(buff), NULL);
		big_buff = ft_strfreejoin_len(big_buff, buff, (size_t)endread);
		if (!big_buff)
			return (free(big_buff), free(buff), NULL);
	}
	if (big_buff[0] == '\0' && backup[0] == '\0')
		return (free(big_buff), free(buff), NULL);
	if (endread == 0)
		*endfile = 1;
	return (free(buff), big_buff);
}

int	get_backup(char *big_buff, char *backup)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (big_buff[i] && big_buff[i] != '\n')
		i++;
	if (!big_buff[i + 1])
	{
		while (backup[j])
		{
			backup[j] = '\0';
			j++;
		}
		return (1);
	}
	i++;
	while (big_buff[i])
	{
		backup[j] = big_buff[i];
		i++;
		j++;
	}
	backup[j] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	char		*big_buff;
	char		*ret;
	static char	backup[BUFFER_SIZE + 1];
	int			endfile;

	endfile = 0;
	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	big_buff = NULL;
	big_buff = get_read(fd, backup, big_buff, &endfile);
	if (big_buff == NULL)
		return (NULL);
	ret = line_from_bb(big_buff);
	if (!ret)
		return (NULL);
	if (ft_strlen(ret) >= ft_strlen(backup))
		backup[0] = '\0';
	if (endfile == 0)
		get_backup(big_buff, backup);
	free(big_buff);
	return (ret);
}

/*
#include <stdio.h>

int     main(void)
{
        int fd;
        char    *ret;
        fd = open("/Users/valentinbertaud/242/gnl/gnlTester/files/
	multiple_line_no_nl", O_RDONLY);
        printf("fd = %d\n", fd);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
	        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);
        ret = get_next_line(fd);
        printf("ret = %s", ret);
        free(ret);

}*/
