#include <SFML/Graphics.hpp>

#include "game.h"
#include "sorting.h"
#include <iostream>
#include <semaphore>
#include <thread>

std::binary_semaphore ready(0); // semaphore to signal when a value is ready
std::binary_semaphore value(0); // semaphore to signal when a value is consumed

bool completed = false;
int selectedIdx = -1, otherIdx = -1;

// function to map a value from one range into another range
int map(int x, int in_min, int in_max, int out_min, int out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main()
{
	std::cout << "Sorting Visualizer\n";
	std::cout << "1. Bubble Sort\n";
	std::cout << "2. Insertion Sort\n";
	std::cout << "3. Selection Sort\n";
	std::cout << "4. Merge Sort\n";
	std::cout << "5. Quick Sort\n";
	int choice;
	while (true)
	{
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (choice >= 1 && choice <= 5)
			break;
	}

	std::vector<void (*)(std::vector<int> &vec)> algorithms = {bubble_sort, insertion_sort, selection_sort, merge_sort, quicksort};

	// number of bars
	int n = 100;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "sorting visualizer", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	// Create an array of bars
	std::vector<int> bars;
	for (int i = 0; i < n; i++)
	{
		bars.push_back(map(i, 0, n, 10, HEIGHT));
	}

	// shuffle the array
	std::random_shuffle(bars.begin(), bars.end());

	std::thread t1(algorithms[choice - 1], std::ref(bars));
	t1.detach();

	while (window.isOpen())
	{
		// Handle events
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		if (!completed)
			ready.acquire(); // wait for a value to be ready

		window.clear(sf::Color::Black);
		int gap = WIDTH / n - 1;
		// draw the bars with one pixel gap between them
		for (int i = 0; i < n; i++)
		{
			sf::RectangleShape bar(sf::Vector2f(gap, bars[i]));
			bar.setPosition(i * (gap + 1), HEIGHT - bars[i]);
			// set the color of the bar to green if it is selected, blue if it is the other bar being compared, white otherwise
			if (i == selectedIdx)
				bar.setFillColor(sf::Color::Green);
			else if (i == otherIdx)
				bar.setFillColor(sf::Color::Blue);
			else
				bar.setFillColor(sf::Color::White);
			window.draw(bar);
		}
		window.display();

		if (!completed)
			value.release(); // signal that the value is consumed
	}
}