
// ButtonTest2View.h : interface of the CButtonTest2View class
//

#pragma once


class CButtonTest2View : public CView
{
protected: // create from serialization only
	CButtonTest2View() noexcept;
	DECLARE_DYNCREATE(CButtonTest2View)

// Attributes
public:
	CButtonTest2Doc* GetDocument() const;

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
	virtual ~CButtonTest2View();
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

#ifndef _DEBUG  // debug version in ButtonTest2View.cpp
inline CButtonTest2Doc* CButtonTest2View::GetDocument() const
   { return reinterpret_cast<CButtonTest2Doc*>(m_pDocument); }
#endif

