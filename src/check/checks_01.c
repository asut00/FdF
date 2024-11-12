/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_01_checks_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:01 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:04 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	checks(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 2)
	{
		write(2, "Error: Argument error\n", 22);
		exit(1);
	}
	data->map_str = parse_file_to_str(argv[1]);
	if (!data->map_str)
	{
		write(2, "Error: Parsing error\n", 21);
		exit(1);
	}
	check_map(data->map_str);
}

char	*parse_file_to_str(char *file_path)
{
	int		fd;
	char	*full_str;

	fd = get_fd(file_path);
	full_str = malloc(1 * sizeof(char));
	if (!full_str)
	{
		close(fd);
		return (NULL);
	}
	full_str[0] = '\0';
	full_str = read_and_cat_str(fd, full_str);
	delete_extra_nl(full_str);
	close(fd);
	return (full_str);
}

int	get_fd(char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: File error\n", 11);
		exit(1);
	}
	return (fd);
}

char	*read_and_cat_str(int fd, char *full_str)
{
	int		bytes_read;
	char	buffer[1000000];

	bytes_read = read(fd, buffer, 1000000);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		full_str = ft_strdup_and_add_string(full_str, buffer, bytes_read);
		if (!full_str)
		{
			close(fd);
			exit (1);
		}
		bytes_read = read(fd, buffer, 1000000);
	}
	return (full_str);
}

char	*ft_strdup_and_add_string(char *old_s, char *s_to_add, int bytes_read)
{
	char	*new_s;
	int		i;
	int		j;

	i = 0;
	new_s = malloc((ft_strlen(old_s) + ft_strlen(s_to_add) + 1) * sizeof(char));
	if (!new_s)
	{
		free(old_s);
		return (NULL);
	}
	ft_strcpy(new_s, old_s);
	i = ft_strlen(old_s);
	j = 0;
	while (j < bytes_read && s_to_add[j])
	{
		new_s[i] = s_to_add[j];
		i++;
		j++;
	}
	new_s[i] = '\0';
	free(old_s);
	return (new_s);
}
