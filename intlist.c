#include "intlist.h"
#include <stdlib.h>
#include <stdio.h>

int initList(IntList* l) {
    if (l == NULL) {
        return 0; // Controllo se la lista è nulla
    }
    l->head = NULL;
    l->tail = NULL;
    return 1; // Successo
}

int insertAtEnd(IntList* l, int value) {
    if (l == NULL) {
        return 0; // Controllo se la lista è nulla
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0; // Errore nell'allocazione di memoria
    }
    newNode->data = value;
    newNode->next = NULL;

    if (l->head == NULL) {
        l->head = newNode;
        newNode->prev = NULL;
    } else {
        l->tail->next = newNode;
        newNode->prev = l->tail;
    }
    l->tail = newNode;
    return 1; // Successo
}

int deleteValue(IntList* l, int value) {
    if (l == NULL || l->head == NULL) {
        return 0; // Controllo se la lista è nulla o vuota
    }
    Node* current = l->head;
    while (current != NULL) {
        if (current->data == value) {
            if (current == l->head) {
                l->head = current->next;
                if (l->head != NULL) {
                    l->head->prev = NULL;
                } else {
                    l->tail = NULL; // Lista vuota
                }
            } else if (current == l->tail) {
                l->tail = current->prev;
                l->tail->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return 1; // Successo
        }
        current = current->next;
    }
    return 0; // Valore non trovato
}

void printList(IntList* l) {
    if (l == NULL || l->head == NULL) {
        printf("Lista vuota\n");
        return;
    }
    Node* current = l->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
