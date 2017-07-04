
// 17_2_26Dlg.h : 头文件
//

#pragma once


// CMy17_2_26Dlg 对话框
class CMy17_2_26Dlg : public CDialogEx
{
// 构造
public:
	CMy17_2_26Dlg(CWnd* pParent = NULL);	// 标准构造函数
	BOOL  m_Init_One;
// 对话框数据
	enum { IDD = IDD_MY17_2_26_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
	CRect m_rcClent;			// 保存窗口大小改变之前的大小
	CRect m_rcWind;			// 保存窗口的最小大小。
	CSize m_sizeClient;		// 保存窗口的最小大小。
	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};
