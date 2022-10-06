#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define FOLD_MAX 30
#define SUCCESS 1
#define INCORRECT 0
#define NOT_EXISTS -1

int AnalisaDado(char *folder, char *name, char *pass);

int main(int argc, char **argv){
    int num, i, response = -1;
    char folder[FOLD_MAX], out[FOLD_MAX], name[MAX], pass[MAX];
    out[0] = '\0';

    sprintf(folder, "%s", argv[1]);
    strcat(out, "outprog/");
    strcat(out, folder);
    FILE *log = fopen(strcat(out, "/log.txt"), "w");

    scanf("%d", &num);
    scanf("%*c");
    
    for(i=0; i<num; ++i){
        scanf("%s", name);
        scanf("%s", pass);
        response = AnalisaDado(folder, name, pass);
        if(response == 1){
            fprintf(log, "Bem vindo, usuario %s\n", name);
        }else if(response == 0){
            fprintf(log, "Senha incorreta!\n");
        }else if(response == -1){
            fprintf(log, "ERROR! login %s nao existe\n", name);
        }
    }
    fclose(log);
    return 0;
}

int AnalisaDado(char *folder, char *name, char *pass){
    char path[FOLD_MAX], dataName[MAX], dataPass[MAX];
    int encontrado = 0;
    strcpy(path, folder);

    FILE *data = fopen(strcat(path, "/data.txt"), "r");
    while(fscanf(data, "%s%s", dataName, dataPass) != EOF){
        if(strcmp(name, dataName) == 0){
            encontrado = 1;
            if(strcmp(pass, dataPass) == 0){
                fclose(data);
                return SUCCESS;
            }else{
                fclose(data);
                return INCORRECT;
            }
        }
    }
    if(encontrado == 0){
        fclose(data);
        return NOT_EXISTS;
    }
}