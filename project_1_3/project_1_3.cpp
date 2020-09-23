#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========
    std::cout << "x: {" << x[0];
  for(int i = 1; i < x.size(); i++) {
    std::cout << ", " << x[i];
  }
  std::cout << "}" << std::endl;

  std::cout << "w: {" << w[0];
  for(int i = 1; i < w.size(); i++) {
    std::cout << ", " << w[i];
  }
  std::cout << "}" << std::endl;
  int vector_offset = (w.size() - 1) / 2;

  for (int i = 0; i < x.size(); i ++) {
    int intermediate_convolution = 0;
    for (int j = 0; j < w.size(); j++) {
      int vector_multiplier = x[i - vector_offset + j];
      if (!pack_with_zeros) {
        if (i - vector_offset + j < 0) {
          vector_multiplier = x[0];
        } else if (i - vector_offset + j > x.size() - 1) {
          vector_multiplier = x[x.size() - 1];
        }
      }

      intermediate_convolution += w[j] * vector_multiplier;
    }
      y.push_back(intermediate_convolution);
  }


  std::cout << "{" << y[0];
  for(int i = 1; i < y.size(); i++) {
    std::cout << ", " << y[i];
  }
  std::cout << "}" << std::endl;
  // =========== END ===========

  return 0;
}

