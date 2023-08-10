# Sorting Visualizer

This is a sorting algorithm visualizer implemented using SFML (Simple and Fast Multimedia Library) in C++. The program allows you to visualize various sorting algorithms by displaying the sorting process in a graphical window.

## Prerequisites

- C++ compiler with C++20 support
- SFML library

## Getting Started

1. Clone the repository:

   ```bash
   git clone https://github.com/kaustavsahoo/sfml-sorting.git
   ```

2. Compile the project using your preferred C++ compiler. Make sure to link against the SFML library.

   For g++:

   ```bash
   g++ main.cpp sorting.cpp -o sorting_visualizer -lsfml-graphics -lsfml-window -lsfml-system -std=c++20
   ```

   For Visual Studio (using the Developer Command Prompt):

   ```bash
   cl main.cpp sorting.cpp /Fe:sorting_visualizer /EHsc /std:c++20 /I "path_to_SFML_include_folder" /link "path_to_SFML_lib_folder\sfml-graphics.lib" "path_to_SFML_lib_folder\sfml-window.lib" "path_to_SFML_lib_folder\sfml-system.lib"
   ```

3. Run the executable:

   ```bash
   ./sorting_visualizer
   ```

4. Choose a sorting algorithm from the available options (1. Bubble Sort, 2. Insertion Sort, 3. Selection Sort, 4. Merge Sort, 5. Quick Sort).

5. Observe the sorting process visualization in the graphical window.

## Features

- Visualize the sorting process of various sorting algorithms.
- Color-coded bars represent elements being compared or sorted.
- Keyboard input: Press `Esc` to exit the visualization window.

## Project Structure

- `game.h`: Header file containing constants for the graphical window dimensions.
- `main.cpp`: Main program file that sets up the SFML window, handles user input, and initiates the sorting process.
- `sorting.cpp`: Source file containing the implementations of sorting algorithms (Bubble Sort, Insertion Sort, Selection Sort, Merge Sort, Quick Sort).
- `sorting.h`: Header file declaring the sorting algorithms and extern variables for synchronization using semaphores.

## Contributing

Contributions are welcome! If you'd like to add new features, fix bugs, or optimize the code, please feel free to submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).