#include "Jogo.h"
int main(){

		Jogo jogo;
		while(!jogo.GetJanela()->Acabou()){
				jogo.update();
				jogo.executar();
		}
}
