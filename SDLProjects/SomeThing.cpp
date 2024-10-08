
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include <SDL.h>

/// <summary>
/// Piirtaa nykyisen sort algoritmin tilanteen
/// </summary>
/// <param name="v">lista jarjesteltavista asioista</>
/// <param name="renderer">renderoi mita tapahtuu</>
/// <param name="red">i vari</>
/// <param name="blue">j vari</>
void draw_state(std::vector<int>& v,
	SDL_Renderer* renderer,
	unsigned int red, unsigned int blue) 
{
	unsigned int index = 0;
	for (int i : v) {
		if (index == red) SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		
		else if (index == blue) SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		
		else SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderDrawLine(renderer, index, 99, index, i );
		index += 1;
	}
}

/// <summary>
/// SDL Ei toimi ilman naita
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char* argv[]) {

	SDL_Renderer;
	std::random_device rd;
	std::uniform_int_distribution<> d(1, 99);
	std::vector<int> v;
	//v.reserve(100); doing this is slower LOL

	// laita kamaa vectoriin
	for (int i = 0; i < 100; i++) {

		v.push_back(d(rd));
	}
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_CreateWindowAndRenderer(100 * 10, 100 * 10, 0, &window, &renderer);

	SDL_RenderSetScale(renderer, 10, 10);
	// sort algo

	for (unsigned int i = 0; i < v.size(); i++)
	{
		for (unsigned int j = i; j < v.size(); j++)
		{
			if (v[j] < v[i])
			{
				std::swap(v[j], v[i]);
			}

			//tyhjenn� ikkuna

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			// piirr� sortin tilanne
			draw_state(v, renderer, i,j);

			//n�yt� ikkunalle
			SDL_RenderPresent(renderer);
			SDL_Delay(10);
		}
	}

	return 0;
}