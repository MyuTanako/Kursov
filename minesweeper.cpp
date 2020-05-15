#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main()
{
		
	int w = 32; // Ширина клетки

	int N = 11;
	int kol_min = 25;
	int veroyatost = 10;
	int nam = 13;
	int gridView[13][13];
	int gridLogic[13][13];
	/*int **gridLogic = new int* [nam];
	
	for (int i = 0; 1 < nam; i++)
	{
		gridLogic[i] = new int[nam];
	}

	int **gridView = new int* [nam];
	for (int i = 0; 1 < nam; i++)
	{
		gridView[i] = new int[nam];
	}
	*/
	
	
	

	int raz = 32 * (N + 2);
	
	// Генератор случайных чисел
	srand(time(0));
	RenderWindow app(VideoMode(raz, raz), "Minesweeper!");

	// Загрузка текстуры и создание спрайта
	Texture t;
	t.loadFromFile("C:\\Users\\User\\source\\repos\\Minesweeper\\Debug\\1.jpg");
	
	Sprite s(t);

	//Рисуем видимый экран
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			gridView[i][j] = 10;

	//Расставляем мины
	while (kol_min > 0)
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (gridLogic[i][j] != 9)
				{
					if ((rand() % veroyatost == 0) and (kol_min > 0))
					{
						gridLogic[i][j] = 9;
						kol_min--;
					}
					else gridLogic[i][j] = 0;
				}
	}

	// Подсчёт мин вокруг каждой клетки	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{

			int n = 0;
			if (gridLogic[i][j] == 9) continue;
			if (gridLogic[i + 1][j] == 9) n++;
			if (gridLogic[i][j + 1] == 9) n++;
			if (gridLogic[i - 1][j] == 9) n++;
			if (gridLogic[i][j - 1] == 9) n++;
			if (gridLogic[i + 1][j + 1] == 9) n++;
			if (gridLogic[i - 1][j - 1] == 9) n++;
			if (gridLogic[i - 1][j + 1] == 9) n++;
			if (gridLogic[i + 1][j - 1] == 9) n++;
			gridLogic[i][j]		= n;
			gridView[i][j] = gridLogic[i][j];
		}

	while (app.isOpen())
	{
		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}
		// Устанавливаем белый фон
		app.clear(Color::White);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				// Вырезаем из спрайта нужный нам квадратик текстуры
				s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
				// Устанавливаем его в заданную позицию...
				s.setPosition(i*w, j*w);
				// ... и отрисовываем
				app.draw(s);
				gridView[i][j] = gridLogic[i][j];
			}


		// Отображаем всю композицию на экране
		app.display();
	}
	
	
	
	/*
	
	for (int i = 0; 1 < nam; i++)
	{
		delete[] gridView[i];
	}

	delete[] gridView;

	for (int i = 0; 1 < nam; i++)
	{
		delete[] gridLogic[i];
	}
	
	delete[] gridLogic;
	
	*/
	
	return 0;
}
