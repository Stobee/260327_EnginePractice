#pragma once
#include "Component.h"
#include "RenderableComponent.h"

class UMovementComponent : public UComponent, public IRenderableComponent
{public:
	UMovementComponent();
	virtual ~UMovementComponent();

};

