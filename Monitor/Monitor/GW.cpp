// GW.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Monitor.h"
#include "GW.h"
#include "afxdialogex.h"


// CGW �Ի���

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


// CGW ��Ϣ�������


BOOL CGW::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
