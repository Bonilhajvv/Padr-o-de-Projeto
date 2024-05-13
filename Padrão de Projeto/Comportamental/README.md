// O padrão Memento é utilizado quando se precisa implementar a funcionalidade de capturar e restaurar o estado interno de um objeto, sem violar o encapsulamento. Ele resolve o problema de como capturar e restaurar o estado de um objeto sem expor detalhes de sua implementação interna, como seus campos e métodos.

// Problema: como exemplo caso esteja desenvolvendo um editor de texto e deseje implementar a funcionalidade de desfazer/refazer. Você precisa capturar o estado atual do editor de texto em determinados momentos (por exemplo, antes de cada operação de edição) e ser capaz de restaurar esse estado mais tarde, se necessário.

// Solução: O padrão Memento oferece uma solução para esse problema. Ele introduz três principais participantes:
// Originator: É o objeto cujo estado queremos salvar. Ele possui métodos para definir e obter o estado, bem como métodos para criar e restaurar o estado a partir de um memento.
// Memento: É uma classe que armazena o estado do Originator. O estado é encapsulado dentro do Memento, garantindo que ele não seja acessível diretamente por outros objetos. Apenas o Originator pode acessar e modificar o estado do Memento.
// Caretaker: É uma classe externa que é responsável por manter e gerenciar os mementos. Ele pode criar, armazenar e fornecer mementos para o Originator, mas não tem acesso ao estado contido dentro dos mementos.

// Desta forma, o padrão Memento é usado para capturar o estado interno de um objeto em um determinado momento, permitindo que o objeto seja restaurado para esse estado mais tarde, sem expor sua implementação interna. Ele promove o princípio do encapsulamento, garantindo que apenas o próprio objeto possa acessar e modificar seu estado interno.