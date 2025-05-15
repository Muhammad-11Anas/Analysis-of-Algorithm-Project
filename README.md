# Analysis-of-Algorithm-Project
Simple implementation Fast Fourier Transform (FFT)

# Fast Fourier Transform (FFT) in C++ using STL

This repository contains a simple and clean implementation of the **Fast Fourier Transform (FFT)** algorithm in C++ using only basic programming principles and the Standard Template Library (STL). It's designed to help beginners understand how FFT works step-by-step without relying on external libraries.

---

## 🚀 Features

- Implements the **Cooley-Tukey FFT algorithm**
- Uses **`std::vector`** for dynamic arrays
- Uses **`std::complex<double>`** for complex number arithmetic
- Handles inputs whose length is a **power of 2**

---

## 📘 What is FFT?

The Fast Fourier Transform is a highly efficient algorithm to compute the **Discrete Fourier Transform (DFT)** of a sequence. It's used in signal processing, audio analysis, image compression, and many other applications.

---

## 🧠 How It Works

- The input signal is recursively divided into even and odd parts.
- Each part is transformed separately using FFT.
- The results are combined using complex exponential multipliers called **twiddle factors** (`e^(-2πik/N)`).
- The output shows how much of each frequency is present in the input signal.

---

## 📦 Example Input and Output

### Input:

```cpp
std::vector<std::complex<double>> input = {1, 2, 3, 4};
