#include "conta_palavras.hpp"
#include <sstream>
#include <map>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>

// Função para remover acentos de uma string
std::string removerAcentos(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideStr = converter.from_bytes(str);
    std::wstring result;

    for (wchar_t ch : wideStr) {
        switch (ch) {
            case L'à': case L'á': case L'â': case L'ã': case L'ä': ch = L'a'; break;
            case L'è': case L'é': case L'ê': case L'ë': ch = L'e'; break;
            case L'ì': case L'í': case L'î': case L'ï': ch = L'i'; break;
            case L'ò': case L'ó': case L'ô': case L'õ': case L'ö': ch = L'o'; break;
            case L'ù': case L'ú': case L'û': case L'ü': ch = L'u'; break;
            case L'ç': ch = L'c'; break;
            case L'À': case L'Á': case L'Â': case L'Ã': case L'Ä': ch = L'A'; break;
            case L'È': case L'É': case L'Ê': case L'Ë': ch = L'E'; break;
            case L'Ì': case L'Í': case L'Î': case L'Ï': ch = L'I'; break;
            case L'Ò': case L'Ó': case L'Ô': case L'Õ': case L'Ö': ch = L'O'; break;
            case L'Ù': case L'Ú': case L'Û': case L'Ü': ch = L'U'; break;
            case L'Ç': ch = L'C'; break;
            default: break;
        }
        result += ch;
    }

    return converter.to_bytes(result);
}

// Função para remover caracteres especiais de uma string
std::string removerCaracteresEspeciais(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (std::isalnum(ch)) {
            result += ch;
        }
    }
    return result;
}

// Função para contar palavras em um arquivo
std::map<std::string, int> contaPalavras(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::map<std::string, int> contagem;
    std::string palavra;

    while (arquivo >> palavra) {
        palavra = removerAcentos(palavra);
        palavra = removerCaracteresEspeciais(palavra);
        ++contagem[palavra];
    }

    arquivo.close();
    return contagem;
}