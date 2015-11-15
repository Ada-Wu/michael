
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
#include "GWConf.h"
#include "PrjConf.h"
#include "History.h"
#include "SoundChg.h"
#include "TimeCheck.h"
#include "MainFrm.h"
#include "CommonModule.h"

//extern void InitMapTreeList(int& treeItemId, CString treeNodePath[],
//	CTreeCtrl& mapTreeLst, TV_INSERTSTRUCT& treeCtlItemInfo, HTREEITEM& treeCtlRoot);
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMonitorView

IMPLEMENT_DYNCREATE(CMonitorView, CFormView)

BEGIN_MESSAGE_MAP(CMonitorView, CFormView)
	ON_WM_SIZE()
	ON_COMMAND(ID_MENU_SRVCONF, &CMonitorView::OnMenuSrvconf)
	ON_COMMAND(ID_MENU_GWCONF, &CMonitorView::OnMenuGwconf)
	ON_COMMAND(ID_MENU_PRJCONF, &CMonitorView::OnMenuPrjconf)
	ON_COMMAND(ID_MENU_TMCHK, &CMonitorView::OnMenuTmchk)
	ON_COMMAND(ID_MENU_SOUND, &CMonitorView::OnMenuSound)
	ON_COMMAND(ID_MENU_HISTORY, &CMonitorView::OnMenuHistory)
	ON_NOTIFY(NM_CLICK, IDC_TREE_ADDR, &CMonitorView::OnNMClickMapTreeList)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMonitorView ����/����

CMonitorView::CMonitorView()
	: CFormView(CMonitorView::IDD)
{
	// TODO:  �ڴ˴���ӹ������
	m_curMapPath = "";
	m_curPrjPath = "";
}

CMonitorView::~CMonitorView()
{
	GdiplusShutdown(m_pGdiToken);//ж��gdiplus��
}

void CMonitorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCTRL, m_eventLst);
	DDX_Control(pDX, IDC_TREE_ADDR, m_mapTreeLst);
	DDX_Control(pDX, IDC_PIC_MAP, m_mapPicCtl);
}

BOOL CMonitorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMonitorView::InitEventLst()
{
	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_eventLst.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_eventLst.SetExtendedStyle(m_eventLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ����6��   
	m_eventLst.InsertColumn(0, _T("ʱ��"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_eventLst.InsertColumn(1, _T("����ID"), LVCFMT_CENTER, rect.Width() / 15, 1);
	m_eventLst.InsertColumn(3, _T("�豸ID"), LVCFMT_CENTER, rect.Width() / 15, 2);
	m_eventLst.InsertColumn(4, _T("�豸��Ϣ"), LVCFMT_CENTER, rect.Width() / 3, 3);
	m_eventLst.InsertColumn(5, _T("�¼���Ϣ"), LVCFMT_CENTER, rect.Width() / 3, 4);
	m_eventLst.InsertColumn(6, _T("�¼�����"), LVCFMT_CENTER, rect.Width() / 10, 5);
}


void CMonitorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//��ȡ�ĵ�ָ��
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMonitorDoc *pDoc = (CMonitorDoc*)pFrame->GetActiveDocument();
	ASSERT_VALID(pDoc);

	//��ȡͼƬ�ؼ��ľ�������
	m_mapPicCtl.GetWindowRect(&m_mapRect);//��ȡ�ؼ���λ����Ϣ
	ScreenToClient(m_mapRect);

	InitEventLst();//��ʼ���¼��б�
	
	//���浱ǰ�Ĵ��ڳ��ȺͿ��
	CSize sz = GetTotalSize();
	m_oldWndCx = sz.cx;
	m_oldWndCy = sz.cy;

	//װ��gdiplus��
	GdiplusStartup(&m_pGdiToken, &m_gdiplusStartupInput, NULL);
	InitMapTreeList(FALSE, m_treeItemId, m_treeNodePath, m_mapTreeLst, m_treeCtlItemInfo, m_treeCtlRoot);
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

	float dx_percent = (m_oldWndCx == 0) ? 1 : (float)((float)cx / (float)m_oldWndCx);
	float dy_percent = (m_oldWndCy == 0) ? 1 : (float)((float)cy / (float)m_oldWndCy);

	if (m_oldWndCx){
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

	m_oldWndCx = cx;
	m_oldWndCy = cy;
}


void CMonitorView::OnMenuSrvconf()
{
	// TODO:  �ڴ���������������
	CSrvConf srv_conf;
	srv_conf.DoModal();
}


void CMonitorView::OnMenuGwconf()
{
	// TODO:  �ڴ���������������
	CGWConf gw_conf;
	gw_conf.DoModal();
}


void CMonitorView::OnMenuPrjconf()
{
	// TODO:  �ڴ���������������
	CPrjConf prj_conf;
	prj_conf.DoModal();
}


void CMonitorView::OnMenuTmchk()
{
	// TODO:  �ڴ���������������
	CTimeCheck time_chk;
	time_chk.DoModal();
}


void CMonitorView::OnMenuSound()
{
	// TODO:  �ڴ���������������
	CSoundChg sound_chg;
	sound_chg.DoModal();
}


void CMonitorView::OnMenuHistory()
{
	// TODO:  �ڴ���������������
	CHistory ht;
	ht.DoModal();
}


void CMonitorView::OnNMClickMapTreeList(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CPoint pt = GetCurrentMessage()->pt;
	m_mapTreeLst.ScreenToClient(&pt);  //��������Ļ���꣬ת�������οؼ��Ŀͻ�������
	UINT uFlags = 0;
	CFileFind picFileFind;//Ѱ��ָ���ڵ��µ�ͼƬ·��
	CString picName;//���ڱ���ָ���ڵ��µ�ͼƬ����
	CString picPath;//���ڱ���ָ���ڵ��µ�ͼƬ·��
	HTREEITEM hItem = m_mapTreeLst.HitTest(pt, &uFlags);//Ȼ����������� 
	//m_curMapPath = "";//��ʱ���ͼƬ·��
	//m_curPrjPath = "";//��ʱ��������ļ�·��
	if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//���������������ڽڵ�λ��
	{
		m_mapTreeLst.SelectItem(hItem);
		int nDat = m_mapTreeLst.GetItemData(hItem);//��ȡ�ڵ�ı��
		CString treeItemPath = m_treeNodePath[nDat];//����ͼƬ·��
		m_curTreeItemPath = treeItemPath;//���浱ǰ�ڵ�·��
		treeItemPath += "\\*.*";

		//////////////////////////////////////////////////////////////////////////
		m_curMapPath = "";//��������ݣ��������û������û�б���ͼƬ���ļ���ʱ���м�������ʾ�հ�
		m_curPrjPath = "";
		BOOL flag = picFileFind.FindFile(treeItemPath);//��ʼ����temp�ļ���		
		while (flag)//���map�ļ��������ļ�
		{
			flag = picFileFind.FindNextFile();//ָ���¸��ļ�
			if (picFileFind.IsDots())
			{
				//ÿ���ļ��ж������������������ļ���:
				//(1) .   ��ʾ���ļ����Լ�
				//(2) ..  ��ʾ���ļ��еĸ��ļ����ǵ�ǰĿ¼�����Ǹ�Ŀ¼
				continue;
			}
			else
			{
				if (!picFileFind.IsDirectory())//��ǰ�ļ����Ͳ����ļ��У����й��˲���
				{
					picPath = picFileFind.GetFilePath();//��ȡ�ļ�·��
					picName = picFileFind.GetFileName();//��ȡ�ļ�����
					int pos = picName.Find(_T("."));//�򵽡�.����λ��
					CString fileExtension = picName.Right(picName.GetLength() - pos - 1);//��ȡ�ļ���չ��
					char *pa = (char*)((LPCTSTR)fileExtension);
					//if (strcmp(pa, "bmp") == 0 || strcmp(pa, "JPG") == 0 || strcmp(pa, "jpg") == 0 || strcmp(pa, "JPEG") == 0 || strcmp(pa, "jpeg") == 0)//����ļ���չ��Ϊ��bmp����JPG����jpg��
					if (fileExtension == "bmp" || fileExtension == "jpg" || fileExtension == "JPEG" || fileExtension == "jpeg")
						m_curMapPath = picPath;//����ͼƬ·��

					if (strcmp(pa, "prj") == 0)//������ļ�����չ��Ϊ��prj��
					{
						m_curPrjPath = picPath;//���������ļ�·��
						CFile file;
						BOOL fileret = file.Open(m_curPrjPath, CStdioFile::modeRead);//��ȡ�����ļ�������
						if (fileret)//���ļ�
						{
							file.SeekToBegin();	//�����ļ�ָ�뵽�ļ��Ŀ�ʼ��
							CArchive ar(&file, CArchive::load);
							pDoc->Serialize(ar);//���л��ļ���ȡ
							ar.Abort();
							file.Close();
						}
					}
				}
			}
		}
		picFileFind.Close();
	}
	
	this->InvalidateRect(&m_mapRect, FALSE);		//ˢ��ָ������
}

//void CMonitorView::DisplayCurMap(CString curMapPath)
//{
//	if (!curMapPath.IsEmpty())//��ǰ��ͼ·���ǿգ������û�����Ľڵ�·���´���ͼƬ
//	{
//		CRect pic;
//		m_mapPicCtl.GetWindowRect(&pic);//��ȡIDC_MAP�ؼ���������
//		ScreenToClient(&pic);//���������껻Ϊ�ͻ�������
//
//		BSTR str = curMapPath.AllocSysString();//�����ַ����ռ�
//		Image image(str);
//		CDC* hdc = GetDC();
//		Graphics imgraphics(hdc->m_hDC);
//		//5�������ֱ��ʾ��(1)ͼƬ·����(2)�������ꣻ(3)��������ꣻ(4)��ȣ�(5)�߶�
//		imgraphics.DrawImage(&image, pic.left, pic.top, pic.right - pic.left, pic.bottom - pic.top);
//		SysFreeString(str);
//		ReleaseDC(hdc);
//	}
//}

void CMonitorView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFormView::OnPaint()
	CDC* pCDC = GetDC();
	DisplayCurMap(this->m_hWnd, pCDC, m_curMapPath, m_mapRect);
	ReleaseDC(pCDC);
}
