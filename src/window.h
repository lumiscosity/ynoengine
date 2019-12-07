/*
 * This file is part of EasyRPG Player.
 *
 * EasyRPG Player is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Player is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EP_WINDOW_H
#define EP_WINDOW_H

// Headers
#include "system.h"
#include "drawable.h"
#include "rect.h"

/**
 * Window class.
 */
class Window : public Drawable {
public:
	Window();
	~Window() override;

	void Draw() override;

	void Update();
	BitmapRef const& GetWindowskin() const;
	void SetWindowskin(BitmapRef const& nwindowskin);
	BitmapRef GetContents() const;
	void SetContents(BitmapRef const& ncontents);
	bool GetStretch() const;
	void SetStretch(bool nstretch);
	Rect const& GetCursorRect() const;
	void SetCursorRect(Rect const& ncursor_rect);
	bool GetActive() const;
	void SetActive(bool nactive);
	bool GetVisible() const;
	void SetVisible(bool nvisible);
	bool GetPause() const;
	void SetPause(bool npause);
	bool GetUpArrow() const;
	void SetUpArrow(bool npause);
	bool GetDownArrow() const;
	void SetDownArrow(bool npause);
	int GetX() const;
	void SetX(int nx);
	int GetY() const;
	void SetY(int ny);
	int GetWidth() const;
	void SetWidth(int nwidth);
	int GetHeight() const;
	void SetHeight(int nheight);
	int GetOx() const;
	void SetOx(int nox);
	int GetOy() const;
	void SetOy(int noy);
	int GetBorderX() const;
	void SetBorderX(int nox);
	int GetBorderY() const;
	void SetBorderY(int noy);
	int GetOpacity() const;
	void SetOpacity(int nopacity);
	int GetBackOpacity() const;
	void SetBackOpacity(int nback_opacity);
	int GetContentsOpacity() const;
	void SetContentsOpacity(int ncontents_opacity);
	void SetOpenAnimation(int frames);
	void SetCloseAnimation(int frames);

	bool IsOpening() const;
	bool IsClosing() const;
	bool IsOpeningOrClosing() const;

protected:
	unsigned long ID;
	BitmapRef windowskin, contents;
	bool stretch;
	Rect cursor_rect;
	bool active;
	bool visible;
	bool closing;
	bool up_arrow;
	bool down_arrow;
	int x;
	int y;
	int width;
	int height;
	int ox;
	int oy;
	int border_x;
	int border_y;
	int opacity;
	int back_opacity;
	int contents_opacity;

private:
	BitmapRef
		background, frame_down,
		frame_up, frame_left, frame_right, cursor1, cursor2;

	void RefreshBackground();
	void RefreshFrame();
	void RefreshCursor();

	bool background_needs_refresh;
	bool frame_needs_refresh;
	bool cursor_needs_refresh;
	bool pause = false;

	int cursor_frame = 0;
	int pause_frame = 0;
	int animation_frames = 0;
	double animation_count;
	double animation_increment;
};

inline bool Window::IsOpening() const {
	return animation_frames > 0 && !closing;
}

inline bool Window::IsClosing() const {
	return animation_frames > 0 && closing;
}

inline bool Window::IsOpeningOrClosing() const {
	return animation_frames > 0;
}

#endif
