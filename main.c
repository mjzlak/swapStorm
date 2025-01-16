/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjzlak <mjzlak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/16 08:53:55 by mjzlak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    // Choisir un algorithme de tri performant
    // Générer les instructions
}

int is_sorted(t_stack *stack_a)
{
    int i;

    i = 0;
    while (i < stack_a->size - 1)
    {
        if (stack_a->stack[i] > stack_a->stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int error_handler(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    if (ac < 2)
        return (-1);
    // Check for invalid characters
    while (av[++i])
    {
        if (!ft_isdigit(av[i]))
            return (-1);
    }
    // Check for duplicates
    i = 0;
    j = 0;
    while (av[i++])
    {
        while (av[j++])
        {
            if (i != j && ft_atoi(av[i]) == ft_atoi(av[j]))
                return (-1);
        }
        j = 0;
    }
    // Check for integer overflow
    i = 0;
    while (av[i++])
    {
        if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
            return (-1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    if (error_handler(argc, argv) == -1)
        return (-1);
    // 1. Parsing
    // 2. Initialiser et remplir la pile a
    while (argv[i])
    {
        stack_a.stack[i] = ft_atoi(argv[i]);
        i++;
    }
    stack_a.size = i;
    if (is_sorted(&stack_a))
        return (0);
    else
        sort_stack(&stack_a, &stack_b);
    // 3. Appeler la logique de tri
    // 4. Afficher les instructions
    return (0);
}

/*
Voici un plan succinct :

1. Parsing & validation  
   • Vérifier les arguments (valeurs, doublons, dépassement d’entier).  
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