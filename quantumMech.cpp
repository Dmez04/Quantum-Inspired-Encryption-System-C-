#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class qubit {
public:
  int alpha, beta;
  qubit(int a, int b): alpha(a), beta(b) {}
};

vector<qubit> loadFlips(const string& filename) {
  ifstream file(filename);
  vector<qubit> flips;
  int a, b;
  while (file >> a >> b) {
    flips.push_back(qubit(a, b));
  }
  file.close();
  return flips;
}

vector<int> loadBinary(const string& filename) {
  ifstream file(filename);
  vector<int> binary;
  char bit;
  while (file >> bit) {
    binary.push_back(bit - '0');
  }
  file.close();
  return binary;
}

vector<int> encrypt(const vector<int>& binary, const vector<qubit>& flips, int mode) {
  vector<int> encrypted;
  int limit = min(mode, static_cast<int>(flips.size()));
  for (int i = 0; i < binary.size(); ++i) {
    int idx1 = rand() % limit;
    int idx2 = rand() % limit;
    int randBit = rand() % 2;
    if (binary[i] == 1) encrypted.push_back(flips[idx1].beta);
    else encrypted.push_back(flips[idx1].alpha);
    if (randBit == 1) encrypted.push_back(flips[idx2].beta);
    else encrypted.push_back(flips[idx2].alpha);
  }
  return encrypted;
}

vector<int> toBytes(const vector<int>& bits) {
  vector<int> bytes;
  for (int i = 0; i < bits.size(); i += 8) {
    int value = 0;
    for (int j = 0; j < 8 && i + j < bits.size(); ++j) {
      value = (value << 1) | bits[i + j];
    }
    bytes.push_back(value);
  }
  return bytes;
}

void printCipher(const vector<int>& bytes) {
  for (int i = 0; i < bytes.size(); ++i) {
    cout << bytes[i];
    if (i != bytes.size() - 1) cout << ".";
  }
  cout << endl;
}

int main() {
  srand(static_cast<unsigned>(time(0)));

  vector<int> binary = loadBinary("binSeq.txt");
  vector<qubit> flips = loadFlips("flip.txt");

  if (binary.empty() || flips.empty()) {
    cerr << "Error: Input files are missing or empty." << endl;
    return 1;
  }

  vector<int> encrypted128 = encrypt(binary, flips, 128);
  vector<int> encrypted64 = encrypt(binary, flips, 64);

  vector<int> bytes128 = toBytes(encrypted128);
  vector<int> bytes64 = toBytes(encrypted64);

  cout << "First Cipher: Modulo 128\n";
  printCipher(bytes128);

  cout << "Second Cipher: Modulo 64\n";
  printCipher(bytes64);

  return 2;
}
