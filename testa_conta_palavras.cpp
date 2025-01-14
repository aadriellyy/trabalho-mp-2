//começa com teste vazio

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"

TEST_CASE("Teste 1: contaPalavras retorna vazio para texto vazio"){
    std::unordered_map<std::string, int> resultado = contaPalavrasDeString("");
    REQUIRE(resultado.empty());
}