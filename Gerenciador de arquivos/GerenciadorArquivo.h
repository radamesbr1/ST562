#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>

#ifndef GERENCIADORARQUIVO_H
#define GERENCIADORARQUIVO_H

using namespace std;

class GerenciadorArquivo {
public:
    GerenciadorArquivo();
    GerenciadorArquivo(const GerenciadorArquivo& orig);
    virtual ~GerenciadorArquivo();
    
    public list<string> camposArquivos;
    
        
    void GerenciadordeArquivos(string caminhoArquivo);
    bool carregarArquivo();
    bool gerarChavePrimaria();
    bool gerarIndiceSecundarioArquivo(string _field);
    string normatiza(string _field, int _maxNum);
    list<string, string> FindByPkBin(string _pk);//pesquisa pela chave primaria usando busca binaria
    list<string, string> FindBySKSeq(string _column, string _sk);
    bool deleteRegistro(string _pk);
    int tamanhoRegistro(list<string, string> _reg);
    bool EspacoVazioFile();
    bool AdicionarRegistroVazio(list<string, string> _reg);
    
private:
    string caminhoArquivo;
    char separadorCampos = '|';
    char fimRegistro = '#';
    bool finalArquivo = false;
    int tamanhoCampoChaveSecundaria = 20;
    
    list<string, string> nextReg();
    string proximoCampo();
    bool CarregarCampos();
    bool VerificaRegDeletado(list<string, string> _reg);
    int indiceChavePrimaria(string _pk);
    
    

};

#endif /* GERENCIADORARQUIVO_H */

