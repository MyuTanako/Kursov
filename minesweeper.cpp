#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

int main()
{
	
	int w = 32; // Ширина клетки
	
	int N = 10;
	int kol_min = 5;
	int veroyatost = 10;
	int nam = N + 2;
	/*int gridView[12][12];
	int gridLogic[12][12];*/
	
	

	int **gridLogic = new int* [nam];
	
	for (int i = 0; i < nam; i++)
	{
		gridLogic[i] = new int[nam];
	}

	int **gridView = new int* [nam];
	for (int i = 0; i < nam; i++)
	{
		gridView[i] = new int[nam];
	}
	
	
	int Foo(int x,int y, int k, int l)
	{
		(gridView[x + k][y + l] = gridLogic[x + k][y + l]);

	}
	

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
			//gridView[i][j] = gridLogic[i][j];
		}

	while (app.isOpen())
	{
		// Получаем координаты курсора мышки относительно окна нашего приложения
		Vector2i pos = Mouse::getPosition(app);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
			// Определяем, была ли нажата кнопка мыши?
			int o;
			if (e.type == Event::MouseButtonPressed)

				// Если была нажата левая кнопка мыши, то открываем клетку
				if (e.key.code == Mouse::Left)
				{
					int RightButton;
					RightButton = 1;
					if (gridView[x][y] == 11); //gridView[x][y] = 11;
					else gridView[x][y] = gridLogic[x][y];
				}
			
				// Если была нажата правая кнопка мыши, то отображаем флажок
				else if (e.key.code == Mouse::Right)
				{
					if (gridView[x][y] == 11) { gridView[x][y] = 10; }
					else if (gridView[x][y] == 10) { gridView[x][y] = 11; }
					
				}
				
				
		}
		// Устанавливаем белый фон
		app.clear(Color::White);


		

		/*if ((gridView[x][y] >= 1) or (gridView[x][y] ) gridView[i][j] = gridLogic[i][j];
		{

		}*/

		if (gridView[x][y] == 0)
		{

			for (int k = -1; k < 2; k++)
				for (int l = -1; l < 2; l++)
					if ((gridLogic[x + k][y + l] != 9) and (gridView[x + k][y + l] != 11))
						

		}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				

				if (gridView[x][y] == 9) gridView[i][j] = gridLogic[i][j];

				/*for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++)
					{
						
					}*/

			
				// Вырезаем из спрайта нужный нам квадратик текстуры
				s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
				// Устанавливаем его в заданную позицию...
				s.setPosition(i*w, j*w);
				// ... и отрисовываем
				app.draw(s);
				//gridView[i][j] = gridLogic[i][j];
			}


		// Отображаем всю композицию на экране
		app.display();
	}
	
	
	
	
	
	for (int i = 0; i < nam; i++)
	{
		delete[] gridView[i];
	}

	delete[] gridView;

	for (int i = 0; i < nam; i++)
	{
		delete[] gridLogic[i];
	}
	
	delete[] gridLogic;
	
	
	
	return 0;
}
