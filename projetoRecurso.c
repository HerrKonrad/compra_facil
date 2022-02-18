// QUANDO FIZ ESSE CÓDIGO SÓ EU E DEUS SABIA O QUE ESTAVA ACONTECENDO,
// AGORA SÓ DEUS


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
    int codigo;
    PRODUTO produto;
} ITEMLISTA;

typedef struct lista
{
    ITEMLISTA item;
    char nome[40];
    int codigo;
} LISTA;

// FUNCAO LER LINHA FICHEIRO

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

    return 0;
}
int criarFicheiroListaCompraBin()
{
    FILE *F1 = fopen("ListaCompra.txt", "a+b");

    return 0;
}
int criarFicheiroProduto()
{
    FILE *F1 = fopen("Produtos.txt", "a+");

    return 0;
}
int criarFicheiroProdutoBin()
{
    FILE *F1 = fopen("Produtos.bin", "a+b");
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
    FILE *F1 = fopen("Categorias.bin", "a+b");

    return 0;
}
int criarFicheiroItensCabaz()
{
    FILE *F1 = fopen("ItensCabaz.txt", "a+");

    return 0;
}
int criarFicheiroItensCabazBin()
{
    FILE *F1 = fopen("ItensCabaz.bin", "a+b");
    return 0;
}
int criarFicheiroItensLista()
{
    FILE *F1 = fopen("ItensLista.txt", "a+");
    return 0;
}
int criarFicheiroItensListaBin()
{
    FILE *F1 = fopen("ItensLista.bin", "a+b");
    return 0;
}

//  FUNÇÕES AUXILIARES
//TODO: preco da lista

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
/*
int escreverAlfProdCat(int codigo){
    ITEMLISTA *item;
    CATEGORIA *cat;
    int i,j;
    for (i = 0; i < contarItensLista(codigo); i++)
    {
        if(item[i].produto.categoria==cat[j]){                      //percorrer todas as categorias, comparar,
                                                                    // se existe algum produto que coincida com a categoria, 
                                                                   //escreve a categoria e os alimentos por ordem alfabetica
        

            //codigo para printar produtos alfabeticamente
                    
        }
    }
    
    
    
}
*/
// FUNÇÕES DE ELIMINAR:



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
    FILE *F1 = fopen("Lista.txt", "a");
    lista.codigo = gerarCodigo();
    fprintf(F1, "%s;%d \n", lista.nome, lista.codigo);
    fclose(F1);

    return 0;
}

int criarCategoria(CATEGORIA categoria)
{
    FILE *f = fopen("Categorias.txt", "a");
    int erro = 0;

    categoria.codigo = gerarCodigo();

    fprintf(f, "%s;%d\n", categoria.nome, categoria.codigo);
    fclose(f);

    return 0;
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

// TODO: REFAZER DE MANEIRA MAIS SIMPLES IMBECIL
PRODUTO obterProdutoPorCodigo(int codigo)
{
    PRODUTO prod;

    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i;
    int count = 1;
    int temp = 0;
    FILE *f = fopen("Produtos.txt", "r");
    while (!feof(f))
    {
        STRING *V = splitLine(f, 5, &n_campos_lidos, ";\r\n");
        if(temp != codigo)
        {
        ++n_linhas_lidas;
        for (i = 0; i < n_campos_lidos; i++)
        {
                if (i + 1 == 1 )
            {
                strcpy(prod.nome, V[i]);
            }
            else if (i + 1 == 2)
            {
                strcpy(prod.categoria.nome, V[i]);
            }
            else if (i + 1 == 3)
            {
                int x = atoi(V[i]); // preco
                prod.preco = x;
            }
            else if (i + 1 == 4)
            {
                 
                 temp = atoi(V[i]);
                prod.codigo = temp;
            }
            
        }
        }
       
        for (i = 0; i < n_campos_lidos; i++)
        {
            free(V[i]);
        }
        free(V);
    }
    return prod;
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
int contarLista(LISTA *lista)
{
    int i = 0;
    do
    {
        i++;
    } while (lista[i].codigo != 0);

    return i;
}
int contarProdutosLista(LISTA *lista, int k)
{
    int j = 0;

    return j;
}
int contarItensLista(ITEMLISTA *item)
{
    int i = 0;
    do
    {
        i++;
    } while (item[i].codigo != 0);

    return i;
}

PRODUTO *listarProdutos()
{
    PRODUTO *prod = (PRODUTO *)malloc(65536 * sizeof(PRODUTO));
    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i;
    int count = 1;
    FILE *f = fopen("Produtos.txt", "r");

    while (!feof(f))
    {
        STRING *V = splitLine(f, 4, &n_campos_lidos, ";\r\n");
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
    prod = realloc(prod, (count - 1) * sizeof(prod));
    return prod;
}
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

    return cat;
}
LISTA *listarListas()
{

    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i;
    FILE *f = fopen("Lista.txt", "r");
    int count = 1;

    LISTA *lista = (LISTA *)malloc(65536 * sizeof(LISTA));
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
            // Verifica se na posicao i+1 == 1 Le os dados na primeira

            if (i + 1 == 1)
            {
                strcpy(lista[count - 1].nome, V[i]);
            }
            else if (i + 1 == 2)
            {
                lista[count - 1].codigo = atoi(V[i]);
            }
        }
        for (i = 0; i < n_campos_lidos; i++)
        {

            free(V[i]);
        }
        free(V);
        count++;
    }

    lista = realloc(lista, (count - 1) * sizeof(LISTA));

    return lista;
}
ITEMLISTA *listarItensLista()
{
    ITEMLISTA *item = (ITEMLISTA *)malloc(65536 * sizeof(ITEMLISTA));
    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i, t, r;
    int count = 1;
    FILE *f = fopen("ItensLista.txt", "r");

    while (!feof(f))
    {
        STRING *V = splitLine(f, 5, &n_campos_lidos, ";\r\n");
        ++n_linhas_lidas;
        for (i = 0; i < n_campos_lidos; i++)
        {
            if (i + 1 == 1)
            {
                int temp = atoi(V[i]);
                item[count - 1].codigo = temp; // codigo da lista
            }
            // FAZER UM FOR
            else if (i + 1 == 2)
            {

                strcpy(item[count - 1].produto.nome, V[i]); // nome do produto
            }
            else if (i + 1 == 3)
            {

                int temp = atoi(V[i]);
                item[count - 1].quantidade = temp; // quantidade do produto
            }
            else if (i + 1 == 4)
            {
                int temp = atoi(V[i]);
                item[count - 1].estado = temp; // estado do produto
            }
            else if (i + 1 == 5)
            {
                int temp = atoi(V[i]);
                item[count - 1].estado = temp; // codigo do produto
            }
        }
        // Desloca a mem�ria alocada em V[i]
        for (i = 0; i < n_campos_lidos; i++)
        {
            free(V[i]);
        }

        free(V);
        count++;
    }
    item = realloc(item, (count - 1) * sizeof(item));
    puts("erro");
    fclose(f);
    return item;
}
ITEMLISTA *listarItensListaPorCodigoLista(int codigo)
{
    ITEMLISTA *item = (ITEMLISTA *)malloc(65536 * sizeof(ITEMLISTA));
    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i, t, r;
    int tempCodigo = 0;
    int count = 1;
    FILE *f = fopen("ItensLista.txt", "r");

    while (!feof(f))
    {
        STRING *V = splitLine(f, 5, &n_campos_lidos, ";\r\n");
        ++n_linhas_lidas;
        for (i = 0; i < n_campos_lidos; i++)
        {
            if (i + 1 == 1)
            {
                tempCodigo = atoi(V[i]);
                if (tempCodigo != codigo)
                {
                    break;
                }
                item[count - 1].codigo = tempCodigo; // codigo da lista
            }
            // FAZER UM FOR
            else if (i + 1 == 2)
            {

                strcpy(item[count - 1].produto.nome, V[i]); // nome do produto
            }
            else if (i + 1 == 3)
            {

                int temp = atoi(V[i]);
                item[count - 1].quantidade = temp; // quantidade do produto
            }
            else if (i + 1 == 4)
            {
                int temp = atoi(V[i]);
                item[count - 1].estado = temp; // estado do produto
            }
            else if (i + 1 == 5)
            {
                int temp = atoi(V[i]);
                item[count - 1].estado = temp; // codigo do produto
            }
        }
        // Desloca a mem�ria alocada em V[i]
        for (i = 0; i < n_campos_lidos; i++)
        {
            free(V[i]);
        }
        free(V);
        if (tempCodigo == codigo)
                {
                    count++;
                }
        
    }
    item = realloc(item, (count - 1) * sizeof(item));
    puts("erro");
    fclose(f);
    return item;
}

void printCategorias(CATEGORIA *categoria)
{
    int i;
    printf("-----------------CATEGORIAS-----------------\n");
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
    printf("-----------------PRODUTOS-----------------\n");
    for (i = 0; i < contarProdutos(produto); i++)
    {
        printf("\n %d. ", i);
        printf("Nome:  %s \n", produto[i].nome);
        printf("Codigo: %d \n", produto[i].codigo);
        printf("Preço: %.2f EUR \n", produto[i].preco / 10.0);
        printf("Categoria: %s \n", produto[i].categoria.nome);
    }
}
void printListas(LISTA *lista)
{
    int i;
    printf("-----------------LISTAS-----------------\n");
    for (i = 0; i < contarLista(lista); i++)
    {
        printf("\n %d.", i + 1);
        printf("Nome:  %s ", lista[i].nome);
        printf("  Codigo: %d \n", lista[i].codigo);
    }
}


int calcularPrecoTotalLista(int codigo)
{   
    ITEMLISTA *item;
    LISTA *lista;
    item = listarItensListaPorCodigoLista(codigo);
    int preco = 0;
    int i;
    PRODUTO prod;
    
    for (i = 0; i < contarItensLista(item); i++)
    {
        prod = obterProdutoPorCodigo(item[i].codigo);
        printf("\n preco -> %d \n", prod.preco);
        preco += ( prod.preco * item[i].quantidade );
    }
    return preco;
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
void menuCriarLista()
{
    LISTA lista;
    printf("\n Nome da lista: ");
    scanf("%s", lista.nome);
    criarLista(lista);
}

// TODO: Arrumar parte opcao invalida
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

//TODO: arranjar eliminarProduto e menuEliminarProduto, fazer eliminar de Lista, Categoria e Item lista

int eliminarCategoria(int codigo)
{
    CATEGORIA *categoria;
    categoria = listarCategorias();
    int t = contarCategoria(categoria);
    int i;
    FILE *F = fopen("Categorias.txt", "w");
     fclose(F);
    for (i = 0; i < t; i++)
        if (categoria[i].codigo != codigo)
        {
             criarCategoria(categoria[i]);
        }
}


int eliminarProduto(int codigo)
{
    PRODUTO *produto;
    produto = listarProdutos();
    int t = contarProdutos(produto);
    int i;
    FILE *F = fopen("Produtos.txt", "w");
     fclose(F);
    for (i = 0; i < t; i++)
        if (produto[i].codigo != codigo)
        {
             criarProduto(produto[i]);
        }
    }

void menuAdicionarItemLista()
{

}

// TODO: AJUSTAR PARA SER NÃO O CODIGO N EXISTIR
void menuEliminarProduto()
{
    int codigo = 0;
    int i;
    int opcao = 0;
    int existe = 0;
    PRODUTO *produto = listarProdutos();
    printProdutos(produto);
    int num = contarProdutos(produto);

    printf("\n Escolha uma opcao. ");
    scanf("%d", &opcao);
    do
    {
        if(opcao > 0 && opcao <= num )
    {
        eliminarProduto(produto[opcao].codigo);
        existe = 1;
    }
    else
    {
        printf("\n Digite opcao valida: ");
        scanf("%d", &opcao);
    }
    } while (!existe);
   
    eliminarProduto(codigo);
}

void menuEliminarCategoria()
{
    int codigo = 0;
    int i;
    int opcao = 0;
    int existe = 0;
    CATEGORIA *categoria = listarCategorias();
    printCategorias(categoria);
    int num = contarCategoria(categoria);

    printf("\n Escolha uma opcao. ");
    scanf("%d", &opcao);
    do
    {
        if(opcao > 0 && opcao <= num )
    {
        eliminarCategoria(categoria[opcao].codigo);
        existe = 1;
    }
    else
    {
        printf("\n Digite opcao valida: ");
         scanf("%d", &opcao);
    }
    } while (!existe);
   
    eliminarCategoria(codigo);
}

void printItensLista(ITEMLISTA *item)
{
    printf("\n Itens Lista \n");

    int i;

    for (i = 0; i < contarItensLista(item)  ; i++)
    {
        if (item[i].codigo != 0)
        {
            printf(" \n Codigo lista: %d ", item[i].codigo);
            printf("\n Nome Produto: %s \n", item[i].produto.nome);
            // TODO: ADICIONAR O RESTO
        }
    }
}

// TODO: ACABAR DE FAZER MODO COMPRAS
int mostrarMenuPrincipal()
{
    int opcaoInvalida, opcao;

    do
    {
        system("cls");
        printf(" _________________________________________________________________________\n");
        printf("|                            MENU PRINCIPAL                               |\n");
        printf("|_________________________________________________________________________|\n");
        printf("\n\t1 - Area de Produtos \t\t Na primeira utilizacao, e necessario criar produtos \n");
        printf("\t2 - Area das listas \t\t\t     para utilizar a aplicacao!\n");
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
            system("exit");
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
            printProdutos(listarProdutos());
            while (getchar() != '\n') 
            continue;
            getchar();
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
            printListas(listarListas());
            while (getchar() != '\n') 
            continue;
            getchar();
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
            printCategorias(listarCategorias());
            while (getchar() != '\n') 
            continue;
            getchar();
            break;
        case 4:
            system("cls");
            // eliminarCategoria();
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
int mostrarMenuModoCompras() // ACABAR
{

    int numero;
    printListas(listarListas());
    printf("\n Insira o codigo da lista que deseja escolher: ");
    scanf("%d", &numero);
    printItensLista(listarItensLista(numero));
    sleep(2000);
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
    criarFicheiroItensLista();
}

// INICIALIZAÇÃO

// TODO: REMOVER TESTES. ADICIONAR SUPORTE A PORTUGUES
int main()
{
    setlocale(LC_ALL, "Portuguese");
    iniciarFicheiros();
    srand(time(NULL));
    int preco;
    menuEliminarProduto();
    
    menuCriarProduto();
   // mostrarMenuPrincipal();
   /*
    PRODUTO p = obterProdutoPorCodigo(802725);
    preco = calcularPrecoTotalLista(502914);
    printf(" \n preco total:  %d \n", preco);
    eliminarProduto(203100);
    */
    return 0;
}