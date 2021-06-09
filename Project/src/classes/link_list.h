#ifndef linkList_h
#define linkList_h

#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    float score;
    struct Node* next;
};

void add_score(struct Node** list, float data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *list;

    node->score = data;
    node->next = NULL;

    if (*list == NULL) {
        *list = node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = node;
    return;
}

float show_avg(struct Node* node) {
    float sum = 0;
    int i = 0;
    
    while (node != NULL) {
        sum +=  node->score;
        node = node->next;
        i++;
    }

    return sum/i;
}

#endif