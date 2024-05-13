O padrão de projeto estrutural Decorator é utilizado para adicionar funcionalidades adicionais a um objeto dinamicamente, sem alterar sua estrutura básica. Isso é útil quando você precisa estender o comportamento de um objeto de forma flexível e modular, sem criar subclasses excessivas.

Problema: Às vezes, você tem uma classe com funcionalidade básica, mas deseja adicionar funcionalidades extras a essa classe de forma flexível e sem criar subclasses desnecessárias.

Solução: O padrão Decorator sugere que você crie uma série de classes decoradoras que implementam a mesma interface que a classe original. Essas classes têm uma referência para a classe original e adicionam ou modificam seu comportamento conforme necessário. Dessa forma, você pode adicionar ou remover funcionalidades de um objeto dinamicamente em tempo de execução.

Propósito geral: O padrão Decorator é usado para estender as funcionalidades de um objeto de forma flexível e modular, sem modificar sua estrutura básica.