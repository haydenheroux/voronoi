#include <iostream>

#include <cmath>

#include <SDL2/SDL.h>

#include "Cell.h"
#include "Color.h"

Cell::Cell(int x, int y, Color* color) {
	m_x = x;
	m_y = y;
	m_color = color;
}

Cell::~Cell() {
	// TODO: Creates memory leak
	// delete m_color;
}

void Cell::Draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, m_color->Red(), m_color->Green(), m_color->Blue(), m_color->Alpha());
	SDL_RenderDrawPoint(renderer, m_x, m_y);
}

int Cell::GetX() {
	return m_x;
}

int Cell::GetY() {
	return m_y;
}

Color* Cell::GetColor() {
	return m_color;
}

void Cell::SetColor(Color* color) {
	m_color = color;
}

double Cell::DistanceTo(Cell* other) {
	double dx, dy;
	dx = m_x - other->GetX();
	dy = m_y - other->GetY();
	return std::pow(dx, 2) + std::pow(dy, 2);
}

void Cell::Move(int dx, int dy) {
	m_x += dx;
	m_y += dy;
}
