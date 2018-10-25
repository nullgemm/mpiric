NAME = mpiric_test
CC = gcc
FLAGS = -std=c99 -pedantic -g -O3
FLAGS+= -Wall -Wextra -Werror -Wno-strict-aliasing -Werror=vla
FLAGS+= -DBENCHMARK
BIND = bin
SRCD = src
SUBD = sub
OBJD = obj
RESD = res
INCL = -I$(SRCD)
LINK = -lm

SRCS = $(SRCD)/test.c
SRCS+= $(SRCD)/mpiric.c

OBJS:=$(patsubst $(SRCD)/%.c,$(OBJD)/$(SRCD)/%.o,$(SRCS))

$(OBJD)/%.o:%.c
	@echo "building source object $@"
	@mkdir -p $(@D)
	@$(CC) $(INCL) $(FLAGS) -c -o $@ $<

.PHONY: $(BIND)/$(NAME)
$(BIND)/$(NAME): $(OBJS) $(BIND)/charter_svg
	@echo "compiling $@"
	@mkdir -p $(BIND)
	@$(CC) $(INCL) $(FLAGS) -o $(BIND)/$(NAME) $(OBJS) $(LINK)

$(BIND)/charter_svg:
	@echo "compiling $@"
	@mkdir -p $(BIND)
	@mkdir -p $(SUBD)/charter/build
	@cd $(SUBD)/charter && meson ./build
	@cd $(SUBD)/charter/build && ninja
	@cp $(SUBD)/charter/build/charter_svg $(BIND)

clean:
	@echo "cleaning repo"
	@rm -rf $(BIND) $(OBJD)
	@rm -rf $(SUBD)/charter/build

run: $(BIND)/$(NAME)
	@echo "running tests"
	@cd $(BIND) && ./$(NAME) >> ../$(RESD)/benchmark.log

svg:
	@echo "copying svg files"
	@cp $(BIND)/*.svg $(RESD)/graphs/
