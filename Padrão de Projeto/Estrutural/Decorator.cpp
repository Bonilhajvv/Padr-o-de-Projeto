
#include <stdio.h>

// Interface Componente
typedef struct {
    void (*operation)();
} Component;

// Componente Concreto
typedef struct {
    Component base;
} ConcreteComponent;

void operation_ConcreteComponent() {
    printf("Operação do Componente Concreto.\n");
}

Component* createConcreteComponent() {
    Component *component = (Component*)malloc(sizeof(Component));
    component->operation = &operation_ConcreteComponent;
    return component;
}

// Decorator
typedef struct {
    Component *component;
} Decorator;

void operation_Decorator(Decorator *self) {
    printf("Operação do Decorator base.\n");
    self->component->operation(self->component);
}

// Decorador Concreto 1
typedef struct {
    Decorator base;
} ConcreteDecorator1;

void operation_ConcreteDecorator1(ConcreteDecorator1 *self) {
    printf("Operação adicional do Decorator Concreto 1.\n");
}

Decorator* createConcreteDecorator1(Component *component) {
    ConcreteDecorator1 *decorator = (ConcreteDecorator1*)malloc(sizeof(ConcreteDecorator1));
    decorator->base.component = component;
    decorator->base.operation = (void (*)(Decorator*))&operation_ConcreteDecorator1;
    return (Decorator*)decorator;
}

// Decorador Concreto 2
typedef struct {
    Decorator base;
} ConcreteDecorator2;

void operation_ConcreteDecorator2(ConcreteDecorator2 *self) {
    printf("Operação adicional do Decorator Concreto 2.\n");
}

Decorator* createConcreteDecorator2(Component *component) {
    ConcreteDecorator2 *decorator = (ConcreteDecorator2*)malloc(sizeof(ConcreteDecorator2));
    decorator->base.component = component;
    decorator->base.operation = (void (*)(Decorator*))&operation_ConcreteDecorator2;
    return (Decorator*)decorator;
}

int main() {
    // Criando um componente concreto
    Component *component = createConcreteComponent();

    // Criando um decorator concreto 1 e envolvendo o componente concreto
    Decorator *decorator1 = createConcreteDecorator1(component);

    // Criando um decorator concreto 2 e envolvendo o decorator 1
    Decorator *decorator2 = createConcreteDecorator2((Component*)decorator1);

    // Chamando a operação do decorator mais externo
    decorator2->operation(decorator2);

    free(component);
    free(decorator1);
    free(decorator2);

    return 0;
}


// Componente: Define a interface para objetos que podem ter responsabilidades adicionadas a eles.

// Componente Concreto: Implementa a interface do componente básico.

// Decorator: Mantém uma referência para um objeto Componente e define uma interface que segue a interface Componente.

// Decorador Concreto 1 e 2: Adiciona funcionalidades adicionais ao componente básico.