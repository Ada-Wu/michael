// SrvConf.cpp : 实现文件
//

#include "stdafx.h"
#include "Monitor.h"
#include "SrvConf.h"
#include "afxdialogex.h"


// CSrvConf 对话框

IMPLEMENT_DYNAMIC(CSrvConf, CDialogEx)

CSrvConf::CSrvConf(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSrvConf::IDD, pParent)
{

}

CSrvConf::~CSrvConf()
{
}

void CSrvConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCTRL_NUM, m_srvLst);
}


BEGIN_MESSAGE_MAP(CSrvConf, CDialogEx)
END_MESSAGE_MAP()


// CSrvConf 消息处理程序


BOOL CSrvConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitSrvLst();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CSrvConf::InitSrvLst()
{
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_srvLst.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_srvLst.SetExtendedStyle(m_srvLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加6列   
	m_srvLst.InsertColumn(0, _T("编号"), LVCFMT_RIGHT, rect.Width() / 5, 0);
	m_srvLst.InsertColumn(1, _T("数据服务器地址"), LVCFMT_CENTER, rect.Width() *4/ 5, 1);
}