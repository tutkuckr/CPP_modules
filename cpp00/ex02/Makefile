# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tutku <tutku@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 17:57:34 by tutku             #+#    #+#              #
#    Updated: 2026/01/24 17:58:45 by tutku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Directories
OBJ_DIR = obj

# Source files
SRC =	Account.cpp\
		tests.cpp

# Convert source file name into object file path inside obj/
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# Executable name
NAME = account

# Default rule: builds executable
all: $(NAME)

# Rule to compile .cpp files into .o files in obj/
$(OBJ_DIR)/%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		@echo "\033[0;33mCompiling $<.."
		@$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link executable
$(NAME):$(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME) 
	@echo "\033[0;32mAll files compiled!"

# Clean rule: removes object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;31mAll object files removed."

# Full clean rule: removes executables
fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mAll executable files removed."

# Recompile everything
re: fclean all
	@echo "Object + exec files have been cleaned and rebuilt."
# Mark targets that are not actual files
.PHONY: all clean fclean re
