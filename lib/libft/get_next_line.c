/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:27:14 by dajesus-          #+#    #+#             */
/*   Updated: 2025/01/10 09:05:30 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_current_line(int fd, char *buffer, char *accumulated_content)
{
	int		bytes_read;
	char	*temporary_content;

	bytes_read = 1;
	temporary_content = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!accumulated_content)
			accumulated_content = ft_strdup("");
		temporary_content = accumulated_content;
		accumulated_content = ft_strjoin(temporary_content, buffer);
		free(temporary_content);
		temporary_content = NULL;
		if (ft_strchr(accumulated_content, '\n'))
			break ;
	}
	return (accumulated_content);
}

static char	*get_rest_lines(char *line)
{
	int		len_of_rest_content;
	int		line_len;
	int		newline_len;
	char	*remaining_line_content;
	char	*newline_position;

	if (line && ft_strchr(line, '\n'))
	{
		newline_position = ft_strchr(line, '\n');
		line_len = ft_strlen(line);
		newline_len = ft_strlen(newline_position);
		len_of_rest_content = (line_len - newline_len) + 1;
		remaining_line_content = ft_strdup(newline_position + 1);
		line[len_of_rest_content] = '\0';
		return (remaining_line_content);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*accumulated_content[1024];
	char		*current_line;
	char		*read_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	current_line = get_current_line(fd, read_buffer, accumulated_content[fd]);
	free(read_buffer);
	read_buffer = NULL;
	if (current_line == NULL && accumulated_content[fd])
	{
		free(accumulated_content[fd]);
		accumulated_content[fd] = NULL;
	}
	accumulated_content[fd] = get_rest_lines(current_line);
	if (current_line == NULL || *current_line == '\0')
	{
		free(current_line);
		current_line = NULL;
	}
	return (current_line);
}
