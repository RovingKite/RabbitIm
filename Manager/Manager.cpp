#include "Manager.h"
#include "ManageMessageDialogBigScreen.h"

CManager::CManager()    
{
}

CManager::~CManager()
{
}

QSharedPointer<CManageMessageDialog> CManager::GetManageMessageDialog()
{
#ifdef MOBILE
    static QSharedPointer<CManageMessageDialog> manageMessageDialog(new CManageMessageDialog);
#else
    static QSharedPointer<CManageMessageDialog> manageMessageDialog(new CManageMessageDialogBigScreen);
#endif
    return manageMessageDialog;
}

int CManager::Init(const QString &szId)
{
    GetManageUser()->Init(szId);
    GetManageMessageDialog()->Init(szId);
    return 0;
}

int CManager::Clean()
{
        GetManageUser()->Clean();
        GetManageMessageDialog()->Clean();
        return 0;
}
