
// TestSingleDocView.h : interface of the CTestSingleDocView class
//

#pragma once


class CTestSingleDocView : public CView
{
protected: // create from serialization only
	CTestSingleDocView() noexcept;
	DECLARE_DYNCREATE(CTestSingleDocView)

// Attributes
public:
	CTestSingleDocDoc* GetDocument() const;

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
	virtual ~CTestSingleDocView();
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
};

#ifndef _DEBUG  // debug version in TestSingleDocView.cpp
inline CTestSingleDocDoc* CTestSingleDocView::GetDocument() const
   { return reinterpret_cast<CTestSingleDocDoc*>(m_pDocument); }
#endif

