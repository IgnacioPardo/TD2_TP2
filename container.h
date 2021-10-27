#ifndef _CONTAINER_HH_
#define _CONTAINER_HH_

#include <stdio.h>
#include <stdlib.h>

struct node {
    char* data;
    struct node* next;
};

struct container {
    struct node* data[4];
    int count;
};

int dupStr(char* src, char** dst);

int cmpStr(char* s1, char* s2);

int equalStr(char* s1, char* s2);

char normalizeChar(char c);

void split(char* source, int count, char** s1, char** s2);

int getIndex(char* s);

void sortedAdd(struct container* c, char* value);

int contains(struct container* c, char* value);

int inverseDelete(struct container* c, char* value);

struct container* newContainer();

void deleteContainer(struct container* c);

void printContainer(struct container* c);

#endif
