#pragma once
#include "afxcmn.h"


// CGWConf �Ի���

class CGWConf : public CDialogEx
{
	DECLARE_DYNAMIC(CGWConf)

public:
	CGWConf(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGWConf();

// �Ի�������
	enum { IDD = IDD_GWCONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void InitGwLst();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_gwLst;
	virtual BOOL OnInitDialog();
};
