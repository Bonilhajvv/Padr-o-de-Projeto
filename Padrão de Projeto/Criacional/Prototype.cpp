#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *type;
    void (*printInfo)();
    void (*destroy)();
    void* (*clone)();
} Prototype;


typedef struct {
    Prototype base;
    int id;
} ConcretePrototype;

void printInfo_Concrete(Prototype *self) {
    ConcretePrototype *concrete = (ConcretePrototype*)self;
    printf("Concrete Prototype of type %s with ID: %d\n", concrete->base.type, concrete->id);
}

void destroy_Concrete(Prototype *self) {
    ConcretePrototype *concrete = (ConcretePrototype*)self;
    free(concrete->base.type);
    free(concrete);
}

void* clone_Concrete(Prototype *self) {
    ConcretePrototype *concrete = (ConcretePrototype*)self;
    ConcretePrototype *cloned = (ConcretePrototype*)malloc(sizeof(ConcretePrototype));
    cloned->base.type = strdup(concrete->base.type);
    cloned->id = concrete->id;
    cloned->base.printInfo = concrete->base.printInfo;
    cloned->base.destroy = concrete->base.destroy;
    cloned->base.clone = concrete->base.clone;
    return cloned;
}

Prototype* createConcretePrototype(int id) {
    ConcretePrototype *concrete = (ConcretePrototype*)malloc(sizeof(ConcretePrototype));
    concrete->base.type = strdup("ConcretePrototype");
    concrete->id = id;
    concrete->base.printInfo = &printInfo_Concrete;
    concrete->base.destroy = &destroy_Concrete;
    concrete->base.clone = &clone_Concrete;
    return (Prototype*)concrete;
}

int main() {
    Prototype *prototype = createConcretePrototype(100);
    prototype->printInfo(prototype);

    Prototype *clonedPrototype = prototype->clone(prototype);
    clonedPrototype->printInfo(clonedPrototype);

    prototype->destroy(prototype);
    clonedPrototype->destroy(clonedPrototype);

    return 0;
}
