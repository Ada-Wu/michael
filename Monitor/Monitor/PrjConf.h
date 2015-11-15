#pragma once


// CPrjConf 对话框

class CPrjConf : public CDialogEx
{
	DECLARE_DYNAMIC(CPrjConf)

public:
	CPrjConf(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPrjConf();

// 对话框数据
	enum { IDD = IDD_PRJCONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
