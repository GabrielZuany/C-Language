mkdir outprog
gcc -o teste main.c tConta.c tUsuario.c
valgrind --leak-check=full -s  ./teste<input/test_1.in > outprog/test_1.out 
valgrind --leak-check=full -s  ./teste<input/test_2.in > outprog/test_2.out 
valgrind --leak-check=full -s  ./teste<input/test_3.in > outprog/test_3.out
rm teste
diff output/ outprog/ 