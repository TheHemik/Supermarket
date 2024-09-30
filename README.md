
# Supermercado Hemarket

Este é um sistema simples de supermercado em linguagem C. Ele permite que o usuário cadastre produtos, visualize uma lista de produtos disponíveis, adicione itens ao carrinho de compras, visualize o carrinho, remova itens, e finalize a compra. O sistema é desenvolvido para ser executado em um ambiente de console e mantém as informações em estruturas de dados na memória.

### Funcionalidades Implementadas
Cadastrar Produto: Permite adicionar novos produtos ao sistema.

Listar Produtos: Exibe todos os produtos cadastrados no sistema.

Comprar Produto: Adiciona um produto ao carrinho de compras com base no código do produto.

Visualizar Carrinho: Exibe os itens adicionados ao carrinho, mostrando a quantidade e o preço total.

Remover Item do Carrinho: Permite remover ou reduzir a quantidade de um produto específico do carrinho.

Fechar Pedido: Gera a fatura do carrinho, exibindo o total e limpando o carrinho após a confirmação da compra.

Arquivos main.c: Contém todo o código do sistema, incluindo a estrutura de dados e as funções responsáveis pelas operações do supermercado.

### Instruções para Compilação e Execução:
- Compilador GCC ou qualquer outro compatível com a linguagem C. VSCODE ou etc...
- Programmiz. Site online.


### Uso do Programa

- Cadastrar Produto:

O sistema solicitará o nome e o preço do produto.
O produto será salvo com um código único gerado automaticamente.
- Listar Produtos:

Exibe todos os produtos cadastrados com seu respectivo código, nome e preço.
- Comprar Produto:

Solicita o código do produto que deseja comprar.
Caso o produto esteja disponível, ele será adicionado ao carrinho.
- Visualizar Carrinho:

Exibe os itens que foram adicionados ao carrinho, incluindo a quantidade e o preço total.
- Fechar Pedido:

Exibe uma fatura com o total dos itens no carrinho.
Após a finalização da compra, o carrinho é esvaziado.
- Remover Item do Carrinho:

Solicita o código do produto que deseja remover do carrinho.
Caso o produto tenha mais de uma unidade, apenas a quantidade será reduzida. Se houver apenas uma unidade, o produto será completamente removido do carrinho.
- Sair:

Encerra o programa.

### Considerações Finais

O código permite que o usuário tenha acesso ao controle dos produtos cadastrados de um supermercado. É possível cadastrar, retirar e listar os produtos. Além de ter acesso a um carrinho, em que você pode adicionar muitos produtos antes de decidir fechar o pedido.
