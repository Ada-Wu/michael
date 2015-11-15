// PrjConf.cpp : 实现文件
//

#include "stdafx.h"
#include "Monitor.h"
#include "PrjConf.h"
#include "afxdialogex.h"


// CPrjConf 对话框

IMPLEMENT_DYNAMIC(CPrjConf, CDialogEx)

CPrjConf::CPrjConf(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPrjConf::IDD, pParent)
{

}

CPrjConf::~CPrjConf()
{
}

void CPrjConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPrjConf, CDialogEx)
END_MESSAGE_MAP()


// CPrjConf 消息处理程序


BOOL CPrjConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
