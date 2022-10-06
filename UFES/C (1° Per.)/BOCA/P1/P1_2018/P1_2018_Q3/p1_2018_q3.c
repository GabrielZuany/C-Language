#include <stdio.h>

int main(void){

    char c11 = '.', c12 = '.', c13 = '.';
    char c21 = '.', c22 = '.', c23 = '.';
    char white = '.';

    scanf("%c%c%c", &c11, &c12, &c13);
    scanf("%c", &white);
    scanf("%c%c%c", &c21, &c22, &c23);

    if(white!=' ' ||
     !(c11>='0'&&c11<='9' && c21>='0'&&c21<='9') ||
      !(c12>='a'&&c12<='z' && c22>='a'&&c22<='z') || 
      (!(c13>='A'&&c13<='Z' && c13>='a'&&c13<='z' ) && !(c23>='A'&& c23<='Z' || c23>='a'&& c23<='z'))){
        printf("Codigo invalido!\n");
        return 0;
    }

    if(c11==c21 && c12==c22 && c13==c23){
        printf("III\n");
    }
    if(c11==c21 && c12==c22 && c13!=c23){

        if((c13==c23+32 || c13+32==c23) || (c13==c23-32 || c13-32==c23)){
            printf("IIC\n");
            return 0;
        }

        printf("IID\n");
    }
    if(c11==c21 && c12!=c22 && c13==c23){

        if((c12==c22+32 || c12+32==c22) || (c12==c22-32 || c12-32==c22)){
            printf("ICI\n");
            return 0;
        }

        printf("IDI\n");
    }
    if(c11!=c21 && c12==c22 && c13==c23){

        if((c11==c21+32 || c11+32==c21) || (c11==c21-32 || c11-32==c21)){
            printf("CII\n");
            return 0;
        }

        printf("DII\n");
    }
    if(c11==c21 && c12!=c22 && c13!=c23){

        if((c12==c22+32 || c12+32==c22) || (c12==c22-32 || c12-32==c22)){
            printf("ICD\n");
            return 0;
        }
        if((c13==c23+32 || c13+32==c23) || (c13==c23-32 || c13-32==c23)){
            printf("IDC\n");
            return 0;
        }


        printf("IDD\n");
    }
    if(c11!=c21 && c12!=c22 && c13==c23){

        if((c11==c21+32 || c11+32==c21) || (c11==c21-32 || c11-32==c21)){
            printf("CDI\n");
            return 0;
        }

        if((c12==c22+32 || c12+32==c22) || (c12==c22-32 || c12-32==c22)){
            printf("DCI\n");
            return 0;
        }

        printf("DDI\n");
    }

    if(c11!=c21 && c12==c22 && c13!=c23){

        if((c11==c21+32 || c11+32==c21) || (c11==c21-32 || c11-32==c21)){
            printf("CID\n");
            return 0;
        }

        if((c13==c23+32 || c13+32==c23) || (c13==c23-32 || c13-32==c23)){
            printf("DIC\n");
            return 0;
        }

        printf("DID\n");
    }
    if(c11!=c21 && c12!=c22 && c13!=c23){
        
        if((c11==c21+32 || c11+32==c21) || (c11==c21-32 || c11-32==c21) && !((c12==c22+32 || c12+32==c22) || (c12==c22-32 || c12-32==c22) && !((c13==c23+32 || c13+32==c23) || (c13==c23-32 || c13-32==c23)))){
            
            printf("CDD\n");

            return 0;
        }
        if((c11==c21+32 || c11+32==c21) || (c11==c21-32 || c11-32==c21) && (c12==c22+32 || c12+32==c22) || (c12==c22-32 || c12-32==c22) && !((c13==c23+32 || c13+32==c23) || (c13==c23-32 || c13-32==c23))){
            printf("CCD\n");
            return 0;
        }

        if((c11==c21+32 || c11+32==c21) || (c11==c21-32 || c11-32==c21) && (c12==c22+32 || c12+32==c22) || (c12==c22-32 || c12-32==c22) && (c13==c23+32 || c13+32==c23) || (c13==c23-32 || c13-32==c23)){
            printf("DDC\n");
            return 0;
        }


        printf("DDD\n");
    }


    return 0;
}