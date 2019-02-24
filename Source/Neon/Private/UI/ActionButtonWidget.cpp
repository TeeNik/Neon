#include "ActionButtonWidget.h"
#include "Action/ActionTableData.h"
#include "Engine/Texture2D.h"
#include "Components/Image.h"
#include "UI/ActionButton.h"

void UActionButtonWidget::SetWidgetData(FActionTableData* data)
{
	Data = data;
	Icon->SetBrushFromTexture(data->Icon);
	ActionButton->SetButtonData(data);
}
