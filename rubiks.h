#ifndef RUBIKS_H_
#define RUBIKS_H_
#define EMPTY 0
#define BLOCKED 1
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//fonction permettant de crééer un tableau de 4 lignes et 4 colonnes 
void	print_tab(int **table);

//fonction permettant de décaler une lignes sur la gauche
void	algo_line(int **table, int line);

//fonction permettant de tourner une colonne vers le haut
void	algo_column(int **table, int column);

//fonction permettant de tourner une face dans le sens des aiguilles d'une montre
void	algo_square(int **table, int square);

void	algo_line_reverse(int **table, int line);

void	algo_column_reverse(int **table, int column);

void	algo_square_reverse(int **table, int square);

int	is_in_line(int **table, int line, int value);

int	is_in_col(int **table, int column, int value);

int	*look_for_space(int **table, int *lines, int *columns, int value);

int	*look_for_value(int **table, int *lines, int *columns, int value);

void	verif_return(int *ret);

void	rotate_lines(int **table, int line, int offset);

void	rotate_columns(int **table, int column, int offset);

void	build_first_line(int **table);

void	build_first_square(int **table);

#endif
