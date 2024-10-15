CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
CFLAGS+=-fprofile-arcs -ftest-coverage --coverage
FLAG_TEST=-lcheck -lm -lpthread
CLEAN_FIELS=*.o *.a *.info *.out *.gcno *.gcda *.gch *.log
CLEAN_DIR=report test_files object

ifeq ($(shell uname), Linux)
    FLAG_TEST += -lsubunit -lm
endif

all: gcov_report

rebuild: clean all

s21_matrix.a:
	$(CC) $(FLAGS) -c core/*.c
	ar -rcs s21_matrix.a *.o
	ranlib s21_matrix.a
	@mkdir object
	@mv *.o object

test: s21_matrix.a
	$(CC) $(FLAGS) main.c core/*.c tests/*.c -o test.out $(CFLAGS) $(FLAG_TEST)
	./test.out
	@mkdir test_files
	@mv *.gcno test_files
	@mv *.gcda test_files

gcov_report: test
	@echo "┏=========================================┓"
	@echo "┃     Generating your html report ...     ┃"
	@echo "┗=========================================┛"
	@mkdir report
	gcovr -r . --html --html-details -o report/coverage.html
	@open report/coverage.html

clean:
	rm -rf $(CLEAN_DIR)
	rm -f $(CLEAN_FIELS)
	@clear

clang_format:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@cp ../linters/.clang-format .
	@clang-format -i **/*.c **/*.h *.c *.h
	@rm ./.clang-format

clang_check:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@cp ../linters/.clang-format .
	@clang-format -n **/*.c **/*.h *.c *.h
	@rm ./.clang-format

valgrind: clean  test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="valgrind.log" -v --verbose -q --quiet -s ./test.out
	@mv *.gcda test_files
	@clear
	@cat valgrind.log