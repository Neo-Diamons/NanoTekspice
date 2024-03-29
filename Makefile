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

DIR			+=	src/parsing
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					Parser.cpp										\
					Factory.cpp										\
					Circuit.cpp										\
					Shell.cpp										\
				)

DIR			+=	src/components
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					AComponent.cpp									\
					Link.cpp										\
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
					4017.cpp										\
					4013.cpp										\
					4040.cpp										\
				)

FU_DIR		:=	tests/func

UT_DIR		:=	tests/unit
UT_SRC		:=	$(filter-out src/Main.cpp, $(SRC))
UT_SRC		+=	$(addprefix $(UT_DIR)/,								\
					Tests_4008.cpp									\
					Tests_4017.cpp									\
					Tests_4013.cpp									\
					Tests_4040.cpp									\
					Tests_And.cpp									\
					Tests_Not.cpp									\
					Tests_Or.cpp									\
					Tests_Xor.cpp									\
					Tests_Clock.cpp									\
					Tests_False.cpp									\
					Tests_Input.cpp									\
					Tests_Output.cpp								\
					Tests_True.cpp									\
					Tests_4001.cpp									\
					Tests_4011.cpp									\
					Tests_4030.cpp									\
					Tests_4069.cpp									\
					Tests_4071.cpp									\
					Tests_4081.cpp									\
					Tests_Link.cpp									\
				)

DIR_BUILD	:=	build
DIR_BIN		:=	$(DIR_BUILD)/bin

DIR_OBJ		:=	$(DIR_BUILD)/obj
OBJ			:=	$(patsubst %$(EXT),$(DIR_OBJ)/%.o,$(SRC))
DEP			:=	$(OBJ:.o=.d)

UT_DIR_OBJ	:=	$(DIR_BUILD)/tests/unit
UT_OBJ		:=	$(patsubst %$(EXT),$(UT_DIR_OBJ)/%.o,$(UT_SRC))
UT_DEP		:=	$(UT_OBJ:.o=.d)

DG_DIR_OBJ	:=	$(DIR_BUILD)/debug
DG_OBJ		:=	$(patsubst %$(EXT),$(DG_DIR_OBJ)/%.o,$(SRC))
DG_DEP		:=	$(DG_OBJ:.o=.d)

DEBUG		:=	$(DIR_BIN)/debug
FU_TEST		:=	$(FU_DIR)/tester.sh
UT_TEST		:=	$(DIR_BIN)/unit_test

DOC_OUT		:=	doc/html

RM			:=	rm -rf

CXX			:=	g++
CXXFLAGS	:=	-iquote. --std=c++20 -Wall -Wextra

all:				$(NAME)

define CREATE_DIR
	@if [ ! -d $(dir $@) ]; then									\
		mkdir -p $(dir $@) 											\
		&& printf "\033[93m[CREATED]\033[0m %s\n" $(dir $@)			\
		|| printf "\033[31m[ERROR]\033[0m %s\n"   $(dir $@);		\
	fi
endef

define BUILD_OBJ
	@$(RM) $(patsubst %.o,%.gcda,$@)
	@$(RM) $(patsubst %.o,%.gcno,$@)
	$(CREATE_DIR)
	@$(CXX) $(CXXFLAGS) -MMD -c $< -o $@							\
	&& printf "\033[32m[OK]\033[0m %s\n" $<							\
	|| printf "\033[31m[KO]\033[0m %s\n" $<
endef

$(DIR_OBJ)/%.o:		%$(EXT); $(BUILD_OBJ)
$(UT_DIR_OBJ)/%.o:	%$(EXT); $(BUILD_OBJ)
$(DG_DIR_OBJ)/%.o:	%$(EXT); $(BUILD_OBJ)

define COMPILE
	$(CREATE_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ $^			 						\
	&& printf "\033[32m[SUCCES]\033[0m %s\n" $@						\
	|| printf "\033[31m[ERROR]\033[0m %s\n"  $@
endef

-include $(DEP)
$(NAME):			$(OBJ); 	$(COMPILE)

tests_functional:	$(FU_TEST) $(NAME)
	@$^

-include $(UT_DEP)
$(UT_TEST):			CXXFLAGS += -lcriterion --coverage
$(UT_TEST):			$(UT_OBJ);	$(COMPILE)
tests_unit:			$(UT_TEST)
	@cp $(UT_TEST) $(UT_DIR_OBJ)
	@$(UT_DIR_OBJ)/$(notdir $<)

-include $(DG_DEP)
$(DEBUG):			CXXFLAGS += -g
$(DEBUG):			$(DG_OBJ); 	$(COMPILE)
debug:				$(DEBUG)

tests_run:			tests_functional tests_unit
	gcovr $(UT_DIR_OBJ) --exclude tests/
	gcovr $(UT_DIR_OBJ) --exclude tests/ --branches

doc:
	doxygen doc/Doxyfile
	python -m webbrowser -t doc/html/index.html

clean:
	@[ -d $(DIR_BUILD) ]											\
	&& $(RM) $(DIR_BUILD)											\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(DIR_BUILD) || true
	@[ -d $(DOC_OUT) ]												\
	&& $(RM) $(DOC_OUT)												\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(DOC_OUT) || true

fclean:				clean
	@[ -f $(NAME) ]													\
	&& $(RM) $(NAME)												\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(NAME) || true

re:					fclean all

.PHONY:				all tests tests_run debug clean fclean re doc

.SILENT:			all tests tests_run debug clean fclean re doc
