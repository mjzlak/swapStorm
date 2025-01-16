/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjzlak <mjzlak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:39:46 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/16 08:19:04 by mjzlak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_stack *a, t_stack *b)
{
    // Choisir un algorithme de tri performant
    // Générer les instructions
    quicksort(a);
}

static t_list *get_tail(t_list *cur)
{
    while (cur && cur->next)
        cur = cur->next;
    return cur;
}

static t_list *partition(t_list *head, t_list *end, t_list **newHead, t_list **newEnd)
{
    t_list  *pivot = end;
    t_list  *prev = NULL, *cur = head, *tail = pivot;
    while (cur != pivot)
    {
        if (cur->value < pivot->value)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur; 
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            t_list *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    (*newEnd) = tail;
    return pivot;
}

static t_list *quicksort_rec(t_list *head, t_list *end)
{
    if (!head || head == end) 
        return head;
    t_list *newHead = NULL, *newEnd = NULL;
    t_list *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        t_list *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quicksort_rec(newHead, tmp);
        tmp = get_tail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quicksort_rec(pivot->next, newEnd);
    return newHead;
}

t_list *quicksort(t_list *head)
{
    t_list *end = get_tail(head);
    return quicksort_rec(head, end);
}