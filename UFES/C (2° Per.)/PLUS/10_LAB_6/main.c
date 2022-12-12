#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct criatura
{
  const char* nome;
  const char* especie;
  const int idade;
};

struct criatura muppets[] =
  {
    {"Kermit", "sapo", 3},
    {"Piggy", "porco", 5},
    {"Gonzo", "Vaisaber", 1},
    {"Fozzie", "urso", 0},
    {"Sam", "aguia", 9},
    {"Robin", "sapo", 1},
    {"Animal", "animal", 4},
    {"Camilla", "galinha", 9},
    {"Sweetums", "monstro", 4},
    {"Dr. Strangepork", "porco", 6},
    {"Link Hogthrob", "porco", 3},
    {"Zoot", "humano", 2},
    {"Dr. Bunsen Honeydew", "humano", 2},
    {"Beaker", "humano", 1},
    {"Swedish Chef", "humano", 1}
  };


/* Imprime a informação sobre a criatura
. */
void
print_criatura(const struct criatura  *c)
{
  printf ("%s, o %s, %d\n", c->nome, c->especie, c->idade);
}

int criatura_cmp(const void *v1, const void *v2)
{
   const struct criatura *c1 = v1;
   const struct criatura *c2 = v2;
   return strcmp(c1->nome, c2->nome);
}
  
int comp_num(const void *v1, const void *v2){
    const struct criatura *c1 = v1;
    const struct criatura *c2 = v2;
    if(c1->idade > c2->idade){
        return 1;
    }
    return 0;
}

int criatura_cmp_all(const void *v1, const void *v2){
    const struct criatura *c1 = v1;
    const struct criatura *c2 = v2;
    int nome = strcmp(c1->nome, c2->nome);
    int especie = strcmp(c1->especie, c2->especie);
    if(nome == 1 && especie == 1){
        return 1;
    }
    return 0;
}

void encontra_criatura(struct criatura* c){
    int numMuppets = sizeof(muppets)/sizeof(struct criatura);
    if(bsearch(c, muppets, numMuppets, sizeof(struct criatura), criatura_cmp_all)){
        printf("\nENCONTRADA: ");
        print_criatura(c);
    }else{
        printf("Nao encontrada\n");
    }
    printf("\n===========================================\n");
}

int main(void) {
  
    int numMuppets = sizeof(muppets)/sizeof(struct criatura);

    printf("========NAO ORDENADO========\n");
    for (int i = 0; i < numMuppets; i++)
        print_criatura(&muppets[i]);

    printf("\n");

    
    //3. Ordene as criaturas por nome utilizando a qsort da stdlib.
    printf("========ORDENADO POR NOME========\n");
    qsort(muppets, numMuppets, sizeof(struct criatura), criatura_cmp);
    for (int i = 0; i < numMuppets; i++)
        print_criatura(&muppets[i]);

    printf("\n===============================================\n");

    
    //4. Teste a função encontra_criatura procurando na main procurando um muppet que existe e outro que não existe.
    struct criatura c = {"Swedish Chef", "humano", 1};
    encontra_criatura(&c);
 
    
    //5. Ordene as criaturas por idade utilizando a qsort da stdlib.
    printf("========ORDENADO POR IDADE========\n");
    qsort(muppets, numMuppets, sizeof(struct criatura), comp_num);
    for (int i = 0; i < numMuppets; i++)
        print_criatura(&muppets[i]);

    printf("\n");


    // 6. Imprima a lista de criaturas da mesma espécie.

  return 0;
}