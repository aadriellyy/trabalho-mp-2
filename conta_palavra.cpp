#include "conta_palavras.hpp"
#include <sstream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> contaPalavras(const std::string& texto) {
    std::unordered_map<std::string, int> contagem;
    std::istringstream stream(texto);
    std::string palavra;

    while (stream >> palavra) {
        contagem[palavra]++;
    }

    return contagem;
}