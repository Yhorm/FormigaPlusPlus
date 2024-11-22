/**
 * Project Untitled
 */


#pragma once

class Gerenciador_Colisões {
public: 
    
/**
 * @param Obstaculo* po
 */
void incluirObstaculo(void Obstaculo* po);
    
void tratarColisoesJogsObstacs();
    
void tratarColisoresJogsInimgs();
    

private: 
    vector<*Inimigo> LIs;
    list<*Obstaculo> LOs;

};
