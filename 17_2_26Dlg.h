
// 17_2_26Dlg.h : ͷ�ļ�
//

#pragma once


// CMy17_2_26Dlg �Ի���
class CMy17_2_26Dlg : public CDialogEx
{
// ����
public:
	CMy17_2_26Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	BOOL  m_Init_One;
// �Ի�������
	enum { IDD = IDD_MY17_2_26_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
	CRect m_rcClent;			// ���洰�ڴ�С�ı�֮ǰ�Ĵ�С
	CRect m_rcWind;			// ���洰�ڵ���С��С��
	CSize m_sizeClient;		// ���洰�ڵ���С��С��
	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
