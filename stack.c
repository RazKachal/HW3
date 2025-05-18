#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct stack {
    elem_t *data;
    size_t max_size;
    size_t top;
    clone_t clone;
    destroy_t destroy;
    print_t print;
};

struct stack *stack_create(size_t max_size, clone_t clone, destroy_t destroy, print_t print) {
    if (max_size == 0 || !clone || !destroy || !print) {
        return NULL;
    }
    struct stack *s = malloc(sizeof(struct stack));
    if (!s) return NULL;
    s->data = malloc(max_size * sizeof(elem_t));
    if (!s->data) {
        free(s);
        return NULL;
    }
    s->max_size = max_size;
    s->top = 0;
    s->clone = clone;
    s->destroy = destroy;
    s->print = print;
    return s;
}

int stack_destroy(struct stack *s) {
    if (!s) return 1;
    for (size_t i = 0; i < s->top; ++i) {
        if (s->data[i]) {
            s->destroy(s->data[i]);
        }
    }
    free(s->data);
    free(s);
    return 0;
}

int stack_push(struct stack *s, elem_t elem) {
    if (!s || s->top >= s->max_size) return 1;
    elem_t copy = s->clone(elem);
    if (!copy) return 1;
    s->data[s->top++] = copy;
    return 0;
}

void stack_pop(struct stack *s) {
    if (!s || s->top == 0) return;
    s->top--;
    s->destroy(s->data[s->top]);
    s->data[s->top] = NULL;
}

elem_t stack_peek(struct stack *s) {
    if (!s || s->top == 0) return NULL;
    return s->data[s->top - 1];
}

size_t stack_size(struct stack *s) {
    if (!s) return 0;
    return s->top;
}

bool stack_is_empty(struct stack *s) {
    if (!s) return false;
    return s->top == 0;
}

size_t stack_capacity(struct stack *s) {
    if (!s) return 0;
    return s->max_size - s->top;
}

void stack_print(struct stack *s) {
    if (!s) return;
    for (size_t i = s->top; i > 0; --i) {
        s->print(s->data[i - 1]);
    }
}