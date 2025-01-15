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

TEST_CASE("Teste 1: contaPalavras retorna vazio para texto vazio") {
    std::string nomeArquivo = "teste1.txt";
    std::string conteudo = "";
    criarArquivoTeste(nomeArquivo, conteudo);
    
    std::map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado.empty());
}

TEST_CASE("Teste 2: contaPalavras separa e conta corretamente") {
    std::string nomeArquivo = "teste2.txt";
    std::string conteudo = "teste de contagem de palavras teste";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["de"] == 2); 
    REQUIRE(resultado["contagem"] == 1);
    REQUIRE(resultado["palavras"] == 1);
}

TEST_CASE("Teste 3: contaPalavras diferencia maiusculas e minusculas") {
    std::string nomeArquivo = "teste3.txt";
    std::string conteudo = "teste Teste de De contagem Contagem de Palavras palavras teste";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(nomeArquivo);
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

    std::map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado["e"] == 2); 
    REQUIRE(resultado["a"] == 2); 
    REQUIRE(resultado["o"] == 2); 
    REQUIRE(resultado["u"] == 2); 

}

TEST_CASE("Teste 5: separação de palavras"){
    std::string nomeArquivo = "teste5.txt";
    std::string conteudo = "teste contagem";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado.size() == 2);
    REQUIRE(resultado["teste"] == 1);
    REQUIRE(resultado["contagem"] == 1);
}

TEST_CASE("Teste 6: desconsidera caracteres especiais"){
    std::string nomeArquivo = "teste6.txt";
    std::string conteudo = "teste, contagem. contagem teste!";
    criarArquivoTeste(nomeArquivo, conteudo);

    std::map<std::string, int> resultado = contaPalavras(nomeArquivo);
    REQUIRE(resultado.size() == 2);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["contagem"] == 2);
}

TEST_CASE("Teste 7: verificar ordem alfabetica das palavras com indices") {
    std::string nomeArquivo = "teste7.txt"; 
    std::string conteudo = "este é um exemplo de texto para testar a ordenação de palavras";
    criarArquivoTeste(nomeArquivo, conteudo);

    //std::string texto = lerArquivo(nomeArquivo);
    auto resultado = contaPalavras(nomeArquivo);
    auto vetorResultado = ordenarPalavras(converterParaVetorOrdenado(resultado));
    REQUIRE(vetorResultado.size() == 11);
    REQUIRE(vetorResultado[0] == "a");
    REQUIRE(vetorResultado[1] == "de");
    REQUIRE(vetorResultado[2] == "e");
    REQUIRE(vetorResultado[3] == "este");
    REQUIRE(vetorResultado[4] == "exemplo");
    REQUIRE(vetorResultado[5] == "ordenacao");
    REQUIRE(vetorResultado[6] == "palavras");
    REQUIRE(vetorResultado[7] == "para");
    REQUIRE(vetorResultado[8] == "testar");
    REQUIRE(vetorResultado[9] == "texto");
}

TEST_CASE("Teste 8: verificar ordem alfabetica das palavras com indices - diferenciando entre maiuscula e minuscula") {
    std::string nomeArquivo = "teste8.txt"; 
    std::string conteudo = "este é um exemplo Exemplo de texto para testar a A ordenação de palavras";
    criarArquivoTeste(nomeArquivo, conteudo);

    //std::string texto = lerArquivo(nomeArquivo);
    auto resultado = contaPalavras(nomeArquivo);
    auto vetorResultado = ordenarPalavras(converterParaVetorOrdenado(resultado));
    REQUIRE(vetorResultado.size() == 13);
    REQUIRE(vetorResultado[0] == "A");
    REQUIRE(vetorResultado[1] == "a");
    REQUIRE(vetorResultado[2] == "de");
    REQUIRE(vetorResultado[3] == "e");
    REQUIRE(vetorResultado[4] == "este");
    REQUIRE(vetorResultado[5] == "Exemplo");
    REQUIRE(vetorResultado[6] == "exemplo");
    REQUIRE(vetorResultado[7] == "ordenacao");
    REQUIRE(vetorResultado[8] == "palavras");
    REQUIRE(vetorResultado[9] == "para");
    REQUIRE(vetorResultado[10] == "testar");
    REQUIRE(vetorResultado[11] == "texto");
}

TEST_CASE("Teste 9: ordenar e tratar caracteres especiais") {
    std::string nomeArquivo = "teste9.txt"; 
    std::string conteudo = "este é um exemplo.... Exemplo,, de texto, para testar$ a A! ordenação? de palavras:";
    criarArquivoTeste(nomeArquivo, conteudo);

    //std::string texto = lerArquivo(nomeArquivo);
    auto resultado = contaPalavras(nomeArquivo);
    auto vetorResultado = ordenarPalavras(converterParaVetorOrdenado(resultado));
    REQUIRE(vetorResultado.size() == 13);
    REQUIRE(vetorResultado[0] == "A");
    REQUIRE(vetorResultado[1] == "a");
    REQUIRE(vetorResultado[2] == "de");
    REQUIRE(vetorResultado[3] == "e");
    REQUIRE(vetorResultado[4] == "este");
    REQUIRE(vetorResultado[5] == "Exemplo");
    REQUIRE(vetorResultado[6] == "exemplo");
    REQUIRE(vetorResultado[7] == "ordenacao");
    REQUIRE(vetorResultado[8] == "palavras");
    REQUIRE(vetorResultado[9] == "para");
    REQUIRE(vetorResultado[10] == "testar");
    REQUIRE(vetorResultado[11] == "texto");
}

TEST_CASE("Teste 10: verificar contagem e ordenação de palavras com hífens") {
    std::string nomeArquivo = "teste12.txt"; 
    std::string conteudo = "palavra-chave palavra-chave palavra chave palavra-chave";
    criarArquivoTeste(nomeArquivo, conteudo);

    auto resultado = contaPalavras(nomeArquivo);
    auto vetorResultado = ordenarPalavras(converterParaVetorOrdenado(resultado));
    
    REQUIRE(vetorResultado.size() == 2);
    REQUIRE(vetorResultado[0] == "chave");
    REQUIRE(vetorResultado[1] == "palavra-chave");

    REQUIRE(resultado["palavra-chave"] == 3);
    REQUIRE(resultado["chave"] == 1);
}