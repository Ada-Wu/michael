// GWConf.cpp : 实现文件
//

#include "stdafx.h"
#include "Monitor.h"
#include "GWConf.h"
#include "afxdialogex.h"


// CGWConf 对话框

IMPLEMENT_DYNAMIC(CGWConf, CDialogEx)

CGWConf::CGWConf(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGWConf::IDD, pParent)
{

}

CGWConf::~CGWConf()
{
}

void CGWConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCTRL_NGSTATE, m_gwLst);
}

void CGWConf::InitGwLst()
{
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_gwLst.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_gwLst.SetExtendedStyle(m_gwLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加6列   
	m_gwLst.InsertColumn(0, _T("选择"), LVCFMT_CENTER, rect.Width() / 18, 0);
	m_gwLst.InsertColumn(1, _T("所属数据服务器"), LVCFMT_CENTER, rect.Width() * 2 / 9, 0);
	m_gwLst.InsertColumn(2, _T("网关名称"), LVCFMT_CENTER, rect.Width() * 2 / 9, 0);
	m_gwLst.InsertColumn(3, _T("网关ID"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_gwLst.InsertColumn(4, _T("用户名"), LVCFMT_CENTER, rect.Width()  / 10, 0);
	m_gwLst.InsertColumn(5, _T("密码"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_gwLst.InsertColumn(6, _T("验证状态"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_gwLst.InsertColumn(7, _T("运行状态"), LVCFMT_CENTER, rect.Width()/ 10, 0);
}

BEGIN_MESSAGE_MAP(CGWConf, CDialogEx)
END_MESSAGE_MAP()


// CGWConf 消息处理程序


BOOL CGWConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitGwLst();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
