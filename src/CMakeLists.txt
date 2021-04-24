add_subdirectory(lib)

add_executable(forth main.c)
target_link_libraries(forth etat table op_base op_gestion op_affichage op_condition pile programme )
