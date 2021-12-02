/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdynamic_buffer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:13:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/01 13:04:54 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDYNAMIC_BUFFER_H
# define LIBDYNAMIC_BUFFER_H
# define EXPAND_LEN 10
# include <stddef.h>
# include <stdlib.h>

# include "libft.h"

typedef struct s_dynamic_buffer
{
	void			*buffer;
	unsigned long	i;
	unsigned long	len;
	size_t			elem_size;
}	t_dynamic_buffer;

t_dynamic_buffer	get_buffer(size_t elem_size);
int					append(t_dynamic_buffer *buffer, void *elem);
static void			*get_elem_ptr(t_dynamic_buffer *buffer, unsigned long i);
static int			expand(t_dynamic_buffer *buffer);
#endif
