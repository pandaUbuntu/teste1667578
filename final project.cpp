#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    RenderWindow window(VideoMode(400, 400), "tipa minerware (IT)");

    int w = 32;
    int grid[12][12];
    int sgrid[12][12];

    Texture t;
    t.loadFromFile("C:/Users/Admin/Desktop/photo/IT.png");
    Sprite tiles(t);

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            sgrid[i][j] = 10;

            if (rand() % 5 == 0)
                grid[i][j] = 9;
            else
                grid[i][j] = 0;
        }

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            int n = 0;

            if (grid[i][j] == 9)
                continue;
            if (grid[i + 1][j] == 9)
                n++;
            if (grid[i][j + 1] == 9)
                n++;
            if (grid[i - 1][j] == 9)
                n++;
            if (grid[i][j - 1] == 9)
                n++;
            if (grid[i + 1][j + 1] == 9)
                n++;
            if (grid[i - 1][j - 1] == 9)
                n++;
            if (grid[i - 1][j + 1] == 9)
                n++;
            if (grid[i + 1][j - 1] == 9)
                n++;

            grid[i][j] = n;
        }

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x / w;
        int y = pos.y / w;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Left)
                    sgrid[x][y] = grid[x][y];
            if (event.key.code == Mouse::Right)
                sgrid[x][y] = 11;
        }

        window.clear(Color::White);

        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++) {
                if (sgrid[x][y] == 9)
                    sgrid[i][j] = grid[i][j];
                tiles.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
                tiles.setPosition(i * w, j * w);

                window.draw(tiles);
            }

        window.display();
    }

    return 0;
}