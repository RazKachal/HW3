#ifndef STUDENT_H
#define STUDENT_H

#include "common.h"

struct student {
    char *name;
    int age;
    int id;
};

elem_t student_clone(elem_t e);
void student_destroy(elem_t e);
void student_print(elem_t e);

#endif // STUDENT_H