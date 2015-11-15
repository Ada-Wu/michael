
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

// CMonitorView 构造/析构

CMonitorView::CMonitorView()
	: CFormView(CMonitorView::IDD)
{
	// TODO:  在此处添加构造代码
	m_curMapPath = "";
	m_curPrjPath = "";
}

CMonitorView::~CMonitorView()
{
	GdiplusShutdown(m_pGdiToken);//卸载gdiplus库
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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMonitorView::InitEventLst()
{
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_eventLst.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_eventLst.SetExtendedStyle(m_eventLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加6列   
	m_eventLst.InsertColumn(0, _T("时间"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_eventLst.InsertColumn(1, _T("网关ID"), LVCFMT_CENTER, rect.Width() / 15, 1);
	m_eventLst.InsertColumn(3, _T("设备ID"), LVCFMT_CENTER, rect.Width() / 15, 2);
	m_eventLst.InsertColumn(4, _T("设备信息"), LVCFMT_CENTER, rect.Width() / 3, 3);
	m_eventLst.InsertColumn(5, _T("事件信息"), LVCFMT_CENTER, rect.Width() / 3, 4);
	m_eventLst.InsertColumn(6, _T("事件类型"), LVCFMT_CENTER, rect.Width() / 10, 5);
}


void CMonitorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//获取文档指针
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMonitorDoc *pDoc = (CMonitorDoc*)pFrame->GetActiveDocument();
	ASSERT_VALID(pDoc);

	//获取图片控件的矩形区域
	m_mapPicCtl.GetWindowRect(&m_mapRect);//获取控件的位置信息
	ScreenToClient(m_mapRect);

	InitEventLst();//初始化事件列表
	
	//保存当前的窗口长度和宽度
	CSize sz = GetTotalSize();
	m_oldWndCx = sz.cx;
	m_oldWndCy = sz.cy;

	//装载gdiplus库
	GdiplusStartup(&m_pGdiToken, &m_gdiplusStartupInput, NULL);
	InitMapTreeList(FALSE, m_treeItemId, m_treeNodePath, m_mapTreeLst, m_treeCtlItemInfo, m_treeCtlRoot);
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
	// TODO:  在此添加命令处理程序代码
	CSrvConf srv_conf;
	srv_conf.DoModal();
}


void CMonitorView::OnMenuGwconf()
{
	// TODO:  在此添加命令处理程序代码
	CGWConf gw_conf;
	gw_conf.DoModal();
}


void CMonitorView::OnMenuPrjconf()
{
	// TODO:  在此添加命令处理程序代码
	CPrjConf prj_conf;
	prj_conf.DoModal();
}


void CMonitorView::OnMenuTmchk()
{
	// TODO:  在此添加命令处理程序代码
	CTimeCheck time_chk;
	time_chk.DoModal();
}


void CMonitorView::OnMenuSound()
{
	// TODO:  在此添加命令处理程序代码
	CSoundChg sound_chg;
	sound_chg.DoModal();
}


void CMonitorView::OnMenuHistory()
{
	// TODO:  在此添加命令处理程序代码
	CHistory ht;
	ht.DoModal();
}


void CMonitorView::OnNMClickMapTreeList(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	CPoint pt = GetCurrentMessage()->pt;
	m_mapTreeLst.ScreenToClient(&pt);  //将鼠标的屏幕坐标，转换成树形控件的客户区坐标
	UINT uFlags = 0;
	CFileFind picFileFind;//寻找指定节点下的图片路径
	CString picName;//用于保存指定节点下的图片名称
	CString picPath;//用于保存指定节点下的图片路径
	HTREEITEM hItem = m_mapTreeLst.HitTest(pt, &uFlags);//然后做点击测试 
	//m_curMapPath = "";//暂时清空图片路径
	//m_curPrjPath = "";//暂时清空配置文件路径
	if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//如果点击的坐标是在节点位置
	{
		m_mapTreeLst.SelectItem(hItem);
		int nDat = m_mapTreeLst.GetItemData(hItem);//获取节点的编号
		CString treeItemPath = m_treeNodePath[nDat];//保存图片路径
		m_curTreeItemPath = treeItemPath;//保存当前节点路径
		treeItemPath += "\\*.*";

		//////////////////////////////////////////////////////////////////////////
		m_curMapPath = "";//先清空数据，这样当用户点击到没有保存图片的文件夹时，中间区域显示空白
		m_curPrjPath = "";
		BOOL flag = picFileFind.FindFile(treeItemPath);//开始遍历temp文件夹		
		while (flag)//如果map文件夹下有文件
		{
			flag = picFileFind.FindNextFile();//指向下个文件
			if (picFileFind.IsDots())
			{
				//每个文件夹都有下面两个特殊子文件夹:
				//(1) .   表示本文件夹自己
				//(2) ..  表示本文件夹的父文件夹是当前目录或者是父目录
				continue;
			}
			else
			{
				if (!picFileFind.IsDirectory())//当前文件类型不是文件夹，进行过滤操作
				{
					picPath = picFileFind.GetFilePath();//获取文件路径
					picName = picFileFind.GetFileName();//获取文件名称
					int pos = picName.Find(_T("."));//打到“.”的位置
					CString fileExtension = picName.Right(picName.GetLength() - pos - 1);//获取文件扩展名
					char *pa = (char*)((LPCTSTR)fileExtension);
					//if (strcmp(pa, "bmp") == 0 || strcmp(pa, "JPG") == 0 || strcmp(pa, "jpg") == 0 || strcmp(pa, "JPEG") == 0 || strcmp(pa, "jpeg") == 0)//如果文件扩展名为“bmp”或“JPG”或“jpg”
					if (fileExtension == "bmp" || fileExtension == "jpg" || fileExtension == "JPEG" || fileExtension == "jpeg")
						m_curMapPath = picPath;//保存图片路径

					if (strcmp(pa, "prj") == 0)//如果有文件的扩展名为“prj”
					{
						m_curPrjPath = picPath;//保存配置文件路径
						CFile file;
						BOOL fileret = file.Open(m_curPrjPath, CStdioFile::modeRead);//读取配置文件的内容
						if (fileret)//读文件
						{
							file.SeekToBegin();	//设置文件指针到文件的开始处
							CArchive ar(&file, CArchive::load);
							pDoc->Serialize(ar);//序列化文件读取
							ar.Abort();
							file.Close();
						}
					}
				}
			}
		}
		picFileFind.Close();
	}
	
	this->InvalidateRect(&m_mapRect, FALSE);		//刷新指定区域
}

//void CMonitorView::DisplayCurMap(CString curMapPath)
//{
//	if (!curMapPath.IsEmpty())//当前地图路径非空，表明用户点击的节点路径下存有图片
//	{
//		CRect pic;
//		m_mapPicCtl.GetWindowRect(&pic);//获取IDC_MAP控件窗口坐标
//		ScreenToClient(&pic);//将窗口坐标换为客户区坐标
//
//		BSTR str = curMapPath.AllocSysString();//分配字符串空间
//		Image image(str);
//		CDC* hdc = GetDC();
//		Graphics imgraphics(hdc->m_hDC);
//		//5个参数分别表示：(1)图片路径；(2)起点横坐标；(3)起点纵坐标；(4)宽度；(5)高度
//		imgraphics.DrawImage(&image, pic.left, pic.top, pic.right - pic.left, pic.bottom - pic.top);
//		SysFreeString(str);
//		ReleaseDC(hdc);
//	}
//}

void CMonitorView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CFormView::OnPaint()
	CDC* pCDC = GetDC();
	DisplayCurMap(this->m_hWnd, pCDC, m_curMapPath, m_mapRect);
	ReleaseDC(pCDC);
}
