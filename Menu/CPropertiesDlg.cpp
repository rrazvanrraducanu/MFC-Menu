// CPropertiesDlg.cpp : implementation file
//

#include "pch.h"
#include "Menu.h"
#include "CPropertiesDlg.h"
#include "afxdialogex.h"


// CPropertiesDlg dialog

IMPLEMENT_DYNAMIC(CPropertiesDlg, CDialog)

CPropertiesDlg::CPropertiesDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_edit1(_T(""))
	, m_edit2(_T(""))
{

}

CPropertiesDlg::~CPropertiesDlg()
{
}

void CPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(CPropertiesDlg, CDialog)
END_MESSAGE_MAP()


// CPropertiesDlg message handlers
