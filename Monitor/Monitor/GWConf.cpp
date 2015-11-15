// GWConf.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Monitor.h"
#include "GWConf.h"
#include "afxdialogex.h"


// CGWConf �Ի���

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

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_gwLst.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_gwLst.SetExtendedStyle(m_gwLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ����6��   
	m_gwLst.InsertColumn(0, _T("ѡ��"), LVCFMT_CENTER, rect.Width() / 18, 0);
	m_gwLst.InsertColumn(1, _T("�������ݷ�����"), LVCFMT_CENTER, rect.Width() * 2 / 9, 0);
	m_gwLst.InsertColumn(2, _T("��������"), LVCFMT_CENTER, rect.Width() * 2 / 9, 0);
	m_gwLst.InsertColumn(3, _T("����ID"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_gwLst.InsertColumn(4, _T("�û���"), LVCFMT_CENTER, rect.Width()  / 10, 0);
	m_gwLst.InsertColumn(5, _T("����"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_gwLst.InsertColumn(6, _T("��֤״̬"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_gwLst.InsertColumn(7, _T("����״̬"), LVCFMT_CENTER, rect.Width()/ 10, 0);
}

BEGIN_MESSAGE_MAP(CGWConf, CDialogEx)
END_MESSAGE_MAP()


// CGWConf ��Ϣ�������


BOOL CGWConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitGwLst();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
