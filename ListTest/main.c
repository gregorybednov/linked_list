#include <stdio.h>
#include "../list/library.h"

int main(void) {
    list a;
    init(&a);
    append_back(&a,1);
    append_back(&a,4);
    go_to(&a,1);
    append_front(&a,2);
    append_front(&a,3);
    append_back(&a,5);
    go_to(&a,0);
    {
        size_t i = 0;
        for (i=0; i<a.size; i++){
            printf("%d ", current_val(&a));
            next(&a);
        }
    }
    return 0;
}
