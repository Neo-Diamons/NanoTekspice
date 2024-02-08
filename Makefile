##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

NAME		:=	nanotekspice
EXT			:=	.cpp

DIR			:=	src
SRC			:=	$(addprefix $(DIR)/,								\
					Main.cpp										\
				)

DIR			+=	src/components
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
				AComponent.cpp										\
			)

DIR			+=	src/components/special
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					True.cpp										\
					False.cpp										\
					Input.cpp										\
					Output.cpp										\
					Clock.cpp										\
				)

DIR			+=	src/components/elementary
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					And.cpp											\
					Or.cpp											\
					Xor.cpp											\
					Not.cpp											\
				)

DIR			+=	src/components/gates
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					4001.cpp										\
					4011.cpp										\
					4030.cpp										\
					4069.cpp										\
					4071.cpp										\
					4081.cpp										\
				)

DIR			+=	src/components/advanced
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					4008.cpp										\
				)

DIR_FUNC	:=	tests/functional
SRC_FUNC	:=	$(addprefix $(DIR_FUNC)/,							\
					functional_tester.c								\
				)

DIR_UTEST	:=	tests/unit
SRC_UTEST	:=	$(filter-out src/Main.cpp, $(SRC))
SRC_UTEST	+=	$(addprefix $(DIR_UTEST)/,							\
					tests_4008.cpp									\
				)

DIR_BUILD	:=	build

ROOT_OBJ	:=	$(addprefix $(DIR_BUILD)/,obj/)
DIR_OBJ		:=	$(addprefix $(ROOT_OBJ),$(DIR))

OBJ			:=	$(patsubst %$(EXT),$(ROOT_OBJ)%.o,$(SRC))

D_DIR_BUILD	:=	$(addprefix $(DIR_BUILD)/, debug)

D_ROOT_OBJ	:=	$(addprefix $(D_DIR_BUILD)/,obj/)
D_DIR_OBJ	:=	$(addprefix $(D_ROOT_OBJ),$(DIR))
D_OBJ		:=	$(patsubst %$(EXT),$(D_ROOT_OBJ)%.o,$(SRC))

TEST_DIR	:=	$(addprefix $(DIR_BUILD)/,tests/)
FUNC_TEST	:=	functional_test
UNIT_TEST	:=	unit_test

RM			:=	rm -rf

CXX			:=	g++
CXXFLAGS	:=	-iquote. --std=c++20 -Wall -Wextra

all:				$(ROOT_OBJ) $(NAME)

$(ROOT_OBJ):
	@mkdir -p $(DIR_OBJ)											\
	&& printf "\033[93m[CREATED]\033[0m %s\n" $(DIR_OBJ)			\
	|| printf "\033[31m[ERROR]\033[0m %s\n"   $(DIR_OBJ)

$(ROOT_OBJ)%.o:		%$(EXT)
	@$(CXX) $(CXXFLAGS) -c $< -o $@									\
	&& printf "\033[32m[OK]\033[0m %s\n" $<							\
	|| printf "\033[31m[KO]\033[0m %s\n" $<

$(NAME):			$(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS)									\
	&& printf "\033[32m[SUCCES]\033[0m %s\n" $@						\
	|| printf "\033[31m[ERROR]\033[0m %s\n"  $@

##  _______        _
## |__   __|      | |
##    | | ___  ___| |_ ___
##    | |/ _ \/ __| __/ __|
##    | |  __/\__ \ |_\__ \
##    |_|\___||___/\__|___/

tests:				all
	@gcc -Wall -Wextra -o $(FUNC_TEST) $(SRC_FUNC) -L. -lasm		\
	&& printf "\033[32m[SUCCES]\033[0m %s\n" $@						\
	|| printf "\033[31m[ERROR]\033[0m %s\n"  $@
	@./$(FUNC_TEST)

$(UNIT_TEST):		CXXFLAGS += -lcriterion --coverage
$(UNIT_TEST):		fclean
	@mkdir -p $(TEST_DIR)
	@$(CXX) $(CXXFLAGS) $(SRC_UTEST) -o $(TEST_DIR)$@				\
	&& printf "\033[32m[SUCCES]\033[0m %s\n" $@						\
	|| printf "\033[31m[ERROR]\033[0m %s\n"  $@

tests_run:			$(UNIT_TEST)
	@$(TEST_DIR)$(UNIT_TEST)
	gcovr $(TEST_DIR) --exclude tests/
	gcovr $(TEST_DIR) --exclude tests/ --txt-metric branch

##  _____       _
## |  __ \     | |
## | |  | | ___| |__  _   _  __ _
## | |  | |/ _ \ '_ \| | | |/ _` |
## | |__| |  __/ |_) | |_| | (_| |
## |_____/ \___|_.__/ \__,_|\__, |
##                           __/ |
##                          |___/

$(D_ROOT_OBJ):
	@mkdir -p $(D_DIR_OBJ)											\
	&& printf "\033[93m[CREATED]\033[0m %s\n" $(DIR_OBJ)			\
	|| printf "\033[31m[ERROR]\033[0m %s\n"   $(DIR_OBJ)

$(D_ROOT_OBJ)%.o:	%$(EXT)
	@$(CXX) $(CXXFLAGS) -c $< -o $@									\
	&& printf "\033[32m[OK]\033[0m %s\n" $<							\
	|| printf "\033[31m[KO]\033[0m %s\n" $<

debug:				CXXFLAGS += -g
debug:				$(D_ROOT_OBJ) $(D_OBJ)
	@$(CXX) -o $(NAME) $(D_OBJ) $(CXXFLAGS)							\
	&& printf "\033[32m[SUCCES]\033[0m %s\n" $(NAME)				\
	|| printf "\033[31m[ERROR]\033[0m %s\n"  $(NAME)

##   _____ _
##  / ____| |
## | |    | | ___  __ _ _ __
## | |    | |/ _ \/ _` | '_ \
## | |____| |  __/ (_| | | | |
##  \_____|_|\___|\__,_|_| |_|

clean:
	@[ -d $(DIR_BUILD) ]											\
	&& $(RM) $(DIR_BUILD)											\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(DIR_BUILD) || true

fclean:				clean
	@[ -f $(NAME) ]													\
	&& $(RM) $(NAME)												\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(NAME) || true

##   ____  _   _
##  / __ \| | | |
## | |  | | |_| |__   ___ _ __
## | |  | | __| '_ \ / _ \ '__|
## | |__| | |_| | | |  __/ |
##  \____/ \__|_| |_|\___|_|

re:					fclean all

.PHONY:				all tests tests_run debug clean fclean re 		\
					$(DIR_OBJ) $(ROOT_OBJ)%.o $(NAME) $(UNIT_TEST)

.SILENT:			all tests tests_run debug clean fclean re 		\
					$(DIR_OBJ) $(ROOT_OBJ)%.o $(NAME) $(UNIT_TEST)
