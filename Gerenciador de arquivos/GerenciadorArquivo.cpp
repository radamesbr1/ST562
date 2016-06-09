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


GerenciadorArquivo::GerenciadorArquivo() {
}

GerenciadorArquivo::GerenciadordeArquivos(string caminhoArquivo){
    this->caminhoArquivo= caminhoArquivo;
}

GerenciadorArquivo::carregarArquivo(){
    ofstream myfile;
    myfile=this->caminhoArquivo;
    
    if(ifstream(myfile)){
     cout << "File already exists" << std::endl;
     return false;
    }
    
    
}

GerenciadorArquivo::~GerenciadorArquivo() {
}

