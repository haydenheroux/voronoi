#pragma once

class Color {
	private:
		int m_r, m_g, m_b, m_a;
	public:
		Color(int, int, int);
		Color(int, int, int, int);
		int Red();
		int Green();
		int Blue();
		int Alpha();
};
