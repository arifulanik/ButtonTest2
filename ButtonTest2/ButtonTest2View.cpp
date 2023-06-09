
// ButtonTest2View.cpp : implementation of the CButtonTest2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ButtonTest2.h"
#endif

#include "ButtonTest2Doc.h"
#include "ButtonTest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonTest2View

IMPLEMENT_DYNCREATE(CButtonTest2View, CView)

BEGIN_MESSAGE_MAP(CButtonTest2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CButtonTest2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CButtonTest2View construction/destruction

CButtonTest2View::CButtonTest2View() noexcept
{
	// TODO: add construction code here

}

CButtonTest2View::~CButtonTest2View()
{
}

BOOL CButtonTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CButtonTest2View drawing

void CButtonTest2View::OnDraw(CDC* /*pDC*/)
{
	CButtonTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CButtonTest2View printing


void CButtonTest2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CButtonTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CButtonTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CButtonTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CButtonTest2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CButtonTest2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CButtonTest2View diagnostics

#ifdef _DEBUG
void CButtonTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CButtonTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButtonTest2Doc* CButtonTest2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonTest2Doc)));
	return (CButtonTest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CButtonTest2View message handlers
