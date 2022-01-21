/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:22:38 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:36:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define FLAG_ERROR 1
# define FLAG_0_PAD 2
# define FLAG_LEFT_ADJUSTED 4
# define FLAG_PRECISION 8
# define FLAG_ALTERNATE_FORM 16
# define FLAG_BLANK 32
# define FLAG_ALWAYS_SIGN 64

int			get_flag_code(char c);
int			is_flag(char c);
int			has_flag(int flags, int flag);
#endif
