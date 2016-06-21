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
        cerr << "Erro na abertura do arquivo." << endl;
    } /*else {
        cout << "Arquivo aberto para leitura com sucesso." << endl;
    }*/
//OBSERVEM QUE AQUI, ESSE TRECHO DE CÓDIGO FUNCIONA
//POSICIONA CURSOR EM UMA DETERMINA POSIÇÃO, REALIZA LEITURA DE 100 (chutei um valor) CARACTERES E MANDA IMPRIMIR
//CERTO? ESSE MESMO CÓDIGO, NO MÉTODO INSEREFIM() NÃO FUNCIONA.    
    myfile.seekg(37, ios::beg);
    char buffer[100];
    myfile.read(buffer, 100);
    buffer[100] = '\0';
    cout << buffer << endl;
    cout << endl << "Fim do Construtor" << endl << endl;

    myfile.close();
    
    insereFim();
}

bool GerenciadorArquivo::insereFim() { //NOME PROVISORIO
    //variaveis
    char c;
    vector <int> posicao;
    int inicio, fim;


    ifstream myfile(caminhoArquivo);
    if (!myfile) {
        cerr << "Erro na abertura do arquivo." << endl;
    }

    myfile.seekg(0, ios::beg); //POSICIONA CURSOR NO COMEÇO DO ARQUIVO

//PERCORRE ARQUIVO, ARMAZENANDO POSIÇÃO (INT) DOS #
    while (!myfile.eof()) {
        myfile.get(c);
        if (c == '#') {
            posicao.insert(posicao.end(), myfile.tellg());
        }
    }

    myfile.seekg(0, ios::beg);
    vector <int>::iterator scan = posicao.begin();

//POSICIONA CURSOR EM CIMA DE UM HASHTAG. CALCULA TAMANHO DO CAMPO. CRIA VETOR DE CHAR. LÊ A QUANTIDADE DE CARACTERES CALCULADA E MANDA EXIBIR
    while (scan != posicao.end()) {

        inicio = *scan;
        //cout << inicio << endl;
        scan++;
        if (scan == posicao.end()) {
            break;
        } else {
            fim = *scan;
            //cout << fim << endl;
            scan--;
//CALCULA TAMANHO DO CAMPO
            int tamanho = fim - inicio;
            //cout << tamanho << endl << endl;
            //myfile.seekg(inicio, ios::beg);
            //char buffer[tamanho];
            //myfile.read(buffer, tamanho);
            //cout << buffer << endl;
//POSICIONA CURSOR EM CIMA DE UM HASHTAG. CRIA VETOR DE CHAR DO TAMANHO CALCULADO. LÊ ARQUVIVO A PARTIR DA POSIÇÃO DO CURSOR, ATÉ FINAL DO TAMANHO CALCULADO
//NÃO FUNCIONA. SENDO MESMO CÓDIGO QUE ESTÁ NO CONSTRUTOR
//TENTEI ALOCAR DINAMICAMENTE CHAR. FIZ VÁRIAS COISAS. NÃO FUNCIONA
            myfile.seekg(inicio, ios::beg);
            char buffer[tamanho];
            myfile.read(buffer, tamanho);
            buffer[tamanho] = '\0';
            cout << buffer << endl;
        }
        scan++;
    }
}

bool GerenciadorArquivo::carregarArquivo() {

    ifstream myfile(caminhoArquivo);
    if (!myfile) {
        cerr << "Erro na abertura do arquivo." << endl;
    } /*else {
        cout << "Arquivo aberto para leitura com sucesso." << endl;
    }*/
}

GerenciadorArquivo::~GerenciadorArquivo() {
}
