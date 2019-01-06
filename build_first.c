#include "rubiks.h"
#define PRINT_SQUARE_DEBUG__ 1

//Exercise 1
//Affiche le squelette du rubiks cube
void	print_tab(int **table)
{
  int i = 0;
  int j = 0;

  if (PRINT_SQUARE_DEBUG__ == 1)
    {
      while (i < 4)
	{
	  printf("-----------------\n");

	  printf("| %d | %d | %d | %d |\n", table[i][j], table[i][j+1], table[i][j+2], table[i][j+3]);
	  i++;
	}
      printf("-----------------\n");
    }
}

//Exercise 2
//Tourne une ligne sur la gauche
void	algo_line(int **table, int line)
{
  int temp = table[line][0];
  int i = 0;

  while (i < 3)
    {
      table[line][i] = table[line][i + 1];
      i++;
    }
  table[line][3] = temp;
}

//Tourne une ligne sur la droite
void	algo_line_reverse(int **table, int line)

{
  int temp = table[line][3];
  int i = 3;

  while (i > 0)
    {
      table[line][i] = table[line][i - 1];
      i--;
    }
  table[line][0] = temp;  

}

//Tourne une colonne vers le haut
void	algo_column(int **table,int column)
{
  int temp = table[0][column];
  int i = 0;

  while
    (i < 3)
    {
      table[i][column] = table[i + 1][column];
      i++;
    }
  table[3][column] = temp;
}

//Tourne une colonne vers le bas
void	algo_column_reverse(int **table, int column)
{
  int temp = table[3][column];
  int i = 3;

  while (i > 0)
    {
      table[i][column] = table[i - 1][column];
      i--;
    }
  table[0][column] = temp;
}

//Tourne un carré dans le sens des aiguilles d'une montre
void	algo_square(int **table, int square)
{
  int temp;

  if(square == 0)
    {
      temp = table[0][0];
      table[0][0] = table [1][0];
      table[1][0] = table [1][1];
      table[1][1] = table [0][1];
      table[0][1] = temp;
    }

  if (square == 1)
    {
      temp = table [0][2];
      table[0][2]= table [1][2];
      table[1][2] = table [1][3];
      table[1][3] = table [0][3];
      table[0][3] = temp;
    }

  if (square == 2)
    {
      temp = table [2][0];
      table[2][0] = table [3][0];
      table[3][0] = table [3][1];
      table[3][1] = table [2][1];
      table[2][1] = temp;
    }

  if (square == 3)
    {
      temp = table [2][2];
      table[2][2] = table [3][2];
      table[3][2] = table [3][3];
      table[3][3] = table [2][3];
      table[2][3] = temp;
    }
}

//Tourne un carré dans le sens inverse des aiguilles d'une montre
void	algo_square_reverse(int **table, int square)
{
  int temp;

  if(square == 0)
    {
      temp = table[0][0];
      table[0][0] = table [0][1];
      table[0][1] = table [1][1];
      table[1][1] = table [1][0];
      table[1][0] = temp;
    }

  if (square == 1)
    {
      temp = table [0][2];
      table[0][2] = table [0][3];
      table[0][3] = table [1][3];
      table[1][3] = table [1][2];
      table[1][2] = temp;
    }

  if (square == 2)
    {
      temp = table [2][0];
      table[2][0] = table [2][1];
      table[2][1] = table [3][1];
      table[3][1] = table [3][0];
      table[3][0] = temp;
    }

  if (square == 3)
    {
      temp = table [2][2];
      table[2][2] = table [2][3];
      table[2][3] = table [3][3];
      table[3][3] = table [3][2];
      table[3][2] = temp;
    }
}
//Exercise 4
//Recherche une valeur dans une ligne et retourne 0 s'il y a la valeur et 1 si non
int	is_in_line(int **table, int line, int value)
{
  int i = 0;

  while (i < 4)
    {
      if (table[line][i] == value)
	{
	  return 0;
	}
      i++;
    }
  return 1;
}

//Recherche une valeur dans une colonne (0 : valeur présente, 1 : non présente)
int	is_in_col(int **table, int column, int value)
{
  int i = 0;

  while (i < 4)
    {
      if(table[i][column] == value)
	{
	  return 0;
	}
      i++;
    }
  return 1;
}

//Exercise 5
//Recherche une valeur différente de la valeur demandée, retourne la position de la valeur différente pour déterminer espace libre
int	*look_for_space(int **table, int *lines, int *columns, int value)
{
  int i; //lignes
  int j; //column

  int *position = malloc(sizeof(int) * 2);
  // créer un tableau de 2 cases pour afficher les positions

  for (i = 0; i < 4; i++) //parcours les lignes
    {
      for(j = 0; j < 4; j++) //parcours les colonnes
	{
	  if (lines[i] == EMPTY && columns[j] == EMPTY && table[i][j] != value)
	    {
	      position[0] = i;
	      position[1] = j;
	      return position;
	    }
	}
    }
  return NULL;
}

//Exercice 6
//Recherche une valeur, fonction retourne position ligne colonne de la valeur trouvée
int	*look_for_value(int **table, int *lines, int *columns, int value)
{
  int i; //ligne
  int j; //colonnes

  int *position = malloc(sizeof(int) * 2);
  // créer un tableau de 2 cases pour afficher les positions

  for (i = 0; i < 4; i++)
    {
      for(j = 0; j < 4; j++)
	{
	  if (lines[i] == EMPTY && columns[j] == EMPTY && table[i][j] == value)
	    {
	      position[0] = i;
	      position[1] = j;
	      return position;
	    }
	}
    }
  return NULL;

}

//Permet d'afficher le return de la fonction précédente
void	verif_return(int *ret)
{
  if (ret != NULL)
    printf("line :\t%d\nColumn :\t%d\n", ret[0], ret[1]);
  else
    printf("Nothing found in the given range.\n");
}

//Exercise 7
//Tourne une ligne un certain nombre de fois en fonction du offset
void	rotate_lines(int **table, int line, int offset)
{
  offset;

  while (offset > 0)
    {
      algo_line(table, line);
      offset--;
    }

  while (offset < 0)
    {
      algo_line_reverse(table, line);
      offset++;
    }
}

//Tourne une colonne un certain nombre de fois en fonction du offset
void	rotate_columns(int **table, int column, int offset)
{
  offset;

  while (offset > 0)
    {
      algo_column(table, column);
      offset--;
    }

  while (offset < 0)
    {
      algo_column_reverse(table, column);
      offset++;
    }
}


//Exercise 8
//Fonction qui permet de mettre toutes les mêmes valeurs sur une face
void	build_first_line(int **table)
{
  int	j = 0;

  while (j < 4)
    {
      if(is_in_col(table, j, 0) == 1)
	{
	  int i = 1; //on recherche à mettre tous les 0 sur une ligne qui est la 1ère donc on ne recherche pas dessus donc i=1 et non 0
	  while (i < 4)
	    {
	      //si j'ai un zéro dans ma ligne, je rotate 
	      if(is_in_line(table, i, 0) == 0)
		{
		  while(table[i][j] != 0) //rotate jusqu'à ce qu'il trouve la ligne de la case libre
		    algo_line(table, i);
    
		  while(table[0][j] != 0)
		    algo_column(table, j);
		}
	      i++;
	    }
	}
      else
	{
	  while(table[0][j] != 0)
	    algo_column(table, j);
	}
      print_tab(table);
	j++;
    }

}

//Fonction pour transformer une ligne en carré
void	line_to_square(int **table, int line)
{
algo_square(table, 0);
algo_square(table, 0);
algo_line(table, 0);
algo_line(table, 0);
 printf("ici");
 print_tab(table);
}

//fonction qui permet de faire un carré de valeur égales 
void	build_first_square(int **table)
{

//print_tab(table);
build_first_line(table);
line_to_square(table, 0);

}


int	main()
{
int **table;
int column = 4;
int line = 0;

table = malloc(sizeof(int *) * column);

while (line < column)
{
  table[line] = malloc(sizeof(int) * 4);
  line++;
}

/*
table[0][0] = 0;
table[0][1] = 0;
table[0][2] = 1;
table[0][3] = 1;
table[1][0] = 0;
table[1][1] = 0;
table[1][2] = 1;
table[1][3] = 1;
table[2][0] = 2;
table[2][1] = 2;
table[2][2] = 3;
table[2][3] = 3;
table[3][0] = 2;
table[3][1] = 2;
table[3][2] = 3;
table[3][3] = 3;


print_tab(table);

algo_line_reverse(table, 0);
print_tab(table);

algo_column_reverse(table, 0);
print_tab(table);

algo_square_reverse(table, 0);
print_tab(table);

printf("%d - %d\n", is_in_line(table, 0, 1), is_in_col(table, 2, 3));
printf("%d - %d\n", is_in_line(table, 3, 1), is_in_col(table, 2, 0));
*/


table[0][0] = 2;
table[0][1] = 0;
table[0][2] = 3;
table[0][3] = 0;
table[1][0] = 2;
table[1][1] = 3;
table[1][2] = 1;
table[1][3] = 0;
table[2][0] = 2;
table[2][1] = 2;
table[2][2] = 1;
table[2][3] = 3;
table[3][0] = 1;
table[3][1] = 1;
table[3][2] = 3;
table[3][3] = 0;

 printf("la");
 print_tab(table);
int lines [4];
int columns[4];
int *ret_value;
int *ret_space;


lines[0] = BLOCKED;
lines[1] = EMPTY;
lines[2] = BLOCKED;
lines[3] = BLOCKED;
columns[0] = EMPTY;
columns[1] = EMPTY;
columns[2] = EMPTY;
columns[3] = EMPTY;

// verif_return(look_for_value(table, lines, columns, 2));
// verif_return(look_for_value(table, lines, columns, 1));

ret_value = look_for_value(table, lines, columns, 0);

lines[0] = EMPTY;
lines[1] = BLOCKED;

ret_space = look_for_space(table, lines, columns, 0);


//build_first_line(tableau);
//print_tab(tableau);
//line_to_square(tableau, 0);

build_first_square(table);

print_tab(table);

rotate_lines(table, ret_value[0], ret_value[1] - ret_space[1]);
print_tab(table);
rotate_columns(table, ret_space[1], ret_value[0] - ret_space[0]);
print_tab(table);

return 0;
}
