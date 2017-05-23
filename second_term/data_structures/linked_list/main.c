#include "list.h"

int main() {
    list_t list = list_init();

    add_first(&list, 0);
    add_first(&list, -1);
    add_first(&list, -2);
    add_first(&list, -3);
    print_list(list);

    add_last(&list, 1);
    add_last(&list, 2);
    add_last(&list, 3);
    print_list(list);

    poll_first(&list);
    poll_first(&list);
    poll_first(&list);
    print_list(list);
    
    set(&list, 0, -1);
    set(&list, get_size(list) - 1, 4);
    print_list(list);

    return 0;
}
