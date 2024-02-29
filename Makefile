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
					Tristate.cpp									\
					Circuit.cpp										\
					Exception.cpp									\
				)

DIR			+=	src/components
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					AComponent.cpp									\
					Link.cpp										\
					ASourceComponent.cpp							\
					AInputComponent.cpp								\
					ComponentFactory.cpp							\
				)

DIR			+=	src/components/special
SRC			+=	$(addprefix $(lastword $(DIR))/,					\
					TrueComponent.cpp								\
					FalseComponent.cpp								\
					InputComponent.cpp								\
					ClockComponent.cpp								\
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
FU_SRC		:=	$(filter-out src/Main.cpp, $(SRC))
FU_SRC		+=	$(addprefix $(FU_DIR)/,								\
					Tests.cpp										\
				)

UT_DIR		:=	tests/unit
UT_SRC		:=	$(filter-out src/Main.cpp, $(SRC))
UT_SRC		+=	$(addprefix $(UT_DIR)/,								\
					Tests_4008.cpp									\
					Tests_4017.cpp									\
					Tests_4013.cpp									\
					Tests_4040.cpp									\
				)

DIR_BUILD	:=	build
DIR_BIN		:=	$(DIR_BUILD)/bin

DIR_OBJ		:=	$(DIR_BUILD)/obj
OBJ			:=	$(patsubst %$(EXT),$(DIR_OBJ)/%.o,$(SRC))

FU_OBJ		:=	$(patsubst %$(EXT),$(DIR_OBJ)/%.o,$(FU_SRC))

UT_DIR_OBJ	:=	$(DIR_BUILD)/tests/unit
UT_OBJ		:=	$(patsubst %$(EXT),$(UT_DIR_OBJ)/%.o,$(UT_SRC))

DG_DIR_OBJ	:=	$(DIR_BUILD)/debug
DG_OBJ		:=	$(patsubst %$(EXT),$(DG_DIR_OBJ)/%.o,$(SRC))

DEBUG		:=	$(DIR_BIN)/debug
FU_TEST		:=	$(DIR_BIN)/func_test
UT_TEST		:=	$(DIR_BIN)/unit_test

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
	@$(CXX) $(CXXFLAGS) -c $< -o $@									\
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

$(NAME):			$(OBJ); 	$(COMPILE)

$(FU_TEST):			$(FU_OBJ);	$(COMPILE)
tests_functional:	$(FU_TEST)
	@$<

$(UT_TEST):			CXXFLAGS += -lcriterion --coverage
$(UT_TEST):			$(UT_OBJ);	$(COMPILE)
tests_unit:			$(UT_TEST)
	@cp $(UT_TEST) $(UT_DIR_OBJ)
	@$(UT_DIR_OBJ)/$(notdir $<)

debug:				CXXFLAGS += -g
debug:				$(DG_OBJ); 	$(COMPILE)

docs:
	@doxygen

tests_run:			tests_functional tests_unit
	gcovr $(UT_DIR_OBJ) --exclude tests/
	gcovr $(UT_DIR_OBJ) --exclude tests/ --txt-metric branch

clean:
	@[ -d $(DIR_BUILD) ]											\
	&& $(RM) $(DIR_BUILD)											\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(DIR_BUILD) || true

fclean:				clean
	@[ -f $(NAME) ]													\
	&& $(RM) $(NAME)												\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(NAME) || true

re:					fclean all

.PHONY:				all tests tests_run debug clean fclean re docs

.SILENT:			all tests tests_run debug clean fclean re docs
