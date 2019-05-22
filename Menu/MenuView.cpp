
// MenuView.cpp : implementation of the CMenuView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Menu.h"
#endif

#include "MenuDoc.h"
#include "MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CPropertiesDlg.h"
#include <stdlib.h> 

// CMenuView

IMPLEMENT_DYNCREATE(CMenuView, CView)

BEGIN_MESSAGE_MAP(CMenuView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMenuView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DESENE_RECTANGLE, &CMenuView::OnDeseneRectangle)
	ON_COMMAND(ID_DESENE_ELLIPSE, &CMenuView::OnDeseneEllipse)
	ON_COMMAND(ID_DESENE_PROPERTIES, &CMenuView::OnDeseneProperties)
END_MESSAGE_MAP()

// CMenuView construction/destruction

CMenuView::CMenuView() noexcept
{
	// TODO: add construction code here
	m_pen = 1;
	m_width = 1;
	m_color = RGB(255, 0, 0);
}

CMenuView::~CMenuView()
{
}

BOOL CMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMenuView drawing

void CMenuView::OnDraw(CDC* /*pDC*/)
{
	CMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMenuView printing


void CMenuView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMenuView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMenuView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMenuView diagnostics

#ifdef _DEBUG
void CMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuDoc* CMenuView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuDoc)));
	return (CMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMenuView message handlers


void CMenuView::OnDeseneRectangle()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CMenuDoc* pDoc = (CMenuDoc*)GetDocument();
	m_color = pDoc->m_crColor;
	CPen pen(m_pen, m_width, m_color);
	dc.SelectObject(&pen);
	dc.Rectangle(10, 10, 200, 200);
}


void CMenuView::OnDeseneEllipse()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CMenuDoc* pDoc = (CMenuDoc*)GetDocument();
	m_color = pDoc->m_crColor;
	CPen pen(m_pen, m_width, m_color);
	dc.SelectObject(&pen);
	dc.Ellipse(10, 10, 200, 200);
}


void CMenuView::OnDeseneProperties()
{
	// TODO: Add your command handler code here
	CPropertiesDlg dlg;
	CString str_pen,str_width;
	int result = dlg.DoModal();
	if (result == IDOK) {
		str_pen = dlg.m_edit1;
		str_width = dlg.m_edit2;
		m_pen = _wtoi(str_pen);
		m_width = _wtoi(str_width);;
	}
}
