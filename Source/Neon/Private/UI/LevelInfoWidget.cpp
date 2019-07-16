#include "LevelInfoWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/Spacer.h"
#include "HealthInfoWidget.h"
#include "Components/HorizontalBox.h"

UHealthInfoWidget* ULevelInfoWidget::AddHealthWidget(uint32& id)
{
	const USpacer* spacer1 = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	UHealthInfoWidget* widget = WidgetTree->ConstructWidget<UHealthInfoWidget>(HealthWidgetBP);
	HealthWidgetBox->AddChildToHorizontalBox(widget);
	HealthWidgets.Add(widget);
	widget->SetID(id);
	return widget;
}