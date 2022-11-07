#ifndef _TUSUARIO_H_
#define _TUSUARIO_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct tUsuario tUsuario;


/**
 * @brief Cadastra um usuário a partir de valores dados.
 * 
 * @param nome nome do usuário
 * @param cpf cpf do usuário
 * @return tUsuario* ponteiro para o usuario.
 */
tUsuario* RegistraUsuario(char *nome, int cpf);

/**
 * @brief Imprime informções registradas do usuário.
 * 
 * @param usuario ponteiro para a struct.
 */
void ImprimeUsuario(tUsuario *usuario);

void FILE_ImprimeUsuario(tUsuario* usuario, FILE* arq);

#endif