// ItemDIALOG.cpp : implementation file
//

#include "stdafx.h"
#include "RuneStone.h"
#include "ItemDIALOG.h"

// *�߰��� ��� ����
#include "RuneStoneDoc.h"
#include "MainFrm.h"
#include "RuneStoneView.h"
#include "LocDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CItemDIALOG dialog


CItemDIALOG::CItemDIALOG(CWnd* pParent /*=NULL*/)
	: CDialog(CItemDIALOG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CItemDIALOG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CItemDIALOG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CItemDIALOG)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CItemDIALOG, CDialog)
	//{{AFX_MSG_MAP(CItemDIALOG)
	ON_WM_CLOSE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CItemDIALOG message handlers

void CItemDIALOG::OnClose() // *���̾�α� �ı���
{
	// *�޸� ��ȯ �� ������ �缳��
	m_pItemMainFrame->m_pItemDlg = NULL;
	DestroyWindow();
	
	delete this;
}

BOOL CItemDIALOG::PreTranslateMessage(MSG* pMsg) // *������ �޽��� �������� �˻�
{
	// *�ش� Ű �޽��� ��ȿȭ
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN)
			return TRUE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

int CItemDIALOG::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CMainFrame *pMainFrm = (CMainFrame*)AfxGetMainWnd();
	CRuneStoneView *pView = (CRuneStoneView*)pMainFrm->GetActiveView();

	// *���� ���̾�α� �ı�
	if(pMainFrm->m_pLocDlg != NULL)
	{
		pView->m_ShowLoc = FALSE;
		pView->m_SelectDlgLoc = -1;	
		pMainFrm->m_pLocDlg->m_pLocMainFrame = NULL;
		pMainFrm->m_pLocDlg->DestroyWindow();
		pMainFrm->m_pLocDlg = NULL;
	}
	
	return 0;
}