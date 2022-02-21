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
    int codigoItem;
    int codigoProduto;
    int codigoLista;
} ITEMLISTA;

typedef struct lista
{
    ITEMLISTA item;
    char nome[40];
    int codigo;
} LISTA;


typedef struct itemCabaz
{
    int codigoCabaz;
    int codigoItem;
    int codigoProduto;
    int codigoLista;

} ITEMCABAZ;

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
    FILE *F1 = fopen("Lista.txt", "a+");

    return 0;
}
int criarFicheiroListaCompraBin()
{
    FILE *F1 = fopen("Lista.bin", "a+b");

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
int criarFicheiroCabaz()
{
    FILE *F1 = fopen("Cabaz.txt", "a+");
    return 0;
}
int criarFicheiroCabazBin()
{
    FILE *F1 = fopen("Cabaz.bin", "a+b");
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
//  FUNÇÕES AUXILIARES.
// TODO: preco da lista
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
/*
    Está função "supostamente" pega os dados que foram inseridos
    quanto a um produto, geralmente vindo de um menu e;
    1º VERIFICA SE OS DADOS ESTÃO CORRETOS, CASO NÃO A FUNÇÃO DEVOLVE 0 "ERRO"
    2º CASO ESTEJAM CORRETOS, TENTA COLOCAR NO FICHEIRO, CASO NÃO
    CONSIGA COLOCAR NO FICHEIRO, A FUNÇÃO DEVOLVE 0 "ERRO"
    - No milagre de tudo der certo, a função devolve 1, ou seja o produto foi
    criado com sucesso
*/
// TODO: REMOVER O CAMPO "QUANTIDADE DO PRODUTO"
// MELHORAR VALIDAÇÃO
// LIMPAR CÓDIGO
//FUNCOES CRIAR
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
int criarProdutoPorCodigo(PRODUTO produto, int codigo)// NAO USAR, a nao ser que saiba o que está fazendo
{
    FILE *f = fopen("Produtos.txt", "a");
    int erro = 0;
    produto.codigo = codigo;
    produto.preco = (produto.preco) > 0 ? produto.preco : -produto.preco;
    fprintf(f, "%s;%s;%d;%d\n", produto.nome, produto.categoria.nome, produto.preco,
            produto.codigo);

    fclose(f);

    return erro;
}
int criarCategoriaPorCodigo(CATEGORIA categoria, int codigo)
{
    FILE *f = fopen("Categorias.txt", "a");
    int erro = 0;
    categoria.codigo = codigo;
    fprintf(f, "%s;%d\n", categoria.nome, categoria.codigo);
    fclose(f);
    return erro;
}
int criarListaPorCodigo(LISTA lista, int codigo)
{
    FILE *f = fopen("Lista.txt", "a");
    int erro = 0;
    lista.codigo = codigo;
    fprintf(f, "%s;%d\n", lista.nome, lista.codigo);
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
//FUNCOES DE CONTAGEM
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
    } while (item[i].codigoItem != 0);

    return i;
}

int contarItensCabaz(ITEMCABAZ *item)
{
    int i = 0;
    do
    {
        i++;
    } while (item[i].codigoItem != 0);

    return i;
}
//FUNCOES AUXILIARES
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
        if (temp != codigo)
        {
            ++n_linhas_lidas;
            for (i = 0; i < n_campos_lidos; i++)
            {
                if (i + 1 == 1)
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
    fclose(f);

    return lista;
}
LISTA obterListaPorCodigo(int codigo)
{
    LISTA list;
    LISTA *listas;
    listas = listarListas();
    int i;
    int tam = contarLista(listas);

    for (i = 0; i < tam; i++)
    {
        if (listas[i].codigo == codigo)
        {
            list.codigo = listas[i].codigo;
            strcpy(list.nome, listas[i].nome);
        }
    }
    return list;
}

ITEMCABAZ * listarItensCabaz(int codigoLista)
{
    ITEMCABAZ *item = (ITEMCABAZ *) malloc(65536 * sizeof(ITEMCABAZ));
    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 1;
    int i, t, r;
    int holdCodigoItem = 0;
    int holdCodigoProduto = 0;
    int holdCodigoLista= 0;
    int count = 1;
    FILE *f = fopen("ItensCabaz.txt", "r");
    while (!feof(f))
    {
        STRING *V = splitLine(f, 3, &n_campos_lidos, ";\r\n");
        ++n_linhas_lidas;
        for (i = 0; i < n_campos_lidos; i++)
        {
            
            if (i + 1 == 1)
            {
                holdCodigoLista = atoi(V[i]);
                if (holdCodigoLista != codigoLista)
                {
                     count--;
                    break;
                }
               
                item[count - 1].codigoLista = holdCodigoLista;
            }
            else if (i + 1 == 2)
            {
                item[count -1].codigoProduto = atoi(V[i]);
                
            }
            else if (i + 1 == 3)
            {
               item[count - 1].codigoItem = atoi(V[i]);
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
    fclose(f);
    return item;
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
        STRING *V = splitLine(f, 6, &n_campos_lidos, ";\r\n");
        ++n_linhas_lidas;
        for (i = 0; i < n_campos_lidos; i++)
        {
            if (i + 1 == 1)
            {
                int temp = atoi(V[i]);
                item[count - 1].codigoLista = temp; // codigo da lista
            }
            // FAZER UM FOR
            else if (i + 1 == 2)
            {

                obterProdutoPorCodigo(item[count - 1].codigoProduto).nome;
                strcpy(obterProdutoPorCodigo(item[count - 1].codigoProduto).nome,
                       V[i]); // nome do produto
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
                item[count - 1].codigoProduto = temp; // codigo do produto
            }
            else if (i + 1 == 6)
            {
                int temp = atoi(V[i]); // codigo do item
                item[count - 1].codigoItem = temp;
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
                item[count - 1].codigoLista = tempCodigo; // codigo da lista
            }
            // FAZER UM FOR
            else if (i + 1 == 2)
            {
                strcpy(obterProdutoPorCodigo(item[count - 1].codigoProduto).nome,
                       V[i]); // nome do produto
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
                item[count - 1].codigoProduto = temp; // codigo do produto
            }
            else if (i + 1 == 6)
            {
                int temp = atoi(V[i]);
                item[count - 1].codigoItem = temp; // codigo item lista
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
    fclose(f);
    return item;
}
ITEMLISTA obterItemListaPorCodigo(int codigo)
{
    ITEMLISTA item;
    ITEMLISTA *itens;
    itens = listarItensLista();
    int i;
    int tam = contarItensLista(itens);

    for (i = 0; i < tam; i++)
    {
        if (itens[i].codigoItem == codigo)
        {
            item.codigoItem = codigo;
            item.estado = itens[i].estado;
            item.codigoLista = itens[i].codigoLista;
            item.codigoProduto = itens[i].codigoProduto;
            item.quantidade = itens[i].quantidade;
        }
    }
    return item;
}
ITEMLISTA * ordernarItensListaAlfabetico(ITEMLISTA *itens)
{
    int qtd = contarItensLista(itens);
    int i, j;
    ITEMLISTA * item = itens;
    ITEMLISTA temp;
  

    for (i = 0 ; i < qtd - 1 ; i++)
    {
        for (j = 0 ; j < qtd ; j++)
        {
              char nome1[50];
              char nome2[50];
            strcpy(nome1, obterProdutoPorCodigo(item[i].codigoProduto).nome);
            strcpy(nome2, obterProdutoPorCodigo(item[j].codigoProduto).nome);

            if(strcmp(nome1, nome2) > 0){
      temp=item[i];
      item[i]=item[j];
      item[j]=temp;
        }
    }

    return item;
}
}
// TODO: TERMINAR FUNÇÃO
//PRINT DE DADOS DOS FICHEIROS
int printItensLista(ITEMLISTA *item)
{
    int i, vazio = 0;
    printf("\n--------------Itens da Lista-------------- \n");
    if (item != NULL)
    {
        for (i = 0; i < contarItensLista(item); i++)
        {
            if (item[i].codigoItem != 0)
            {
                printf(" %d -", i + 1);
                printf(" Nome Produto: %s ",
                 obterProdutoPorCodigo(item[i].codigoProduto).nome);
                printf("\n     Codigo item: %d", item[i].codigoItem);
                printf(" Quantidade : %d ", item[i].quantidade);
                printf("\nPreco: %.2f EUR \n",
                 obterProdutoPorCodigo(item[i].codigoProduto).preco / 100.00 );

                if (item[i].estado)
                {
                    printf("    >________JA ADQUIRIDO\n\n");
                }
                else
                {
                    printf("    >________NAO ADQUIRIDO\n\n");
                }
                // TODO: ADICIONAR O RESTO
            }
        }
        printf("PRECO TOTAL LISTA: %.2f EUR", calcularPrecoTotalLista(item[0].codigoLista) / 100.00);
        printf("\n-------------------------------------------");
    }
    else
    {
        vazio = 1;
        printf("\n Lista Vazia! \n");
        printf("\n-------------------------------------------");
    }
    return vazio;
}
int printCategorias(CATEGORIA *categoria)
{
    int i;
    int vazio = 0;
    printf("-----------------CATEGORIAS-----------------\n");
    if (categoria[0].codigo != 0)
    {
        for (i = 0; i < contarCategoria(categoria); i++)
        {
    
            printf("\n %d.", i + 1);
            printf("Nome:  %s ", categoria[i].nome);
            printf("  Codigo: %d \n", categoria[i].codigo);
        }
        printf("\n--------------------------------------------\n");
    }
    else
    {
        vazio = 1;
        printf("\n SEM CATEGORIAS \n");
        printf("\n------------------------------------------");
    }
    return vazio;
}
int printProdutos(PRODUTO *produto)
{
    printf("-----------------PRODUTOS-----------------\n");
    int i;
    int vazio = 0;
    int count;
    if (produto[0].codigo != 0)
    {
        count = contarProdutos(produto);

        for (i = 0; i < contarProdutos(produto); i++)
        {
            printf("\n %d. ", i + 1);
            printf("Nome:  %s \n", produto[i].nome);
            printf("Codigo: %d \n", produto[i].codigo);
            printf("Preco: %.2f EUR \n", produto[i].preco / 100.0);
            printf("Categoria: %s \n", produto[i].categoria.nome);
        }
        printf("\n---------------------------------------");
    }
    else
    {
        vazio = 1;
        printf("\n Sem produtos! \n");
        printf("\n---------------------------------------");
    }
    return vazio;
}
int printListas(LISTA *lista)
{
    int i;
    int vazio = 0;
    int count = contarLista(lista);
    printf("-----------------LISTAS-----------------\n");
    if (lista[0].codigo != 0)
    {
         vazio = 0;
        for (i = 0; i < count; i++)
        {
            printf("\n %d.", i + 1);
            printf("Nome:  %s ", lista[i].nome);
            printf("  Codigo: %d \n", lista[i].codigo);
        }
        printf("\n------------------------------------------");
    }
    else
    {
        vazio = 1;
        printf("\n SEM LISTAS \n");
        printf("\n---------------------------------------");
    }
    return vazio;
}

void printItensCabaz(ITEMCABAZ *item)
{
    int i, vazio = 0;
    i = 0;
    printf("\n--------------Itens do Cabaz-------------- \n");
    if (item != NULL)
    {
      for( i = 0 ; i < contarItensCabaz(item) ; i++)
      {
                printf(" %d -", i + 1);
                printf(" Nome Produto: %s ", obterProdutoPorCodigo(item[i].codigoProduto).nome);
                // TODO: MOSTRAR CATEGORIA
                printf("\n  Codigo item: %d", item[i].codigoItem);
                 printf("\n-------------------------------------------\n");
                i++;
    }
    }
    else
    {
        vazio = 1;
        printf("\n Lista Vazia! \n");
        printf("\n-------------------------------------------");
    }
    return vazio;
}

void trocarItemDeLista(int codigoItem, int codigoListaDest)
{
    ITEMLISTA *item;
    ITEMLISTA destino = obterItemListaPorCodigo(codigoItem);
    item = listarItensLista(); // ARRUMAR ISSO
    int t = contarItensLista(item);
    int i;
    FILE *F = fopen("ItensLista.txt", "w");
    fclose(F);
    for (i = 0; i < t; i++)
        if (item[i].codigoItem != codigoItem)
        {

            criarItemLista(item[i]);
        }
        else
        {
            destino.codigoLista = codigoListaDest;
            criarItemLista(destino);
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
        prod = obterProdutoPorCodigo(item[i].codigoProduto);
        preco += (prod.preco * item[i].quantidade);
    }
    return preco;
}
int gerarFicheiroListaParaImprimir(int codigo)
{
    LISTA  lista;
    lista = obterListaPorCodigo(codigo);
    FILE *f = fopen("ListaParaImprimir.txt", "w");
    ITEMLISTA * itens;
    itens = listarItensListaPorCodigoLista(lista.codigo);

    char nomeProduto[50];
    char nomeCategoria[50];
    int codigoProduto;
    int codigoCategoria;
    int codigoItem;
    int quantidade;
    int sucesso = 0;
    float precoProduto = 0.0;
    float precoTotal = 0.0;

    if(itens != NULL)
    {
        PRODUTO prod;
    int i;
    int count = contarItensLista(itens);
   
        fprintf(f, " ---- %s ---\n", lista.nome);
    for ( i = 0 ; i < count ; i++ )
    {
       codigoProduto = itens[i].codigoProduto;
       codigoItem = itens[i].codigoItem;
       prod = obterProdutoPorCodigo(codigoProduto);
       codigoCategoria = 
        prod.categoria.codigo;
        quantidade = itens[i].quantidade;
        precoProduto = prod.preco;
        strcpy(nomeProduto, 
            prod.nome); // obtem nome produto do item
        strcpy(nomeCategoria,
        prod.categoria.nome); // obtem cateogira do produto do item
        fprintf(f, "%d - ", i+1);
        fprintf(f, "Nome Produto: %s \n", nomeProduto);
        fprintf(f, "Quantidade: %d \n", quantidade);
        fprintf(f, "Preco: %.2f EUR \n", precoProduto / 100.0);
        fprintf(f, " --------------- \n");
        sucesso = 1;
    }
    }
    else
    {
        sucesso = 0;
    }
    
    
    fclose(f);
    return sucesso;
}
// MENUS E CRIACAO
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
void menuCriarProduto()
{
    PRODUTO produto;
    CATEGORIA *categoria = listarCategorias();
    categoria = listarCategorias();
    int qtdCategorias = contarCategoria(categoria);
    int erro = 0;
    float precoFloat;
    int nCategoria = 0;

    printf("\nNome Produto:");
    scanf("%s", &produto.nome);

    printf("\nPreco: ");
    scanf("%f", &precoFloat);
    produto.preco = (int)(precoFloat * 100.00);

    system("cls");
    printCategorias(categoria);
    printf("\nEscolha uma opcao (0 para criar  nova categoria): "); // SE A OPÇÃO 0 FOR ESCOLHIDA, PEDIRÁ PARA CRIAR
    Sleep(500);
    while (getchar() != '\n') // ARRUMA O BUG DO scanf()
        continue;
    scanf("%d", &nCategoria); // UMA NOVA CATEGORIA CASO O USUÁRIO DECIDA
    // TODO: AJUSTAR
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
        Sleep(5000);
    }
}

// TODO: Melhorar



int criarItemCabaz(ITEMCABAZ item)
{
    ITEMCABAZ * lista;
    lista = listarItensCabaz(item.codigoLista);
    int sucesso = 1;
    int i = 0;

   for( i = 0; i < contarItensCabaz(lista) ; i++)
    {
        if(lista[i].codigoProduto == item.codigoProduto)
        {
            sucesso = 0;
            break;
        }
        i++;
    }
    if(sucesso)
    {
    FILE *F = fopen("ItensCabaz.txt", "a");
    item.codigoItem = gerarCodigo();
    fprintf(F, "%d;%d;%d\n", item.codigoLista, item.codigoProduto, item.codigoItem);
    fclose(F);
    }
    return sucesso;
}


void criarItemListaPorCodigo(ITEMLISTA item, int codigo)
{
    int i;
    char *nomeProduto = (char *)malloc(100 * sizeof(char));
    strcpy(nomeProduto, obterProdutoPorCodigo(item.codigoProduto).nome);
    // printf("\n nome: %s \n", obterProdutoPorCodigo(item.produto.codigo).nome);
    item.codigoLista = codigo;
    item.codigoItem = gerarCodigo();
    FILE *F = fopen("ItensLista.txt", "a");

    fprintf(F, "%d;%s;%d;%d;%d;%d\n",
            item.codigoLista, nomeProduto, item.quantidade,
            item.estado, item.codigoProduto, item.codigoItem);
    free(nomeProduto);
    fclose(F);
    return 0;
}
int criarItemLista(ITEMLISTA item)
{
    int i;
    char *nomeProduto = (char *)malloc(100 * sizeof(char));
    nomeProduto = obterProdutoPorCodigo(item.codigoProduto).nome;

    FILE *F = fopen("ItensLista.txt", "a");
   
    fprintf(F, "%d;%s;%d;%d;%d;%d\n",
            item.codigoLista, nomeProduto, item.quantidade,
            item.estado, item.codigoProduto, item.codigoItem);
    free(nomeProduto);
    fclose(F);
    return 0;
}
// TODO: Arrumar parte opcao invalida, caso produto ja exista em alguma lista
// TODO: arranjar eliminarProduto e menuEliminarProduto, fazer eliminar de Lista, Categoria e Item lista
// TODO: ARRUMAR DPS ESSA FUNCAO
//MENUS E EDICAO
int editarProdutos(int codigo, PRODUTO novoProduto)
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
        else
        {
            criarProdutoPorCodigo(novoProduto, codigo);
        }
}
void editarItemLista(int codigoItem, ITEMLISTA novoItem)
{
    ITEMLISTA *item;
    item = listarItensLista(); // ARRUMAR ISSO
    int t = contarItensLista(item);
    int i;
    FILE *F = fopen("ItensLista.txt", "w");
    fclose(F);
    for (i = 0; i < t; i++)
        if (item[i].codigoItem != codigoItem)
        {

            criarItemLista(item[i]);
        }
        else
        {
            criarItemLista(novoItem);
        }
}
void editarCategoria(int codigo, CATEGORIA novaCategoria)
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
             criarCategoriaPorCodigo(categoria[i], categoria[i].codigo);
        }
        else
        {
            criarCategoriaPorCodigo(novaCategoria, novaCategoria.codigo);
        }
}
void editarLista(int codigo, LISTA novaLista)
{
    LISTA *lista;
    lista = listarListas();
    int t = contarLista(lista);
    int i;
    FILE *F = fopen("Lista.txt", "w");
     fclose(F);
    for (i = 0; i < t; i++)
        if (lista[i].codigo != codigo)
        {
             criarListaPorCodigo(lista[i], lista[i].codigo);
        }
        else
        {
            criarListaPorCodigo(novaLista, novaLista.codigo);
        }
}
void editarProduto(int codigo, PRODUTO novoProduto)  //TODO: Adicionar PedirPreco de novo
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
             criarProdutoPorCodigo(produto[i], produto[i].codigo);
        }
        else
        {
            criarProdutoPorCodigo(novoProduto, novoProduto.codigo);
        }
}
int menuEditarLista (){
    int escolha;
    char nome[50];
    LISTA lista;
    LISTA *lis = listarListas();
    printListas(lis);
    
    printf("Insira a opcao que deseja escolher: \n");
    scanf("%d", &escolha);
    printf("Insira o nome que deseja mudar: \n");
    scanf("%s", nome);
    strcpy(lis[escolha - 1].nome, nome);
    editarLista(lis[escolha - 1].codigo, lis[escolha - 1]);
    
}
int menuEditarProduto(){
    int escolha;
    char nome[50];
    float precoRead = 0.0;
    PRODUTO produto;
    PRODUTO *prod = listarProdutos();
    printProdutos(prod);
    // TODO: AJUSTAR CASO OPCAO NAO EXISTA
    
    printf("\n Insira a opcao que deseja escolher: ");
    scanf("%d", &escolha);
    printf(" Insira o nome que deseja mudar: \n");
    scanf("%s", nome);
    printf(" Insira um novo preco: \n");
    scanf("%f", &precoRead);
    prod[escolha - 1 ].preco = (int) ( precoRead * 100 );
    strcpy(prod[escolha - 1].nome, nome);
    editarProduto(prod[escolha - 1].codigo, prod[escolha - 1]);
    
}
int menuEditarCategoria()
{
    int escolha;
    char nome[50];
    CATEGORIA categoria;
    CATEGORIA *cat = listarCategorias();
    printCategorias(cat);
    printf("Insira a opcao que deseja escolher: ");
    scanf("%d", &escolha);
    printf("Insira o nome que deseja mudar: ");
    scanf("%s", nome);
    strcpy(cat[escolha - 1].nome, nome);
    editarCategoria(cat[escolha - 1].codigo, cat[escolha - 1]);
}
//FUNCOES AUXILIARES
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
int mudarEstadoItem(int codigo, int estado)
{
    ITEMLISTA item;
    item = obterItemListaPorCodigo(codigo);
    printf(" \n CODIGO: %d \n", item.codigoItem);
    item.estado = estado;
    editarItemLista(codigo, item);
}
int menuMudarEstadoItem(int codigoLista)
{
    ITEMLISTA * itens;
    ITEMCABAZ cabaz;
    itens = listarItensListaPorCodigoLista(codigoLista);
    int opcao = 1;
    int valido = 0;
    int count = contarItensLista(itens);
    printItensLista(itens);
    do
    {
        printf("\n Escolha um item: ");
        scanf("%d",&opcao);
        opcao--;
        if( opcao < 0 && opcao >= count)
        {
            printf("\n Opcao invalida");
            valido = 0;
        }
    } while (valido);

    // adiciona o item ao cabaz
    cabaz.codigoProduto = itens[opcao].codigoProduto;
    cabaz.codigoLista = itens[opcao].codigoLista;
    

    if(criarItemCabaz(cabaz))
    {
     printf("\n Item Adicionado ao Cabaz");
    }
    else
    {
        printf("\n Item nao adicionado ao cabaz, pois ja existe no mesmo");
    }
      while (getchar() != '\n')
                continue;
        getchar();

    mudarEstadoItem(itens[opcao].codigoItem, 1);
}
void menuTrocarItemDeLista(int codigoLista)
{
    int opcao = 0;
    int opcao2 = 0;

    ITEMLISTA * item;
    item = listarItensListaPorCodigoLista(codigoLista);
    int valido = 0;
    int valido2 = 0;
    int count = 0;
    int count2 = 0;
    printItensLista(item);
    count = contarItensLista(item);

    LISTA * listas;
    listas = listarListas();
    count2 = contarLista(listas);

    printf(" \n Escolha um item: ");
    scanf("%d", &opcao);
    opcao--;
    do
    {
       if (opcao >= 0 && opcao < count)
       {
         valido = 1;
        printListas(listas);
        printf("\n---------------------------------------");
        printf("\n Escolha lista deseja colocar: ");
        scanf("%d", &opcao2);
        opcao2--;
        do
        {
             if (opcao2 >= 0 && opcao < count)
             {
                 valido2= 1;
                 trocarItemDeLista(item[opcao].codigoItem, listas[opcao2].codigo);
             }
        
        } while (!valido2);
       }
    } while (!valido);
}
int verificarSeProdutoEstaNasListas(int codigoProduto)
{
    int existeListas = 0;
    int i;
    int count = 0;
    ITEMLISTA * itens;
    itens = listarItensLista();
    count = contarItensLista(itens);

    for(i = 0 ; i < count ; i++)
    {
        if(itens[i].codigoProduto == codigoProduto)
        {
            existeListas = 1;
            break;
        }
    }


    return existeListas;
}
void menuAdicionarItemLista(int codigoLista)
{
    int i;
    int escolha = 0;
    int valido = 1;
    int num;
    int qtd = 0;
    ITEMLISTA item;
    PRODUTO *produtos;
    PRODUTO produto;
    produtos = listarProdutos();
    num = contarProdutos(produtos);
    printf(" \n  qtd produtos %d \n", num);

    printProdutos(produtos);
    printf("\n Escolha uma opcao (0 caso deseja criar novo produto): \n ");
    scanf("%d", &escolha);
    escolha--;
    do
    {
        if (escolha < 0)
        {
            menuCriarProduto();
            produtos = listarProdutos();
            escolha = contarProdutos(produtos) - 1;
            num++;
        }
        if (escolha >= 0 && escolha < num)
        {
            printf("\n Quantidade: ");
            scanf("%d", &qtd);
            item.quantidade = qtd;
            item.codigoProduto = produtos[escolha].codigo;
            item.estado = 0;
            item.codigoLista = codigoLista;
            // strcpy(,produtos[escolha].nome );
            valido = 1;
            criarItemListaPorCodigo(item, codigoLista);
        }
        else
        {
            printf("\n Digite opcao valida: ");
            scanf("%d", &escolha);
            escolha--;
        }
    } while (!valido);
}
// AJUSTAR
// TODO: TIRAR COMENTARIO TIRAR ITEM LISTA, LOGICA CASO ADICONAR QTD A PRODUTO EXISTNETE
//MENUS E ELIMINACAO
void menuEliminarLista()
{
    int codigo = 0;
    int i;
    int opcao = 0;
    int existe = 0;
    LISTA *lista = listarListas();
    printListas(lista);
    int num = contarLista(lista);

    printf("\n Escolha uma opcao: ");
    scanf("%d", &opcao);
    opcao--;
    do
    {
        if (opcao >= 0 && opcao <= num)
        {
            eliminarLista(lista[opcao].codigo);
            existe = 1;
        }
        else
        {
            printf("\n Digite opcao valida: ");
            scanf("%d", &opcao);
            opcao--;
        }
    } while (!existe);

    eliminarLista(codigo);
}
void menuEliminarProduto()
{
    int codigo = 0;
    int i;
    int opcao = 0;
    int existe = 0;
    PRODUTO *produto = listarProdutos();
    printProdutos(produto);
    int num = contarProdutos(produto);

    printf("\n Escolha uma opcao: ");
    scanf("%d", &opcao);
    opcao--;
    do
    {
        if (opcao >= 0 && opcao < num)
        {
            eliminarProduto(produto[opcao].codigo);
            existe = 1;
        }
        else
        {
            printf("\n Digite opcao valida: ");
            scanf("%d", &opcao);
            opcao--;
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

    printf("\n Escolha uma opcao: ");
    scanf("%d", &opcao);
    opcao--;
    do
    {
        if (opcao >= 0 && opcao < num)
        {
            eliminarCategoria(categoria[opcao].codigo);
            existe = 1;
        }
        else
        {
            printf("\n Digite opcao valida: ");
            scanf("%d", &opcao);
            opcao--;
        }
    } while (!existe);
}
void menuEliminarItensListaPorCodigo(int codigo)
{
    int i;
    int opcao = 0;
    int existe = 0;
    ITEMLISTA *item = listarItensListaPorCodigoLista(codigo);
    printItensLista(item);
    int num = contarItensLista(item);
    printf("\n---------------------------------------");
    printf("\n Escolha uma opcao: ");
    scanf("%d", &opcao);
    opcao--;
    do
    {
        if (opcao >= 0 && opcao < num)
        {
            eliminarItemLista(item[opcao].codigoItem);
            existe = 1;
        }
        else
        {
            printf("\n Digite opcao valida: ");
            scanf("%d", &opcao);
            opcao--;
        }
    } while (!existe);

    //eliminarItemLista(codigo);
}
void menuEliminarItensLista()
{
    int codigo = 0;
    int i;
    int opcao = 0;
    int existe = 0;
    ITEMLISTA *item = listarItensLista();
    printItensLista(item);
    int num = contarItensLista(item);

    printf("\n Escolha uma opcao: ");
    scanf("%d", &opcao);
    opcao--;
    do
    {
        if (opcao >= 0 && opcao < num)
        {
            eliminarItemLista(item[opcao].codigoLista);
            existe = 1;
        }
        else
        {
            printf("\n Digite opcao valida: ");
            scanf("%d", &opcao);
            opcao--;
        }
    } while (!existe);

    eliminarItemLista(codigo);
}
int eliminarItemLista(int codigoItem)
{
    ITEMLISTA *item;
    item = listarItensLista();
    int t = contarItensLista(item);
    int i;
    FILE *F = fopen("ItensLista.txt", "w");
    fclose(F);
    for (i = 0; i < t; i++)
        if (item[i].codigoItem != codigoItem)
        {
            criarItemLista(item[i]);
        }
}
int eliminarProduto(int codigo)
{
    PRODUTO *produto;
    produto = listarProdutos();
    int erro = 0;
     int i;
    int t;
    if(!verificarSeProdutoEstaNasListas(codigo))
    {
         t =  contarProdutos(produto);

    FILE *F = fopen("Produtos.txt", "w");
    fclose(F);
    for (i = 0; i < t; i++)
        if (produto[i].codigo != codigo)
        {
            criarProdutoPorCodigo(produto[i], produto[i].codigo);
        }
    }
    else
    {
        erro = 1;
    }
   

        return erro;
}
int eliminarLista(int codigo)
{
    LISTA *lista;
    lista = listarListas();
    int t = contarLista(lista);
    int i;
    FILE *F = fopen("Lista.txt", "w");
    fclose(F);
    for (i = 0; i < t; i++)
        if (lista[i].codigo != codigo)
        {
            criarListaPorCodigo(lista[i], lista[i].codigo);
        }
}
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
            criarCategoriaPorCodigo(categoria[i], categoria[i].codigo);
        }
}
void eliminarTodosCompradosLista(int codigoLista)
{
    int i;
    int count = 0;
    int comprado = 0;
    ITEMLISTA * itens;
    ITEMLISTA item;
    itens = listarItensListaPorCodigoLista(codigoLista);
    count = contarItensLista(itens);
   
    for ( i = 0 ; i < count ; i++)
    {
        comprado = itens[i].estado;
        if ( comprado != 0)
        {
            eliminarItemLista(itens[i].codigoItem);
        }
    }

}
//FUNCOES MENU
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
            guardarFicheirosBin();
            printf("\n\n\n\t\tObrigado por usar a nossa aplicao!");
            Sleep(2500);
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
    int vazio = printProdutos(listarProdutos());

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
            menuEditarProduto();
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
            if( vazio == 0 ){
            menuEliminarProduto();
            }
            else {
                printf("\n\n        NAO EXISTEM DADOS!");
                while (getchar() != '\n')
                continue;
            getchar();
            }
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
    int vazio = printListas(listarListas());
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
            menuEditarLista();
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
            if(vazio == 0)
            {
            menuEliminarLista();
            }
            else 
            {
                printf("\n\n        NAO EXISTEM DADOS!");
                while (getchar() != '\n')
                continue;
            getchar();
            }
            break;
        case 5:
            system("cls");
            // transferirProduto(); TODO: FAZER
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
    int opcao, vazio=printCategorias(listarCategorias());
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
            menuEditarCategoria();
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
            if(vazio == 0){
            menuEliminarCategoria();
            }
            else {
                printf("\n\n        NAO EXISTEM DADOS!");
                while (getchar() != '\n')
                continue;
            getchar();
            }
            break;
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
int mostrarMenuModoCompras() //TODO: ACABAR
{

    int escolha = 0;
    int escolha2 = 0;
    int sair = 0;
    int codigo = 0;
    int vazio = 0;
    LISTA *lista;
    lista = listarListas();
    printListas(lista);
    printf("\n Insira uma opcao (0 para criar nova lista): ");
    scanf("%d", &escolha);
    escolha--;
    if (escolha < 0)
    {
        system("cls");                       
        menuCriarLista();
        lista = listarListas();
        codigo = lista[contarLista(lista) - 1].codigo;
        system("cls");
    }
    else
    {
        system("cls");
        codigo = lista[escolha].codigo;
    }
    printf("   \n Lista codigo: %d  \n", codigo);
    // TODO: Fazer resto
   
    do
    {
        system("cls");
         printItensLista(listarItensListaPorCodigoLista(codigo));

        printf("\n\n O que deseja fazer? ");
        printf("\n 1 - Adicionar item a lista ");
        printf("\n 2 - Retirar item da lista ");
        printf("\n 3 - Marcar item como comprado ");
        printf("\n 4 - Apagar todos itens comprados");
        printf("\n 5 - Trocar item de lista");
        printf("\n 6 - Exportar lista em .txt");
        printf("\n 7 - Ver Cabaz");
        printf("\n 8 - Voltar \n");
        printf("\n Insira uma opcao: ");
        scanf("%d", &escolha2);

        switch (escolha2)
        {
        case 1:
        system("cls");
            menuAdicionarItemLista(codigo);
            break;
        case 2:
        system("cls");
            vazio = printItensLista(listarItensListaPorCodigoLista(codigo));
            if(vazio == 0){
            menuEliminarItensListaPorCodigo(codigo);
            }
            else {
                system("cls");
                printf("\n\n        NAO EXISTEM DADOS!");
                while (getchar() != '\n')
                continue;
            getchar();
            system("cls");
            }
            break;
        case 3:  
        system("cls");
            menuMudarEstadoItem(codigo);
            break;
        case 4: 
        system("cls");
            eliminarTodosCompradosLista(codigo);
             break;
        case 5: 
        system("cls");
            menuTrocarItemDeLista(codigo);
            break;
        case 6: 
            if(gerarFicheiroListaParaImprimir(codigo))
            {
                 printf("FICHEIRO CRIADO COM SUCESSO!!!");
            printf("\n Verifique o ficheiro ListaParaImprimir.txt \n");
            while (getchar() != '\n')
                continue;
                getchar();
            }
            else
            {
                printf("Lista vazia, ficheiro nao criado");
                  while (getchar() != '\n')
                continue;
                getchar();
            }
           
            system("cls");
            break;
        case 7:
        printItensCabaz(listarItensCabaz(codigo));
         while (getchar() != '\n')
                continue;
                getchar();
            break;
        case 8:
            system("cls");
            mostrarMenuPrincipal();
            break;
        default:
            printf("\n Opcao invalida!!!");
        }
    } while (!sair);

    return 0;
}
//FUNCOES DE INICIALIZAÇÃO E FINALIZAÇÃO
void iniciarFicheiros()
{
    criarFicheiroProduto();
    criarFicheiroCategorias();
    criarFicheiroListaCompra();
    criarFicheiroCategoriasBin();
    criarFicheiroItensCabaz();
    criarFicheiroItensLista();
    criarFicheiroCabaz();
}
void guardarFicheirosBin()
{
    mudarTXTparaBin("Produtos.txt", "Produtos.bin");
    mudarTXTparaBin("Categorias.txt", "Categorias.bin");
    mudarTXTparaBin("Lista.txt", "Lista.bin");
    mudarTXTparaBin("ItensLista.txt", "ItensLista.bin");
}
int mudarTXTparaBin(char *src, char *tgt)
{
    int num;
    FILE *f1, *f2;
    char ch;

    /* open the source file in read mode */
    f1 = fopen(src, "r");
    /* open the target file in binary write mode */
    f2 = fopen(tgt, "wb");
    /*
     * read data from input file and write
     * the binary form of it in output file
     */
    while (!feof(f1))
    {
        /* reading one byte of data */
        fread(&ch, sizeof(char), 1, f1);
        /* converting the character to ascii integer value */
        num = ch;
        /* writing 4 byte of data to the output file */
        fwrite(&num, sizeof(int), 1, f2);
    }

    /* close all opened files */
    fclose(f1);
    fclose(f2);
    return 0;
}
//FUNCAO PRINCIPAL
int main()
{
    setlocale(LC_ALL, "Portuguese");
    iniciarFicheiros();
    srand(time(NULL));
    mostrarMenuPrincipal();
    return 0;
}