#ifndef ARRAY_H_SENTRY
#define ARRAY_H_SENTRY
typedef struct node {
    int data;
    struct node *next;
} item;

void watch_list(item *addr);

void create_arr(int c, item **first, item **last);

void delete_arr(item *addr);
#endif
