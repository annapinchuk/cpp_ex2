#pragma ONCE

using namespace std;
namespace ariel
{
class Player {     // The class
  private:          // Access specifier
    string name;
    int stack_size;
    int cardes_Taken;
  public:           // Access specifier
    // Constructor
    Player(string p_name){ 
      name = p_name;
      stack_size = 0;
      cardes_Taken = 0;
    }
    // Default Constructor   
    Player(){ 
      name = "stranger";
      stack_size = 0;
      cardes_Taken = 0;
    }  
    // Copy Constructor
    Player(const Player& p){ 
      name = p.name;
      stack_size = p.stack_size;
      cardes_Taken = p.cardes_Taken;
    }   
    int stacksize(){
      return stack_size;
    }
    int cardesTaken(){
      return cardes_Taken;
    }
};
}