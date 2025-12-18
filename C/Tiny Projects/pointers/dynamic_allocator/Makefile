# -fsanitize=address -g make sure baundary checks are done.

run:
	@ gcc -fsanitize=address -g $(FILE).c -o $(FILE)
	@ ./$(FILE)