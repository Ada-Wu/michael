#pragma once


// CPrjConf �Ի���

class CPrjConf : public CDialogEx
{
	DECLARE_DYNAMIC(CPrjConf)

public:
	CPrjConf(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPrjConf();

// �Ի�������
	enum { IDD = IDD_PRJCONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
