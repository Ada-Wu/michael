// History.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Monitor.h"
#include "History.h"
#include "afxdialogex.h"


// CHistory �Ի���

IMPLEMENT_DYNAMIC(CHistory, CDialogEx)

CHistory::CHistory(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHistory::IDD, pParent)
{

}

CHistory::~CHistory()
{
}

void CHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CTRL_HIS, m_historyLst);
}


BEGIN_MESSAGE_MAP(CHistory, CDialogEx)
END_MESSAGE_MAP()


// CHistory ��Ϣ�������
void CHistory::InitHistoryLst()
{
	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_historyLst.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_historyLst.SetExtendedStyle(m_historyLst.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ����6��   
	m_historyLst.InsertColumn(0, _T("���"), LVCFMT_CENTER, rect.Width() / 10, 0);
	m_historyLst.InsertColumn(1, _T("ASD���"), LVCFMT_CENTER, rect.Width() / 10, 1);
	m_historyLst.InsertColumn(2, _T("λ����Ϣ"), LVCFMT_CENTER, rect.Width() / 5, 2);
	m_historyLst.InsertColumn(3, _T("ʱ��"), LVCFMT_CENTER, rect.Width() / 5, 3);
	m_historyLst.InsertColumn(4, _T("�¼�����"), LVCFMT_CENTER, rect.Width()*2 / 5, 0);
}

BOOL CHistory::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitHistoryLst();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

