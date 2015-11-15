#pragma once


// CGW 对话框

class CGW : public CDialogEx
{
	DECLARE_DYNAMIC(CGW)

public:
	CGW(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGW();

// 对话框数据
	enum { IDD = IDD_GWCONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
