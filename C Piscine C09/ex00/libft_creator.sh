# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 18:06:35 by lny-tina          #+#    #+#              #
#    Updated: 2023/11/11 18:07:16 by lny-tina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/shell

# Compilation des fichiers sources
gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

# Création de la bibliothèque
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Nettoyage des fichiers objets
rm -f ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

echo "libft.a créée avec succès."
