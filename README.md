# Analysis-of-Algorithm-Project
# C++ Fast Fourier Transform (FFT) Implementation

This repository contains a C++ implementation of the Fast Fourier Transform (FFT) algorithm. The FFT is an efficient algorithm to compute the Discrete Fourier Transform (DFT) and its inverse. This implementation uses a recursive approach, commonly known as the Cooley-Tukey algorithm.

## Description

The program takes a sequence of complex numbers as input (specifically, the number of samples must be a power of 2) and computes its FFT. The output is the frequency-domain representation of the input signal.

## Features

* **Recursive FFT:** Implements the Cooley-Tukey FFT algorithm recursively.
* **Complex Number Support:** Utilizes the `std::complex<double>` class for handling complex numbers.
* **User Input:** Allows users to specify the number of samples and input the real and imaginary parts for each sample.
* **Input Validation:** Checks if the number of samples is a positive power of 2, which is a requirement for this specific FFT implementation.
* **Clear Output:** Displays the FFT results in a user-friendly complex number format (e.g., `a + bi` or `a - bi`).

## Requirements

* A C++ compiler that supports C++11 or later (for `std::complex`, `std::vector`, etc.). Examples include:
    * GCC (g++)
    * Clang
    * MSVC (Visual Studio)
* Standard C++ libraries:
    * `<iostream>` for input/output operations.
    * `<vector>` for dynamic arrays (`std::vector`).
    * `<complex>` for complex number arithmetic (`std::complex`).
    * `<cmath>` for mathematical functions like `polar` and `PI` constant (though `M_PI` is often preferred if available and more standard).

## How to Compile and Run

1.  **Save the Code:** Save the C++ code into a file named `fft.cpp` (or any other `.cpp` file).

2.  **Compile:** Open a terminal or command prompt and use a C++ compiler to compile the code. Here's an example using g++:

    ```bash
    g++ fft.cpp -o fft_program -std=c++11
    ```

    * `fft.cpp`: Your source code file.
    * `-o fft_program`: Specifies the output executable file name as `fft_program`.
    * `-std=c++11`: Ensures C++11 standard compatibility (or higher, like `-std=c++14`, `-std=c++17`).

3.  **Run:** Execute the compiled program:

    ```bash
    ./fft_program
    ```

    On Windows, you might run it as:

    ```bash
    fft_program.exe
    ```

## Usage

When you run the program, it will prompt you to:

1.  **Enter the number of samples:** This number **must be a positive power of 2** (e.g., 2, 4, 8, 16, 32, ...).
2.  **Enter the real and imaginary parts** for each sample.

The program will then calculate and display the FFT of the input samples.

### Example Interaction


Enter the number of samples (must be a power of 2): 4
Enter the real and imaginary parts of the 4 samples:
Sample 1 - Real: 1
Sample 1 - Imaginary: 0
Sample 2 - Real: 2
Sample 2 - Imaginary: 0
Sample 3 - Real: 3
Sample 3 - Imaginary: 0
Sample 4 - Real: 4
Sample 4 - Imaginary: 0

FFT output (in frequency domain):
10 + 0i
-2 + 2i
-2 + 0i
-2 - 2i


## Algorithm Explanation

The code implements the **Cooley-Tukey FFT algorithm**, which is a divide-and-conquer algorithm. Here's a high-level overview:

1.  **Base Case:** If the input sequence has 0 or 1 sample, it's returned as is (its DFT is itself).
2.  **Divide:** The input sequence `a` of size `n` is split into two sub-sequences:
    * `even`: containing elements at even indices `a[0], a[2], ..., a[n-2]`.
    * `odd`: containing elements at odd indices `a[1], a[3], ..., a[n-1]`.
3.  **Conquer:** The FFT is recursively computed for both `even` and `odd` sub-sequences.
4.  **Combine:** The results from the recursive calls are combined to produce the FFT of the original sequence. For `k` from `0` to `n/2 - 1`:
    * $ A[k] = \text{FFT}_{\text{even}}[k] + \omega_n^k \cdot \text{FFT}_{\text{odd}}[k] $
    * $ A[k + n/2] = \text{FFT}_{\text{even}}[k] - \omega_n^k \cdot \text{FFT}_{\text{odd}}[k] $
    where $ \omega_n^k = e^{-2\pi i k / n} $ is the twiddle factor. The `polar(1.0, -2 * PI * k / n)` function in the code calculates this twiddle factor.

## Code Structure

* **`fft(vector<complex<double>>& a)`:** The core recursive function that performs the Fast Fourier Transform.
    * It splits the input vector into even and odd indexed elements.
    * Recursively calls itself on these two halves.
    * Combines the results using twiddle factors.
* **`printComplex(const complex<double>& c)`:** A utility function to display complex numbers in a readable format (e.g., `real + imag i` or `real - imag i`).
* **`main()`:**
    * Handles user input for the number of samples and the sample values.
    * Validates that the number of samples is a power of 2.
    * Calls the `fft` function to perform the transformation.
    * Prints the resulting frequency domain data using `printComplex`.

## License

Consider adding a license to your project, for example, the [MIT License](https://opensource.org/licenses/MIT). To do this, create a `LICENSE` file in your repository and add the license text to it.
