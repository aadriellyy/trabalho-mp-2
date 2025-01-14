//começa com teste vazio

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"
//#include "conta_palavra.cpp"
#include <unordered_map>

TEST_CASE("Teste 1: contaPalavras retorna vazio para texto vazio") {
    std::unordered_map<std::string, int> resultado = contaPalavras("");
    REQUIRE(resultado.empty());
}

TEST_CASE("Teste 2: contaPalavras separa e conta corretamente") {
    std::string texto = "teste de contagem de palavras teste";
    std::unordered_map<std::string, int> resultado = contaPalavras(texto);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["de"] == 1);
    REQUIRE(resultado["contagem"] == 1);
    REQUIRE(resultado["palavras"] == 1);
}
