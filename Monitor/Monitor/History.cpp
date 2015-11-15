// History.cpp : 实现文件
//

#include "stdafx.h"
#include "Monitor.h"
#include "History.h"
#include "afxdialogex.h"


// CHistory 对话框

IMPLEMENT_DYNAMIC(CHistory, CDialogEx)

CHistory::CHistory(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHistory::IDD, pParent)
{

}

CHistory::~CHistory()
{
}

void CHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CTRL_HIS, m_historyLst);
}


BEGIN_MESSAGE_MAP(CHistory, CDialogEx)
END_MESSAGE_MAP()


// CHistory 消息处理程序
void CHistory::InitHistoryLst()
{
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_historyLst.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_historyLst.SetExtendedStyle(m_historyLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加6列   
	m_historyLst.InsertColumn(0, _T("序号"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_historyLst.InsertColumn(1, _T("ASD编号"), LVCFMT_CENTER, rect.Width() / 10, 1);
	m_historyLst.InsertColumn(2, _T("位置信息"), LVCFMT_CENTER, rect.Width() / 5, 2);
	m_historyLst.InsertColumn(3, _T("时间"), LVCFMT_CENTER, rect.Width() / 5, 3);
	m_historyLst.InsertColumn(4, _T("事件类型"), LVCFMT_CENTER, rect.Width()*2 / 5, 0);
}

BOOL CHistory::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitHistoryLst();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

