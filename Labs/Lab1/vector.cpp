#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

typedef sturct {

}

typedef struct {
    double* body;
    size_t size;
} vector;


vector* v_create()
{
    vector* v = (vector*)malloc(sizeof(vector));
    v -> size = 0;
    v -> body = NULL;
    return v;
}


void v_destroy(vector* v)
{
    free(v -> body);
    free(v);
}


size_t v_get_size(vector* v)
{
    return v -> size;
}


double v_get(vector* v, size_t i)
{
    return v -> body[i];
}


void v_set(vector* v, size_t i, double val)
{
    v -> body[i] = val;
}


bool v_set_size(vector* v, size_t new_size)
{
    double* bodyRe = (double*)realloc(v -> body, new_size * sizeof(double));
    if (bodyRe == NULL && new_size != 0) {
        return false;
    }
    for (int i = v -> size; i < v -> size; ++i) {
        bodyRe[i] = 0;
    }
    v -> body = bodyRe;
    v -> size = new_size;
    return true;
}


int main()
{
    vector* data = v_create();
    double a;
    while ((std::cin >> a) != -1) {
        size_t sz = v_get_size(data);
        if (!v_set_size(data, sz + 1)) {
            break;
        }
        v_set(data, sz, a);
    }

}

A 000 AA  13207862122685464576
Z 999 ZZ  7670388314707853312
A 000 AA  4588010303972900864
Z 999 ZZ  12992997081104908288
Q 242 UI  1214141241141414124
T 111 YY  51521512125521512
O 242 AB  521515121212
R 222 AR  215151
Y 211 AE  2121512
O 212 AG  124421421
I 211 AC  12414124
H 211 AD  1241212124
O 211 AM  214124412421
