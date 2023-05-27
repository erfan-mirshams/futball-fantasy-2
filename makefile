##
# futball-fantasy
#
# @file
# @version 0.1
CFLAGS = -c -Wall -Wextra
LFLAGS = -Wall -Wextra -fsanitize=address -fsanitize=undefined -fsanitize=leak

SRC_DIR = src
BUILD_DIR = build

TARGET = futballFantasy.out

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC_FILES:.cpp=.o)))

all: $(TARGET)

$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(LFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CFLAGS) -o $@ $<

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

# end
