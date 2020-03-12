/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** push_list
*/

#include <linked_list.h>

void push_back(dlist_t **dlist, void *data, STRUCT_NAME_t name)
{
    node_t *new_elemnt = malloc(sizeof(node_t));
    new_elemnt->prev = NULL;
    new_elemnt->next = NULL;
    new_elemnt->plant = data;
    new_elemnt->plant_name = name;
    if (is_empty_dlist(*dlist) == true) {
        (*dlist) = malloc(sizeof(dlist_t));
        (*dlist)->end = new_elemnt;
        (*dlist)->begin = new_elemnt;
        (*dlist)->len = 0;
    } else {
        new_elemnt->prev = (*dlist)->end;
        (*dlist)->end->next = new_elemnt;
        (*dlist)->end = new_elemnt;
    }
    (*dlist)->len += 1;
}

void push_front(dlist_t **dlist, void *data, STRUCT_NAME_t name)
{
    node_t *new_elemnt = malloc(sizeof(node_t));
    new_elemnt->prev = NULL;
    new_elemnt->next = NULL;
    new_elemnt->plant = data;
    new_elemnt->plant_name = name;
    if (is_empty_dlist(*dlist) == true) {
        *dlist = malloc(sizeof(dlist_t));
        (*dlist)->begin = new_elemnt;
        (*dlist)->end = new_elemnt;
        (*dlist)->len = 0;
    } else {
        new_elemnt->next = (*dlist)->begin;
        (*dlist)->begin->prev = new_elemnt;
        (*dlist)->begin = new_elemnt;
    }
    (*dlist)->len += 1;
}