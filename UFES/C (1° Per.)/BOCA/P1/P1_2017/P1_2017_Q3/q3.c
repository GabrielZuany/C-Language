#include <stdio.h>

int main(void){

    char c1 = '.', c2 = '.', c3 = '.', c4 = '.', WhiteSpace = '.';

    scanf("%c%c", &c1, &c2);
    scanf("%c", &WhiteSpace);
    scanf("%c%c", &c3, &c4);

    if(WhiteSpace!=' '){
        printf("Invalido");
        return 0;
    }

    if(((c1>='0' && c1<='9') || (c1>='a' && c1<='z') || (c1>='A' && c1<='Z'))  &&  ((c2>='0' && c2<='9') || (c2>='a' && c2<='z') || (c2>='A' && c2<='Z'))  && ((c3>='0' && c3<='9') || (c3>='a' && c3<='z') || (c3>='A' && c3<='Z')) && ((c4>='0' && c4<='9') || (c4>='a' && c4<='z') || (c4>='A' && c4<='Z'))){
        
    

        if(c1!=c3 || c1!=c4 || c2!=c3 || c2!=c4){

            if(c1>='a' && c1<='z'){
                c1 = c1 - 32;
            }
            if(c2>='a' && c2<='z'){
                c2 = c2 - 32;
            }
            if(c3>='a' && c3<='z'){
                c3 = c3 - 32;
            }
            if(c4>='a' && c4<='z'){
                c4 = c4 - 32;
            }
            
            if((c1==c3 && c2==c4)){
                printf("IGUAIS");
                return 0;
            }

            printf("DIFERENTES");
            return 0;


        }else {
            printf("IGUAIS");
            return 0;
        }



    }else printf("Invalido");

    return 0;

}

/*
    for i in *; do ../teste <$i>../outprog/$i;done
*/