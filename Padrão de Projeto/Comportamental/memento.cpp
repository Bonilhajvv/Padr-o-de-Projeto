
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *state;
} Memento;

Memento* createMemento(const char *state) {
    Memento *memento = (Memento*)malloc(sizeof(Memento));
    memento->state = strdup(state);
    return memento;
}

void destroyMemento(Memento *memento) {
    free(memento->state);
    free(memento);
}


typedef struct {
    char *state;
} Originator;

Originator* createOriginator(const char *state) {
    Originator *originator = (Originator*)malloc(sizeof(Originator));
    originator->state = strdup(state);
    return originator;
}

void setState(Originator *originator, const char *state) {
    free(originator->state);
    originator->state = strdup(state);
}

void restoreFromMemento(Originator *originator, Memento *memento) {
    setState(originator, memento->state);
}

Memento* saveToMemento(Originator *originator) {
    return createMemento(originator->state);
}

void destroyOriginator(Originator *originator) {
    free(originator->state);
    free(originator);
}


int main() {
    Originator *originator = createOriginator("State1");
    Memento *memento = saveToMemento(originator);
    
    setState(originator, "State2");
    printf("Current State: %s\n", originator->state);

    restoreFromMemento(originator, memento);
    printf("Restored State: %s\n", originator->state);

    destroyMemento(memento);
    destroyOriginator(originator);

    return 0;
}


