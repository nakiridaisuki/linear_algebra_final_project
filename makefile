CC=gcc
MAIN=main.c
SHELL = /bin/bash
EXE=main
SOURCEDIR=src
SRCFILES=$(wildcard $(SOURCEDIR)/*.c)
SRCOBJS=$(patsubst %.c,%.o,$(SRCFILES))
# OBJ=$(addprefix $(SOURCEDIR)/, )


test: MAIN=test.c
test: all
.PHONY: test

dtest: MAIN=test.c
dtest: debug
.PHONY: dtest

%.o: %.c
	@$(CC) -c $< -o $@

all: $(MAIN) $(SRCOBJS)
	$(CC) $(MAIN) $(SRCOBJS) -o $(EXE)


debug: CC += -DDEBUG -g
debug: all
.PHONY: debug

clean:
	-rm -f $(SOURCEDIR)/*.o $(EXE)

.PHONY: clean