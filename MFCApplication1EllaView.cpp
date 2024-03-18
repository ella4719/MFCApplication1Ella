
// MFCApplication1EllaView.cpp: CMFCApplication1EllaView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1Ella.h"
#endif

#include "MFCApplication1EllaDoc.h"
#include "MFCApplication1EllaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1EllaView

IMPLEMENT_DYNCREATE(CMFCApplication1EllaView, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1EllaView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication1EllaView 생성/소멸

CMFCApplication1EllaView::CMFCApplication1EllaView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication1EllaView::~CMFCApplication1EllaView()
{
}

BOOL CMFCApplication1EllaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1EllaView 그리기

void CMFCApplication1EllaView::OnDraw(CDC* pDC)
{
	CMFCApplication1EllaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(10, 10, m_strWindowSize);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	pDC->TextOut(m_ptMouseMove.x+ 20, m_ptMouseMove.y, m_strMouseMove);
}


// CMFCApplication1EllaView 인쇄

BOOL CMFCApplication1EllaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1EllaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1EllaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication1EllaView 진단

#ifdef _DEBUG
void CMFCApplication1EllaView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1EllaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1EllaDoc* CMFCApplication1EllaView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1EllaDoc)));
	return (CMFCApplication1EllaDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1EllaView 메시지 처리기


void CMFCApplication1EllaView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_strWindowSize.Format(_T("윈도우 크기는 넓이 %d, 높이 %d입니다."), cx, cy);
	//화면 갱신
	Invalidate();
}



void CMFCApplication1EllaView::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_strOutput = _T("오른쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}



void CMFCApplication1EllaView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = TRUE;
	m_strOutput = _T("왼쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1EllaView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("키보드를 눌렀습니다.");
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCApplication1EllaView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE)
	{
		m_strOutput = _T("마우스를 드래그하고 있습니다.");
		
		
	}
	else
	{
		m_strOutput = _T("마우스르 이동 중 입니다.");
		m_ptMouseMove = point;
		m_strMouseMove.Format(_T("X:%d, Y:%d"), point.x, point.y);
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication1EllaView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = FALSE;
	CView::OnLButtonUp(nFlags, point);
}
