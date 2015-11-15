// SndCho.cpp : 实现文件
//

#include "stdafx.h"
#include "Monitor.h"
#include "SndCho.h"
#include "afxdialogex.h"


// CSndCho 对话框

IMPLEMENT_DYNAMIC(CSndCho, CDialogEx)

CSndCho::CSndCho(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSndCho::IDD, pParent)
{

}

CSndCho::~CSndCho()
{
}

void CSndCho::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSndCho, CDialogEx)
END_MESSAGE_MAP()


// CSndCho 消息处理程序


BOOL CSndCho::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
