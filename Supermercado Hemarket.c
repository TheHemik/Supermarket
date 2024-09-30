#include <stdio.h>

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

Produto produtos[50];
Carrinho carrinho[50];
int numeroProdutos = 0;
int numeroItensCarrinho = 0;

void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();
int temNoCarrinho(int codigo);
Produto* pegarProdutoPorCodigo(int codigo);
void removerItemCarrinho(); 

void menu() {
    int option;
    do {
        printf("===============================================================================================\n");
        printf("==================================== BEM VINDO AO SUPERMERCADO HEMARKET ========================\n");
        printf("===============================================================================================\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Visualizar Carrinho\n");
        printf("5. Fechar Pedido\n");
        printf("6. Remover Item do Carrinho\n"); // Nova opção no menu
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                comprarProduto();
                break;
            case 4:
                visualizarCarrinho();
                break;
            case 5:
                fecharPedido();
                break;
            case 6:
                removerItemCarrinho();
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (option != 7);
}

void cadastrarProduto() {
    if (numeroProdutos >= 50) {
        printf("Limite de produtos cadastrados atingido!\n");
        return;
    }

    Produto p;
    p.codigo = numeroProdutos + 1;
    printf("Digite o nome do produto: ");
    scanf("%s", p.nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &p.preco);

    produtos[numeroProdutos] = p;
    numeroProdutos++;

    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    for (int i = 0; i < numeroProdutos; i++) {
        printf("%d - %s (R$%.2f)\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
}

void comprarProduto() {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    Produto *p = pegarProdutoPorCodigo(codigo);
    if (p == NULL) {
        printf("Produto não encontrado!\n");
        return;
    }

    int pos = temNoCarrinho(codigo);
    if (pos != -1) {
        carrinho[pos].quantidade++;
    } else {
        carrinho[numeroItensCarrinho].produto = *p;
        carrinho[numeroItensCarrinho].quantidade = 1;
        numeroItensCarrinho++;
    }

    printf("Produto adicionado ao carrinho!\n");
}

void visualizarCarrinho() {
    if (numeroItensCarrinho == 0) {
        printf("Carrinho vazio!\n");
        return;
    }

    for (int i = 0; i < numeroItensCarrinho; i++) {
        Produto p = carrinho[i].produto;
        printf("%d - %s (R$%.2f) x %d\n", p.codigo, p.nome, p.preco, carrinho[i].quantidade);
    }
}

void fecharPedido() {
    if (numeroItensCarrinho == 0) {
        printf("Carrinho vazio! Não há pedido para fechar.\n");
        return;
    }

    float total = 0;
    printf("Fatura:\n");
    for (int i = 0; i < numeroItensCarrinho; i++) {
        Produto p = carrinho[i].produto;
        int qtd = carrinho[i].quantidade;
        printf("%s (R$%.2f) x %d = R$%.2f\n", p.nome, p.preco, qtd, p.preco * qtd);
        total += p.preco * qtd;
    }
    printf("Total: R$%.2f\n", total);

    numeroItensCarrinho = 0;
    printf("Pedido fechado com sucesso!\n");
}
int temNoCarrinho(int codigo) {
    for (int i = 0; i < numeroItensCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            return i;
        }
    }
    return -1;
}

Produto* pegarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < numeroProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return &produtos[i];
        }
    }
    return NULL;
}

void removerItemCarrinho() {
    if (numeroItensCarrinho == 0) {
        printf("Carrinho vazio! Não há itens para remover.\n");
        return;
    }

    int codigo;
    printf("Digite o código do produto que deseja remover: ");
    scanf("%d", &codigo);

    int pos = temNoCarrinho(codigo);
    if (pos == -1) {
        printf("Produto não encontrado no carrinho!\n");
        return;
    }

    if (carrinho[pos].quantidade > 1) {
        carrinho[pos].quantidade--;
        printf("Quantidade do produto %s reduzida em 1.\n", carrinho[pos].produto.nome);
    } else {
        for (int i = pos; i < numeroItensCarrinho - 1; i++) {
            carrinho[i] = carrinho[i + 1]; 
        }
        numeroItensCarrinho--; 
        printf("Produto removido do carrinho.\n");
    }
}

int main() {
    menu();
    return 0;
}
