#include "../include/Menu.h"
#include "iostream"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>


Menu::Menu(sf::Vector2f pos,int scale){
		if(!fonte.loadFromFile("Fontes/arial.ttf")){
				std::cerr<<"Erro carrengando fonte";
		}
		opc[0].setString("TITULO DO JOGO");
		opc[1].setString("Iniciar");
		opc[2].setString("Salvar");
		opc[3].setString("Sair");
				for(int i=0;i<4;i++){
				opc[i].setFont(fonte);
				opc[i].setCharacterSize(24*scale);
				opc[i].setFillColor(sf::Color::White);
				opc[i].setPosition(-opc[i].getLocalBounds().getSize().x/2.0+pos.x,pos.y+(40*i*scale));
		}
}
Menu::~Menu(){}
void Menu::move(){
}
void Menu::selected(){

}
void Menu::draw(){
		for(int i=0;i<4;i++)
			pGerGraf->draw(opc[i]);
}
void Menu::refresh(){

}
