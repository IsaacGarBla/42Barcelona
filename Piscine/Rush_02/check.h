/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:25:30 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 19:25:32 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

int	check_digits(char *str);
int	check_dict_file(char *dict);
int	check_arg(int narg, char **argv, char *default_dict);

#endif
