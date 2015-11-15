
// MonitorView.cpp : CMonitorView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Monitor.h"
#endif

#include "MonitorDoc.h"
#include "MonitorView.h"
#include "SrvConf.h"
#include "GW.h"
#include "PrjConf.h"
#include "History.h"
#include "SndCho.h"
#include "TimeCheck.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int m_old_cx, m_old_cy;

// CMonitorView

IMPLEMENT_DYNCREATE(CMonitorView, CFormView)

BEGIN_MESSAGE_MAP(CMonitorView, CFormView)
	ON_WM_SIZE()
	//ON_STN_CLICKED(IDC_STC_DATARV2, &CMonitorView::OnStnClickedStcDatarv2)
	//ON_STN_CLICKED(IDC_STC_DATASRVx7, &CMonitorView::OnStnClickedStcDatasrvx7)
	//ON_STN_CLICKED(IDC_STC_DATASRVx8, &CMonitorView::OnStnClickedStcDatasrvx8)
	//ON_STN_CLICKED(IDC_PIC_MAP, &CMonitorView::OnStnClickedPicMap)
	ON_COMMAND(ID_MENU_SRVCONF, &CMonitorView::OnMenuSrvconf)
	ON_COMMAND(ID_MENU_GWCONF, &CMonitorView::OnMenuGwconf)
	ON_COMMAND(ID_MENU_PRJCONF, &CMonitorView::OnMenuPrjconf)
	ON_COMMAND(ID_MENU_TMCHK, &CMonitorView::OnMenuTmchk)
	ON_COMMAND(ID_MENU_SOUND, &CMonitorView::OnMenuSound)
	ON_COMMAND(ID_MENU_HISTORY, &CMonitorView::OnMenuHistory)
END_MESSAGE_MAP()

// CMonitorView 构造/析构

CMonitorView::CMonitorView()
	: CFormView(CMonitorView::IDD)
{
	// TODO:  在此处添加构造代码

}

CMonitorView::~CMonitorView()
{
}

void CMonitorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCTRL, m_ListCtrl);
}

BOOL CMonitorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMonitorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_ListCtrl.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_ListCtrl.InsertColumn(0, _T("时间"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_ListCtrl.InsertColumn(1, _T("网关ID"), LVCFMT_CENTER, rect.Width() / 15, 1);
	m_ListCtrl.InsertColumn(2, _T("设备ID"), LVCFMT_CENTER, rect.Width() / 15, 2);
	m_ListCtrl.InsertColumn(2, _T("设备信息"), LVCFMT_CENTER, rect.Width() / 3, 3);
	m_ListCtrl.InsertColumn(2, _T("事件信息"), LVCFMT_CENTER, rect.Width() / 3, 4);
	m_ListCtrl.InsertColumn(2, _T("事件类型"), LVCFMT_CENTER, rect.Width() / 10, 5);

	CSize sz = GetTotalSize();
	m_old_cx = sz.cx;

	m_old_cy = sz.cy;
}


// CMonitorView 诊断

#ifdef _DEBUG
void CMonitorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMonitorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMonitorDoc* CMonitorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMonitorDoc)));
	return (CMonitorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMonitorView 消息处理程序



void CMonitorView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	if (cx < 800 || cy < 600){
		cx = 800;
		cy = 600;
	}

	float dx_percent = (m_old_cx == 0) ? 1 : (float)((float)cx / (float)m_old_cx);
	float dy_percent = (m_old_cy == 0) ? 1 : (float)((float)cy / (float)m_old_cy);

	if (m_old_cx){
		CRect WndRect;
		CWnd * pWnd = GetWindow(GW_CHILD);;
		while (pWnd){
			pWnd->GetWindowRect(&WndRect);
			ScreenToClient(&WndRect);
			WndRect.left = (int)(WndRect.left*dx_percent);
			WndRect.right = (int)(WndRect.right*dx_percent);
			WndRect.top = (int)(WndRect.top*dy_percent);
			WndRect.bottom = (int)(WndRect.bottom*dy_percent);
			pWnd->MoveWindow(&WndRect);
			pWnd = pWnd->GetWindow(GW_HWNDNEXT);
		}
	}

	m_old_cx = cx;
	m_old_cy = cy;
}


//void CMonitorView::OnStnClickedStcDatarv2()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}
//
//
//void CMonitorView::OnStnClickedStcDatasrvx7()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}
//
//
//void CMonitorView::OnStnClickedStcDatasrvx8()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}
//
//
//void CMonitorView::OnStnClickedPicMap()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}


void CMonitorView::OnMenuSrvconf()
{
	// TODO:  在此添加命令处理程序代码
	CSrvConf srv;
	srv.DoModal();
}


void CMonitorView::OnMenuGwconf()
{
	// TODO:  在此添加命令处理程序代码
	CGW gw;
	gw.DoModal;
}


void CMonitorView::OnMenuPrjconf()
{
	// TODO:  在此添加命令处理程序代码
	CPrjConf prj;
	prj.DoModal;
}


void CMonitorView::OnMenuTmchk()
{
	// TODO:  在此添加命令处理程序代码
	CTimeCheck tmchk;
	tmchk.DoModal;
}


void CMonitorView::OnMenuSound()
{
	// TODO:  在此添加命令处理程序代码
	CSndCho snd;
	snd.DoModal;
}


void CMonitorView::OnMenuHistory()
{
	// TODO:  在此添加命令处理程序代码
	CHistory ht;
	ht.DoModal;
}
