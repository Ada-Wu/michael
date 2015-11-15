
// MonitorView.cpp : CMonitorView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMonitorView ����/����

CMonitorView::CMonitorView()
	: CFormView(CMonitorView::IDD)
{
	// TODO:  �ڴ˴���ӹ������

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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMonitorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_ListCtrl.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ��������   
	m_ListCtrl.InsertColumn(0, _T("ʱ��"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_ListCtrl.InsertColumn(1, _T("����ID"), LVCFMT_CENTER, rect.Width() / 15, 1);
	m_ListCtrl.InsertColumn(2, _T("�豸ID"), LVCFMT_CENTER, rect.Width() / 15, 2);
	m_ListCtrl.InsertColumn(2, _T("�豸��Ϣ"), LVCFMT_CENTER, rect.Width() / 3, 3);
	m_ListCtrl.InsertColumn(2, _T("�¼���Ϣ"), LVCFMT_CENTER, rect.Width() / 3, 4);
	m_ListCtrl.InsertColumn(2, _T("�¼�����"), LVCFMT_CENTER, rect.Width() / 10, 5);

	CSize sz = GetTotalSize();
	m_old_cx = sz.cx;

	m_old_cy = sz.cy;
}


// CMonitorView ���

#ifdef _DEBUG
void CMonitorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMonitorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMonitorDoc* CMonitorView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMonitorDoc)));
	return (CMonitorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMonitorView ��Ϣ�������



void CMonitorView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
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
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}
//
//
//void CMonitorView::OnStnClickedStcDatasrvx7()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}
//
//
//void CMonitorView::OnStnClickedStcDatasrvx8()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}
//
//
//void CMonitorView::OnStnClickedPicMap()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


void CMonitorView::OnMenuSrvconf()
{
	// TODO:  �ڴ���������������
	CSrvConf srv;
	srv.DoModal();
}


void CMonitorView::OnMenuGwconf()
{
	// TODO:  �ڴ���������������
	CGW gw;
	gw.DoModal;
}


void CMonitorView::OnMenuPrjconf()
{
	// TODO:  �ڴ���������������
	CPrjConf prj;
	prj.DoModal;
}


void CMonitorView::OnMenuTmchk()
{
	// TODO:  �ڴ���������������
	CTimeCheck tmchk;
	tmchk.DoModal;
}


void CMonitorView::OnMenuSound()
{
	// TODO:  �ڴ���������������
	CSndCho snd;
	snd.DoModal;
}


void CMonitorView::OnMenuHistory()
{
	// TODO:  �ڴ���������������
	CHistory ht;
	ht.DoModal;
}
