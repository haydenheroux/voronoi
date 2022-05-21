#include <vector>
#include <random>

#include <SDL2/SDL.h>

#include "Cell.h"

void setColorToNearestSpecial(Cell* myself, std::vector<Cell>* specials) {
	std::vector<Cell>::iterator it;
	double closestDistance = INFINITY; 

	for (it = specials->begin(); it != specials->end(); ++it) {
		double currentDistance = myself->DistanceTo(&(*it));
		if (currentDistance <= closestDistance) {
			closestDistance = currentDistance;
			myself->SetColor(it->GetColor());
		}
	}
}

int main(void) {
	SDL_Event event;
	SDL_Window *window;
	SDL_Renderer *renderer;

	Color black = Color(0, 0, 0);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> x(0, 799);
	std::uniform_int_distribution<int> y(0, 599);
	std::uniform_int_distribution<int> count(40, 400);
	std::uniform_int_distribution<int> value(0, 255);

	std::vector<Cell> specialCells;
	int numOfSpecials = count(rng);
	while (numOfSpecials--) {
		Color* color = new Color(value(rng), value(rng), value(rng));
		specialCells.push_back(Cell(x(rng), y(rng), color));
	}

	std::vector<Cell> screen;

	for (int i = 0; i < 800; i++)
		for (int j = 0; j < 600; j++)
			screen.push_back(Cell(i, j, &black));

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;

	SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	std::vector<Cell>::iterator it;
	for (it = screen.begin(); it != screen.end(); ++it) {
		setColorToNearestSpecial(&(*it), &specialCells);
		it->Draw(renderer);
	}
	SDL_RenderPresent(renderer);

	specialCells.clear();

	while (1) {
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
