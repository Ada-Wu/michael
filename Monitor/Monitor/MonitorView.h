
// MonitorView.h : CMonitorView 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"


class CMonitorView : public CFormView
{
protected: // 仅从序列化创建
	CMonitorView();
	DECLARE_DYNCREATE(CMonitorView)

public:
	enum{ IDD = IDD_MONITOR_FORM };

// 特性
public:
	CMonitorDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMonitorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//afx_msg void OnStnClickedStcDatarv2();
	//afx_msg void OnStnClickedStcDatasrvx7();
	//afx_msg void OnStnClickedStcDatasrvx8();
	//afx_msg void OnStnClickedPicMap();
	afx_msg void OnMenuSrvconf();
	afx_msg void OnMenuGwconf();
	afx_msg void OnMenuPrjconf();
	afx_msg void OnMenuTmchk();
	afx_msg void OnMenuSound();
	afx_msg void OnMenuHistory();
};

#ifndef _DEBUG  // MonitorView.cpp 中的调试版本
inline CMonitorDoc* CMonitorView::GetDocument() const
   { return reinterpret_cast<CMonitorDoc*>(m_pDocument); }
#endif

