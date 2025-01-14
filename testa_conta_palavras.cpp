//começa com teste vazio

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"
//#include "conta_palavra.cpp"
#include <unordered_map>

// Função auxiliar para criar arquivos de teste
void criarArquivoTeste(const std::string& nomeArquivo, const std::string& conteudo) {
    std::ofstream arquivo(nomeArquivo);
    arquivo << conteudo;
    arquivo.close();
}

TEST_CASE("Teste 1: contaPalavras retorna vazio para texto vazio") {
    std::string nomeArquivo = "teste1.txt";
    std::string conteudo = "";
    criarArquivoTeste(nomeArquivo, conteudo);
    
    std::unordered_map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado.empty());
}

TEST_CASE("Teste 2: contaPalavras separa e conta corretamente") {
    std::string nomeArquivo = "teste2.txt";
    std::string conteudo = "teste de contagem de palavras teste";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::unordered_map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["de"] == 2);
    REQUIRE(resultado["contagem"] == 1);
    REQUIRE(resultado["palavras"] == 1);
}

TEST_CASE("Teste 3: contaPalavras diferencia maiusculas e minusculas") {
    std::string nomeArquivo = "teste3.txt";
    std::string conteudo = "teste Teste de De contagem Contagem de Palavras palavras teste";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::unordered_map<std::string, int> resultado = contaPalavras(nomeArquivo);
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
    std::string nomeArquivo = "teste4.txt";
    std::string conteudo = "é e a á o ó u ú";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::unordered_map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado["e"] == 2);
    REQUIRE(resultado["a"] == 2);
    REQUIRE(resultado["o"] == 2);
    REQUIRE(resultado["u"] == 2);
}

TEST_CASE("Teste 5: separação de palavras"){
    std::string nomeArquivo = "teste5.txt";
    std::string conteudo = "teste contagem";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::unordered_map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado.size() == 2);
    REQUIRE(resultado["teste"] == 1);
    REQUIRE(resultado["contagem"] == 1);
}