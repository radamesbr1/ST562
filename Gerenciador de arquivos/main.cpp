/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: p157018
 *
 * Created on 9 de Junho de 2016, 13:51
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "GerenciadorArquivo.h"
using namespace std;

/*
 * 
 */
int main() {
    
    char caminho[100];
    cout << "Digite o nome do arquivo a ser lido: ";
    cin >> caminho;
    
    GerenciadorArquivo arquivo(caminho);
    
    
    
    int sair =0;
    
    while(sair !=7){
       cout <<("SEJA BEM VINDO AO SEU GERENCIADOR DE ARQUIVOS!\n") << endl; 
       cout<<"1 - busca por chave primaria   "<<endl;
       cout<<"2 - busca por chave secundaria "<<endl;
       cout<<"3 - inclusao                   "<<endl;
       cout<<"4 - remocao                    "<<endl;
       cout<<"5 - lista de espacos vazios    "<<endl;
       cout<<"6 - sair			     "<<endl;
       cin>>sair;
       
       switch(sair){
       
           case 6:{
           cout << ("OBRIGADO POR USAR A AGENDA DE COMPROMISSOS!\n") << endl;
	   sair=7;
           break;
			}
           default:
            cout<<"opção invalida"<<endl;
            cout<<endl;
       
       }
    }
    return 0;
}

