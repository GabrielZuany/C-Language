#ifndef _TRETANGULO_H_
#define _TRETANGULO_H_

typedef struct{
    float base;
    float altura;
}tRetangulo;

tRetangulo CriaRetangulo(float base, float altura);
float RetornaAreaRetangulo(tRetangulo retangulo);
float RetornaMultaRetangulo(float area);

#endif