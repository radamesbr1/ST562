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
#include <vector>

#include "GerenciadorArquivo.h"

using namespace std;

GerenciadorArquivo::GerenciadorArquivo(char caminhoArquivo[]) {
    this->caminhoArquivo = caminhoArquivo;

    ifstream myfile(caminhoArquivo);
    if (!myfile) {
        cout << "Erro na abertura do arquivo." << endl;
    } else {
        cout << "Arquivo aberto para leitura com sucesso." << endl;
    }

    insereFim();
}

bool GerenciadorArquivo::carregarArquivo() {

    ifstream myfile(caminhoArquivo);
    if (!myfile) {
        cout << "Erro na abertura do arquivo." << endl;
    } else {
        cout << "Arquivo aberto para leitura com sucesso." << endl;
    }
}

bool GerenciadorArquivo::insereFim() {

    ifstream myfile(caminhoArquivo);
    char line;
    vector <int> posicao;
    if (myfile.is_open()) {
        while (!myfile.eof()) //enquanto end of file for false continua
        {
            myfile.get(line);
            if (line == '#') {
                posicao.insert(posicao.end(), myfile.tellg());
            }
        }

        /*vector<int>::iterator scan = posicao.begin();
        while (scan != posicao.end()) {
            cout << *scan << endl;
            scan++;
        }*/

        for (int i = 0; i < posicao.size(); i++) {
            cout << posicao[i] << endl;
            
        }

        //buffer = getchar();
        //int length = myfile.tellg();
        //cout << buffer << endl;
    }
}

GerenciadorArquivo::~GerenciadorArquivo() {

}
