NAME = mpiric
CC = gcc
FLAGS = -std=c99 -pedantic -g -O3
FLAGS+= -Wall -Wextra -Werror -Wno-strict-aliasing -Werror=vla
FLAGS+= -DBENCHMARK
INCL = -I$(SRCD)
LINK = -lm

BIND = bin
OBJD = obj
SRCD = src
SUBD = sub
RESD = res

SRCS = $(SRCD)/main.c
SRCS+= $(SRCD)/mpiric.c
SRCS_OBJS := $(patsubst %.c,$(OBJD)/%.o,$(SRCS))

# aliases
.PHONY: final
final: $(BIND)/$(NAME) $(BIND)/charter_svg

# generic compiling command
$(OBJD)/%.o: %.c
	@echo "building object $@"
	@mkdir -p $(@D)
	@$(CC) $(INCL) $(FLAGS) -c -o $@ $<

# final executable
$(BIND)/$(NAME): $(SRCS_OBJS)
	@echo "compiling executable $@"
	@mkdir -p $(@D)
	@$(CC) -o $@ $^ $(LINK)

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

remotes:
	@echo "registering remotes"
	@git remote add github git@github.com:nullgemm/$(NAME).git
	@git remote add gitea ssh://git@git.nullgemm.fr:2999/nullgemm/$(NAME).git

gitea: github
github:
	@echo "sourcing submodules from https://github.com"
	@git submodule sync
	@git submodule update --init --recursive --remote
