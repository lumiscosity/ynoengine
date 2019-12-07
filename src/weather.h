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

#ifndef EP_WEATHER_H
#define EP_WEATHER_H

// Headers
#include <string>
#include "drawable.h"
#include "system.h"
#include "tone.h"

/**
 * Renders the weather effects.
 */
class Weather : public Drawable {
public:
	Weather();
	~Weather() override;

	void Draw() override;
	void Update();

	Tone GetTone() const;
	void SetTone(Tone tone);

private:
	void DrawRain();
	void DrawSnow();
	void DrawFog();
	void DrawSandstorm();

	BitmapRef weather_surface;
	BitmapRef snow_bitmap;
	BitmapRef rain_bitmap;

	Tone tone_effect;

	bool dirty = false;
};

#endif
