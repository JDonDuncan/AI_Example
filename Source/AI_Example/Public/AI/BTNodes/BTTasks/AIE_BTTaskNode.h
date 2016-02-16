// Copyright Jordan Duncan 2016

#pragma once

#include "BehaviorTree/BTTaskNode.h"

// required to access AICharacters and their controllers
#include "AIE_AIController.h"
#include "AIE_BotCharacter.h"
// required to access blackboard keys
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

#include "AIE_BTTaskNode.generated.h"
/**
 *  this is a base class to be used for all our custom BTTaskNodes
 *	Make sure to overide ExecuteTask and call the super to aquire our BehaviorTreeComp, BlackboardComp, AIController, and BotCharacter for child classess
 */
UCLASS()
class AI_EXAMPLE_API UAIE_BTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
public:
	// constructor
	UAIE_BTTaskNode(const FObjectInitializer& ObjectInitializer);
	// execution
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	// owning AI controller
	AAIE_AIController* AIController;
	// owning bot character
	AAIE_BotCharacter* BotCharacter;
	// owning BehaviorTreeComp
	UBehaviorTreeComponent* BehaviorTree;
	// owning blackboard comp
	UBlackboardComponent* Blackboard;
};