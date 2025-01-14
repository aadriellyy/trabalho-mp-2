#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <string>
#include <map>

std::map<std::string, int> contaPalavras(const std::string& nomeArquivo);
std::string removerAcentos(const std::string& str);
std::string removerCaracteresEspeciais(const std::string& str);

#endif // CONTA_PALAVRAS_HPP