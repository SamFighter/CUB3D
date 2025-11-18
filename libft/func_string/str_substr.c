/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:59:50 by fmontel           #+#    #+#             */
/*   Updated: 2025/05/10 14:30:13 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Duplicate part of a string and return it:
 * - Duplicate from the position 'start' and for 'len' characters
 */

char    *str_substr(char *s, unsigned int start, size_t len)
{
    size_t  slen;
    size_t  i;
    char    *sub;
    if (!s)
        return (NULL);
    slen = str_len(s);
    if (start >= slen)
        return (malloc(1));
    if (len > slen - start)
        len = slen - start;
    sub = malloc(len + 1);
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

/**
 * Duplicate part of a string and return it:
 * - Duplicate backward from the position 'end' and for 'len' characters
 */
char	*str_subrstr(char *s, int end, int len)
{
	int		i;
	char	*src;

	i = 0;
	if ((size_t)len > str_len(s))
		return (s);
	src = malloc((len + 1) * sizeof(char));
	if (!src)
		return (NULL);
	while (s[i] != '\0' && i != len)
	{
		src[i] = s[end - i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
