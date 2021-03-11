#ifndef LIST_LIBRARY_H
#define LIST_LIBRARY_H
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#define value_t int

typedef struct list_node lnode;
typedef struct list list;


struct list_node {
    value_t val;
    lnode *next;
};

struct list {
    lnode *root;
    lnode *current;
    size_t size;
    size_t pos;
};


void init(list *l);

void final(list *l);

int is_empty(list *l); /* возваращает 1, если l.root==NULL и список пуст; иначе возвращает 0 */
value_t current_val(list *l); /* возвращает значение. Если список пуст, возвращает 0 */

/* Группа функций добавления. Возвращает 0 при успехе, иначе errno */
int append_back(list *l, value_t x); /* новое значение x помещается после элемента, на который указывает l.current */
int append_front (list *l, value_t x); /*новое значение x помещается до элемента, на который укзаывет l.current */
int append_before_root (list *l, value_t x); /* новое значение x помещается в качестве головного */

/* Функция навигации. Возвращает количество совершённых переходов */
size_t go_to (list *l, size_t index); /* l.current будет указывать на элемент l под номером index */
size_t next (list *l); /*переходит по указателю next: l.current = l.current->next */


/* Группа функций удаления. */
void remove_current (list *l, size_t i); /*удаляет из списка элемент current.
 * Удаление запрещено, если current указывает последний элемент списка l, который при этом длинее 1 элемента */
void erase_list (list *l); /* удаляет весь список, начиная с root */

#endif //LIST_LIBRARY_H