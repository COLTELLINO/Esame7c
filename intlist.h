// Definizione del nodo
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Definizione della lista doppiamente concatenata
typedef struct {
    Node* head;
    Node* tail;
} IntList;

// Prototipi delle funzioni da implementare in intlist.c
int initList(IntList* l); // Inizializza la lista come vuota
int insertAtEnd(IntList* l, int value); // Inserisce un elemento in coda alla lista
int deleteValue(IntList* l, int value); // Elimina la prima occorrenza di un valore dalla lista
void printList(IntList* l); // Stampa tutti gli elementi della lista
