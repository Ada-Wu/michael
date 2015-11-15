// SrvConf.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Monitor.h"
#include "SrvConf.h"
#include "afxdialogex.h"


// CSrvConf �Ի���

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


// CSrvConf ��Ϣ�������


BOOL CSrvConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitSrvLst();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void CSrvConf::InitSrvLst()
{
	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_srvLst.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_srvLst.SetExtendedStyle(m_srvLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ����6��   
	m_srvLst.InsertColumn(0, _T("���"), LVCFMT_RIGHT, rect.Width() / 5, 0);
	m_srvLst.InsertColumn(1, _T("���ݷ�������ַ"), LVCFMT_CENTER, rect.Width() *4/ 5, 1);
}