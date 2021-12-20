#ifndef LAB5_STACK_H
#define LAB5_STACK_H

struct LE {
    double v;
    struct LE *next;
};

typedef struct {
    struct LE *top;
} StackL;


int Push(StackL *s, double v);

double Pop(StackL *s);

double Peek(StackL const *s);

int IsEmptyStack(StackL const *s);

void Clear(StackL *s);

void InitStack(StackL *s);

void PrintStack(StackL const *s);

void Destruct(StackL *s);

#endif //LAB5_STACK_H
