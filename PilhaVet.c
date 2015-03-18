#include<stdlib.h>
#include<stdio.h>
#include "PilhaVet.h"

PilhaVet* criarPilha() {
    PilhaVet* pilha = (PilhaVet*) malloc(sizeof(PilhaVet));
    if (pilha == NULL) return NULL;
    pilha->topo = 0;
    return pilha;
}

int liberarPilha(PilhaVet* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    free(pilha);
    pilha = NULL;
}

int estahCheia(PilhaVet* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (pilha->topo == TAM_MAX) return TRUE;
    return FALSE;
}

int estahVazia(PilhaVet* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (pilha->topo == 0) return TRUE;
    return FALSE;
}

int empilhar(int item, PilhaVet* pilha) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahCheia(pilha))
        return ESTRUTURA_CHEIA;

    pilha->itens[pilha->topo] = item;
    pilha->topo++;
    return OK;
}

int desempilhar(PilhaVet* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    *item = pilha->itens[pilha->topo - 1];
    pilha->topo--;
    return OK;
}

int obterTopo(PilhaVet* pilha, int* item) {
    if (pilha == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(pilha))
        return ESTRUTURA_VAZIA;
    *item = pilha->itens[pilha->topo - 1];
    return OK;
}
