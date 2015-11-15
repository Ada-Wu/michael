// TimeCheck.cpp : 实现文件
//

#include "stdafx.h"
#include "Monitor.h"
#include "TimeCheck.h"
#include "afxdialogex.h"


// CTimeCheck 对话框

IMPLEMENT_DYNAMIC(CTimeCheck, CDialogEx)

CTimeCheck::CTimeCheck(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTimeCheck::IDD, pParent)
{

}

CTimeCheck::~CTimeCheck()
{
}

void CTimeCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CTRL_TIMECHECK, m_timeCheckLst);
}


BEGIN_MESSAGE_MAP(CTimeCheck, CDialogEx)
END_MESSAGE_MAP()


// CTimeCheck 消息处理程序


BOOL CTimeCheck::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitTimeCheckLst();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
void CTimeCheck::InitTimeCheckLst()
{
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_timeCheckLst.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_timeCheckLst.SetExtendedStyle(m_timeCheckLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加6列   
	m_timeCheckLst.InsertColumn(0, _T("是否校准时间"), LVCFMT_CENTER, rect.Width() / 5, 0);
	m_timeCheckLst.InsertColumn(1, _T("所属数据服务器"), LVCFMT_CENTER, rect.Width() / 5, 1);
	m_timeCheckLst.InsertColumn(2, _T("网关ID"), LVCFMT_CENTER, rect.Width() / 5, 2);
	m_timeCheckLst.InsertColumn(3, _T("网关名称"), LVCFMT_CENTER, rect.Width() *2/5 , 3);
}