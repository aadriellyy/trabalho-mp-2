//começa com teste vazio

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// Função auxiliar para criar arquivos de teste
void criarArquivoTeste(const std::string& nomeArquivo, const std::string& conteudo) {
    std::ofstream arquivo(nomeArquivo);
    arquivo << conteudo;
    arquivo.close();
}

std::vector<std::pair<std::string, int>> converterParaVetorOrdenado(const std::map<std::string, int>& mapa) {
    std::vector<std::pair<std::string, int>> vetor(mapa.begin(), mapa.end());
    std::sort(vetor.begin(), vetor.end());
    return vetor;
}

TEST_CASE("Teste 1: contaPalavras retorna vazio para texto vazio") {
    std::string nomeArquivo = "teste1.txt";
    std::string conteudo = "";
    criarArquivoTeste(nomeArquivo, conteudo);
    
    std::map<std::string, int> resultado = contaPalavras(lerArquivo(nomeArquivo));
    REQUIRE(resultado.empty());
}

TEST_CASE("Teste 2: contaPalavras separa e conta corretamente") {
    std::string nomeArquivo = "teste2.txt";
    std::string conteudo = "teste de contagem de palavras teste";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(lerArquivo(nomeArquivo));
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["de"] == 2);
    REQUIRE(resultado["contagem"] == 1);
    REQUIRE(resultado["palavras"] == 1);
}

TEST_CASE("Teste 3: contaPalavras diferencia maiusculas e minusculas") {
    std::string nomeArquivo = "teste3.txt";
    std::string conteudo = "teste Teste de De contagem Contagem de Palavras palavras teste";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(lerArquivo(nomeArquivo));
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

    std::map<std::string, int> resultado = contaPalavras(lerArquivo(nomeArquivo));
    REQUIRE(resultado["e"] == 2);
    REQUIRE(resultado["a"] == 2);
    REQUIRE(resultado["o"] == 2);
    REQUIRE(resultado["u"] == 2);
}

TEST_CASE("Teste 5: separação de palavras"){
    std::string nomeArquivo = "teste5.txt";
    std::string conteudo = "teste contagem";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(lerArquivo(nomeArquivo));
    REQUIRE(resultado.size() == 2);
    REQUIRE(resultado["teste"] == 1);
    REQUIRE(resultado["contagem"] == 1);
}

TEST_CASE("Teste 6: desconsidera caracteres especiais"){
    std::string nomeArquivo = "teste6.txt";
    std::string conteudo = "teste, contagem. contagem teste!";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(lerArquivo(nomeArquivo));
    REQUIRE(resultado.size() == 2);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["contagem"] == 2);
}

TEST_CASE("Teste 7: verificar ordem alfabetica das palavras com indices") {
    std::string nomeArquivo = "teste8.txt";
    std::string conteudo = "este é um exemplo de texto para testar a ordenação de palavras";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::string texto = lerArquivo(nomeArquivo);
    auto resultado = contaPalavras(texto);
    auto vetorResultado = converterParaVetorOrdenado(resultado);
    REQUIRE(vetorResultado.size() == 8);
    REQUIRE(vetorResultado[0].first == "de");
    REQUIRE(vetorResultado[1].first == "exemplo");
    REQUIRE(vetorResultado[2].first == "este");
    REQUIRE(vetorResultado[3].first == "para");
    REQUIRE(vetorResultado[4].first == "palavras");
    REQUIRE(vetorResultado[5].first == "ordenacao");
    REQUIRE(vetorResultado[6].first == "testar");
    REQUIRE(vetorResultado[7].first == "texto");
}

