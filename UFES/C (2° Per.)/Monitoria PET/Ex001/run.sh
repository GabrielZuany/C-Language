gcc -o test main.c tAluno.c
mkdir outprog
./test < inputs/test_1.in > outprog/test_1.out
./test < inputs/test_2.in > outprog/test_2.out
./test < inputs/test_3.in > outprog/test_3.out
diff outprog/ outputs/
rm -rf outprog
rm test