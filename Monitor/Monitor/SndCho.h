#pragma once


// CSndCho 对话框

class CSndCho : public CDialogEx
{
	DECLARE_DYNAMIC(CSndCho)

public:
	CSndCho(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSndCho();

// 对话框数据
	enum { IDD = IDD_SOUND_CHOICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
