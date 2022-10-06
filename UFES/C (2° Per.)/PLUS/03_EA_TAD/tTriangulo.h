#ifndef _TTRIANGULO_H_
#define _TTRIANGULO_H_

typedef struct{
    float comprimento;
    float largura;
}tTriangulo;

tTriangulo LeTriangulo();
float RetornaAreaTriangulo(tTriangulo triangulo);
float RetornaMultaTriangulo(float area);

#endif