#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node_s{
    struct list_node_s *next;
    int data;
}list_node_t;

typedef struct list_s {
    list_node_t *head;
    int count;
}list_t;

list_node_t* list_node_create()
{
    list_node_t *node = (list_node_t*)malloc(sizeof(list_node_t));
    return node;
}

list_t* list_create()
{
    list_t *list = (list_t*)malloc(sizeof(list_t));
    list->head = NULL;
    return list;
}

bool list_insert(list_t *list, list_node_t *node)
{
    if (!list || !node) return false;
    if (!list->head) {
        list->head = node;
        return true;
    }

    list_node_t *n = list->head;
    while (n) {
        if (n->next) {
            n = n->next;
        } else {
            n->next = node;
            node->next = NULL;
            break;
        }
    }
    return true;
}

void list_iterate(list_t *list)
{
    if (!list) return;
    list_node_t *n = list->head;
    while (n) {
        printf("data:%d\n", n->data);
        n = n->next;
    }
}

void list_revert(list_t *list)
{
    if (!list) return;
    list_node_t *n = NULL;
    list_node_t *p = NULL;
    list_node_t *c = list->head;
    while(c) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    list->head = p;
}

void list_destroy(list_t *list)
{
    if (!list) return;
    list_node_t *tmp = NULL;
    list_node_t *n = list->head;
    while (n) {
        tmp = n->next;
        printf("destroy:%d\n", n->data);
        free(n);
        n = tmp;
    }

    free(list);
}


int main()
{
    int i;
    list_t *list = list_create();
    for (i = 0; i < 10; i++) {
        list_node_t *node = list_node_create();
        node->data = rand()%10;
        list_insert(list, node);
    }
    list_iterate(list);

    list_revert(list);
    list_iterate(list);

    list_destroy(list);

    return 0;
}
