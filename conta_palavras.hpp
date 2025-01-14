#ifndef CONTADOR_PALAVRAS_HPP
#define CONTADOR_PALAVRAS_HPP

#include <string>
#include <unordered_map>
#include <vector>

std::string lerArquivoParaString(const std::string& nomeArquivo);
std::unordered_map<std::string, int> contaPalavras(const std::string& texto);  
#endif