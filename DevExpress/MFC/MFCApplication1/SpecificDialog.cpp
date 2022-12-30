#include "SpecificDialog.h"
#include "resource.h"
#include "SphInc/gui/SphEditElement.h"
using namespace sophis::gui;

SpecificDialog::SpecificDialog() : CSRFitDialog()
{
    fResourceId = IDD_MFCAPPLICATION1_DIALOG - ID_DIALOG_SHIFT;
    fElementCount = 1;
    fElementList = new CSRElement * [fElementCount];
    if (fElementList) 
    {
        fElementList[0] = new CSREditDouble(this, IDC_EDIT1 -ID_ITEM_SHIFT, 2, 0, 1000000000., 10.0);
    } 
}