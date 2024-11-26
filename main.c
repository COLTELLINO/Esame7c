#include <stdio.h>
#include "intlist.h"

int main() {
    IntList list;
    initList(&list); // Inizializza la lista

    // Test dell'inserimento in coda
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);

    // Stampa la lista
    printf("Lista dopo l'inserimento: ");
    printList(&list);

    // Test dell'eliminazione di un valore
    int valueToDelete = 20;
    if (deleteValue(&list, valueToDelete)) {
        printf("Valore %d eliminato dalla lista.\n", valueToDelete);
    } else {
        printf("Valore %d non trovato nella lista.\n", valueToDelete);
    }

    // Stampa la lista dopo l'eliminazione
    printf("Lista dopo l'eliminazione: ");
    printList(&list);

    return 0;
}
