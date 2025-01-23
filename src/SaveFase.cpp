#include "../include/SaveFase.h"
using namespace Fases;
SaveFase::SaveFase(States::StateMachine* pSm) :
	Fase(pSm, States::StateType::STATE_SAVE_FASE)
{
			CriarCenario();	
}
SaveFase::~SaveFase(){

}
