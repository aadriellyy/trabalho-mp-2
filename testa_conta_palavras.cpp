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
    REQUIRE(resultado["de"] == 2);
    REQUIRE(resultado["contagem"] == 1);
    REQUIRE(resultado["palavras"] == 1);
}

TEST_CASE("Teste 3: contaPalavras diferencia maiusculas e minusculas") {
    std::string texto = "teste Teste de De contagem Contagem de Palavras palavras teste";
    std::unordered_map<std::string, int> resultado = contaPalavras(texto);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["Teste"] == 1);
    REQUIRE(resultado["de"] == 2);
    REQUIRE(resultado["De"] == 1);
    REQUIRE(resultado["contagem"] == 1);
    REQUIRE(resultado["Contagem"] == 1);
    REQUIRE(resultado["palavras"] == 1);
    REQUIRE(resultado["Palavras"] == 1);
}

TEST_CASE("Teste 4: contaPalavras desconsidera acentos") {
    std::string texto = "é e a á o ó u ú";	
    std::unordered_map<std::string, int> resultado = contaPalavras(texto);
    REQUIRE(resultado["e"] == 2);
    REQUIRE(resultado["a"] == 2);
    REQUIRE(resultado["o"] == 2);
    REQUIRE(resultado["u"] == 2);
}
