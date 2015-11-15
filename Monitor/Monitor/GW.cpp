// GW.cpp : 实现文件
//

#include "stdafx.h"
#include "Monitor.h"
#include "GW.h"
#include "afxdialogex.h"


// CGW 对话框

IMPLEMENT_DYNAMIC(CGW, CDialogEx)

CGW::CGW(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGW::IDD, pParent)
{

}

CGW::~CGW()
{
}

void CGW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGW, CDialogEx)
END_MESSAGE_MAP()


// CGW 消息处理程序


BOOL CGW::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
