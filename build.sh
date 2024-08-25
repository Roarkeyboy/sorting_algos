#/usr/bin/bash
OUTPUT_NAME=sorter
CPP_VERSION="-std=c++23"
# DEBUGGING="-g"
W_FLAGS="-Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Werror -Wno-unused"
COMPILE_FLAGS="$CPP_VERSION -fconcepts -pedantic $DEBUGGING $W_FLAGS"
g++ $COMPILE_FLAGS -o $OUTPUT_NAME sorter.cpp sorting_algos.cpp random_fill.cpp

echo -e "Successfuly built $OUTPUT_NAME"