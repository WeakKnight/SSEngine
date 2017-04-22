#include "Controller\FocusMoveController.h"
#include "Object\Pawn.h"

FocusMoveController::~FocusMoveController()
{
}


void FocusMoveController::UpdateController()
{
	if (pawn_)
	{
		focusMovePawn();
	}
}

void FocusMoveController::focusMovePawn()
{
	const float speed = 20.0f;
	if (pawn_ && focusPawn_)
	{
		Vector3 velocity = ((*focusPawn_).GetActorLocation() - (*pawn_).GetActorLocation()).Normalize() * speed;
		(*pawn_).SetActorVelocity(velocity);
	}
}
