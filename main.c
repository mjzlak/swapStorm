/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/16 11:23:13 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*value;

	a = NULL;
	b = NULL;
	value = NULL;
	if (argc == 1)
		ft_split_to_list(argv[1], ' ', a);
	else
	{
		while (--argc)
		{
			*value = ft_atoi(argv[argc]);
			ft_lstadd_back(&a, ft_lstnew(value));
		}
		/*while (--argc)
			ft_lstadd_front(&a, ft_lstnew(ft_atoi(argv[argc])));*/
	}
	//REMOVE
	int i = 0;
	t_list *current = a;
	while (current)
	{
		printf("a[%d] = %d\n", i, *(int *)(current->content));
		current = current->next;
		i++;
	}
	// 1. Parsing
	// 2. Initialiser et remplir la pile a
	// 3. Appeler la logique de tri
	// 4. Afficher les instructions
	return (0);
}

int main(int argc, char **argv)
{
/*	if (!error_handler(argc, argv))
		return (42);*/
	if (!push_swap(argc, argv))
		return (42);
	return (0);
}

/*
Voici un plan succinct :

1. Parsing & validation  
   • Vérifier les arguments (valeurs, doublons, dépassement d’entier).  
   // "4 66 554 47 8 1 4"
   // 4  6458 2 485 15 58 4
   • Stocker les nombres dans la pile a.  

2. Gestion des piles  
   • Créer les structures de piles (pile a, pile b).  
   • Implémenter les opérations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).  

3. Algorithmes de tri  
   • Détecter si la pile est déjà triée.  
   • Gérer les petits cas (tri simple par swaps).  
   • Implémenter un tri optimisé (ex. tri par insertion, quicksort, etc.).  

4. Affichage & performance  
   • Afficher la suite d’instructions.  
   • Minimiser le nombre d’opérations (benchmark).  

5. Gestion des erreurs  
   • En cas d’entrée invalide, afficher "Error".  

6. Makefile  
   • Compiler le tout : règles (NAME, all, clean, fclean, re).  

### Exemple de squelettes de fonctions (C)

```c
// main.c
#include "push_swap.h"

int main(int argc, char **argv)
{
	// 1. Parsing
	// 2. Initialiser et remplir la pile a
	// 3. Appeler la logique de tri
	// 4. Afficher les instructions
	return (0);
}
```

```c
// operations.c
#include "push_swap.h"

void sa(t_stack *a)
{
	// Échanger les deux premiers éléments de la pile a
}

void pb(t_stack *a, t_stack *b)
{
	// Déplacer le premier élément de a vers b
}
```

```c
// sort_algorithm.c
#include "push_swap.h"

void sort_stack(t_stack *a, t_stack *b)
{
	// Choisir un algorithme de tri performant
	// Générer les instructions
}
```*/