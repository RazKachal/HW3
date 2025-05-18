#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

elem_t student_clone(elem_t e) {
    if (!e) return NULL;
    struct student *src = (struct student *)e;
    struct student *copy = malloc(sizeof(struct student));
    if (!copy) return NULL;
    copy->age = src->age;
    copy->id = src->id;
    if (src->name) {
        copy->name = malloc(strlen(src->name) + 1);
        if (!copy->name) {
            free(copy);
            return NULL;
        }
        strcpy(copy->name, src->name);
    } else {
        copy->name = NULL;
    }
    return (elem_t)copy;
}

void student_destroy(elem_t e) {
    if (!e) return;
    struct student *s = (struct student *)e;
    free(s->name);
    free(s);
}

void student_print(elem_t e) {
    if (!e) return;
    struct student *s = (struct student *)e;
    printf("student name: %s, age: %d, id: %d.\n", s->name, s->age, s->id);
}