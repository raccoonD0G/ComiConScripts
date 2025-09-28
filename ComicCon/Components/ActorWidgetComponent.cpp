// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ActorWidgetComponent.h"
#include "Widgets/ComponentWidget.h"

void UActorWidgetComponent::InitWidget()
{
	Super::InitWidget();

	if (GetWidget())
	{
		UComponentWidget* ComponentWidget = Cast<UComponentWidget>(GetWidget());
		ComponentWidget->SetOwningActor(GetOwner());
		ComponentWidget->Init();
	}
}
