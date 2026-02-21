/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:16:28 by bcausseq          #+#    #+#             */
/*   Updated: 2026/02/17 19:26:10 by bcausseq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	win_hooks(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_game *)param)->mlx_ctx.mlx_ctx);
}
