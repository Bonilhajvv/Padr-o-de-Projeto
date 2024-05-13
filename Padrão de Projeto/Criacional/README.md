O padrão de projeto criacional Prototype é usado para criar novos objetos clonando um protótipo existente, em vez de instanciá-los usando um construtor. Isso é útil quando a criação de um objeto é cara em termos de tempo ou recursos, e uma cópia do objeto existente pode ser modificada conforme necessário.

Problema: Às vezes, a criação de objetos complexos pode ser custosa em termos de tempo e recursos. Além disso, é necessário criar objetos que são semelhantes a objetos existentes, com pequenas variações.

Solução: O padrão Prototype sugere a criação de uma interface ou classe abstrata que define um método para clonar objetos. As classes concretas implementam essa interface e fornecem sua própria implementação de clonagem. Quando um novo objeto é necessário, um objeto existente é clonado em vez de criar um novo do zero.

Propósito geral: O padrão Prototype permite a criação de novos objetos por meio da cópia de um protótipo existente, evitando a necessidade de construtores complexos e custosos.