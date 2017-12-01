/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:26:29 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/06 11:52:00 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

int		solve_sudoku(int sudoku[9][9], int row, int col);
int		solve_sudoku_back(int sudoku[9][9], int row, int col);
int		sudoku_compare(int sudoku1[9][9], int sudoku2[9][9]);
int		initial_check(int arguments, char **array);
int		empty_space(int sudoku[9][9], int row, int col, int num);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
void	print_sudoku(int sudoku[9][9]);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*sudoku_string(int sudoku[9][9], char string[82]);

#endif
