/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:17:22 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/05 17:33:02 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_col(int id_x, int x, int id_y, int y)
{
	if (id_x == 0 && id_y == 0)
	{
		ft_putchar('A');
	}
	else if (id_x == x - 1 && id_y == 0)
	{
		ft_putchar('A');
	}
	else if (id_x == 0 && id_y == y - 1)
	{
		ft_putchar('C');
	}
	else if (id_x == x - 1 && id_y == y - 1)
	{
		ft_putchar('C');
	}
	else if ((id_x > 0 && id_x < x - 1) && (id_y > 0 && id_y < y - 1))
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('B');
	}
}

void	print_cols(int x, int id_y, int y)
{
	int	id_x;

	id_x = 0;
	while (id_x < x)
	{
		print_col(id_x, x, id_y, y);
		id_x++;
	}
	ft_putchar('\n');
}

void	print_rows(int x, int y)
{
	int	id_y;	

	id_y = 0;
	while (id_y < y)
	{
		print_cols(x, id_y, y);
		id_y++;
	}
}

void	rush(int x, int y)
{
	print_rows(x, y);
}
