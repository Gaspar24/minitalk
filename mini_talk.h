/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:44:18 by msacaliu          #+#    #+#             */
/*   Updated: 2024/02/20 15:14:01 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <signal.h>
# include <sys/wait.h>
# include "../libftprintf/ft_printf.h"

typedef struct s_sig
{
	char	byte;
	int		i;
}	t_sig;

#endif