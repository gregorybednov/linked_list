#include "library.h"

void init(list *l){
    l->current=NULL;
    l->pos = 0;
    l->root = NULL;
    l->size = 0;
}

void final(list *l){
    erase_list(l);
}

int is_empty(list *l){
    return (l->root==NULL);
}

value_t current_val (list *l){
    if (l->current==NULL) return 0;
    return l->current->val;
}

int new_root(list *l, value_t x) {
    l->root = malloc(sizeof(lnode));
    if (l->root==NULL) return errno;
    l->root->val = x;
    l->root->next = l->root;
    l->current = l->root;
    l->pos = 0;
    l->size = 1;
    return 0;
}

int append_back(list *l, value_t x){
    if (is_empty(l)) return new_root(l,x);
    lnode *plnode = malloc(sizeof(lnode));
    if (plnode==NULL) return errno;
    l->size++;

    if (l->current!=l->current->next) plnode->next = l->current->next; else plnode->next = plnode; /* проверка на конечный элемент */

    l->current->next = plnode;
    plnode->val = x;
    return 0;
}
int append_front (list *l, value_t x){
    if (is_empty(l)) return new_root(l,x);
    lnode *plnode = malloc(sizeof(lnode));
    if (plnode==NULL) return errno;
    l->size++;

    *plnode = *(l->current);
    l->current->next = plnode;
    l->current->val = x;
    l->current = plnode;
    return 0;
}
int append_before_root (list *l, value_t x){
    if (is_empty(l)) return new_root(l,x);
    lnode *plnode = malloc(sizeof(lnode));
    if (plnode==NULL) return errno;
    l->size++;

    plnode->next = l->root;
    l->root = plnode;
    plnode->val = x;

    return 0;
}

size_t go_to (list *l, size_t index){
    if (is_empty(l)) return 0;
    size_t res = 0;
    if (index>l->size) index = l->size-1;
    if (l->pos>index){
        l->pos = 0;
        l->current = l->root;
        res++;
    }
    while (l->pos<index){
        l->current = l->current->next;
        res++;
        l->pos++;
    }
    return res;
}

size_t next (list *l){
    if (l->current==l->current->next) return 0;
    l->current = l->current->next;
    l->pos++;
    return 1;
}

/* Группа функций удаления. */
void remove_current (list *l, size_t i){
    if (l->current==l->current->next && l->current!=l->root) return;
    l->size--;
    lnode *p = l->current->next;
    *(l->current) = *(l->current->next);
    free(p);
    if (l->current==l->root) l->current = l->root = NULL;
}

void erase_list (list *l){
    if (is_empty(l)) return;
    while (l->root!=l->root->next){
        lnode *p = l->root->next;
        free(l->root);
        l->root = p;
    }
    free(l->root);
    init(l);
}