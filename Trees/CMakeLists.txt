
set(TREE_SOURCES tree.hpp tree.inc)

add_library(Trees STATIC ${TREE_SOURCES})
set_target_properties(Trees PROPERTIES LINKER_LANGUAGE CXX)

