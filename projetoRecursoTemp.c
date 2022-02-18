// pré-compilação
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stddef.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

#define STRING char *
#define MAX_LINHA_FICHEIRO 2048
typedef char LinhaTexto[MAX_LINHA_FICHEIRO];
LinhaTexto LT;
// STRUCTS

typedef struct categoria
{
    char nome[40];
    int codigo;

} CATEGORIA;

typedef struct produto
{
    char nome[40];
    CATEGORIA categoria;
    int preco;
    int codigo;

} PRODUTO;

typedef struct itemLista
{
    int quantidade;
    int estado;
    PRODUTO produto;
} ITEMLISTA;

typedef struct lista
{
    ITEMLISTA *ITEM;
    char nome[40];
    int codigo;
} LISTA;

// OPERAÇÃO COM FICHEIROS
char **splitLine(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores)
{
    *n_campos_lidos = 0;

    if (fgets(LT, 150, f) != NULL) // fgets lê uma linha do ficheiro de texto para a string LT
    {
        // "partir" a linha lida, usando os separadores definidos
        char **Res = (char **)malloc(n_campos_max * sizeof(char *)); // alocação de um array com
                                                                     // n_campos_max ponteiros para STRING
        char *pch = strtok(LT, separadores);
        int cont = 0;
        while (pch != NULL)
        {
            Res[cont] = (char *)malloc((strlen(pch) + 1) * sizeof(char)); // alocação do espaço necessário para guardar a
                                                                          // string correspondente ao campo
            strcpy(Res[cont++], pch);
            pch = strtok(NULL, separadores);
        }
        *n_campos_lidos = cont;
        return Res;
    }

    return NULL;
};

// CRIAÇAO DE FICHEIROS

int criarFicheiroListaCompra()
{
    FILE *F1 = fopen("ListaCompra.txt", "a+");
    // fprintf(F1, "Nome;codigo");

    return 0;
}
int criarFicheiroListaCompraBin()
{
    FILE *F1 = fopen("ListaCompra.txt", "a+b");
    fprintf(F1, "Produto;Codigo;Quantidade;Preço");

    return 0;
}
// TODO: REMOVER O CAMPO "QUANTIDADE DO PRODUTO", JÁ QUE ISSO
// ESTARÁ NO FICHEIRO DO ITEM DA LISTA
int criarFicheiroProduto()
{
    FILE *F1 = fopen("Produtos.txt", "a+");
    // fprintf(F1, "Nome;Categoria;Preço;Codigo");

    return 0;
}
int criarFicheiroProdutoBin()
{
    FILE *F1 = fopen("Produtos.txt", "a+b");
    // fprintf(F1, "Nome;Categoria;Preço;Codigo");

    return 0;
}
int criarFicheiroCategorias()
{
    FILE *F1 = fopen("Categorias.txt", "a+");

    return 0;
}
int criarFicheiroCategoriasBin()
{
    FILE *F1 = fopen("Categorias.txt", "a+b");

    return 0;
}
int criarFicheiroItensCabaz()
{
    FILE *F1 = fopen("ItensCabaz.txt", "a+");

    return 0;
}
int criarFicheiroItensCabazBin()
{
    FILE *F1 = fopen("ItensCabaz.txt", "a+b");

    return 0;
}

//TODO: criar ficheiro item listat
// FUNÇÕES AUXILIARES

int gerarCodigo()
{
    byte numerais[6];
    int codigo = 0;
    int i;
    for (i = 0; i < 6; i++)
    {
        numerais[i] = rand() % 10 + 1;
        codigo += numerais[i] * pow(10, i);
    }
    return codigo;
}

// CRIAR, REMOVER, EDITAR, LISTAR NOS FICHEIROS

// FUNÇÕES DE ELIMINAR:
int Temp_EliminarProduto(PRODUTO produto)
{
    int i;
    int temp = 0;

     FILE *f = fopen("ProdutosTemp.txt", "w");

    int erro = 0;
    fprintf(f, "%s;%s;%d;%d\n", produto.nome, produto.categoria.nome, produto.preco,
            produto.codigo);

    fclose(f);
    return 0;
}





int criarItemLista(ITEMLISTA item)
{
    FILE *f = fopen("ItemLista.txt", "a");
    if(item.estado != 0)
    {
        item.estado = 1;
    }
    return 0;
}
int editarProdutos()
{
    PRODUTO produtos;
    int linha, i;
    char nomeProduto[50];
    linha = Temp_EliminarProduto(produtos);

    FILE *f, *temp;
    char nome_f[1024] = "Produtos.txt";
    char nome_temp[1024];
    char buffer[MAX_LINHA_FICHEIRO];

    strcpy(nome_temp, "temp_");
    strcat(nome_temp, nome_f);

    f = fopen(nome_f, "r");
    temp = fopen(nome_temp, "w");

    if (f == NULL || temp == NULL)
    {
        printf("Ficheiro não encontrado!\n");
        return 1;
    }

    bool keep_reading = true;
    int current_line = 1;
    // Enquanto a variavel keep_reading for verdadeira faz:
    // Vai buscar os dados na linha atual e insere no ficheiro temp_Pessoas
    // Quando o ficheiro acabar ou a linha que foi dada pela funcao for igual a linha coloca a varivel a falso e fecha o ficheiro
    // Quando as linhas forem iguals pede ao utilizador dados nomes e insere no ficheiro
    do
    {

        fgets(buffer, MAX_LINHA_FICHEIRO, f);

        if (feof(f))
        {
            keep_reading = false;
        }
        else if (current_line == linha)
        {

            criarProduto(produtos);
        }
    } while (keep_reading);
    fclose(f);
    fclose(temp);

    remove(nome_f);
    rename(nome_temp, nome_f);
}

// TODO: REMOVER


int eliminarLista()
{

    return 0;
}

/*
    Está função "supostamente" pega os dados que foram inseridos
    quanto a um produto, geralmente vindo de um menu e;
    1º VERIFICA SE OS DADOS ESTÃO CORRETOS, CASO NÃO A FUNÇÃO DEVOLVE 0 "ERRO"
    2º CASO ESTEJAM CORRETOS, TENTA COLOCAR NO FICHEIRO, CASO NÃO
    CONSIGA COLOCAR NO FICHEIRO, A FUNÇÃO DEVOLVE 0 "ERRO"
    - No milagre de tudo der certo, a função devolve 1, ou seja o produto foi
    criado com sucesso
*/

// FUNÇÕES DE CRIAR:

// TODO: REMOVER O CAMPO "QUANTIDADE DO PRODUTO"
// MELHORAR VALIDAÇÃO
// LIMPAR CÓDIGO

int criarProduto(PRODUTO produto)
{
    FILE *f = fopen("Produtos.txt", "a");
    int erro = 0;
    produto.codigo = gerarCodigo();
    produto.preco = (produto.preco) > 0 ? produto.preco : -produto.preco;
    fprintf(f, "%s;%s;%d;%d\n", produto.nome, produto.categoria.nome, produto.preco,
            produto.codigo);

    fclose(f);

    return erro;
}

/*
    Está função "supostamente" pega os dados que foram inseridos
    quanto a uma lista, geralmente vindo de um menu e;
    1º VERIFICA SE OS DADOS ESTÃO CORRETOS, CASO NÃO A FUNÇÃO DEVOLVE 0 "ERRO"
    2º CASO ESTEJAM CORRETOS, TENTA COLOCAR NO FICHEIRO, CASO NÃO
    CONSIGA COLOCAR NO FICHEIRO, A FUNÇÃO DEVOLVE 0 "ERRO"
    - No milagre de tudo der certo, a função devolve 1, ou seja a lista foi
    criada com sucesso
*/

// TODO: CRIAR FUNÇÃO NOS MOLDES DE criarProduto();
int criarLista(LISTA lista)
{
    int i;
    FILE *F1 = fopen("ListaCompra.txt", "a");
    lista.codigo = gerarCodigo();
    fprintf(F1, "%s;%d \n", lista.nome, lista.codigo);
    fclose(F1);

    return 0;
}

// TODO: MELHORAR
int criarCategoria(CATEGORIA categoria)
{
    FILE *f = fopen("Categorias.txt", "a");
    int erro = 0;

    categoria.codigo = gerarCodigo();

    fprintf(f, "\n%s;%d", categoria.nome, categoria.codigo);
    fclose(f);

    return 0;
}

// FUNÇÕES DE LISTAR

// TODO: FAZER FUNÇÃO

// TODO: FAZER FUNÇÃO
ITEMLISTA *listarItensLista(int codigoLista)
{
}

// TODO: FAZER FUNÇÃO
LISTA *listarListas()
{
}
int contarProdutos(PRODUTO *prod)
{
    int i = 0;
    do
    {
        i++;
    } while (prod[i].codigo != 0);

    return i;
}

int contarCategoria(CATEGORIA *cat)
{
    int i = 0;
    do
    {
        i++;
    } while (cat[i].codigo != 0);

    return i;
}

// TODO: limpar código
PRODUTO * listarProdutos()
{
    PRODUTO *prod = (PRODUTO*) malloc(65536 * sizeof(PRODUTO));
    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i;
    int count = 1;
    FILE *f = fopen("Produtos.txt", "r");

    while (!feof(f))
    {
        STRING *V = splitLine(f, 4, &n_campos_lidos, ";\r\n"); // NÃO ESTÁ FUNCIONANDO
        ++n_linhas_lidas;
        for (i = 0; i < n_campos_lidos; i++)
        {
            if (i + 1 == 1)
            {
                strcpy(prod[count - 1].nome, V[i]);
            }
            else if (i + 1 == 2)
            {
                strcpy(prod[count - 1].categoria.nome, V[i]);
            }
            else if (i + 1 == 3)
            {
                int x = atoi(V[i]); // preco
                float y = x / 10.0;
                prod[count - 1].preco = x;
            }
            else if (i + 1 == 4)
            {
                prod[count - 1].codigo = atoi(V[i]);
            }
        }
        printf("\n");
        // Desloca a mem�ria alocada em V[i]
        for (i = 0; i < n_campos_lidos; i++)
        {
            free(V[i]);
        }
        free(V);
        count++;
    }
    printf("...Teste: %d \n", count - 1);
    printf("Teste: %d \n", sizeof(prod));

    prod =  realloc(prod, (count - 1) * sizeof(prod));
    return prod;
}

// TODO: FAZER FUNÇÃO
CATEGORIA *listarCategorias()
{
    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i;
    FILE *f = fopen("Categorias.txt", "r");
    int count = 1;

    CATEGORIA *cat = (CATEGORIA *)malloc(65536 * sizeof(CATEGORIA));
    while (!feof(f))
    {
        // Aloca os dados numa string V
        STRING *V = splitLine(f, 2, &n_campos_lidos, ";\r\n");
        ++n_linhas_lidas;
        // printf("%s", V);
        // Le os dados no ficheiro com os separados ; \r e \n
        // printf("%d. ", count);

        for (i = 0; i < n_campos_lidos; i++)
        {
            // printf("%d \t", i+1);
            // Le os dados nos campos e
            // Verifica se na posicao i+1 == 1 Le os dados na primeira "comparti��o" que s�o os nomes dos ALimentos

            if (i + 1 == 1)
            {
                strcpy(cat[count - 1].nome, V[i]);
            }
            else if (i + 1 == 2)
            {
                cat[count - 1].codigo = atoi(V[i]);
            }
        }
        for (i = 0; i < n_campos_lidos; i++)
        {

            free(V[i]);
        }
        free(V);
        count++;
    }

    cat = realloc(cat, (count - 1) * sizeof(CATEGORIA));
    printf("Teste: %d \n", sizeof(cat));

    return cat;
}

void printCategorias(CATEGORIA *categoria)
{
    int i;
    for (i = 0; i < contarCategoria(categoria); i++)
    {
        printf("\n %d.", i + 1);
        printf("Nome:  %s ", categoria[i].nome);
        printf("  Codigo: %d \n", categoria[i].codigo);
    }
}

void printProdutos(PRODUTO *produto)
{
    int i;
    for (i = 0; i < contarProdutos(produto); i++)
    {
        printf("\n %d. ", i);
        printf("Nome:  %s \n", produto[i].nome);
        printf("Codigo: %d \n", produto[i].codigo);
        printf("Preço: %.2f EUR \n", produto[i].preco / 10.0);
        printf("Categoria: %s \n", produto[i].categoria.nome);
    }
}

int calcularPrecoTotalLista()
{
}

// LISTAGENS

// MENUS E INTERAÇÃO

void menuCriarCategoria()
{
    system("cls");
    CATEGORIA categoria;

    printf("\n Nome da categoria: \n");
    scanf("%s", categoria.nome);

    criarCategoria(categoria);
}

// TODO: MELHORAR
void menuCriarLista()
{
    LISTA lista;
    printf("\n Nome da lista: ");
    scanf("%s", lista.nome);
    criarLista(lista);
}

// TODO: MELHORAR A PARTE DE IR PARA CRIAR A CATEGORIA
void menuCriarProduto()
{
    PRODUTO produto;
    CATEGORIA *categoria = listarCategorias();
    categoria = listarCategorias();
    int qtdCategorias = contarCategoria(categoria);
    int nProduto;
    int erro = 0;
    float precoFloat;
    int nCategoria = 0;

    printf("\nNome Produto:");
    scanf("%s", &produto.nome);

    printf("\nPreco: ");
    scanf("%f", &precoFloat);
    produto.preco = (int)(precoFloat * 100.00);

    system("cls");
    printf("\n Escolha uma categoria Categoria: ");
    printCategorias(categoria);
    printf("\n Escolha uma opção (0 para criar  nova categoria) \n"); // SE A OPÇÃO 0 FOR ESCOLHIDA, PEDIRÁ PARA CRIAR
    Sleep(500);
    while (getchar() != '\n') // ARRUMA O BUG DO scanf()
        continue;
    scanf("%d", &nCategoria); // UMA NOVA CATEGORIA CASO O USUÁRIO DECIDA
    if (nCategoria <= 0)
    {
        menuCriarCategoria();
        categoria = listarCategorias();
        qtdCategorias = contarCategoria(categoria) - 1;
        produto.categoria.codigo = categoria[qtdCategorias].codigo;
        strcpy(produto.categoria.nome, categoria[qtdCategorias].nome);
        criarProduto(produto);
    }
    else if (nCategoria > 0 && nCategoria <= qtdCategorias)
    { // USA A CATEGORIA SELECIONADA PRO PRODUTO
        produto.categoria.codigo = categoria[nCategoria - 1].codigo;
        strcpy(produto.categoria.nome, categoria[nCategoria - 1].nome);
        criarProduto(produto);
    }
    else
    {
        // TODO: ajustar
        puts("ERRO");
        Sleep(5000);
    }
}

// TODO: FAZER INTERFACE
void gerenciarListas()
{
}

// TODO: FAZER INTERFACE
void gerenciarProdutos()
{
}

// TODO: FAZER INTERFACE
void gerenciarCategorias()
{
}

// TODO: FAZER INTERFACE
void consultarListas()

{
}

int eliminarProduto(int codigo)
{
    PRODUTO *produto;
    produto=listarProdutos();
    int t = contarProdutos(produto), i;
    printf(" count : %d \n", t);
    for (i = 0; i < t;i++){
        if(produto[i].codigo != codigo){
            puts("teste");
            Temp_EliminarProduto(produto[i]);
        }
    }
    rename("ProdutosTemp.txt", "xpto.txt");
    
}
void menuEliminarProduto(){
    int codigo;
    printProdutos(listarProdutos());
    printf("Insira o codigo do produto que deseja eliminar:");
    scanf("%d", &codigo);
    eliminarProduto(codigo);
}



// TODO: ALTERAR OPÇÕES DO MENU
int mostrarMenuPrincipal()
{
    int opcaoInvalida, opcao;

    do
    {
        system("cls");
        printf(" _________________________________________________________________________\n");
        printf("|                            MENU PRINCIPAL                               |\n");
        printf("|_________________________________________________________________________|\n");
        printf("\n\t1 - Area de Produtos\n");
        printf("\t2 - Area das listas\n");
        printf("\t3 - Area das Categorias\n");
        printf("\t4 - Modo Compras\n");
        printf("\t5 - Sair\n");
        printf("\nDigite o numero relativo ao menu a que pretende aceder: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            system("cls");
            mostrarMenuProdutos();
            break;
        case 2:
            system("cls");
            mostrarMenuLista();
            break;
        case 3:
            system("cls");
            mostrarMenuCategorias();
            break;
        case 4:
            system("cls");
            mostrarMenuModoCompras();
            break;
        case 5:
            system("cls");
            printf("\n\n\n\t\tObrigado por usar a nossa aplicao!");
            Sleep(3500);
            // system(exit);
            break;

        default:
            printf("\n\tERRO! Introduza uma opcao valida\n\n");
            system("pause");

            break;
        }
        fseek(stdin, 2, 0);
    } while (opcaoInvalida);
    return 0;
}

int mostrarMenuProdutos()
{
    int opcaoInvalida, opcao;

    do
    {
        system("cls");
        printf(" _________________________________________________________________________\n");
        printf("|                            MENU PRODDUTOS                               |\n");
        printf("|_________________________________________________________________________|\n");
        printf("\n\t1 - Adicionar Produto\n");
        printf("\t2 - Editar Produto\n");
        printf("\t3 - Listar Produtos\n");
        printf("\t4 - Eliminar Produto\n");
        printf("\t5 - Voltar\n");
        printf("\nDigite o numero relativo ao menu a que pretende aceder: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            system("cls");
            menuCriarProduto();
            break;
        case 2:
            system("cls");
           // editarProdutos();
            break;
        case 3:
            system("cls");
            //listarProdutos();
            break;
        case 4:
            system("cls");
           // eliminarProduto();
            break;
        case 5:
            system("cls");
            mostrarMenuPrincipal(opcao);
            break;
        default:
            printf("\n\tERRO! Introduza uma opcao valida\n\n");
            system("pause");

            break;
        }
        fseek(stdin, 2, 0);
    } while (opcaoInvalida);
    return 0;
}
int mostrarMenuLista()
{
    int opcaoInvalida;
    int opcao;
    do
    {
        system("cls");
        printf(" _________________________________________________________________________\n");
        printf("|                              MENU LISTAS                                |\n");
        printf("|_________________________________________________________________________|\n");
        printf("\n\t1 - Adicionar lista\n");
        printf("\t2 - Editar lista\n");
        printf("\t3 - Listar as listas\n");
        printf("\t4 - Eliminar lista\n");
        printf("\t5 - Transferir Produto a outra lista\n");
        printf("\t6 - Voltar\n");
        printf("\nDigite o numero relativo ao menu a que pretende aceder: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            system("cls");
            menuCriarLista();
            break;
        case 2:
            system("cls");
            // editarLista();
            break;
        case 3:
            system("cls");
            // listarListas();
            break;
        case 4:
            system("cls");
            // eliminarLista();
        case 5:
            system("cls");
            // transferirProduto();
            break;
        case 6:
            system("cls");
            mostrarMenuPrincipal();
            break;
        default:
            printf("\n\tERRO! Introduza uma opcao valida\n\n");
            system("pause");

            break;
        }
        fseek(stdin, 2, 0);
    } while (opcaoInvalida);
    return 0;
}
int mostrarMenuCategorias()
{
    int opcaoInvalida;
    int opcao;
    do
    {
        system("cls");
        printf(" _________________________________________________________________________\n");
        printf("|                             MENU CATEGORIAS                             |\n");
        printf("|_________________________________________________________________________|\n");
        printf("\n\t1 - Adicionar categoria\n");
        printf("\t2 - Editar categoria\n");
        printf("\t3 - Listar as categoria\n");
        printf("\t4 - Eliminar categoria\n");
        printf("\t5 - Voltar\n");
        printf("\nDigite o numero relativo ao menu a que pretende aceder: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            system("cls");
            menuCriarCategoria();
            break;
        case 2:
            system("cls");
            // editarLista();
            break;
        case 3:
            system("cls");
            listarListas();
            break;
        case 4:
            system("cls");
            eliminarLista();
        case 5:
            system("cls");
            mostrarMenuPrincipal();
            break;
        default:
            printf("\n\tERRO! Introduza uma opcao valida\n\n");
            system("pause");

            break;
        }
        fseek(stdin, 2, 0);
    } while (opcaoInvalida);
    return 0;
}
int mostrarMenuModoCompras()
{
    int opcaoInvalida;
    int opcao;
    do
    {
        system("cls");
        printf(" _________________________________________________________________________\n");
        printf("|                               MODO COMPRAS                              |\n");
        printf("|_________________________________________________________________________|\n");
        printf("\n\t1 - Adicionar categoria\n");
        printf("\t2 - Editar categoria\n");
        printf("\t3 - Listar as categoria\n");
        printf("\t4 - Eliminar categoria\n");
        printf("\t5 - Voltar\n");
        printf("\nDigite o numero relativo ao menu a que pretende aceder: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            system("cls");
            menuCriarLista();
            break;
        case 2:
            system("cls");
            // editarLista();
            break;
        case 3:
            system("cls");
            listarListas();
            break;
        case 4:
            system("cls");
            eliminarLista();
        case 5:
            system("cls");
            mostrarMenuPrincipal();
            break;
        default:
            printf("\n\tERRO! Introduza uma opcao valida\n\n");
            system("pause");

            break;
        }
        fseek(stdin, 2, 0);
    } while (opcaoInvalida);
    return 0;
}

// TODO COLOCAR TODOS OS CRIAR"FICHEIRO" AQUI
void iniciarFicheiros()
{
    criarFicheiroProduto();
    criarFicheiroCategorias();
    criarFicheiroListaCompra();
    criarFicheiroCategoriasBin();
    criarFicheiroItensCabaz();
}

// INICIALIZAÇÃO

// TODO: REMOVER TESTES. ADICIONAR SUPORTE A PORTUGUES
int main()
{
    setlocale(LC_ALL, "Portuguese");
    // iniciarFicheiros();
    srand(time(NULL));
    // testes

    // editarProdutos(produto);
    // eliminarProduto(produto);
    // menuCriarProduto();
    // menuCriarLista();

    CATEGORIA *cat;
    PRODUTO *prod;
    // menuCriarLista();
    //menuEliminarProduto();
    //menuCriarProduto();

    
    
    cat = listarCategorias();
    menuEliminarProduto();
    printCategorias(cat);

    return 0;
}