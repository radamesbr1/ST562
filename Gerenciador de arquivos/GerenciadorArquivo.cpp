/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GerenciadorArquivo.cpp
 * Author: p157018
 * 
 * Created on 9 de Junho de 2016, 15:48
 */
#include <fstream>
#include <stdio.h>
#include <string>
#include <list>
#include<iostream>

#include "GerenciadorArquivo.h"

using namespace std;


GerenciadorArquivo::GerenciadorArquivo(char caminhoArquivo[]) {
    this->caminhoArquivo = caminhoArquivo;
    
    ifstream myfile (caminhoArquivo);
    if (!myfile){
        cout << "Erro na abertura do arquivo." << endl;
    }
    else{
        cout << "Arquivo aberto para leitura com sucesso." << endl;
    }
}

/*
GerenciadorArquivo::GerenciadordeArquivos(string caminhoArquivo){
    this->caminhoArquivo = caminhoArquivo;
}
*/

bool GerenciadorArquivo::carregarArquivo(){
    
    ifstream myfile (caminhoArquivo);
    if (!myfile){
        cout << "Erro na abertura do arquivo." << endl;
    }
    else{
        cout << "Arquivo aberto para leitura com sucesso." << endl;
    }
    
    //ofstream abre(cria) arquivo para gravar. Correto é ifstream que abre para leitura
    /*ofstream myfile;                
    myfile=this->caminhoArquivo;
    
    if(ifstream(myfile)){
     cout << "File already exists" << std::endl;
     return false;
    }
    */
    
}

GerenciadorArquivo::~GerenciadorArquivo() {
}

