flags = -Wall -Werror -Wextra

all: s21_cat

rebuild: clean all

s21_cat: cat_no_args.o cat.o cat_args.o cat_parse_arg.o cat_flags.o
	gcc $(flags) cat_no_args.o cat.o cat_args.o cat_parse_arg.o cat_flags.o -o s21_cat

cat.o: cat.c
	gcc $(flags) -c cat.c -o cat.o

cat_flags.o: cat_flags.c
	gcc $(flags) -c cat_flags.c -o cat_flags.o

cat_args.o: cat_args.c
	gcc $(flags) -c cat_args.c -o cat_args.o

cat_parse_arg.o: cat_parse_arg.c
	gcc $(flags) -c cat_parse_arg.c -o cat_parse_arg.o

cat_no_args.o: cat_no_args.c
	gcc $(flags) -c cat_no_args.c -o cat_no_args.o

clean:
	rm -rf *.o
	rm -rf s21_cat
