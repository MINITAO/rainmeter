/* Copyright (C) 2012 Rainmeter Project Developers
 *
 * This Source Code Form is subject to the terms of the GNU General Public
 * License; either version 2 of the License, or (at your option) any later
 * version. If a copy of the GPL was not distributed with this file, You can
 * obtain one at <https://www.gnu.org/licenses/gpl-2.0.html>. */

#ifndef __MOUSE_H__
#define __MOUSE_H__

enum MOUSEACTION
{
	MOUSE_LMB_UP = 0,
	MOUSE_LMB_DOWN,
	MOUSE_LMB_DBLCLK,
	MOUSE_MMB_UP,
	MOUSE_MMB_DOWN,
	MOUSE_MMB_DBLCLK,
	MOUSE_RMB_UP,
	MOUSE_RMB_DOWN,
	MOUSE_RMB_DBLCLK,
	MOUSE_X1MB_UP,
	MOUSE_X1MB_DOWN,
	MOUSE_X1MB_DBLCLK,
	MOUSE_X2MB_UP,
	MOUSE_X2MB_DOWN,
	MOUSE_X2MB_DBLCLK,

	MOUSE_MW_UP,
	MOUSE_MW_DOWN,
	MOUSE_MW_LEFT,
	MOUSE_MW_RIGHT,

	MOUSE_OVER,
	MOUSE_LEAVE,

	MOUSEACTION_COUNT
};

enum MOUSECURSOR
{
	MOUSECURSOR_ARROW,
	MOUSECURSOR_HAND,
	MOUSECURSOR_TEXT,
	MOUSECURSOR_HELP,
	MOUSECURSOR_BUSY,
	MOUSECURSOR_CROSS,
	MOUSECURSOR_PEN,
	MOUSECURSOR_CUSTOM
};

class Mouse
{
public:
	Mouse(Skin* skin, Meter* meter = nullptr);
	~Mouse();

	Mouse(const Mouse& other) = delete;
	Mouse& operator=(Mouse other) = delete;

	void ReadOptions(ConfigParser& parser, const WCHAR* section);

	MOUSECURSOR GetCursorType() const { return m_CursorType; }
	HCURSOR GetCursor() const;
	bool GetCursorState() const {return m_CursorState; }

	void DestroyCustomCursor();

	bool HasActionCommand(MOUSEACTION action) const { return !m_MouseActions[action].empty(); }
	std::wstring GetActionCommand(MOUSEACTION action) const;

	bool HasButtonAction() const
	{
		return !(
			GetLeftUpAction().empty() &&
			GetLeftDownAction().empty() &&
			GetLeftDoubleClickAction().empty() &&
			GetMiddleUpAction().empty() &&
			GetMiddleDownAction().empty() &&
			GetMiddleDoubleClickAction().empty() &&
			GetRightUpAction().empty() &&
			GetRightDownAction().empty() &&
			GetRightDoubleClickAction().empty() &&
			GetX1UpAction().empty() &&
			GetX1DownAction().empty() &&
			GetX1DoubleClickAction().empty() &&
			GetX2UpAction().empty() &&
			GetX2DownAction().empty() &&
			GetX2DoubleClickAction().empty()
			);
	}

	bool HasScrollAction() const
	{
		return !(
			GetMouseScrollUpAction().empty() &&
			GetMouseScrollDownAction().empty() &&
			GetMouseScrollLeftAction().empty() &&
			GetMouseScrollRightAction().empty()
			);
	}

	const std::wstring& GetLeftUpAction() const            { return m_MouseActions[MOUSE_LMB_UP]; }
	const std::wstring& GetLeftDownAction() const          { return m_MouseActions[MOUSE_LMB_DOWN]; }
	const std::wstring& GetLeftDoubleClickAction() const   { return m_MouseActions[MOUSE_LMB_DBLCLK]; }
	const std::wstring& GetMiddleUpAction() const          { return m_MouseActions[MOUSE_MMB_UP]; }
	const std::wstring& GetMiddleDownAction() const        { return m_MouseActions[MOUSE_MMB_DOWN]; }
	const std::wstring& GetMiddleDoubleClickAction() const { return m_MouseActions[MOUSE_MMB_DBLCLK]; }
	const std::wstring& GetRightUpAction() const           { return m_MouseActions[MOUSE_RMB_UP]; }
	const std::wstring& GetRightDownAction() const         { return m_MouseActions[MOUSE_RMB_DOWN]; }
	const std::wstring& GetRightDoubleClickAction() const  { return m_MouseActions[MOUSE_RMB_DBLCLK]; }
	const std::wstring& GetX1UpAction() const              { return m_MouseActions[MOUSE_X1MB_UP]; }
	const std::wstring& GetX1DownAction() const            { return m_MouseActions[MOUSE_X1MB_DOWN]; }
	const std::wstring& GetX1DoubleClickAction() const     { return m_MouseActions[MOUSE_X1MB_DBLCLK]; }
	const std::wstring& GetX2UpAction() const              { return m_MouseActions[MOUSE_X2MB_UP]; }
	const std::wstring& GetX2DownAction() const            { return m_MouseActions[MOUSE_X2MB_DOWN]; }
	const std::wstring& GetX2DoubleClickAction() const     { return m_MouseActions[MOUSE_X2MB_DBLCLK]; }

	const std::wstring& GetMouseScrollUpAction() const     { return m_MouseActions[MOUSE_MW_UP]; }
	const std::wstring& GetMouseScrollDownAction() const   { return m_MouseActions[MOUSE_MW_DOWN]; }
	const std::wstring& GetMouseScrollLeftAction() const   { return m_MouseActions[MOUSE_MW_LEFT]; }
	const std::wstring& GetMouseScrollRightAction() const  { return m_MouseActions[MOUSE_MW_RIGHT]; }

	const std::wstring& GetOverAction() const              { return m_MouseActions[MOUSE_OVER]; }
	const std::wstring& GetLeaveAction() const             { return m_MouseActions[MOUSE_LEAVE]; }

private:
	void ReplaceMouseVariables(std::wstring& result) const;

	std::wstring m_MouseActions[MOUSEACTION_COUNT];

	MOUSECURSOR m_CursorType;
	HCURSOR m_CustomCursor;
	bool m_CursorState;

	Skin* m_Skin;
	Meter* m_Meter;
};

#endif
