#pragma once
#include "Color.h"

class Cell {
	private:
		int m_x, m_y;
		Color* m_color;

	public:
		Cell(int, int, Color*);
		~Cell();
		void Draw(SDL_Renderer*);
		int GetX();
		int GetY();
		Color* GetColor();
		void SetColor(Color*);
		double DistanceTo(Cell*);
		void Move(int, int);
};
