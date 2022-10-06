
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    int i = 0, PrimChar = 0, SegChar = 0, TerChar = 0, QuarChar = 0;
    char caractere = '?', Char_1 = '?',  Char_2 = '?',  Char_3 = '?',  Char_4 = '?';
    
    for (i = 1; i<=4 ; ++i){
        
        scanf("%c", & caractere);
        
        if(i == 1 && caractere>='A' && caractere<='Z'){
            PrimChar = 1;
            Char_1 = caractere;
        }
        if(i == 2 && caractere>='0' && caractere<='9'){
            SegChar = 1;
            Char_2 = caractere;
        }
        if(i == 3 && (caractere =='a' || caractere=='e' || caractere=='i' || caractere=='o' || caractere=='u' || caractere=='A' || caractere=='E' || caractere=='I' || caractere=='O'|| caractere=='U')){


            TerChar = 1;
            
            if(caractere>='a' && caractere <='z'){
                Char_3 = caractere  - ('a'-'A');
            }else Char_3 = caractere;
            
            
        }
        if( i == 4 && caractere!='a' && caractere!='e' && caractere!='i' && caractere!='o' && caractere!='u'&& caractere>='a' && caractere<='z'){

            QuarChar = 1;

            if(caractere>='a' && caractere <='z'){
                Char_4 = caractere  - ('a'-'A');
            }else Char_4 = caractere;
            
        }
        
    }
    
    if(PrimChar == 1 && SegChar == 1 && TerChar == 1 && QuarChar == 1){
        printf("%c%c%c%c", Char_1, Char_2, Char_3, Char_4);
    }else printf("Invalido");
    
    
    return (0);
}

