GCC=gcc -Wall -Werror -Wextra -std=c11
LINUS_FLGS =  -lsubunit -lrt -lpthread -lm

OS := $(shell uname -s);

all: test gcov_report

s21_math.c:	clean
	$(GCC) -c  s21_abs.c
	$(GCC) -c  s21_acos.c
	$(GCC) -c  s21_asin.c
	$(GCC) -c  s21_atan.c
	$(GCC) -c  s21_ceil.c
	$(GCC) -c  s21_cos.c
	$(GCC) -c  s21_fabs.c
	$(GCC) -c  s21_floor.c
	$(GCC) -c  s21_fmod.c
	$(GCC) -c  s21_log.c
	$(GCC) -c  s21_exp.c
	$(GCC) -c  s21_pow.c
	$(GCC) -c  s21_sin.c
	$(GCC) -c  s21_sqrt.c
	$(GCC) -c  s21_tan.c

s21_math.a : clean s21_math.c
	ar rcs s21_math.a *.o

test: clean s21_math.c
	checkmk clean_mode=1 s21_test.check > s21_test.c
	# gcc -c  s21_test.c
	gcc --coverage *.c -o test -lcheck -lpthread -lm
	./test

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h *.check
	rm .clang-format

gcov_report: clean s21_math.a
	gcc --coverage *.c s21_math.a -lcheck -lpthread -lm -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

clean:
	rm -rf s21_math
	rm -rf s21_test
	rm -rf test
	rm -rf out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.out
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
