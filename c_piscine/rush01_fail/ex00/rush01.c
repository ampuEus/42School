/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:17:17 by daampuru          #+#    #+#             */
/*   Updated: 2022/02/27 17:10:34 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int const table_size = 4;
/* Solution box -> array[line][line's char]*/
char sol[table_size][table_size] = {{'0', '0', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'}};

int pre_value(unsigned char row, unsigned char column, unsigned char value)
{
	/* Before write any value check if it already a value in the position
	and if it is have to be the same */
	if (sol[row][column] != '0' && sol[row][column] != value)
	{
		//printf("actual=%i, row=%i, column=%i, value=%i\n", sol[row][column], row, column, value);
		/* TODO sacar error de que ya hay un numero distinto. por lo que el puzzle no tiene solución */
		//printf("No se puede cumplir. Hay un número diferente en esa casilla\n");

		return (1);
	}
	return (0);
	printf("cual\n");
}


int same_value(unsigned char row, unsigned char column, unsigned char value)
{
	/* Check if there is any number with the same value on the same column and row */
	unsigned char count;
	/* Row */
	count = 0;
	while(/*sol[row][count]*/count < table_size)
	{
		if (sol[row][count] == value && count != column && sol[row][count] != 0)
		{
			/* TODO sacar error de que ya hay un numero distinto. por lo que el puzzle no tiene solución */
			//printf("No se puede cumplir. Hay un número igual en la misma fila\n");
			//printf("row=%c // colunm=%c", row, count);

			return (1);
		}
		count++;
	}

	/* Colunm */
	count = 0;
	while(sol[count][column])
	{
		if (sol[count][column] == value && count != row && sol[count][column] != 0)
		{
			/* TODO sacar error de que ya hay un numero distinto. por lo que el puzzle no tiene solución */
			//printf("No se puede cumplir. Hay un número igual en la misma columna\n");

			return (1);
		}
		count++;
	}
	return (0);
}


// int posible_value()
// {
// 	/* Checkear que al poner el número "n" en la tabla este concuerda con la posición mínima que se puede poner
// 	dependiendo de los datos de entrada de su fila y columna */
// }

void PRUEBA_saca_tabla()
{
	printf("%c %c %c %c\n", sol[0][0], sol[0][1], sol[0][2], sol[0][3]);
	printf("%c %c %c %c\n", sol[1][0], sol[1][1], sol[1][2], sol[1][3]);
	printf("%c %c %c %c\n", sol[2][0], sol[2][1], sol[2][2], sol[2][3]);
	printf("%c %c %c %c\n", sol[3][0], sol[3][1], sol[3][2], sol[3][3]);
	printf("\n");
}

int put_value_limits(unsigned char row, unsigned char column, unsigned char value)
{
	if (pre_value(row, column, value))
	{
		printf("No se puede cumplir. Hay un número diferente en esa casilla\n");
		return (1);
	}
	sol[row][column] = value;
	if (same_value(row, column, value))
	{
		printf("No se puede cumplir. Hay un número igual en la misma fila o columna\n");
		return (1);
	}
	return (0);
}

int put_value(unsigned char row, unsigned char column, unsigned char value)
{
	if (!pre_value(row, column, value))
	{
		if (same_value(row, column, value))
			return (1);
		else
			sol[row][column] = value;
	}
	return (0);
}

int rush(void)
{
	unsigned char PRUEBA1;
	unsigned char n;

	unsigned char in_line;
	unsigned char in_line_val;
	int out_line;
	int out_line_val;
	unsigned char value;
	/* Input data -> array[sides of the square][surface size] */
	//char input_data[4][table_size] = {{'2', '2', '2', '1'}, {'3', '1', '2', '4'}, {'3', '1', '2', '2'}, {'1', '2', '2', '3'}};
	char input_data[4][table_size] = {{'2', '2', '2', '1'}, {'3', '1', '2', '4'}, {'3', '1', '2', '2'}, {'1', '2', '2', '3'}};
	//printf("%c", sol[0][1]);


	in_line = 0;
	in_line_val = 0;
	while(in_line < table_size/*input_data[in_line][in_line_val]*/)
	{
		/* 1 - See if there is a "n" value in the input, if there is, complete de column or row (from 1 to n) */
		/* TODO Check if the opposite site there is a input equal to 1. If not rise error*/
		if (input_data[in_line][in_line_val] == table_size + '0')
		{
			out_line = in_line == 0 ? 0 : table_size - 1;
			out_line_val = in_line == 2 ? 0 : table_size - 1;
			//printf("in_line=%i // out=%i\n", in_line, out_line);
			while(out_line >= 0 && out_line < table_size && out_line_val >=0 && out_line_val < table_size)
			{
				if (in_line == 0)
				{
					value = out_line + '1';
					if (put_value_limits(out_line, in_line_val, value))
						return (1);
					out_line++;
				}
				else if (in_line == 1)
				{
					value = table_size + '0' - out_line;
					if (put_value_limits(out_line, in_line_val, value))
						return (1);
					out_line--;
				}
				else if (in_line == 2)
				{
					value = out_line_val + '1';
					if (put_value_limits(in_line_val, out_line_val, value))
						return (1);
					out_line_val++;
				}
				else
				{
					value = table_size + '0' - out_line_val;
					if (put_value_limits(in_line_val, out_line_val, value))
						return (1);
					out_line_val--;
				}
			}
		}
		/* 2 - See if there is a 1 in the input, if there is, put the value "n" next to it */
		if (input_data[in_line][in_line_val] == '1')
		{
			out_line = in_line == 0 ? 0 : table_size - 1;
			out_line_val = in_line == 2 ? 0 : table_size - 1;
			value = table_size + '0';
			//printf("in_line=%i // out=%i\n", in_line, out_line);
			if (in_line == 0)
			{
				put_value_limits(out_line, in_line_val, value);
				out_line++;
			}
			else if (in_line == 1)
			{
				put_value_limits(out_line, in_line_val, value);
				out_line--;
			}
			else if (in_line == 2)
			{
				put_value_limits(in_line_val, out_line_val, value);
				out_line_val++;
			}
			else
			{
				put_value_limits(in_line_val, out_line_val, value);
				out_line_val--;
			}

		}

		/* Go to input data next position */
		//printf("%c ", input_data[in_line][in_line_val]);
		if (in_line_val >= table_size - 1)
		{
			in_line++;
			in_line_val = 0;
		}
		else
			in_line_val++;
	}

	/* 3 - Put the rest of "n" values on the table
	Second loop to the table to put the rest of "n" values */
	/* TODO esto solo sirve para algunos 4x4 */
	in_line = 0;
	in_line_val = 0;
	n = table_size;
	while(in_line < table_size/*input_data[in_line][in_line_val]*/)
	{
		put_value(in_line, in_line_val, n + '0');

		/* Go to input data next position */
		if (in_line_val >= table_size - 1)
		{
			in_line++;
			in_line_val = 0;
		}
		else
			in_line_val++;
	}

	/* 4 - Any clue n>2 you can 'x' out N and N-1 in the front
	Trird loop to the table to put the rest of "n" values */

		in_line = 0;
	in_line_val = 0;
	n = table_size + '0';
	while(in_line < table_size/*input_data[in_line][in_line_val]*/)
	{
		// out_line = in_line == 0 ? 0 : table_size - 1;
		// out_line_val = in_line == 2 ? 0 : table_size - 1;
		// //printf("in_line=%i // out=%i\n", in_line, out_line);
		// while(out_line >= 0 && out_line < table_size && out_line_val >=0 && out_line_val < table_size)
		// {
		// 	if (input_data[in_line][in_line_val] <= 2)
		// 	{
		// 		if (in_line == 0)
		// 		{
		// 			put_value(out_line, in_line_val, n - 1);
		// 			out_line++;
		// 		}
		// 		else if (in_line == 1)
		// 		{
		// 			put_value(out_line, in_line_val, n - 1);
		// 			out_line--;
		// 		}
		// 	}
		// }

		if (input_data[in_line][in_line_val] <= '2' && input_data[in_line + 2][0] != '3')
		{
				put_value(in_line, in_line_val, '3');
		}
		/* Go to input data next position */
		if (in_line_val >= table_size - 1)
		{
			in_line++;
			in_line_val = 0;
		}
		else
			in_line_val++;
	}


	PRUEBA_saca_tabla();
	return (0);
}
