# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/19 13:58:39 by tutku             #+#    #+#              #
#    Updated: 2026/09/01 16:20:46 by tcakir-y         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = ex02

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

# Directories
OBJ_DIR = obj
INC_DIR = inc
SRC_DIR = src

# Header search path
CPP_FLAGS = -I$(INC_DIR)

# Source files
SRC =	main.cpp\
		Bureaucrat.cpp\
		Form.cpp

# Convert source file name into object file path inside obj/
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# Rules

# Default rule: builds executable
all: $(NAME)

# Rule to link executable
$(NAME):$(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)All files compiled!$(RESET)"

# Compile src/*.cpp into obj/*.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(PURPLE)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(CPP_FLAGS) -c $< -o $@

# Clean rule: removes object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)All object files removed. $(RESET)"

# Full clean rule: Remove object files and executable
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)All executable file removed. $(RESET)"

# Recompile everything
re: fclean all
	@echo "$(PURPLE)Object + exec files have been cleaned and rebuilt.$(RESET)"
	
# Mark targets that are not actual files
.PHONY: all clean fclean re

# Colors
PURPLE = \033[35m
CYAN = \033[36m
BLUE = \033[34m
PINK = \033[95m
RED = \033[31m
GREEN = \033[1;32m
YELLOW = \033[33m
RESET = \033[0m
