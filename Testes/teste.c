#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "TainanSuzarte-20212160033-T2.h"

vetorAuxiliar *vetorPrincipal[TAM];




/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    if (posicao<1 || posicao>10)
        return POSICAO_INVALIDA;

    if (tamanho < 1)
    {
        return TAMANHO_INVALIDO;
    }

    if (vetorPrincipal[posicao - 1] != NULL)
    {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        vetorPrincipal[posicao - 1] = (vetorAuxiliar
         *)malloc(sizeof(vetorAuxiliar
         ));

        if (vetorPrincipal[posicao - 1] == NULL)
        {
            return SEM_ESPACO_DE_MEMORIA;
        }
        else
        {
            vetorPrincipal[posicao - 1]->tamanho = tamanho;
            vetorPrincipal[posicao - 1]->espaco = tamanho;
            vetorPrincipal[posicao - 1]->prox = NULL;
            return SUCESSO;
        }
    }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if (posicao<1 || posicao>10)
        return POSICAO_INVALIDA;

    vetorAuxiliar
 *vetorSecundario = vetorPrincipal[posicao - 1];
    vetorAuxiliar
 *novo = (vetorAuxiliar
 *)malloc(sizeof(vetorAuxiliar
 ));

    if (vetorSecundario == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        if (vetorSecundario->espaco > 0)
        {
            novo->tamanho = vetorSecundario->tamanho;
            novo->valor = valor;
            novo->espaco = vetorSecundario->espaco;
            novo->prox = NULL;

            if (vetorSecundario->espaco == vetorSecundario->tamanho)
            {
                *vetorSecundario = *novo;
                vetorSecundario->espaco--;

                if (vetorSecundario->valor == valor)
                    return SUCESSO;
            }
            else
            {
                vetorSecundario->espaco--;
                while (vetorSecundario->prox != NULL)
                {
                    vetorSecundario = vetorSecundario->prox;
                }

                vetorSecundario->prox = novo;

                if (vetorSecundario->prox->valor == valor)
                    return SUCESSO;
            }
        }
        else
        {
            return SEM_ESPACO;
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if (posicao<1 || posicao>10)
        return POSICAO_INVALIDA;

    vetorAuxiliar
 *vetorSecundario = vetorPrincipal[posicao - 1];
    vetorAuxiliar
 *anterior = vetorPrincipal[posicao - 1];

    if (vetorSecundario == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        if (vetorSecundario->espaco < vetorSecundario->tamanho)
        {
            while (vetorSecundario->prox != NULL)
            {

                anterior = vetorSecundario;
                vetorSecundario = vetorSecundario->prox;
            }

            vetorPrincipal[posicao - 1]->espaco++;
            return SUCESSO;
        }
        else
        {
            return ESTRUTURA_AUXILIAR_VAZIA;
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if (posicao<1 || posicao>10)
        return POSICAO_INVALIDA;

    vetorAuxiliar
 *vetorSecundario = vetorPrincipal[posicao - 1];
    vetorAuxiliar
 *anterior = vetorPrincipal[posicao - 1];

    if (vetorSecundario == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        if (vetorSecundario->espaco < vetorSecundario->tamanho)
        {

            while (vetorSecundario->prox != NULL)
            {
                if (vetorSecundario->valor == valor)
                {
                    vetorPrincipal[posicao - 1]->espaco++;
                    vetorSecundario->valor = vetorSecundario->prox->valor;
                    return SUCESSO;
                }
                anterior = vetorSecundario;
                vetorSecundario = vetorSecundario->prox;
            }
            return NUMERO_INEXISTENTE;
        }
        else
        {
            return ESTRUTURA_AUXILIAR_VAZIA;
        }
    }
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if (posicao<1 || posicao>10)
        return POSICAO_INVALIDA;

    vetorAuxiliar
 *first = vetorPrincipal[posicao - 1];
    vetorAuxiliar
 *vetorSecundario = vetorPrincipal[posicao - 1];

    if (vetorSecundario == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else
    {
        for (int i = 0; i < (first->tamanho - first->espaco); i++)
        {
            vetorAux[i] = vetorSecundario->valor;
            vetorSecundario = vetorSecundario->prox;
        }
        return SUCESSO;
    }
}

void substituir(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int inseridosVet = 0;

    if (posicao<1 || posicao>10)
        return POSICAO_INVALIDA;

    vetorAuxiliar
 *first = vetorPrincipal[posicao - 1];
    vetorAuxiliar
 *vetorSecundario = vetorPrincipal[posicao - 1];

    if (vetorSecundario == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else
    {
        for (int i = 0; i < (first->tamanho - first->espaco); i++)
        {
            vetorAux[i] = vetorSecundario->valor;
            vetorSecundario = vetorSecundario->prox;
            inseridosVet++;
        }

        for (int i = 0; i < inseridosVet - 1; i++)
            for (int j = 0; j < inseridosVet - i - 1; j++)
                if (vetorAux[j] > vetorAux[j + 1])
                    substituir(&vetorAux[j], &vetorAux[j + 1]);

        return SUCESSO;
    }
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    vetorAuxiliar
 *vetorSecundario;
    vetorAuxiliar
 *first;
    int j = 0;

    for (int i = 0; i < 10; i++)
    {
        first = vetorPrincipal[i];
        vetorSecundario = vetorPrincipal[i];

        if (vetorSecundario == NULL || vetorSecundario->espaco == vetorSecundario->tamanho)
        {
            continue;
        }
        else
            for (int k = 0; k < (first->tamanho - first->espaco); k++)
            {
                vetorAux[j] = vetorSecundario->valor;
                vetorSecundario = vetorSecundario->prox;
                j++;
            }
    }

    if (j == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    vetorAuxiliar
 *vetorSecundario;
    vetorAuxiliar
 *first;
    int valor;
    int inseridosVet = 0;

    for (int i = 0; i < 10; i++)
    {
        first = vetorPrincipal[i];
        vetorSecundario = vetorPrincipal[i];

        if (vetorSecundario == NULL || vetorSecundario->espaco == vetorSecundario->tamanho)
        {
            continue;
        }
        else
        {
            for (int k = 0; k < (first->tamanho - first->espaco); k++)
            {
                vetorAux[inseridosVet] = vetorSecundario->valor;
                vetorSecundario = vetorSecundario->prox;
                inseridosVet++;
            }
        }
    }
    for (int i = 0; i < inseridosVet - 1; i++)
        for (int j = 0; j < inseridosVet - i - 1; j++)
            if (vetorAux[j] > vetorAux[j + 1])
                substituir(&vetorAux[j], &vetorAux[j + 1]);

    if (inseridosVet == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
    {

        return SUCESSO;
    }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    vetorAuxiliar
 *vetorSecundario = vetorPrincipal[posicao - 1];

    if (posicao<1 || posicao>10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorSecundario == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        if (novoTamanho + vetorSecundario->tamanho < 1)
            return NOVO_TAMANHO_INVALIDO;

        vetorSecundario->tamanho += novoTamanho;
        if (novoTamanho > 0)
            vetorSecundario->espaco += novoTamanho;
        return SUCESSO;
    }
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    vetorAuxiliar
 *first = vetorPrincipal[posicao - 1];
    vetorAuxiliar
 *vetorSecundario = vetorPrincipal[posicao - 1];
    int qtd = 0;

    if (posicao<1 || posicao>10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorSecundario == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {

        if (vetorSecundario->espaco < vetorSecundario->tamanho)
        {
            for (int i = 0; i < (first->tamanho - first->espaco); i++)
            {
                qtd++;
                vetorSecundario = vetorSecundario->prox;
            }

            return qtd;
        }
        else
        {
            return ESTRUTURA_AUXILIAR_VAZIA;
        }
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    No *inicioListaCabecote = (No *)malloc(sizeof(No));
    inicioListaCabecote->prox = (No *)malloc(sizeof(No));

    vetorAuxiliar
 *vetorSecundario;
    vetorAuxiliar
 *first;
    int j = 0;

    for (int i = 0; i < 10; i++)
    {
        first = vetorPrincipal[i];
        vetorSecundario = vetorPrincipal[i];

        if (vetorSecundario == NULL || vetorSecundario->espaco == vetorSecundario->tamanho)
        {
            continue;
        }
        else
            for (int k = 0; k < (first->tamanho - first->espaco); k++)
            {
                vetorSecundario = vetorSecundario->prox;
                j++;
            }
    }

    if (j == 0)
        return NULL;
    else
        return inicioListaCabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *vetorSecundario = inicio;
    No *first = inicio;

    for (int i = 0; i < first->tamanho; i++)
    {
        vetorSecundario = vetorSecundario->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *vetorSecundario = *inicio;
    No *temp;
    while (vetorSecundario->prox != NULL)
    {
        temp = vetorSecundario->prox;
        free(vetorSecundario);
        vetorSecundario = temp;
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/

void inicializar()
{
    for (int i = 0; i < TAM; i++)
        vetorPrincipal[i] = NULL;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
    for (int i = 0; i < TAM; i++)
    {
        vetorAuxiliar
     *vetorSecundario = vetorPrincipal[i];
        vetorAuxiliar
     *temp;

        if (vetorSecundario == NULL)
        {
            free(vetorSecundario);
            continue;
        }

        while (vetorSecundario->prox != NULL)
        {
            temp = vetorSecundario->prox;
            free(vetorSecundario);
            vetorSecundario = temp;
        }
        free(vetorSecundario);
    }
}