#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979323846;
// Recursive FFT function
void fft(vector<complex<double>>& a)
{
    int n = a.size();
    if (n <= 1) return;
    // Split the input into even and odd elements
    vector<complex<double>> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; i++) {  // Traditional for loop
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }
    // Recursive FFT on even and odd parts
    fft(even);
    fft(odd);

    // Combine step
    for (int k = 0; k < n / 2; k++) {  // Traditional for loop
        complex<double> wk = polar(1.0, -2 * PI * k / n); // e^(-2πik/n)//This function from the <cmath> (or implicitly <complex>) library creates a complex number given its magnitude (1.0) and phase angle (-2 * PI * k / n radians). This is equivalent to e −2πik / n in mathematical notation, a crucial part of the FFT algorithm.
        a[k] = even[k] + wk * odd[k];
        a[k + n / 2] = even[k] - wk * odd[k];
    }
}
// Function to display complex numbers in a user-friendly format
void printComplex(const complex<double>& c) {
    if (c.imag() < 0)
        cout << c.real() << " - " << -c.imag() << "i" << endl;
    else
        cout << c.real() << " + " << c.imag() << "i" << endl;
}
int main()
{
    // User input: Number of samples (must be a power of 2)
    int n;
    cout << "Enter the number of samples (must be a power of 2): ";
    cin >> n;
    // Ensure the number of samples is a power of 2
    if ((n & (n - 1)) != 0 || n <= 0) {
        cout << "Error: The number of samples must be a positive power of 2." << endl;
        return 1;
    }
    // Create a vector to hold the complex input values
    vector<complex<double>> input(n);
    // Get the real and imaginary parts of the input from the user
    cout << "Enter the real and imaginary parts of the " << n << " samples:" << endl;
    for (int i = 0; i < n; i++) {  // Traditional for loop
        double realPart, imagPart;
        cout << "Sample " << i + 1 << " - Real: ";
        cin >> realPart;
        cout << "Sample " << i + 1 << " - Imaginary: ";
        cin >> imagPart;
        input[i] = complex<double>(realPart, imagPart);
    }
    // Perform FFT
    fft(input);
    // Output the FFT result (frequency domain representation)
    cout << "\nFFT output (in frequency domain):" << endl;
    for (int i = 0; i < input.size(); i++) {  // Traditional for loop
        printComplex(input[i]);
    }
    return 0;
}