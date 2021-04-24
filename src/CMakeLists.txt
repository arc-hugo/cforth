add_subdirectory(lib)

add_executable(forth main.c)
target_link_libraries(forth pile programme table etat)
