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
    poll_first(&list);
    print_list(list);

    set_first(&list, -1);
    set(&list, 1, -2);
    set_last(&list, -3);
    print_list(list);

    list_t copy = list_copy(list);

    list_destroy(&list);
    print_list(list);

    print_list(copy);
    list_destroy(&copy);
    print_list(copy);

    return 0;
}
