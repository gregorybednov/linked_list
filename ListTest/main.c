#include <stdio.h>
#include "../list/library.h"

void print_list(list l){
    go_to(&l,0);
    size_t i;
    for (i=0; i<l.size; i++){
        printf("%d ", current_val(&l));
        next(&l);
    }
    printf("\n");
}

int main(void) { /* Demo of working */
    list a;
    init(&a);
    append_back(&a,4); /* 4 */
    append_back(&a,6); /* 4 6 */
    append_back(&a,5); /* 4 5 6 */
    append_before_root(&a,1); /* 1 4 5 6 */
    append_before_root(&a,0); /* 0 1 4 5 6 */
    append_front(&a,2); /* 0 1 2 4 5 6 */
    append_front(&a,3); /* 0 1 2 3 4 5 6 */
    print_list(a);
    return 0;
}
