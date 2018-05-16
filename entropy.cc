#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

template <typename NumericType, int Discretization>
NumericType entropy(const std::string& fileDescriptor) {
  //throw std::runtime_error("Implement me!");


   std::uniform_int_distribution<unsigned int> dist(0, 128);
   std::random_device urandom(fileDescriptor);
   std::vector<unsigned int> pi(Discretization);

   // we generate random numbers
   for(unsigned int i = 0 ; i < 1000 ; ++i)
   {
     //vector[i] = dist(urandom);
     unsigned int u = dist(urandom);
     //std::cout<< u <<std::endl;

     if(0<=u && u<8){
      pi[0] += 1;

     }
     else if((8<=u && u<16)){
      pi[1]+= 1;
     }
     else if((16<=u && u<24)){
      pi[2]+= 1;
     }
     else if((24<=u && u<32)){
      pi[3]+= 1;
     }
     else if((32<=u && u<40)){
      pi[4]+= 1;
     }
     else if((40<=u && u<48)){
      pi[5]+= 1;
     }
     else if((48<=u && u<56)){
      pi[6]+= 1;
     }
     else if((56<=u && u<64)){
      pi[7]+= 1;
     }
     else if((64<=u && u<72)){
      pi[8]+= 1;
     }
     else if((72<=u && u<80)){
      pi[9]+= 1;
     }
     else if((80<=u && u<88)){
      pi[10]+= 1;
     }
     else if((88<=u && u<96)){
      pi[11]+= 1;
     }
     else if((96<=u && u<104)){
      pi[12]+= 1;
     }
     else if((104<=u && u<112)){
      pi[13]+= 1;
     }
     else if((112<=u && u<120)){
      pi[14]+= 1;
     }
     else if((120<=u && u<128)){
      pi[15]+= 1;
     }
     
   }
   // entropy is the sum for event independent
   //H(s) = sum pi*log2(1/pi) i =1..16
   NumericType  h = 0;

   for(size_t i = 0; i<16; i++)
    h += (1.0/pi[i])*std::log2(pi[i]);
     

   return h;

   
}

int main() {
  /*
   *Print out the entropy of a probability distribution over 8 discrete events,
   with event occurrences given by a random source of information. 
   */
  std::cout << entropy<float, 16>("/dev/urandom") << std::endl;
  /*
   *Note: this is a suggested function signature, feel free to implement
   whatever you see fit!
   */
}
