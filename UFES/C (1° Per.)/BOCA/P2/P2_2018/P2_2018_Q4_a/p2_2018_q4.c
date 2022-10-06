#include <stdio.h>

int ReduzInteiro(int n){
    int IntRed = 0, digito = 0;
    int  i = 0;

    for(i=0; i<10; ++i){
 
        digito = n%10; 
        n/=10;
        IntRed+=digito;

    }
    if(IntRed>9){
        IntRed = ReduzInteiro(IntRed);
    }

    return IntRed;
}

int MontaSenha(int senha, int dig){
    senha = senha*10 + dig; 
    return senha;
}

int ReduzCodigo(){
    int dig = 0, senha = 0, num = 0, numred = 0;
    char letra = '!';

    while(scanf("%c", &letra)==1 && letra!='.'){
        
        if(letra=='('){

            if(scanf("%1i", &num)==0){
                printf("[ERRO]");
                scanf("%*[^)]");
                scanf("%*c");
                continue;
            }

            numred+=num;
            while(scanf("%1i", &num)==1){//le digito por digito
                numred+=num;
            }
            
            dig = ReduzInteiro(numred);
            senha = MontaSenha(senha, dig);
            printf("[%i]", dig);
            scanf("%*[^)]");
            scanf("%*c");
            numred = 0;
            continue;

        }else printf("%c", letra);

    }

    return senha;
}

int main(void){

    int senha = 0;

    senha = ReduzCodigo();
    printf(". SENHA:%i\n", senha);

    return 0;
}