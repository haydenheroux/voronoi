#include "Color.h"

Color::Color(int r, int g, int b, int a) {
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

Color::Color(int r, int g, int b) {
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = 255;
}

int Color::Red() {
	return m_r;
}

int Color::Blue() {
	return m_b;
}

int Color::Green() {
	return m_g;
}

int Color::Alpha() {
	return m_a;
}
