// TimeCheck.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Monitor.h"
#include "TimeCheck.h"
#include "afxdialogex.h"


// CTimeCheck �Ի���

IMPLEMENT_DYNAMIC(CTimeCheck, CDialogEx)

CTimeCheck::CTimeCheck(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTimeCheck::IDD, pParent)
{

}

CTimeCheck::~CTimeCheck()
{
}

void CTimeCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CTRL_TIMECHECK, m_timeCheckLst);
}


BEGIN_MESSAGE_MAP(CTimeCheck, CDialogEx)
END_MESSAGE_MAP()


// CTimeCheck ��Ϣ�������


BOOL CTimeCheck::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitTimeCheckLst();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
void CTimeCheck::InitTimeCheckLst()
{
	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_timeCheckLst.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_timeCheckLst.SetExtendedStyle(m_timeCheckLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ����6��   
	m_timeCheckLst.InsertColumn(0, _T("�Ƿ�У׼ʱ��"), LVCFMT_CENTER, rect.Width() / 5, 0);
	m_timeCheckLst.InsertColumn(1, _T("�������ݷ�����"), LVCFMT_CENTER, rect.Width() / 5, 1);
	m_timeCheckLst.InsertColumn(2, _T("����ID"), LVCFMT_CENTER, rect.Width() / 5, 2);
	m_timeCheckLst.InsertColumn(3, _T("��������"), LVCFMT_CENTER, rect.Width() *2/5 , 3);
}