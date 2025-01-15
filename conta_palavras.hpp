#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <string>
#include <map>
#include <vector>


std::map<std::string, int> contaPalavras(const std::string& nomeArquivo);
std::string removerAcentos(const std::string& str);
std::string removerCaracteresEspeciais(const std::string& str);
std::string lerArquivo(const std::string& nomeArquivo);
std::vector<std::string> ordenarPalavras(const std::vector<std::string>& palavras);
std::vector<std::string> converterParaVetorOrdenado(const std::map<std::string, int>& mapa);


#endif // CONTA_PALAVRAS_HPP