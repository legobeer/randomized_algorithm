enable_testing()

# Créez un exécutable pour les tests
add_executable(main main.cpp)

# Lier la bibliothèque de tests avec la bibliothèque principale
target_link_libraries(main MyLibrary)

# Incluez le répertoire d'en-tête pour les tests

# Ajoutez ici des directives spécifiques aux tests si nécessaire