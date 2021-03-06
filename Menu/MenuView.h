
// MenuView.h : interface of the CMenuView class
//

#pragma once


class CMenuView : public CView
{
protected: // create from serialization only
	CMenuView() noexcept;
	DECLARE_DYNCREATE(CMenuView)

// Attributes
public:
	CMenuDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	COLORREF m_color;
	int m_pen;
	int m_width;
	afx_msg void OnDeseneRectangle();
	afx_msg void OnDeseneEllipse();
	afx_msg void OnDeseneProperties();
};

#ifndef _DEBUG  // debug version in MenuView.cpp
inline CMenuDoc* CMenuView::GetDocument() const
   { return reinterpret_cast<CMenuDoc*>(m_pDocument); }
#endif

