#include <stdio.h>

int main(void){

    char c = 'x';
    int controlador = 1;
    
    do{
        scanf("%c", &c);
        if(controlador==1){
            printf("RESP:");
            controlador=0;
        }
        if(c==32){
            /*
            c=0; 0 na tabela ascii significa null ou '/0'. Mas atente:
            ao realizar uma comparação com o diff, ele irá comparar bit a bit
            os valores dos arquivos. Logo, se a ideia do programa é ignorar os
            espaços e tratá-los como inexistentes, o diff irá acusar uma divergência
            de informações contidas nos arquivos, já que irá conter bits com "0" entre 
            as palavras.
            Para evitar que isso aconteça e ele de fato ignore os espaços em branco,
            utilize essa estrutura.
            */
            continue;/*Se for digitado espaço, esse comando reinicia o loop não impri
            mindo o espaço.*/
        }
        printf("%c", c);
        if(c=='.'|| c=='?' || c=='!'){
            break;
        }
    }while(1);

    return 0;
}