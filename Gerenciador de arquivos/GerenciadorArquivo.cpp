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
    myfile.close();
    insereFim();
}

bool
GerenciadorArquivo::carregarArquivo() {

    ifstream myfile(caminhoArquivo);
    if (!myfile) {
        cout << "Erro na abertura do arquivo." << endl;
    } else {
        cout << "Arquivo aberto para leitura com sucesso." << endl;
    }
}

bool
GerenciadorArquivo::insereFim() //Identifica quantidade de campos e posição de inicio dos registros.
{

    ifstream myfile(caminhoArquivo);
    char line;
    vector <int> posicao;

    int cpipe = 0, pipe = 0, comparapipe = 0, j = 0;

    if (myfile.is_open()) {
        while (!myfile.eof()) //enquanto end of file for false continua
        {
            myfile.get(line);
            if (cpipe == 0) {
                if (line == '|') {
                    pipe++;
                }
            }
            if (line == '#') {
                cpipe = 1;
                posicao.insert(posicao.end(), myfile.tellg());
            }
        }
    

        myfile.close();

        ifstream myfile(caminhoArquivo);

        for (j = 0; j <= pipe; j++) {

            ofstream index("index" + to_string(j), ios::out);

            for (int i = 0; i < posicao.size(); i++) {
                myfile.seekg(posicao[i]);

                if (i != posicao.size() - 1) {
                    index << i << '|';

                }

                line = 'a';


                while (comparapipe < j) {
                    line = 'a';
                    while (line != '|') {
                        myfile.get(line);
                        if (line == '|') {
                            comparapipe++;
                        }
                    }
                }

                line = 'a';


                while (line != '|') {
                    myfile.get(line);
                    if (line == '|' || (i == posicao.size() - 1)) {
                        line = '|';
                    } else {
                        index << line;
                    }
                }
                index << endl;
                comparapipe = 0;
            }
        }
    }
}

GerenciadorArquivo::~GerenciadorArquivo() {
}