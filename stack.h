#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>
#include "common.h"

// Generic element type
typedef void * elem_t;

// Function pointer types for element operations
typedef elem_t   (*clone_t)(elem_t e);
typedef void     (*destroy_t)(elem_t e);
typedef void     (*print_t)(elem_t e);

// Opaque stack struct
struct stack;

// Create a new stack with given max_size and element operations
struct stack *stack_create(size_t max_size, clone_t clone, destroy_t destroy, print_t print);

// Destroy the stack and free all memory
int stack_destroy(struct stack *s);

// Push a copy of elem to the top of the stack
int stack_push(struct stack *s, elem_t elem);

// Pop the top element from the stack and delete it
void stack_pop(struct stack *s);

// Return a pointer to the top element, or NULL on failure
elem_t stack_peek(struct stack *s);

// Return the current number of elements in the stack, 0 on failure
size_t stack_size(struct stack *s);

// Return true if the stack is empty, false otherwise (false on failure)
bool stack_is_empty(struct stack *s);

// Return the number of free slots in the stack, 0 on failure
size_t stack_capacity(struct stack *s);

// Print the stack from top to bottom
void stack_print(struct stack *s);

#endif // STACK_H