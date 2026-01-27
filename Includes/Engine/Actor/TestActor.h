#pragma once

#include "Actor.h"

class WANTED_API TestActor : public Wanted::Actor
{
	//오버라이딩 하는 이유는 다형성 때문에 하게된다.
	//public으로 하게 되면 Actor쪽에서 맘대로 사용가능하게 된다.
	//그래서 protected는 다형성 때문에 가능하다.
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;

};

