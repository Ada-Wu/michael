// PrjConf.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Monitor.h"
#include "PrjConf.h"
#include "afxdialogex.h"


// CPrjConf �Ի���

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


// CPrjConf ��Ϣ�������


BOOL CPrjConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
