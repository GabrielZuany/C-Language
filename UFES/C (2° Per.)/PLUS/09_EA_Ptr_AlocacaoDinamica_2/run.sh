gcc -o teste main.c tTerreno.c tCirculo.c tRetangulo.c tTriangulo.c -lm
valgrind ./teste
rm teste
