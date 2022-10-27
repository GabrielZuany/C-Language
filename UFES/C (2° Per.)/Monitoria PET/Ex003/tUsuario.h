#ifndef _TUSUARIO_H_
#define _TUSUARIO_H_

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

/**
 * @brief Faz a cópia do nome na variável simples para a variáel interna da struct.
 * 
 * @param usuario ponteiro para a struct.
 * @param nome variável contendo o nome a ser copiado.
 */
void RegistraNome(tUsuario *usuario, char* nome);

#endif