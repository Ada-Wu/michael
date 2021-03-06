#pragma once
#include "afxcmn.h"


// CSrvConf 对话框

class CSrvConf : public CDialogEx
{
	DECLARE_DYNAMIC(CSrvConf)

public:
	CSrvConf(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSrvConf();

// 对话框数据
	enum { IDD = IDD_DSCONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void InitSrvLst();
	CListCtrl m_srvLst;
};
