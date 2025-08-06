 Quantum-Inspired Encryption System (C++)
This is a quantum-inspired encryption project written in C++ that simulates the concept of quantum bit (qubit) flips to perform binary-level encryption.
It uses a basic pseudo-random model to encrypt a binary sequence based on flip data resembling quantum state behavior.

Files

- main.cpp – Main C++ source file
- flip.txt – Simulated qubit flip data (alpha beta pairs)
- binSeq.txt – Binary sequence to encrypt (0s and 1s, grouped in bytes)

Features

- Reads a binary message (binSeq.txt) and simulated quantum flips (flip.txt)
- Encrypts the binary using random "measurements" of qubit pairs
- Runs two encryption passes:
  - Modulo 128
  - Modulo 64
- Converts the resulting encrypted bits into byte format
- Outputs the cipher as a sequence of integers separated by dots

Concepts Demonstrated

- File input handling using ifstream
- Randomized selection with rand() to simulate quantum measurement
- Binary to decimal byte conversion
- OOP with a simple qubit class
- Vector operations and modular function design
