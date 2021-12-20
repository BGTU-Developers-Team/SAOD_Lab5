#include <iostream>
#include "stack.h"
#include <fstream>
#include <string>
using namespace std;
#define INT_MAXIMUM 2147483647

int main() {
    fstream file("input.txt");
    if (!file.good()) return 0;

    StackL stack;

    string inputLine;
    int numberOfChars;
    int minNumberOfChars = INT_MAXIMUM;
    int idx = 0;
    int minIdx = idx;

    while (getline(file, inputLine)) {
        numberOfChars = inputLine.length();
        Push(&stack, numberOfChars);
        if (numberOfChars <= minNumberOfChars) {
            minNumberOfChars = numberOfChars;
            minIdx = idx;
        }
        idx++;
    }

    PrintStack(&stack);

    cout << endl;
    cout << "The last shortest line is #" << minIdx + 1 << " with " << minNumberOfChars << " characters." << endl;

    return 1;
}

void InitStack(StackL *s) {
    s->top = NULL;
}


int Push(StackL *s, double v) {
    auto *p = (struct LE *) malloc(sizeof(struct LE));
    if (!p) return 0;
    p->next = s->top;
    p->v = v;
    s->top = p;
    return 1;
}

double Pop(StackL *s) {
    struct LE *p;
    double x = 1e300;

    if (s->top) {
        p = s->top;
        s->top = s->top->next;
        x = p->v;
        free(p);
    }
    return x;

}

double Peek(StackL const *s) {
    if (s->top)
        return s->top->v;
    return -1;
}

int IsEmptyStack(StackL const *s) {
    return s->top == NULL;
}

void Clear(StackL *s) {
    while (!IsEmptyStack(s)) Pop(s);
}

void PrintStack(StackL const *s) {
    struct LE *p;
    for (p = s->top; p; p = p->next)
        printf("%-7.0lf ", p->v);
}

void Destruct(StackL *s) {
    Clear(s);
}
