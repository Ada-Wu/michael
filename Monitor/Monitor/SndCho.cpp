// SndCho.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Monitor.h"
#include "SndCho.h"
#include "afxdialogex.h"


// CSndCho �Ի���

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


// CSndCho ��Ϣ�������


BOOL CSndCho::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
