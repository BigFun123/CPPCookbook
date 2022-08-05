
// TestSingleDocView.cpp : implementation of the CTestSingleDocView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestSingleDoc.h"
#endif

#include "TestSingleDocDoc.h"
#include "TestSingleDocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestSingleDocView

IMPLEMENT_DYNCREATE(CTestSingleDocView, CView)

BEGIN_MESSAGE_MAP(CTestSingleDocView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestSingleDocView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestSingleDocView construction/destruction

CTestSingleDocView::CTestSingleDocView() noexcept
{
	// TODO: add construction code here

}

CTestSingleDocView::~CTestSingleDocView()
{
}

BOOL CTestSingleDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestSingleDocView drawing

void CTestSingleDocView::OnDraw(CDC* pDC)
{
	CTestSingleDocDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	COLORREF pc = RGB(255, 0, 0);
	CPen pen(PS_SOLID, 2, pc);
	CPen* oldp = pDC->SelectObject(&pen);
	pDC->MoveTo(10, 10);
	pDC->LineTo(100, 100);
	pDC->Arc(100, 100, 120, 120, 30, 30, 40, 40);
	pDC->TextOutW(100, 100, pDoc->sName);
	pDC->SelectObject(oldp);
}


// CTestSingleDocView printing


void CTestSingleDocView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestSingleDocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestSingleDocView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestSingleDocView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestSingleDocView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestSingleDocView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestSingleDocView diagnostics

#ifdef _DEBUG
void CTestSingleDocView::AssertValid() const
{
	CView::AssertValid();
}

void CTestSingleDocView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestSingleDocDoc* CTestSingleDocView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestSingleDocDoc)));
	return (CTestSingleDocDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestSingleDocView message handlers
